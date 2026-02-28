<?php
class dev_nova {

	function __construct()
	{
		global $langdir;
		switch ($langdir)
		{
			case "estonian":
				$this->classname = "Nova Bomb";
			break;

			case "french":
				$this->classname = "Nova Bomb";
			break;

			case "german":
				$this->classname = "Nova Bomb";
			break;

			case "italian":
				$this->classname = "Nova Bomb";
			break;

			case "russian":
				$this->classname = "Nova Bomb";
			break;

			case "spanish":
				$this->classname = "Nova Bomb";
			break;

			default:
				$this->classname = "Nova Bomb";
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
	public $shipdevicemax = "1";	// maximum number of this device a ship can carry
	public $planetdevicemax = "0";	// maximum number of this device a planet can hold
	public $researchonly = "0";	// this item can only be built at a research station if set to 1
	public $goodevil = "1"; // good or evil commodity
	public $price = 1000000000; // Default Price
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

	public $damage_shields = 10000; // amount of damage to enemy shield hit points per nova
	public $damage_all = 10000; // amount of damage to all enemy items except shields per nova
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
		global $shipdevice, $shipinfo, $zoneinfo;

		$device_java = "";
		if($shipdevice['dev_nova']['amount'] == '0' && $shipinfo['class'] >= $this->shipdevicemax && $zoneinfo['zone_id'] == 3)
		{
			$device_java = "changeNovaPrice(form.nova_purchase.value, 0)";
		}
		return $device_java;
	}

	function get_device_java2_countTotal()
	{
		$device_java = "";
		return $device_java;
	}

	function get_device_java_function($alliancefactor)
	{
		$device_data = "function changeNovaPrice(desiredvalue,currentvalue)\n";
		$device_data .= "{\n";
		$device_data .= "	if (desiredvalue == 0) return 0;\n";
		$device_data .= "	return Math.floor((((mypw(4.30, desiredvalue) - mypw(4.30, currentvalue)) * 200) + " . $this->price . ")) * $alliancefactor;\n";
		$device_data .= "}\n";
		return $device_data;
	}

	public $dev_nova_shiplimit = 50;
	function get_device_input()
	{
		global $zoneinfo, $shipdevice, $shipinfo, $l_equipped, $l_n_a;
		if($zoneinfo['zone_id'] == 3)
		{
			if($shipdevice['dev_nova']['amount'] == 0 and $shipinfo['class'] >= $this->dev_nova_shiplimit)
			{
				$nova_dropdown = $this->dropdown($this->form_name, 10, 15);
				$device_input = "$nova_dropdown";
			}
			else
			{
				$device_input = $shipdevice['dev_nova']['amount'] . "\n";
			}
		}
		else
		{
			if($shipdevice['dev_nova']['amount'] == 0 and $shipinfo['class'] >= $this->dev_nova_shiplimit)
			{
				$device_input = "$l_n_a";
			}
			else
			{
				$device_input = $shipdevice['dev_nova']['amount'] . "\n";
			}
		}
		return $device_input;
	}

	function dropdown($element_name, $current_value, $max_value)
	{
		$i = $current_value;
		$dropdownvar = "<select class=\"inputcss\" size=\"1\" name=\"$element_name\"";
		$dropdownvar = "$dropdownvar ONCHANGE=\"countTotal()\">\n";
		$dropdownvar = "$dropdownvar <option value=\"0\" selected>0</option>\n";
		while ($i <= $max_value)
		{
			$dropdownvar = "$dropdownvar <option value=\"$i\">$i</option>\n";
			 $i++;
		}
		$dropdownvar = "$dropdownvar		 </select>\n";
		return $dropdownvar;
	}

	public $form_name = "nova_purchase";

	// Port Device Purchase Functions
	public $device_amount = 0;
	function get_device_totalcost()
	{
		global $shipdevice, $zoneinfo;

		$formname = $this->form_name;
		$this->device_amount = $_POST[$formname];

		if(($this->device_amount != 0) && ($shipdevice['dev_nova']['amount'] == '0') && $zoneinfo['zone_id'] == 3)
		{
			return floor((((mypw(4.30, $this->device_amount) - mypw(4.30, 0)) * 200) + $this->price));
		}

		$this->device_amount = 0;
		return 0;
	}

	function complete_purchase()
	{
		global $db, $db_prefix, $shipdevice;
		$debug_query = $db->Execute("UPDATE {$db_prefix}ship_devices SET amount=" . $this->device_amount . " WHERE device_id=" . $shipdevice['dev_nova']['device_id']);
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