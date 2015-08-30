#include "stdafx.h"
#include "bowling_game.h"


BowlingGame::BowlingGame()
{
	_hit_index = 0;
	for (size_t i = 0; i < MAX_HIT_TIMES; i++)
	{
		_all_hits[i] = 0;
	}
}

BowlingGame::~BowlingGame()
{
}

void BowlingGame::hit(int score)
{
	if (_hit_index >= MAX_HIT_TIMES)
		return;
	_all_hits[_hit_index++] = score;
}

int BowlingGame::get_score()
{
	fill_frame_score();

	int total_score = 0;
	for (int i = 0; i < MAX_FRAME_NUMBER; i++)
	{
		total_score = total_score + scores[i].get_score();
	}
	return total_score;
}

void BowlingGame::fill_frame_score()
{
	int hitIndex = 0;
	for (int frameIndex = 0; frameIndex < MAX_FRAME_NUMBER; frameIndex++)
	{
		if ( is_strike(hitIndex) )
		{
			scores[frameIndex].fillScore(10, _all_hits[hitIndex + 1], _all_hits[hitIndex + 2]);
			hitIndex++;
		}
		else if ( is_spare(hitIndex) )
		{
			scores[frameIndex].fillScore(_all_hits[hitIndex], _all_hits[hitIndex + 1], _all_hits[hitIndex + 2]);
			hitIndex += 2;
		}
		else
		{
			scores[frameIndex].fillScore(_all_hits[hitIndex], _all_hits[hitIndex + 1]);
			hitIndex += 2;
		}
	}
}

bool BowlingGame::is_strike(int hitIndex)
{
	return (_all_hits[hitIndex] == 10);
}
bool BowlingGame::is_spare(int hitIndex)
{
	return (_all_hits[hitIndex] + _all_hits[hitIndex + 1] == 10);
}