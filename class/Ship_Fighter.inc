<?php
class Ship_Fighter {

	public $fighter_damage_shields = 500; // amount of damage to enemy shield hit points per fighter
	public $fighter_damage_all = 1000; // amount of damage to all enemy items except shields per fighter

	public $fighter_hit_pts = 750; // the amount of damage a fighter can take before it is destroyed

	public $price_modifier = 1; // The cost of each fighter is multiplied by this number
	public $fighter_price = 50; // The cost of each fighter is multiplied by this number
}

?>