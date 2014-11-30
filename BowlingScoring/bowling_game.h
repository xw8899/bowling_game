#pragma once
class FrameScore{
public:
	FrameScore()
	{
		first_score = 0;
		secord_score = 0;
		spare_score = 0;
	}
	bool is_strike() { return first_score == 10; }
	bool is_spare()  { return first_score + secord_score == 10; }
	int get_score()
	{
		return first_score + secord_score + spare_score;
	}
	int first_score;
	int secord_score;
	int spare_score;
};

class BowlingGame
{
public:
	BowlingGame();
	~BowlingGame();
public:
	int get_score();
	int frame_number();
	void hit(int score);
private:
	bool _first_hit;
	int  _frame_number;
	FrameScore scores[11];
};

