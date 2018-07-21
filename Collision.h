#pragma once
#include"Snake.h"
#include"Food.h"

bool food_col(snake &s, food &f)
{
	if (s._head->posX == f.get_pos_x() && s._head->posY == f.get_pos_y())
	{
		s.set_length(s.get_length() + 1);
		s.add_segm();
		f.spawn();
		return true;
	}
	return false;
}

bool tail_col(segm *head)
{
	segm *seg = head;

	while (seg->next != nullptr)
	{
		if (head->posX == seg->next->posX && head->posY == seg->next->posY)
			return true;
		seg = seg->next;
	}
	return false;
}