#pragma once
#include"WindowSize.h"

struct segm
{
	const int edge = EDGE;
	int posX = (WIDTH / 2) - (WIDTH / 2) % edge;
	int prev_posX = (WIDTH / 2) - (WIDTH / 2) % edge;
	int posY = (HEIGHT / 2) - (HEIGHT / 2) % edge;
	int prev_posY = (HEIGHT / 2) - (HEIGHT / 2) % edge;
	char dir = '0';
	segm *next = nullptr;
	segm *prev = nullptr;
};

class snake
{
	int _length;
	

public:
	snake();
	~snake();
	void add_segm();
	void remove_tail();
	segm *_head, *_root;
	void set_length(const int& val);
	int get_length();
};

snake::snake()
{
	this->_length = 1;
	segm *head = new segm;
	this->_head = head;
}

snake::~snake()
{

}

void snake::add_segm()
{
	segm *s = new segm;
	segm *h=this->_head;

	while (h->next != nullptr)
		h = h->next;
	h->next = s;
	this->_root=s;
	s->prev = h;
	s->posX = h->prev_posX;
	s->posY = h->prev_posY;
	s->dir = h->dir;
}

void snake::remove_tail()
{
	segm *s = this->_root;
	segm *r;
	while (s != this->_head)
	{
		r = s;
		s = s->prev;
		delete r;
		s->next = nullptr;
	}
}

void snake::set_length(const int& val)
{
	this->_length = val;
}

int snake::get_length()
{
	return this->_length;
}

