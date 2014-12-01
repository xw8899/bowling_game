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
	for (int i = 1; i <= frame_number(); i++)
	{
		total_score = total_score + scores[i].get_score();
	}
	return total_score;
}

void BowlingGame::hit(int score)
{
	if (_first_hit)
	{
		scores[_frame_number].first_score = score;
		if (score == 10)
			_frame_number++;
		else
		    _first_hit = false;
	}
	else
	{
		scores[_frame_number].secord_score = score;
		_first_hit = true;
		_frame_number++;
	}

	for (int i = 1; i <= _frame_number; i++)
	{
		if (scores[i].is_strike())
		{
			scores[i].secord_score = get_next_hit_score(i);
			scores[i].spare_score = get_next_next_hit_score(i);
		}
		else if (scores[i].is_spare())
		{
			scores[i].spare_score = get_next_hit_score(i);
		}
	}
}

int BowlingGame::get_next_next_hit_score(int frame_number)
{
	if (frame_number < _frame_number)
	{
		if (scores[frame_number + 1].is_strike() && (frame_number < _frame_number + 1))
			return scores[frame_number + 2].first_score;
		else
			return scores[frame_number + 1].secord_score;
	}
	return 0;
}

int BowlingGame::get_next_hit_score(int frame_number)
{
	if (frame_number < _frame_number)
	{
		return scores[frame_number + 1].first_score;
	}
	return 0;
}

int BowlingGame::frame_number()
{
	if (_frame_number > 10) return 10;
	return _frame_number;
}