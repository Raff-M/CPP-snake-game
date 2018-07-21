#pragma once
#include"Snake.h"

void move(segm *seg)
{


		seg->prev_posX = seg->posX;
		seg->prev_posY = seg->posY;
		if (seg->dir == 'L')
		{
			seg->prev_posX = seg->posX;
			seg->posX = (seg->posX - 20);
			if (seg->posX < 0)
			{
				seg->posX = WIDTH - EDGE;
			}
		}
		if (seg->dir == 'R')
		{
			seg->prev_posX = seg->posX;
			seg->posX = (seg->posX + 20);
			if (seg->posX > WIDTH - EDGE)
			{
				seg->posX = 0;
			}
		}
		if (seg->dir == 'U')
		{
			seg->prev_posY = seg->posY;
			seg->posY = (seg->posY - 20);
			if (seg->posY < 0)
			{
				seg->posY = HEIGHT - EDGE;
			}
		}
		if (seg->dir == 'D')
		{
			seg->prev_posY = seg->posY;
			seg->posY = (seg->posY + 20);
			if (seg->posY > HEIGHT - EDGE)
			{
				seg->posY = 0;
			}
		}
		seg = seg->next;
}

void follow(segm *head)
{
	segm *seg = head;
	while (seg->next != nullptr)
	{
		seg->next->prev_posX = seg->next->posX;
		seg->next->prev_posY = seg->next->posY;

		seg->next->posX = seg->prev_posX;
		seg->next->posY = seg->prev_posY;
		
		seg = seg->next;
	}
}