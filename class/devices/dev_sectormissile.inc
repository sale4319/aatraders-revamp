<?php
class dev_sectormissile {

	function __construct()
	{
		global $langdir;
		switch ($langdir)
		{
			case "estonian":
				$this->classname = "Sector Missile";
			break;

			case "french":
				$this->classname = "Sector Missile";
			break;

			case "german":
				$this->classname = "Sector Missile";
			break;

			case "italian":
				$this->classname = "Sector Missile";
			break;

			case "russian":
				$this->classname = "Sector Missile";
			break;

			case "spanish":
				$this->classname = "Sector Missile";
			break;

			default:
				$this->classname = "Sector Missile";
			break;
		}
	}

	public $techmodify = ""; // If not empty then this tech will be modified by the device prefix ship_ for ship tech and prefix planet_ for planet tech
	public $cargoclass = "shipdevice";	// the class of cargo (commodity, generic, shipweapon, planetweapon, sectordefense, ect)
	public $deviceport = "2";	// is this a port item that can be bought and sold (yes or no) 0=no, 1=yes, 2=alliance only
	public $upgradeport = "0";	// is this a port item that can be bought and sold (yes or no)
	public $cargoport = "0";	// is this a port item that can be bought and sold (yes or no)
	public $cargoplanet = "0";	// is this an item that can be from a planet (yes or no)
	public $defaultcargoplanet = "0";	// is this a default item from a planet (yes or no)
	public $defaultcargoship = "0";	// is this a default item always carried by a ship (yes or no)
	public $shipdevice = "1";	// can this be used as a ship device (yes or no)
	public $planetdevice = "0";	// can this be used as a planet device (yes or no)
	public $shipdevicemax = "5";	// maximum number of this device a ship can carry
	public $planetdevicemax = "0";	// maximum number of this device a planet can hold
	public $researchonly = "0";	// this item can only be built at a research station if set to 1
	public $goodevil = "1"; // good or evil commodity
	public $price = 1000000; // Default Price
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

	public $damage_shields = 11000; // amount of damage to enemy shield hit points per energy unit
	public $damage_all = 9000; // amount of damage to all enemy items except shields per energy unit
	public $deflector_damage = 0.8; // minimum random damage percentage ??-100%
	public $hit_pts = 0; // the amount of damage a nova take before it is destroyed
	public $price_modifier = 1.10; // The cost of each nova level is multiplied by this number
	public $energy_usage = 1.10; // Level Multiplier for damage inflicted

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
	public $program = ""; // program to execute when player selects item
	public $hold_space = 1; // the amount of hold space each item requires for storage

	// Port Device View Functions
	public $device_free = 0;
	public $ship_amount = 0;
	function get_device_java_countTotal($alliancefactor)
	{
		$device_java = "(form.dev_sectormissile_number.value * " . $this->price . " * $alliancefactor)";
		return $device_java;
	}

	function get_device_java2_countTotal()
	{
		$device_java = "";
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

	public $form_name = "dev_sectormissile_number";

	// Port Device Purchase Functions
	public $device_amount = 0;
	function get_device_totalcost()
	{
		global $shipdevice;

		$formname = $this->form_name;
		$fixedamount = max(0, $_POST[$formname]);
		if($shipdevice['dev_sectormissile']['amount'] + $fixedamount > $this->shipdevicemax)
		{
			$fixedamount = $this->shipdevicemax - $shipdevice['dev_sectormissile']['amount'];
		}
		$this->device_amount = $fixedamount;
		return $this->device_amount * $this->price;
	}

	function complete_purchase()
	{
		global $db, $db_prefix, $shipdevice;
		$debug_query = $db->Execute("UPDATE {$db_prefix}ship_devices SET amount=amount+" . $this->device_amount . " WHERE device_id=" . $shipdevice['dev_sectormissile']['device_id']);
		db_op_result($debug_query,__LINE__,__FILE__);
	}

	// General Device Functions
	function device_code()
	{
		global $deviceamount, $count;
		return $deviceamount[$count];
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
		global $deviceamount;
		return $deviceamount;
	}

	function modify_tech_code($shipinfo)
	{
		global $shiptypes;
	}
}

?>