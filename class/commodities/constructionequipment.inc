<?php
class constructionequipment {
	public $classname = "construction equipment";
	public $cargoclass = "commodity";	// the class of cargo (commodity, generic, shipweapon, planetweapon, sectordefense, ect)
	public $upgradeport = "0";	// is this a port item that can be bought and sold (yes or no)
	public $deviceport = "0";	// is this a port item that can be bought and sold (yes or no)
	public $cargoport = "1";	// is this a port item that can be bought and sold (yes or no)
	public $cargosellbuy = "0";	// 0 = sell and buy at ports, 1 = ports buy only, 2 = ports sell only
	public $cargoplanet = "1";	// is this an item that can be from a planet (yes or no)
	public $defaultcargoplanet = "0";	// is this a default item from a planet (yes or no)
	public $defaultcargoship = "0";	// is this a default item always carried by a ship (yes or no)
	public $shipdevice = "0";	// can this be used as a ship device (yes or no)
	public $planetdevice = "0";	// can this be used as a planet device (yes or no)
	public $shipdevicemax = "0";	// maximum number of this device a ship can carry
	public $planetdevicemax = "0";	// maximum number of this device a planet can hold
	public $researchonly = "0";	// this item can only be built at a research station if set to 1
	public $goodevil = "1"; // good or evil commodity
	public $price = 103000; // Default Price
	public $delta = 10300; // Price modifier - reduce port sell price by this amount and increase port buy price by this amount
	public $rate = 4200; // How many items to add back to a port per tick
	public $reducerate = 0.0171539; // Price reduces per item traded (calculated from (price * multiplier / itemlimit) multiplier between 1-25 lower value higher the price)
	public $increaserate = 26.62549; // Percentage prices will increase per trade schedule tick
	public $limit = 6000000; // Maximum amount of commodity port can hold
	public $prate = 0.000018; // Planetary Production Rate
	public $default_prod = 1; // Planet production percentage
	public $default_indy_prod = 10; // Planet production percentage
	public $default_create_percent = 1; // Percentage of item to create during Create Game
	public $fixed_start_price = 164800; // this is the max fixed start price for this item 

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
	public $hold_space = 250; // the amount of hold space each item requires for storage

	public $image_location = 0; // 0 = inside each template image file, 1 = inside /images/classes

	// return language
	function __construct()
	{
		global $langdir, $l_constructionequipment;
		switch ($langdir)
		{
			case "estonian":
				$l_constructionequipment = "Construction Equipment";
			break;

			case "french":
				$l_constructionequipment = "Construction Equipment";
			break;

			case "german":
				$l_constructionequipment = "Construction Equipment";
			break;

			case "italian":
				$l_constructionequipment = "Construction Equipment";
			break;

			case "russian":
				$l_constructionequipment = "Construction Equipment";
			break;

			case "spanish":
				$l_constructionequipment = "Construction Equipment";
			break;

			default:
				$l_constructionequipment = "Construction Equipment";
			break;
		}
	}
}
?>
