<?php
// Heartbeat — keeps the player session alive while they remain on a page.
// Called by the footer timer every ~3 minutes via XMLHttpRequest.
// get_player_info() (invoked through checklogin() in ajax_processor.php)
// already updates last_login, so no extra work is needed here.
header('Content-Type: application/json');
echo '{"status":"ok"}';
