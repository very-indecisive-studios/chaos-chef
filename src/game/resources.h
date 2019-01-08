#pragma once

#include <string>

//-----------------------------------------------
//                  Constants
//-----------------------------------------------
// font name
const std::string FONT_NAME = "assets\\font\\PixelOperator.ttf";
const std::string FONT_NAME_BOLD = "assets\\font\\PixelOperator-Bold.ttf";

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
const std::string CUSTOMER_LEFT_IMAGE = "assets\\customer\\customer.png";
const std::string CUSTOMER_RIGHT_IMAGE = "assets\\customer\\customer1.png";

const float CUSTOMER_ANIMATION_DELAY = 0.1f; // time between frames of customer animation
const int  CUSTOMER_WIDTH = 32;              // width of customer image
const int  CUSTOMER_HEIGHT = 32;             // height of customer image

// sprites for map
const std::string GAME_SCENE_IMAGE = "assets\\map\\final_map.png";

const std::string GAME_SCENE_HUD_IMAGE = "assets\\map\\hud.png";

// texts
const std::string FONT_TYPE = "Pixel Operator";
const int FONT_SIZE = 24;
const int FONT_COLOR_WHITE = 0xFFFFFFFF;
const int FONT_COLOR_RED = 0xFFFF0000;
const int FONT_COLOR_BLACK = 0xFF000000;

// leaderboard
const int NAME_INPUT_LIMIT = 12;
const std::string LEADERBOARD_DATA_FRIED_BASKET = "assets\\leaderboard\\data1.txt";
const std::string LEADERBOARD_DATA_S_AND_S = "assets\\leaderboard\\data2.txt";
const std::string LEADERBOARD_DATA_PIZZA = "assets\\leaderboard\\data3.txt";
const std::string LEADERBOARD_DATA_PASTA = "assets\\leaderboard\\data4.txt";
const char CHAR_LIMIT = ',';

// instructions
const std::string INSTRUCTION_IMAGE_1 = "assets\\tutorial\\instruction_1.png";
const std::string INSTRUCTION_IMAGE_2 = "assets\\tutorial\\instruction_2.png";
const std::string INSTRUCTION_IMAGE_3 = "assets\\tutorial\\instruction_3.png";
const std::string INSTRUCTION_IMAGE_4 = "assets\\tutorial\\instruction_4.png";
const std::string INSTRUCTION_IMAGE_5 = "assets\\tutorial\\instruction_5.png";
const std::string INSTRUCTION_IMAGE_6 = "assets\\tutorial\\instruction_6.png";

// backgrounds
const std::string BACKGROUND_IMAGE_MAIN_MENU = "assets\\backgrounds\\main_menu.png";
const std::string BACKGROUND_IMAGE_OTHERS = "assets\\backgrounds\\others.png";

// audio
const std::wstring BG_AUDIO = L"assets/audio/bg_music.mp3";
const std::string BG_AUDIO_TAG = "BG_AUDIO";
const std::wstring NEW_ORDER_AUDIO = L"assets/audio/new_order.wav";
const std::wstring ORDER_SUCCESS_AUDIO = L"assets/audio/order_success.wav";
const std::wstring CHICKEN_SPLAT_AUDIO = L"assets/audio/chicken_splat.wav";
const std::wstring CHICKEN_DED_AUDIO = L"assets/audio/chicken_ded.wav";
const std::wstring TIKTOK_AUDIO = L"assets/audio/tiktok.mp3";
const std::wstring PICKUP_AUDIO = L"assets/audio/pickup.wav";
const std::wstring WRONG_ORDER_AUDIO = L"assets/audio/wrong_order.wav";
const std::wstring TRASH_AUDIO = L"assets/audio/trash.wav";
const std::wstring RIP_AUDIO = L"assets/audio/rip.wav";
const std::wstring GAME_MUSIC_AUDIO = L"assets/audio/game_music.mp3";
const std::wstring ZOOM_AUDIO = L"assets/audio/zoom.mp3";
