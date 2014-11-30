#include "stdafx.h"
#include "bowling_game.h"


BowlingGame::BowlingGame()
{
	_first_hit = true;
	_frame_number = 1;
}


BowlingGame::~BowlingGame()
{
}

int BowlingGame::get_score()
{
	int total_score = 0;
	for (int i = 1; i < _frame_number; i++)
	{
		total_score = total_score + scores[i - 1].get_score();
	}
	return total_score;
}

void BowlingGame::hit(int score)
{
	if (_first_hit)
	{
		scores[_frame_number-1].first_score = score;
		if (_frame_number > 1)
		{
			if (scores[_frame_number - 2].is_strike())
			{
				scores[_frame_number - 2].secord_score = score;
			}
			else if (scores[_frame_number - 2].is_spare())
			{
				scores[_frame_number - 2].spare_score = score;
			}
		}
		if (scores[_frame_number - 1].is_strike())
			_frame_number++;
	}
	else
	{
		scores[_frame_number-1].secord_score = score;
		if (_frame_number > 1)
		{
			if (scores[_frame_number - 2].is_spare())
			{
				scores[_frame_number - 2].spare_score = score;
			}
		}
		_first_hit = true;
		_frame_number++;
	}
}

int BowlingGame::frame_number()
{
	return _frame_number;
}