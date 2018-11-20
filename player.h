#pragma once
#include <iostream>
using namespace std;

class Player
{
	class PlayerAnimator *current;
public:
	Player();
	~Player();

	void setCurrent(PlayerAnimator *s)
	{
		current = s;
	}

	void up();

	void down();

	void left();

	void right();
};

class PlayerAnimator
{
public:
	virtual void up(Player *p)
	{
		cout << " player is going up\n";
	}

	virtual void down(Player *p)
	{
		cout << " player is going down\n";
	}

	virtual void left(Player *p)
	{
		cout << " player is going left\n";
	}

	virtual void right(Player *p)
	{
		cout << " player is going right\n";
	}
};

class UP : public PlayerAnimator
{
public:
	UP() {}
	~UP() {}

	void down(Player *p) { p->setCurrent(new DOWN()); delete this; }	// going from up to down
	void left(Player *p) { p->setCurrent(new LEFT());  delete this;}	// going from up to left
	void right(Player *p) { p->setCurrent(new RIGHT()); delete this;}	// going from up to right
};

class DOWN : public PlayerAnimator
{
public:
	DOWN(){}
	~DOWN(){}

	void up(Player *p);		// going from down to up
	void left(Player *p);	// going from down to left
	void right(Player *p);	// going from down to right
};

class LEFT : public PlayerAnimator
{
public:
	LEFT() {}
	~LEFT() {}

	void up(Player *p);		// going from left to up
	void down(Player *p);	// going from left to down
	void right(Player *p);	// going from left to right
};

class RIGHT : public PlayerAnimator
{
public:
	RIGHT() {}
	~RIGHT() {}

	void up(Player *p);		// going from right to up
	void down(Player *p);	// going from right to down
	void left(Player *p);	// going from right to left
};