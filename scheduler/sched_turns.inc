<?php
// 1
// 70
// 5
// 0
// Y
// How Often Turns will be added to all players.


// enable schedule - 0 disable schedule, 1 enable schedule
// execution order - the order of execution
// ticks full - how many minues between each execution
// loop_count - the number of times to execute schedule before deleting
// is_loop - "Y" loop enlessly, "N" - execute the number of times indocated by spawn value
// extra info - description of the schedule


$turns_results1 = '';
$turns_results2 = '';

$unixstamp = time();
$stamp = date("Y-m-d H:i:s", ($unixstamp - 360));

// Use $idle_max + 2 as the scheduler threshold — 2 minutes more generous than the
// per-request checklogin() threshold. This prevents the scheduler from evicting
// a player whose last heartbeat was up to ~3 min ago and whose next heartbeat had
// not yet fired when the scheduler tick ran (a race that caused active users to be
// unexpectedly logged out). Individual requests still enforce the exact $idle_max.
$debug_query = $db->Execute("UPDATE {$db_prefix}players SET sessionid='', last_login='$stamp', logged_out='Y', profile_cached='Y' 
WHERE ($unixstamp - UNIX_TIMESTAMP(last_login)) / 60 > ($idle_max + 2) and email NOT LIKE '%@npc' and logged_out != 'Y'"); 
db_op_result($debug_query,__LINE__,__FILE__);

$debug_query = $db->Execute("UPDATE {$db_prefix}players SET turns=LEAST(turns+$turn_rate, $max_turns), team_cash_countdown=GREATEST(0,
team_cash_countdown - 1)"); db_op_result($debug_query, __LINE__, __FILE__);

while (!$debug_query->EOF && $debug_query != '') 
{
    $turns_results1 = $debug_query;
}

if ($adminexecuted == 1) {
    TextFlush("<b>TURNS</b><br /><br />");
    
    if ($turns_results1 != '') 
    {
        TextFlush("Errors encountered: $turns_results1");
    } else {
        TextFlush("Completed successfully!");
    }
    TextFlush("<br /><br />");
}

$multiplier = 0;

?>
