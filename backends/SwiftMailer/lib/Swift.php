<?php
/**
 * Swift 1.x compatibility shim backed by PHPMailer 6.x (installed via Composer).
 * Replaces the original Swift Mailer 1.x library which used removed PHP
 * functions (mysql_fetch_array, get_magic_quotes_runtime, etc.).
 *
 * Supported API surface (argument order matches all AATraders call sites):
 *   $smtp = new Swift_Connection_SMTP($host, $port);
 *   $smtp->setUsername($user);
 *   $smtp->setPassword($pass);
 *   $swift   = new Swift($smtp);
 *   $message = new Swift_Message($subject, $body);
 *   $sent    = $swift->send($message, $to, $from);  // $to first, $from second
 */

// Use Composer autoloader (vendor/ at project root)
$_swiftShimAutoload = __DIR__ . '/../../../vendor/autoload.php';
if (file_exists($_swiftShimAutoload)) {
    require_once $_swiftShimAutoload;
}
unset($_swiftShimAutoload);

class Swift_Connection_SMTP
{
    public string $host;
    public int    $port;
    public string $username = '';
    public string $password = '';

    public function __construct(string $host, int $port = 25)
    {
        $this->host = $host;
        $this->port = $port;
    }

    public function setUsername(string $u): void { $this->username = $u; }
    public function setPassword(string $p): void { $this->password = $p; }
}

class Swift_Message
{
    public string $subject;
    public string $body;

    public function __construct(string $subject, string $body = '')
    {
        $this->subject = $subject;
        $this->body    = $body;
    }
}

/**
 * Swift_Address — name + e-mail pair (used in a handful of legacy send() calls)
 */
class Swift_Address
{
    public string $email;
    public string $name;

    public function __construct(string $email, string $name = '')
    {
        $this->email = $email;
        $this->name  = $name;
    }
}

class Swift
{
    private Swift_Connection_SMTP $connection;

    public function __construct(Swift_Connection_SMTP $conn)
    {
        $this->connection = $conn;
    }

    /**
     * Send a message.
     *
     * NOTE: argument order is ($msg, $to, $from) to match all AATraders call
     * sites.  The original Swift library accepted the same order.
     *
     * @param Swift_Message               $msg
     * @param string|Swift_Address        $to   Recipient address
     * @param string|Swift_Address        $from Sender   address
     * @return int  1 on success, 0 on failure
     */
    public function send(Swift_Message $msg, $to, $from): int
    {
        // Resolve Swift_Address objects to plain strings
        $toAddr   = ($to   instanceof Swift_Address) ? $to->email   : (string)$to;
        $fromAddr = ($from instanceof Swift_Address) ? $from->email : (string)$from;

        if (!class_exists('PHPMailer\\PHPMailer\\PHPMailer')) {
            // PHPMailer unavailable — fall back to PHP mail()
            $headers = "From: $fromAddr\r\nContent-Type: text/plain; charset=UTF-8\r\n";
            return mail($toAddr, $msg->subject, $msg->body, $headers) ? 1 : 0;
        }

        $m = new \PHPMailer\PHPMailer\PHPMailer(true);
        try {
            $c = $this->connection;
            $m->isSMTP();
            $m->Host     = $c->host;
            $m->Port     = $c->port;
            $m->SMTPAuth = ($c->username !== '');
            $m->Username = $c->username;
            $m->Password = $c->password;
            if ($c->port === 465) {
                $m->SMTPSecure = \PHPMailer\PHPMailer\PHPMailer::ENCRYPTION_SMTPS;
            } elseif ($c->port === 587) {
                $m->SMTPSecure = \PHPMailer\PHPMailer\PHPMailer::ENCRYPTION_STARTTLS;
            } else {
                $m->SMTPSecure  = '';
                $m->SMTPAutoTLS = false;
            }
            $m->setFrom($fromAddr);
            $m->addAddress($toAddr);
            $m->Subject = $msg->subject;
            $m->Body    = $msg->body;
            $m->CharSet = \PHPMailer\PHPMailer\PHPMailer::CHARSET_UTF8;
            $m->send();
            return 1;
        } catch (\PHPMailer\PHPMailer\Exception $e) {
            error_log('Swift compat error: ' . $e->getMessage());
            return 0;
        }
    }

    /** No-op — connection lifecycle handled internally */
    public function disconnect(): void {}
}
