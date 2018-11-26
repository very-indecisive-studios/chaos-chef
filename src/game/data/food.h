#pragma once

#include <string>
#include <vector>
#include "spriteLayer.h"
#include "game/resources.h"

struct Ingredient
{
	std::string textureName;
};

static const Ingredient INGR_CHEESE		{ CHEESE_IMAGE };
static const Ingredient INGR_CHICKEN	{ CHICKEN_IMAGE };
static const Ingredient INGR_DOUGH		{ DOUGH_IMAGE };
static const Ingredient INGR_FISH		{ FISH_IMAGE };
static const Ingredient INGR_FRIES		{ FRIES_IMAGE };
static const Ingredient INGR_LETTUCE	{ LETTUCE_IMAGE };
static const Ingredient INGR_MEAT		{ MEAT_IMAGE };
static const Ingredient INGR_RICE		{ RICE_IMAGE };
static const Ingredient INGR_SHRIMP		{ SHRIMP_IMAGE };
static const Ingredient INGR_SPAGHETTI	{ SPAGHETTI_IMAGE };
static const Ingredient INGR_TOMATO		{ TOMATO_IMAGE };

struct PlatedFood
{
	SpriteLayer layer;
	const Ingredient *ingredient;
	std::string textureName;
};

static const PlatedFood PFOOD_FB_CHICKEN		{ SpriteLayer::FOOD_1, &INGR_CHICKEN, PLATED_CHICKEN_IMAGE };
static const PlatedFood PFOOD_FB_FRIES			{ SpriteLayer::FOOD_1, &INGR_FRIES, PLATED_FRIES_IMAGE };

static const PlatedFood PFOOD_SS_RICE			{ SpriteLayer::FOOD_1, &INGR_RICE, PLATED_SS_RICE_IMAGE };
static const PlatedFood PFOOD_SS_PRAWN			{ SpriteLayer::FOOD_2, &INGR_SHRIMP, PLATED_SS_PRAWN_IMAGE };
static const PlatedFood PFOOD_SS_FISH			{ SpriteLayer::FOOD_2, &INGR_FISH, PLATED_SS_FISH_IMAGE };

static const PlatedFood PFOOD_PIZZA_DOUGH		{ SpriteLayer::FOOD_1, &INGR_DOUGH, PLATED_PIZZA_DOUGH_IMAGE };
static const PlatedFood PFOOD_PIZZA_TOMATO		{ SpriteLayer::FOOD_2, &INGR_TOMATO, PLATED_PIZZA_TOMATO_IMAGE };
static const PlatedFood PFOOD_PIZZA_MEAT		{ SpriteLayer::FOOD_3, &INGR_MEAT, PLATED_PIZZA_MEAT_IMAGE };
static const PlatedFood PFOOD_PIZZA_CHEESE		{ SpriteLayer::FOOD_4, &INGR_CHEESE, PLATED_PIZZA_CHEESE_IMAGE };

static const PlatedFood PFOOD_PASTA_SPAGHETTI	{ SpriteLayer::FOOD_1, &INGR_SPAGHETTI, PLATED_PASTA_SPAGHETTI_IMAGE };
static const PlatedFood PFOOD_PASTA_TOMATO		{ SpriteLayer::FOOD_2, &INGR_TOMATO, PLATED_PASTA_TOMATO_IMAGE };
static const PlatedFood PFOOD_PASTA_FISH		{ SpriteLayer::FOOD_3, &INGR_FISH, PLATED_PASTA_FISH_IMAGE };
static const PlatedFood PFOOD_PASTA_MEAT		{ SpriteLayer::FOOD_4, &INGR_MEAT, PLATED_PASTA_MEAT_IMAGE };
static const PlatedFood PFOOD_PASTA_CHEESE		{ SpriteLayer::FOOD_5, &INGR_CHEESE, PLATED_PASTA_CHEESE_IMAGE };

struct Meal
{
	std::vector<const PlatedFood *> foods;
};

static const Meal MEAL_FB_COMBO_1	{ { &PFOOD_FB_CHICKEN } };
static const Meal MEAL_FB_COMBO_2	{ { &PFOOD_FB_FRIES } };
static const Meal MEAL_FB_COMBO_3	{ { &PFOOD_FB_CHICKEN, &PFOOD_FB_FRIES } };

static const Meal MEAL_SS_COMBO_1	{ { &PFOOD_SS_FISH } };
static const Meal MEAL_SS_COMBO_2	{ { &PFOOD_SS_PRAWN } };
static const Meal MEAL_SS_COMBO_3	{ { &PFOOD_SS_FISH, &PFOOD_SS_RICE } };
static const Meal MEAL_SS_COMBO_4	{ { &PFOOD_SS_PRAWN, &PFOOD_SS_RICE } };

static const Meal MEAL_PIZZA_COMBO_1	{ { &PFOOD_PIZZA_DOUGH, &PFOOD_PIZZA_TOMATO } };
static const Meal MEAL_PIZZA_COMBO_2	{ { &PFOOD_PIZZA_DOUGH, &PFOOD_PIZZA_TOMATO, &PFOOD_PIZZA_MEAT } };
static const Meal MEAL_PIZZA_COMBO_3	{ { &PFOOD_PIZZA_DOUGH, &PFOOD_PIZZA_TOMATO, &PFOOD_PIZZA_CHEESE } };
static const Meal MEAL_PIZZA_COMBO_4	{ { &PFOOD_PIZZA_DOUGH, &PFOOD_PIZZA_TOMATO, &PFOOD_PIZZA_MEAT, &PFOOD_PIZZA_CHEESE } };

static const Meal MEAL_PASTA_COMBO_1	{ { &PFOOD_PASTA_SPAGHETTI, &PFOOD_PASTA_TOMATO } };
static const Meal MEAL_PASTA_COMBO_2	{ { &PFOOD_PASTA_SPAGHETTI, &PFOOD_PASTA_TOMATO, &PFOOD_PASTA_CHEESE } };
static const Meal MEAL_PASTA_COMBO_3	{ { &PFOOD_PASTA_SPAGHETTI, &PFOOD_PASTA_TOMATO, &PFOOD_PASTA_MEAT } };
static const Meal MEAL_PASTA_COMBO_4	{ { &PFOOD_PASTA_SPAGHETTI, &PFOOD_PASTA_TOMATO, &PFOOD_PASTA_MEAT, &PFOOD_PASTA_CHEESE } };
static const Meal MEAL_PASTA_COMBO_5	{ { &PFOOD_PASTA_SPAGHETTI, &PFOOD_PASTA_TOMATO, &PFOOD_PASTA_FISH } };
static const Meal MEAL_PASTA_COMBO_6	{ { &PFOOD_PASTA_SPAGHETTI, &PFOOD_PASTA_TOMATO, &PFOOD_PASTA_FISH, &PFOOD_PASTA_CHEESE } };


struct FoodMenu
{
	std::vector<const Meal *> meals;
};

static const FoodMenu FOOD_MENU_FB		{ { &MEAL_FB_COMBO_1, &MEAL_FB_COMBO_2, &MEAL_FB_COMBO_3 } };
static const FoodMenu FOOD_MENU_SS		{ { &MEAL_SS_COMBO_1, &MEAL_SS_COMBO_2, &MEAL_SS_COMBO_3, &MEAL_SS_COMBO_4 } };
static const FoodMenu FOOD_MENU_PIZZA	{ { &MEAL_PIZZA_COMBO_1, &MEAL_PIZZA_COMBO_2, &MEAL_PIZZA_COMBO_3, &MEAL_PIZZA_COMBO_4 } };
static const FoodMenu FOOD_MENU_PASTA	{ { &MEAL_PASTA_COMBO_1, &MEAL_PASTA_COMBO_2, &MEAL_PASTA_COMBO_3, &MEAL_PASTA_COMBO_4, &MEAL_PASTA_COMBO_5, &MEAL_PASTA_COMBO_6 } };
