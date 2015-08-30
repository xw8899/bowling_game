#pragma once
class FrameScore{
public:
	FrameScore()
	{
		first_score = 0;
		second_score = 0;
		spare_score = 0;
	}
	bool is_strike() { return first_score == 10; }
	bool is_spare()  { return first_score + second_score == 10; }
	int get_score()
	{
		return first_score + second_score + spare_score;
	}
	int first_score;
	int second_score;
	int spare_score;
};
#define MAX_FRAME_NUMBER 12
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
	
	int get_frame_number();
	void fill_frame_score();
	int get_next_to_next_hit_score(int frame_number);
	int get_next_hit_score(int frame_number);
		 

private:
	bool _first_hit;
	int  _frame_number;
	FrameScore scores[MAX_FRAME_NUMBER+1];
	int _all_hits[MAX_HIT_TIMES];
	int _hit_index;
};

