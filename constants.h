#ifndef _CONSTANTS_H            // prevent multiple definitions if this 
#define _CONSTANTS_H            // ..file is included in more than one place
#define WIN32_LEAN_AND_MEAN

//-----------------------------------------------
//                  Constants
//-----------------------------------------------
// sprites for storage
const char CHEESE_IMAGE[] = "assets\\food\\ingredients\\cheese.png";
const char CHICKEN_IMAGE[] = "assets\\food\\ingredients\\chicken.png";
const char DOUGH_IMAGE[] = "assets\\food\\ingredients\\dough.png";
const char FISH_IMAGE[] = "assets\\food\\ingredients\\fish.png";
const char FRIES_IMAGE[] = "assets\\food\\ingredients\\fries.png";
const char LETTUCE_IMAGE[] = "assets\\food\\ingredients\\lettuce.png";
const char MEAT_IMAGE[] = "assets\\food\\ingredients\\meat.png";
const char RICE_IMAGE[] = "assets\\food\\ingredients\\rice.png";
const char SHRIMP_IMAGE[] = "assets\\food\\ingredients\\shrimp.png";
const char SPAGHETTI_IMAGE[] = "assets\\food\\ingredients\\spaghetti.png";
const char TOMATO_IMAGE[] = "assets\\food\\ingredients\\tomato.png";

// sprites for plated fried-basket
const char PLATED_CHICKEN_IMAGE[] = "assets\\food\\plated_food\\fried-basket\\chicken.png";
const char PLATED_FRIES_IMAGE[] = "assets\\food\\plated_food\\fried-basket\\fries.png";

// sprites for sashimi+sushi
const char PLATED_SS_FISH_IMAGE[] = "assets\\food\\plated_food\\sashimi+sushi\\fish.png";
const char PLATED_SS_PRAWN_IMAGE[] = "assets\\food\\plated_food\\sashimi+sushi\\prawn.png";
const char PLATED_SS_RICE_IMAGE[] = "assets\\food\\plated_food\\sashimi+sushi\\rice.png";

// sprites for plated pizza
const char PLATED_PIZZA_CHEESE_IMAGE[] = "assets\\food\\plated_food\\pizza\\cheese.png";
const char PLATED_PIZZA_DOUGH_IMAGE[] = "assets\\food\\plated_food\\pizza\\dough.png";
const char PLATED_PIZZA_MEAT_IMAGE[] = "assets\\food\\plated_food\\pizza\\meat.png";
const char PLATED_PIZZA_TOMATO_IMAGE[] = "assets\\food\\plated_food\\pizza\\tomato.png";

// sprites for plated pasta
const char PLATED_PASTA_CHEESE_IMAGE[] = "assets\\food\\plated_food\\pasta\\cheese.png";
const char PLATED_PASTA_FISH_IMAGE[] = "assets\\food\\plated_food\\pasta\\fish.png";
const char PLATED_PASTA_MEAT_IMAGE[] = "assets\\food\\plated_food\\pasta\\meat.png";
const char PLATED_PASTA_SPAGHETTI_IMAGE[] = "assets\\food\\plated_food\\pasta\\spaghetti.png";
const char PLATED_PASTA_TOMATO_IMAGE[] = "assets\\food\\plated_food\\pasta\\tomato.png";

// sprites for vehicles
const char CAR1_UP_IMAGE[] = "assets\\vehicle\\car1_up.png";
const char CAR1_DOWN_IMAGE[] = "assets\\vehicle\\car1_down.png";
const char CAR2_UP_IMAGE[] = "assets\\vehicle\\car2_up.png";
const char CAR2_DOWN_IMAGE[] = "assets\\vehicle\\car2_down.png";
const char CAR3_UP_IMAGE[] = "assets\\vehicle\\car3_up.png";
const char CAR3_DOWN_IMAGE[] = "assets\\vehicle\\car3_down.png";

// sprites for player
const char PLAYER_IMAGE[] = "assets\\player\\player.png";

// sprites for customers


// window
const char CLASS_NAME[] = "Chaos Chef";
const char GAME_TITLE[] = "Chaos Chef";
const bool FULLSCREEN = false;              // windowed or fullscreen
const UINT GAME_WIDTH =  640;               // width of game in pixels
const UINT GAME_HEIGHT = 360;               // height of game in pixels

//player
const int  PLAYER_START_FRAME = 0;         // starting frame of player animation
const int  PLAYER_END_FRAME = 3;           // last frame of player animation
const float PLAYER_ANIMATION_DELAY = 0.2f; // time between frames of player animation
const int  PLAYER_COLS = 4;                // player texture has 4 columns
const int  PLAYER_WIDTH = 32;              // width of player image
const int  PLAYER_HEIGHT = 32;             // height of player image

const UCHAR PLAYER_RIGHT_KEY = VK_RIGHT;
const UCHAR PLAYER_LEFT_KEY = VK_LEFT;
const UCHAR PLAYER_UP_KEY = VK_UP;
const UCHAR PLAYER_DOWN_KEY = VK_DOWN;

#endif
