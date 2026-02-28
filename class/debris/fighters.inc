<?php
class fighters {
	public $classname = "fighters";
	public $success = "100";	// Random value range
	public $trigger = "50";	// Midpoint in random value range.  If random value from success range equals trigger then debris added
	public $destroyship_debris = "1";	// Set to 1 is this debris can be created when a ship is destroyed
	public $autoadd_debris = 1; // Set to 1 for the scheduler to auto add this debris,
	public $enable = "1";	// 1 = debris enabled in the game, 0 = debris disabled in the game

	// language variables
	public $l_debris_addfighters;
	public $l_debris_removefighters;

	// fill language variables
	function __construct()
	{
		global $langdir;
		switch ($langdir)
		{
			case "estonian":
				$this->l_debris_addfighters = "You have found the hulk of a carrier and it contains [amount] usable fighters.";
				$this->l_debris_removefighters = "When you bring the debris into your hanger it becomes unstable and explodes destroying [amount] of your fighters.";
			break;

			case "french":
				$this->l_debris_addfighters = "Vous avez trouv la carcasse d'un porte-vaisseau. Elle contient [amount] chasseurs utilisables.";
				$this->l_debris_removefighters = "Le transport des dbris instables dans votre hangar dclenche une explosion qui dtruit [amount] chasseurs.";
			break;

			case "german":
				$this->l_debris_addfighters = "Sie haben den Koloss eines Trgerschiffes gefunden und es beinhaltet [amount] voll funktionsfhige Jger.";
				$this->l_debris_removefighters = "Whrend Sie den Schutt in Ihren Hangar befrdern wird er unstabil. Er explodiert und zerstrt [amount] Ihrer Jger.";
			break;

			case "italian":
				$this->l_debris_addfighters = "Hai scoperto la carcassa di un incrociatore, contenente [amount] Droni utilizzabili.";
				$this->l_debris_removefighters = "Mentre trasporti i rottami nel tuo hangar per analizzarli, essi esplodono distruggendo [amount] dei tuoi Droni.";
			break;

			case "russian":
				$this->l_debris_addfighters = "You have found the hulk of a carrier and it contains [amount] usable fighters.";
				$this->l_debris_removefighters = "When you bring the debris into your hanger it becomes unstable and explodes destroying [amount] of your fighters.";
			break;

			case "spanish":
				$this->l_debris_addfighters = "You have found the hulk of a carrier and it contains [amount] usable fighters.";
				$this->l_debris_removefighters = "When you bring the debris into your hanger it becomes unstable and explodes destroying [amount] of your fighters.";
			break;

			default:
				$this->l_debris_addfighters = "You have found the hulk of a carrier and it contains [amount] usable fighters.";
				$this->l_debris_removefighters = "When you bring the debris into your hanger it becomes unstable and explodes destroying [amount] of your fighters.";
			break;
		}
	}

	// Code to execute when showdebris.php is executed.
	function show_debris_code()
	{
		global $db, $db_prefix, $row, $shipinfo;

		if($row['debris_data'] > 1)
		{
			$debrismessage = str_replace("[amount]", NUMBER($row['debris_data']), $this->l_debris_addfighters);
			$debug_query = $db->Execute("UPDATE {$db_prefix}ships SET fighters=fighters+$row[debris_data] WHERE ship_id=$shipinfo[ship_id]");
			db_op_result($debug_query,__LINE__,__FILE__);
		}else{
			if(($shipinfo['fighters'] + $row['debris_data']) <= 0){
				$row['debris_data'] = 1 - $shipinfo['fighters'];
			}
			$debrismessage = str_replace("[amount]", NUMBER($row['debris_data']), $this->l_debris_removefighters);
			$debug_query = $db->Execute("UPDATE {$db_prefix}ships SET fighters=GREATEST(fighters+$row[debris_data], 0) WHERE ship_id=$shipinfo[ship_id]");
			db_op_result($debug_query,__LINE__,__FILE__);
		}
		return $debrismessage;
	}

	// Code to execute when a ship has been destroyed
	function destroyship_debris_code($max_list, $destroyed_ship_info)
	{
		$amount = mt_rand(50, 50 + $destroyed_ship_info['fighters']);
		$debris_data = (mt_rand(0, 1) == 1) ? -$amount : $amount;
		return $debris_data;
	}

	// Code to execute when the scheduler adds this item to the universe
	function autoadd_debris_code($max_list)
	{
		$amount = mt_rand(50, 50 + NUM_PER_LEVEL($max_list['fighter_max']));
		$debris_data = (mt_rand(0, 1) == 1) ? -$amount : $amount;
		return $debris_data;
	}
}

?>