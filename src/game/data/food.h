#pragma once

#include <string>
#include <vector>
#include "spriteLayer.h"
#include "game/resources.h"

struct Ingredient
{
	std::string name;
	std::string textureName;
};

static const Ingredient INGR_CHEESE		{ "Cheese", CHEESE_IMAGE };
static const Ingredient INGR_CHICKEN	{ "Chicken", CHICKEN_IMAGE };
static const Ingredient INGR_DOUGH		{ "Cheese", DOUGH_IMAGE };
static const Ingredient INGR_FISH		{ "Fish", FISH_IMAGE };
static const Ingredient INGR_FRIES		{ "Fries", FRIES_IMAGE };
static const Ingredient INGR_LETTUCE	{ "Lettuce", LETTUCE_IMAGE };
static const Ingredient INGR_MEAT		{ "Meat", MEAT_IMAGE };
static const Ingredient INGR_RICE		{ "Rice", RICE_IMAGE };
static const Ingredient INGR_SHRIMP		{ "Shrimp", SHRIMP_IMAGE };
static const Ingredient INGR_SPAGHETTI	{ "Spaghetti", SPAGHETTI_IMAGE };
static const Ingredient INGR_TOMATO		{ "Tomato", TOMATO_IMAGE };

struct PlatedFood
{
	std::string name;
	SpriteLayer layer;
	const Ingredient *ingredient;
	std::string textureName;
};

static const PlatedFood PFOOD_FB_CHICKEN		{ "Fried Chicken", SpriteLayer::FOOD_1, &INGR_CHICKEN, PLATED_CHICKEN_IMAGE };
static const PlatedFood PFOOD_FB_FRIES			{ "Fries", SpriteLayer::FOOD_1, &INGR_FRIES, PLATED_FRIES_IMAGE };

static const PlatedFood PFOOD_SS_RICE			{ "Rice", SpriteLayer::FOOD_1, &INGR_RICE, PLATED_SS_RICE_IMAGE };
static const PlatedFood PFOOD_SS_PRAWN			{ "Prawn", SpriteLayer::FOOD_2, &INGR_SHRIMP, PLATED_SS_PRAWN_IMAGE };
static const PlatedFood PFOOD_SS_FISH			{ "Fish (Sushi)", SpriteLayer::FOOD_2, &INGR_FISH, PLATED_SS_FISH_IMAGE };

static const PlatedFood PFOOD_PIZZA_DOUGH		{ "Dough", SpriteLayer::FOOD_1, &INGR_DOUGH, PLATED_PIZZA_DOUGH_IMAGE };
static const PlatedFood PFOOD_PIZZA_TOMATO		{ "Tomato (Pizza)", SpriteLayer::FOOD_2, &INGR_TOMATO, PLATED_PIZZA_TOMATO_IMAGE };
static const PlatedFood PFOOD_PIZZA_MEAT		{ "Meat (Pizza)", SpriteLayer::FOOD_3, &INGR_MEAT, PLATED_PIZZA_MEAT_IMAGE };
static const PlatedFood PFOOD_PIZZA_CHEESE		{ "Cheese (Pizza)", SpriteLayer::FOOD_4, &INGR_CHEESE, PLATED_PIZZA_CHEESE_IMAGE };

static const PlatedFood PFOOD_PASTA_SPAGHETTI	{ "Spaghetti", SpriteLayer::FOOD_1, &INGR_SPAGHETTI, PLATED_PASTA_SPAGHETTI_IMAGE };
static const PlatedFood PFOOD_PASTA_TOMATO		{ "Tomato (Pasta)", SpriteLayer::FOOD_2, &INGR_TOMATO, PLATED_PASTA_TOMATO_IMAGE };
static const PlatedFood PFOOD_PASTA_FISH		{ "Fish (Pasta)", SpriteLayer::FOOD_3, &INGR_FISH, PLATED_PASTA_FISH_IMAGE };
static const PlatedFood PFOOD_PASTA_MEAT		{ "Meat (Pasta)", SpriteLayer::FOOD_4, &INGR_MEAT, PLATED_PASTA_MEAT_IMAGE };
static const PlatedFood PFOOD_PASTA_CHEESE		{ "Cheese (Pasta)", SpriteLayer::FOOD_5, &INGR_CHEESE, PLATED_PASTA_CHEESE_IMAGE };

struct Meal
{
	std::string name;
	std::vector<const PlatedFood *> foods;
};

static const Meal MEAL_FB_COMBO_1	{ "Fried Chicken", { &PFOOD_FB_CHICKEN } };
static const Meal MEAL_FB_COMBO_2	{ "Fries", { &PFOOD_FB_FRIES } };
static const Meal MEAL_FB_COMBO_3	{ "Fried Chicken w/ Fries", { &PFOOD_FB_CHICKEN, &PFOOD_FB_FRIES } };

static const Meal MEAL_SS_COMBO_1	{ "Fish Sashimi", { &PFOOD_SS_FISH } };
static const Meal MEAL_SS_COMBO_2	{ "Prawn Sashimi", { &PFOOD_SS_PRAWN } };
static const Meal MEAL_SS_COMBO_3	{ "Fish Sushi", { &PFOOD_SS_FISH, &PFOOD_SS_RICE } };
static const Meal MEAL_SS_COMBO_4	{ "Prawn Sushi", { &PFOOD_SS_PRAWN, &PFOOD_SS_RICE } };

static const Meal MEAL_PIZZA_COMBO_1	{ "Pizza", { &PFOOD_PIZZA_DOUGH, &PFOOD_PIZZA_TOMATO } };
static const Meal MEAL_PIZZA_COMBO_2	{ "Pizza w/ Meat", { &PFOOD_PIZZA_DOUGH, &PFOOD_PIZZA_TOMATO, &PFOOD_PIZZA_MEAT } };
static const Meal MEAL_PIZZA_COMBO_3	{ "Pizza w/ Cheese", { &PFOOD_PIZZA_DOUGH, &PFOOD_PIZZA_TOMATO, &PFOOD_PIZZA_CHEESE } };
static const Meal MEAL_PIZZA_COMBO_4	{ "Pizza w/ Cheese & Meat", { &PFOOD_PIZZA_DOUGH, &PFOOD_PIZZA_TOMATO, &PFOOD_PIZZA_MEAT, &PFOOD_PIZZA_CHEESE } };

static const Meal MEAL_PASTA_COMBO_1	{ "Spaghetti", { &PFOOD_PASTA_SPAGHETTI, &PFOOD_PASTA_TOMATO } };
static const Meal MEAL_PASTA_COMBO_2	{ "Spaghetti w/ Cheese", { &PFOOD_PASTA_SPAGHETTI, &PFOOD_PASTA_TOMATO, &PFOOD_PASTA_CHEESE } };
static const Meal MEAL_PASTA_COMBO_3	{ "Spaghetti w/ Meat", { &PFOOD_PASTA_SPAGHETTI, &PFOOD_PASTA_TOMATO, &PFOOD_PASTA_MEAT } };
static const Meal MEAL_PASTA_COMBO_4	{ "Spaghetti w/ Cheese & Meat", { &PFOOD_PASTA_SPAGHETTI, &PFOOD_PASTA_TOMATO, &PFOOD_PASTA_MEAT, &PFOOD_PASTA_CHEESE } };
static const Meal MEAL_PASTA_COMBO_5	{ "Spaghetti w/ Fish", { &PFOOD_PASTA_SPAGHETTI, &PFOOD_PASTA_TOMATO, &PFOOD_PASTA_FISH } };
static const Meal MEAL_PASTA_COMBO_6	{ "Spaghetti w/ Cheese & Fish", { &PFOOD_PASTA_SPAGHETTI, &PFOOD_PASTA_TOMATO, &PFOOD_PASTA_FISH, &PFOOD_PASTA_CHEESE } };


struct FoodMenu
{
	std::string name;
	std::vector<const Meal *> meals;
};

static const FoodMenu FOOD_MENU_FB		{ "Fried Basket", { &MEAL_FB_COMBO_1, &MEAL_FB_COMBO_2, &MEAL_FB_COMBO_3 } };
static const FoodMenu FOOD_MENU_SS		{ "Sashimi & Sushi", { &MEAL_SS_COMBO_1, &MEAL_SS_COMBO_2, &MEAL_SS_COMBO_3, &MEAL_SS_COMBO_4 } };
static const FoodMenu FOOD_MENU_PIZZA	{ "Pizza", { &MEAL_PIZZA_COMBO_1, &MEAL_PIZZA_COMBO_2, &MEAL_PIZZA_COMBO_3, &MEAL_PIZZA_COMBO_4 } };
static const FoodMenu FOOD_MENU_PASTA	{ "Pasta", { &MEAL_PASTA_COMBO_1, &MEAL_PASTA_COMBO_2, &MEAL_PASTA_COMBO_3, &MEAL_PASTA_COMBO_4, &MEAL_PASTA_COMBO_5, &MEAL_PASTA_COMBO_6 } };
