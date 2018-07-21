#pragma once
#include<ctime>
#include<cstdlib>
#include"WindowSize.h"

class food
{
	const int _edge = 20;
	int _posX=0;
	int _posY=0;

public:
	const int get_edge();
	int get_pos_x();
	int get_pos_y();
	void set_pos_x(const int& val);
	void set_pos_y(const int& val);
	void spawn();
};

const int food::get_edge()
{
	return _edge;
}

int food::get_pos_x()
{
	return _posX;
}

int food::get_pos_y()
{
	return _posY;
}

void food::set_pos_x(const int& val)
{
	_posX = (_posX + val) % WIDTH - (_posX + val) %_edge;

}

void food::set_pos_y(const int& val)
{
	_posY = (_posY + val) % HEIGHT - (_posY + val) %_edge;

}

void food::spawn()
{
	srand(time(NULL));
	int x = rand() % WIDTH;
	int y = rand() % HEIGHT;
	this->set_pos_x(x);
	this->set_pos_y(y);

}
