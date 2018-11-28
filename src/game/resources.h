#pragma once

#include <string>

const int GAME_WIDTH = 640;               // width of game in pixels
const int GAME_HEIGHT = 480;              // height of game in pixels

//-----------------------------------------------
//                  Constants
//-----------------------------------------------
// plate sprite
const std::string EMPTY_PLATE_IMAGE = "assets\\food\\plated food\\plate.png";

// sprites for dispenser
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
const std::string PLATED_CHICKEN_IMAGE	= "assets\\food\\plated food\\fried-basket\\chicken.png";
const std::string PLATED_FRIES_IMAGE	= "assets\\food\\plated food\\fried-basket\\fries.png";

// sprites for sashimi+sushi
const std::string PLATED_SS_FISH_IMAGE		= "assets\\food\\plated food\\sashimi+sushi\\fish.png";
const std::string PLATED_SS_PRAWN_IMAGE		= "assets\\food\\plated food\\sashimi+sushi\\prawn.png";
const std::string PLATED_SS_RICE_IMAGE		= "assets\\food\\plated food\\sashimi+sushi\\rice.png";

// sprites for plated pizza
const std::string PLATED_PIZZA_CHEESE_IMAGE		= "assets\\food\\plated food\\pizza\\cheese.png";
const std::string PLATED_PIZZA_DOUGH_IMAGE		= "assets\\food\\plated food\\pizza\\dough.png";
const std::string PLATED_PIZZA_MEAT_IMAGE		= "assets\\food\\plated food\\pizza\\meat.png";
const std::string PLATED_PIZZA_TOMATO_IMAGE		= "assets\\food\\plated food\\pizza\\tomato.png";

// sprites for plated pasta
const std::string PLATED_PASTA_CHEESE_IMAGE		= "assets\\food\\plated food\\pasta\\cheese.png";
const std::string PLATED_PASTA_FISH_IMAGE		= "assets\\food\\plated food\\pasta\\fish.png";
const std::string PLATED_PASTA_MEAT_IMAGE		= "assets\\food\\plated food\\pasta\\meat.png";
const std::string PLATED_PASTA_SPAGHETTI_IMAGE	= "assets\\food\\plated food\\pasta\\spaghetti.png";
const std::string PLATED_PASTA_TOMATO_IMAGE		= "assets\\food\\plated food\\pasta\\tomato.png";

// sprites for vehicles
const std::string VEHICLE1_UP_IMAGE		= "assets\\vehicle\\car1_up.png";
const std::string VEHICLE1_DOWN_IMAGE	= "assets\\vehicle\\car1_down.png";
const std::string VEHICLE2_UP_IMAGE		= "assets\\vehicle\\car2_up.png";
const std::string VEHICLE2_DOWN_IMAGE	= "assets\\vehicle\\car2_down.png";
const std::string VEHICLE3_UP_IMAGE		= "assets\\vehicle\\car3_up.png";
const std::string VEHICLE3_DOWN_IMAGE	= "assets\\vehicle\\car3_down.png";

const float VEHICLE_ANIMATION_DELAY = 0.1f; // time between frames of vehicle animation
const int  VEHICLE_WIDTH = 32;              // width of vehicle image
const int  VEHICLE_HEIGHT = 64;             // height of vehicle image

// sprites for player
const std::string PLAYER_NORTH_IMAGE	= "assets\\player\\north.png";
const std::string PLAYER_SOUTH_IMAGE	= "assets\\player\\south.png";
const std::string PLAYER_EAST_IMAGE		= "assets\\player\\east.png";
const std::string PLAYER_WEST_IMAGE		= "assets\\player\\west.png";

const float PLAYER_ANIMATION_DELAY = 0.1f; // time between frames of player animation
const int  PLAYER_WIDTH	= 32;              // width of player image
const int  PLAYER_HEIGHT = 32;             // height of player image

// sprites for customer
const std::string CUSTOMER_IMAGE = "assets\\customer\\customer.png";

const float CUSTOMER_ANIMATION_DELAY = 0.1f; // time between frames of customer animation
const int  CUSTOMER_WIDTH = 32;              // width of customer image
const int  CUSTOMER_HEIGHT = 32;             // height of customer image

// sprites for map
const std::string MAP_IMAGE = "assets\\map\\final_map.png";
const int  MAP_WIDTH	= 640;		// width of map
const int  MAP_HEIGHT	= 320;		// height of map

// texts
const std::string FONT_TYPE = "Arial";
const int FONT_SIZE = 24;
const int FONT_COLOR_WHITE = 0xFFFFFFFF;
const int FONT_COLOR_RED = 0xFFFF0000;
// sprites for hud
const std::string HUD_IMAGE = "assets\\map\\final_hud.png";
const int  HUD_WIDTH	= 640;		// width of hud
const int  HUD_HEIGHT	= 160;		// height of hud
const int  HAND_COMB_HUD_WIDTH = 64;
const int  HAND_COMB_HUD_HEIGHT = 64;
const int  HAND_INDV_HUD_WIDTH = 64;
const int  HAND_INDV_HUD_HEIGHT = 32;
const int  ORDER_HUD_WIDTH = 160;
const int  ORDER_HUD_HEIGHT = 96;