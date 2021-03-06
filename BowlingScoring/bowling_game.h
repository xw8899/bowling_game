#pragma once
class FrameScore{
public:
	FrameScore()
	{
		first_score = 0;
		second_score = 0;
		third_score = 0;
	}
	void fillScore(int first, int second, int third = 0)
	{
		first_score = first;
		second_score = second;
		third_score = third;
	}
	int get_score()
	{
		return first_score + second_score + third_score;
	}
private:
	int first_score;
	int second_score;
	int third_score;
};
#define MAX_FRAME_NUMBER 10
#define MAX_HIT_TIMES 21
class BowlingGame
{
public:
	BowlingGame();
	~BowlingGame();
public:
	int get_score();
	void hit(int score);
private:
	void fill_frame_score();
	bool is_strike(int hitIndex);
	bool is_spare(int hitIndex);
private:
	FrameScore scores[MAX_FRAME_NUMBER+1];
	int _all_hits[MAX_HIT_TIMES];
	int _hit_index;
};

