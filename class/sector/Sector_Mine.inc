<?php
class Sector_Mine {
	public $classname = "Sector Mine";
	public $cargoclass = "sectordefense";	// the class of cargo (commodity, generic, shipweapon, planetweapon, sectordefense, ect)
	public $deviceport = "1";	// is this a port item that can be bought and sold (yes or no)
	public $upgradeport = "0";	// is this a port item that can be bought and sold (yes or no)
	public $cargoport = "0";	// is this a port item that can be bought and sold (yes or no)
	public $cargoplanet = "0";	// is this an item that can be from a planet (yes or no)
	public $defaultcargoplanet = "0";	// is this a default item from a planet (yes or no)
	public $defaultcargoship = "0";	// is this a default item always carried by a ship (yes or no)
	public $shipdevice = "0";	// can this be used as a ship device (yes or no)
	public $planetdevice = "0";	// can this be used as a planet device (yes or no)
	public $shipdevicemax = "0";	// maximum number of this device a ship can carry
	public $planetdevicemax = "0";	// maximum number of this device a planet can hold
	public $researchonly = "0";	// this item can only be built at a research station if set to 1
	public $goodevil = "1"; // good or evil commodity
	public $price = 25; // Default Price
	public $delta = 0; // Price modifier
	public $rate = 0; // Replenishment rate
	public $reducerate = 0.00; // Percentage prices will reduce per unit purchaced by port
	public $increaserate = 0.00; // Percentage prices will increase per trade schedule tick
	public $limit = 0; // Maximum amount of commodity port can hold
	public $prate = 0.0; // Production Rate
	public $default_prod = 10; // Planet production percentage
	public $default_indy_prod = 0; // Planet production percentage
	public $default_create_percent = 0; // Percentage of item to create during Create Game
	public $fixed_start_price = 0; // this is the max fixed start price for this item 

	public $damage_shields = 1500; // amount of damage to enemy shield hit points per torp
	public $damage_all = 3000; // amount of damage to all enemy items except shields per torp
	public $deflector_damage = 150; // amound of damage to mines when each mine deflector hits
	public $hit_pts = 100; // the amount of damage a mine take before it is destroyed
	public $price_modifier = 1; // The cost of each torp is multiplied by this number
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
	public $hold_space = 1; // the amount of hold space each item requires for storage

}

?>