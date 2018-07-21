#pragma once
#include"WindowSize.h"

struct segm
{
	const int _edge = 20;
	int _posX = (WIDTH / 2) - (WIDTH / 2)%_edge;
	int _posY = (HEIGHT / 2) - (HEIGHT / 2) % _edge;
	char _dir='0';
	char _dir_prev = '0';
	int _length = 1;

	segm();
	~segm();
	const int get_edge();
	int get_pos_x();
	int get_pos_y();
	void set_pos_x(const int& val);
	void set_pos_y(const int& val);
	char get_dir();
	void set_dir(const char& dir);
	void set_length(const int& val);
	int get_length();
	void set_next(segm next);
};

segm::segm(){}

segm::~segm(){}

const int segm::get_edge()
{
	return _edge;
}

int segm::get_pos_x()
{
	return _posX;
}

int segm::get_pos_y()
{
	return _posY;
}

void segm::set_pos_x(const int& val)
{
	_posX = (_posX + val) % WIDTH;
	if (_posX < 0)
	{
		_posX = WIDTH - _edge;
	}
	if (_posX > WIDTH - _edge)
	{
		_posX = 0;
	}
}

void segm::set_pos_y(const int& val)
{
	_posY = (_posY + val) % HEIGHT;
	if (_posY < 0)
	{
		_posY = HEIGHT - _edge;
	}
	if (_posY > HEIGHT - _edge)
	{
		_posY = 0;
	}
}

char segm::get_dir()
{
	return _dir;
}

void segm::set_dir(const char& dir)
{
	_dir_prev = _dir;
	_dir = dir;
}

void segm::set_length(const int& val)
{
	this->_length = val;
}

int segm::get_length()
{
	return this->_length;
}

