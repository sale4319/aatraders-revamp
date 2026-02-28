<?php
class dev_probes {

	function __construct()
	{
		global $langdir;
		switch ($langdir)
		{
			case "estonian":
				$this->classname = "Probes";
			break;

			case "french":
				$this->classname = "Probes";
			break;

			case "german":
				$this->classname = "Probes";
			break;

			case "italian":
				$this->classname = "Probes";
			break;

			case "russian":
				$this->classname = "Probes";
			break;

			case "spanish":
				$this->classname = "Probes";
			break;

			default:
				$this->classname = "Probes";
			break;
		}
	}

	public $techmodify = ""; // If not empty then this tech will be modified by the device prefix ship_ for ship tech and prefix planet_ for planet tech
	public $cargoclass = "shipdevice";	// the class of cargo (commodity, generic, shipweapon, planetweapon, sectordefense, ect)
	public $deviceport = "1";	// is this a port item that can be bought and sold (yes or no)
	public $upgradeport = "0";	// is this a port item that can be bought and sold (yes or no)
	public $cargoport = "0";	// is this a port item that can be bought and sold (yes or no)
	public $cargoplanet = "0";	// is this an item that can be from a planet (yes or no)
	public $defaultcargoplanet = "0";	// is this a default item from a planet (yes or no)
	public $defaultcargoship = "0";	// is this a default item always carried by a ship (yes or no)
	public $shipdevice = "1";	// can this be used as a ship device (yes or no)
	public $planetdevice = "0";	// can this be used as a planet device (yes or no)
	public $shipdevicemax = "100";	// maximum number of this device a ship can carry
	public $planetdevicemax = "0";	// maximum number of this device a planet can hold
	public $researchonly = "0";	// this item can only be built at a research station if set to 1
	public $goodevil = "1"; // good or evil commodity
	public $price = 10000; // Default Price
	public $delta = 0; // Price modifier
	public $rate = 0; // Replenishment rate
	public $reducerate = 0.00; // Percentage prices will reduce per unit purchaced by port
	public $increaserate = 0.00; // Percentage prices will increase per trade schedule tick
	public $limit = 0; // Maximum amount of commodity port can hold
	public $prate = 0.0; // Production Rate
	public $default_prod = 0; // Planet production percentage
	public $default_indy_prod = 0; // Planet production percentage
	public $default_create_percent = 0; // Percentage of item to create during Create Game
	public $fixed_start_price = 0; // this is the max fixed start price for this item 

	public $damage_shields = 0; // amount of damage to enemy shield hit points per torp
	public $damage_all = 0; // amount of damage to all enemy items except shields per torp
	public $deflector_damage = 0; // amound of damage to mines when each mine deflector hits
	public $hit_pts = 0; // the amount of damage a mine take before it is destroyed
	public $price_modifier = 0; // The cost of each torp is multiplied by this number
	public $energy_usage = 0; // How many units of energy is used

	public $researchcredits = 0; // How many credits to use per tick to research an item
	public $researchore = 0; // How much ore to use per tick to research an item
	public $researchorganics = 0; // How much organics to use per tick to research an item
	public $researchgoods = 0; // How many goods to use per tick to research an item
	public $researchenergy = 0; // How much energy to use per tick to research an item
	public $researchticks = 0; // How many ticks it takes to complete the researching of an item
	public $buildcredits = 0; // How many credits to use per tick to research an item
	public $buildore = 0; // How much ore to use per tick to research an item
	public $buildorganics = 0; // How much organics to use per tick to research an item
	public $buildgoods = 0; // How many goods to use per tick to research an item
	public $buildenergy = 0; // How much energy to use per tick to research an item
	public $buildticks = 0; // How many ticks it takes to complete building an item
	public $program = "probes.php?command=drop"; // program to execute when player selects item
	public $hold_space = 1; // the amount of hold space each item requires for storage

	// Port Device View Functions
	public $device_free = 0;
	public $ship_amount = 0;
	function get_device_java_countTotal($alliancefactor)
	{
		$device_java = "(form.elements['probe_number'].value * " . $this->price . " * $alliancefactor)";
		return $device_java;
	}

	function get_device_java2_countTotal()
	{
		global $shipdevice, $db, $db_prefix, $playerinfo, $shipinfo;

		$res=$db->Execute("SELECT count(probe_id) as probe_num from {$db_prefix}probe where owner_id=$playerinfo[player_id] AND ship_id=$shipinfo[ship_id]");
		$probe_num = $res->fields['probe_num'];
		$res->close();

		$this->ship_amount = $probe_num;
		$this->device_free = $this->shipdevicemax - $probe_num;

		$device_java = "if ((" . $this->device_free . " < form.probe_number.value) && (form.probe_number.value != 'Full'))\n";
		$device_java .= "{\n";
		$device_java .= "	form.probe_number.value=0;\n";
		$device_java .= "}\n";
		return $device_java;
	}

	function get_device_java_function($alliancefactor)
	{
		$device_java = "";
		return $device_java;
	}

	function get_device_input()
	{
		$device_input = "<input class=\"inputcss\" style=\"text-align:right\" size=\"4\" type=\"text\" name=\"" . $this->form_name . "\" value=\"0\" ONBLUR=\"countTotal()\">";
		return $device_input;
	}

	public $form_name = "probe_number";

	// Port Device Purchase Functions
	public $device_amount = 0;
	function get_device_totalcost()
	{
		global $db, $db_prefix, $playerinfo, $shipinfo;

		$formname = $this->form_name;
		$this->device_amount = $_POST[$formname];

		$res=$db->Execute("SELECT count(probe_id) as probe_num from {$db_prefix}probe where owner_id=$playerinfo[player_id] AND ship_id=$shipinfo[ship_id]");
		$probe_num = $res->fields['probe_num'];
		$res->close();
		if($probe_num <= $this->shipdevicemax)
		{
			$this->device_amount = max(0, min(round(abs($this->device_amount)), $this->shipdevicemax - $probe_num));
		}
		else
		{
			$this->device_amount = 0;
		}

		return $this->device_amount * $this->price;
	}

	function complete_purchase()
	{
		global $db, $db_prefix, $shipinfo, $playerinfo;

		for($i = 1; $i <= $this->device_amount; $i++)
		{
			$debug_query = $db->Execute("INSERT INTO {$db_prefix}probe (probe_id,  owner_id, ship_id, engines, sensors, cloak,sector_id,type,active, class) values ('',$playerinfo[player_id],'$shipinfo[ship_id]','0','0','0','0','0','P','sentry')");
			db_op_result($debug_query,__LINE__,__FILE__);
		}
	}

	// General Device Functions
	function device_code()
	{
		global $db, $db_prefix, $playerinfo, $shipinfo;

		$debug_query = $db->Execute("SELECT * from {$db_prefix}probe WHERE owner_id = $playerinfo[player_id] AND ship_id = $shipinfo[ship_id]");
		db_op_result($debug_query,__LINE__,__FILE__);

		$deviceamount[$count] = $debug_query->RecordCount();
		$amount = $debug_query->RecordCount();
		return $amount;
	}

	function report_code()
	{
	}

	function scan_code()
	{
	}

	function port_devices_code()
	{
	}

	function port_devices_buy_code()
	{
	}

	function devices_score_code($player_id)
	{
		global $db, $db_prefix;

		$debug_query = $db->Execute("SELECT * from {$db_prefix}probe WHERE owner_id = $player_id");
		db_op_result($debug_query,__LINE__,__FILE__);

		$amount = $debug_query->RecordCount();
		return $amount;
	}

	function modify_tech_code($shipinfo)
	{
		global $shiptypes;
	}
}

?>