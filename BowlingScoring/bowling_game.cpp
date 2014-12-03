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

void BowlingGame::hit(int score)
{
	if (_frame_number > MAX_FRAME_NUMBER)
	{
		printf("game over!\n");
		return;
	}
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
}

int BowlingGame::get_score()
{
	fill_frame_score();

	int total_score = 0;
	for (int i = 1; i <= get_frame_number(); i++)
	{
		total_score = total_score + scores[i].get_score();
	}
	return total_score;
}

void BowlingGame::fill_frame_score()
{
	for (int i = 1; i <= get_frame_number(); i++)
	{
		if (scores[i].is_strike())
		{
			scores[i].secord_score = get_next_hit_score(i);
			scores[i].spare_score = get_next_to_next_hit_score(i);
		}
		else if (scores[i].is_spare())
		{
			scores[i].spare_score = get_next_hit_score(i);
		}
	}
}

int BowlingGame::get_next_to_next_hit_score(int frame_number)
{
	if (frame_number <= get_frame_number())
	{
		if (scores[frame_number + 1].is_strike())
		{
			return scores[frame_number + 2].first_score;
		}
		else
		{
			return scores[frame_number + 1].secord_score;
		}	
	}
	return 0;
}

int BowlingGame::get_next_hit_score(int frame_number)
{
	if (frame_number <= get_frame_number())
	{
		return scores[frame_number + 1].first_score;
	}
	return 0;
}

int BowlingGame::get_frame_number()
{
	if (_frame_number > 10) return 10;
	return _frame_number;
}