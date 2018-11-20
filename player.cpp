#include "player.h"

Player::Player(){}
Player::~Player(){}

void Player::up() 
{
	current->up(this);
}

void Player::down()
{
	current->down(this);
}

void Player::left()
{
	current->left(this);
}

void Player::right()
{
	current->right(this);
}