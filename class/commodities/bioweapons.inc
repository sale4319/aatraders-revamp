<?php
class bioweapons {
	public $classname = "bio weapons";
	public $cargoclass = "commodity";	// the class of cargo (commodity, generic, shipweapon, planetweapon, sectordefense, ect)
	public $upgradeport = "0";	// is this a port item that can be bought and sold (yes or no)
	public $deviceport = "0";	// is this a port item that can be bought and sold (yes or no)
	public $cargoport = "1";	// is this a port item that can be bought and sold (yes or no)
	public $cargosellbuy = "1";	// 0 = sell and buy at ports, 1 = ports buy only, 2 = ports sell only
	public $cargoplanet = "1";	// is this an item that can be from a planet (yes or no)
	public $defaultcargoplanet = "0";	// is this a default item from a planet (yes or no)
	public $defaultcargoship = "0";	// is this a default item always carried by a ship (yes or no)
	public $shipdevice = "0";	// can this be used as a ship device (yes or no)
	public $planetdevice = "0";	// can this be used as a planet device (yes or no)
	public $shipdevicemax = "0";	// maximum number of this device a ship can carry
	public $planetdevicemax = "0";	// maximum number of this device a planet can hold
	public $researchonly = "0";	// this item can only be built at a research station if set to 1
	public $goodevil = "-1"; // good or evil commodity
	public $price = 150000000; // Default Price
	public $delta = 12500000; // Price modifier - reduce port sell price by this amount and increase port buy price by this amount
	public $rate = 35; // How many items to add back to a port per tick
	public $reducerate = 24.98123; // Price reduces per item traded (calculated from (price * multiplier / itemlimit) multiplier between 1-25 lower value higher the price)
	public $increaserate = 101749.896731; // Percentage prices will increase per trade schedule tick
	public $limit = 50000; // Maximum amount of commodity port can hold
	public $prate = 0.00000003; // Planetary Production Rate
	public $default_prod = 0; // Planet production percentage
	public $default_indy_prod = 1; // Planet production percentage
	public $default_create_percent = 0.135; // Percentage of item to create during Create Game
	public $fixed_start_price = 240000000; // this is the max fixed start price for this item 

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
	public $program = ""; // program to execute when player selects item
	public $hold_space = 150000; // the amount of hold space each item requires for storage

	public $image_location = 0; // 0 = inside each template image file, 1 = inside /images/classes

	// return language
	function __construct()
	{
		global $langdir, $l_bioweapons;
		switch ($langdir)
		{
			case "estonian":
				$l_bioweapons = "Bioweapons";
			break;

			case "french":
				$l_bioweapons = "Bioweapons";
			break;

			case "german":
				$l_bioweapons = "Bioweapons";
			break;

			case "italian":
				$l_bioweapons = "Bioweapons";
			break;

			case "russian":
				$l_bioweapons = "Bioweapons";
			break;

			case "spanish":
				$l_bioweapons = "Bioweapons";
			break;

			default:
				$l_bioweapons = "Bioweapons";
			break;
		}
	}
}
?>
