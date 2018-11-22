#pragma once

#include <string>

//-----------------------------------------------
//                  Constants
//-----------------------------------------------
// sprites for storage
const std::string CHEESE_IMAGE		= "assets\\food\\ingredients\\cheese.png";
const std::string CHICKEN_IMAGE		= "assets\\food\\ingredients\\chicken.png";
const std::string DOUGH_IMAGE		= "assets\\food\\ingredients\\dough.png";
const std::string FISH_IMAGE		= "assets\\food\\ingredients\\fish.png";
const std::string FRIES_IMAGE		= "assets\\food\\ingredients\\fries.png";
const std::string LETTUCE_IMAGE		= "assets\\food\\ingredients\\lettuce.png";
const std::string MEAT_IMAGE		= "assets\\food\\ingredients\\meat.png";
const std::string RICE_IMAGE		= "assets\\food\\ingredients\\rice.png";
const std::string SHRIMP_IMAGE		= "assets\\food\\ingredients\\shrimp.png";
const std::string SPAGHETTI_IMAGE	= "assets\\food\\ingredients\\spaghetti.png";
const std::string TOMATO_IMAGE		= "assets\\food\\ingredients\\tomato.png";

// sprites for plated fried-basket
const std::string PLATED_CHICKEN_IMAGE	= "assets\\food\\plated_food\\fried-basket\\chicken.png";
const std::string PLATED_FRIES_IMAGE	= "assets\\food\\plated_food\\fried-basket\\fries.png";

// sprites for sashimi+sushi
const std::string PLATED_SS_FISH_IMAGE		= "assets\\food\\plated_food\\sashimi+sushi\\fish.png";
const std::string PLATED_SS_PRAWN_IMAGE		= "assets\\food\\plated_food\\sashimi+sushi\\prawn.png";
const std::string PLATED_SS_RICE_IMAGE		= "assets\\food\\plated_food\\sashimi+sushi\\rice.png";

// sprites for plated pizza
const std::string PLATED_PIZZA_CHEESE_IMAGE		= "assets\\food\\plated_food\\pizza\\cheese.png";
const std::string PLATED_PIZZA_DOUGH_IMAGE		= "assets\\food\\plated_food\\pizza\\dough.png";
const std::string PLATED_PIZZA_MEAT_IMAGE		= "assets\\food\\plated_food\\pizza\\meat.png";
const std::string PLATED_PIZZA_TOMATO_IMAGE		= "assets\\food\\plated_food\\pizza\\tomato.png";

// sprites for plated pasta
const std::string PLATED_PASTA_CHEESE_IMAGE		= "assets\\food\\plated_food\\pasta\\cheese.png";
const std::string PLATED_PASTA_FISH_IMAGE		= "assets\\food\\plated_food\\pasta\\fish.png";
const std::string PLATED_PASTA_MEAT_IMAGE		= "assets\\food\\plated_food\\pasta\\meat.png";
const std::string PLATED_PASTA_SPAGHETTI_IMAGE	= "assets\\food\\plated_food\\pasta\\spaghetti.png";
const std::string PLATED_PASTA_TOMATO_IMAGE		= "assets\\food\\plated_food\\pasta\\tomato.png";

// sprites for vehicles
const std::string CAR1_UP_IMAGE		= "assets\\vehicle\\car1_up.png";
const std::string CAR1_DOWN_IMAGE	= "assets\\vehicle\\car1_down.png";
const std::string CAR2_UP_IMAGE		= "assets\\vehicle\\car2_up.png";
const std::string CAR2_DOWN_IMAGE	= "assets\\vehicle\\car2_down.png";
const std::string CAR3_UP_IMAGE		= "assets\\vehicle\\car3_up.png";
const std::string CAR3_DOWN_IMAGE	= "assets\\vehicle\\car3_down.png";

// sprites for player
const std::string PLAYER_NORTH_IMAGE	= "assets\\player\\north.png";
const std::string PLAYER_SOUTH_IMAGE	= "assets\\player\\south.png";
const std::string PLAYER_EAST_IMAGE		= "assets\\player\\east.png";
const std::string PLAYER_WEST_IMAGE		= "assets\\player\\west.png";

const float PLAYER_ANIMATION_DELAY = 0.2f; // time between frames of player animation
const int  PLAYER_WIDTH = 32;              // width of player image
const int  PLAYER_HEIGHT = 32;             // height of player image

// sprites for customers
const std::string CUSTOMER_IMAGE = "assets\\customer\\customer.png";

const std::string MAP_IMAGE = "assets\\map\\final_map.png";

// window
const std::string CLASS_NAME	= "Chaos Chef";
const std::string GAME_TITLE	= "Chaos Chef";
const bool FULLSCREEN = false;              // windowed or fullscreen
const int GAME_WIDTH = 640;               // width of game in pixels
const int GAME_HEIGHT = 360;               // height of game in pixels
