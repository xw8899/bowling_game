// BowlingScoring.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "bowling_game.h"

#include<gtest/gtest.h>

TEST(BowlingGameTest, get_score_first_frame)
{
	BowlingGame bg = BowlingGame();
	bg.hit(3);
	bg.hit(5);
	EXPECT_EQ(8, bg.get_score());
}

TEST(BowlingGameTest, get_score_2_frame)
{
	BowlingGame bg = BowlingGame();
	bg.hit(10);
	bg.hit(5);
	EXPECT_EQ(15, bg.get_score());
	EXPECT_EQ(2, bg.frame_number());
}

TEST(BowlingGameTest, get_score_3_frame)
{
	BowlingGame bg = BowlingGame();
	bg.hit(10);
	bg.hit(5);
	bg.hit(4);
	EXPECT_EQ(28, bg.get_score());
	EXPECT_EQ(3, bg.frame_number());
}

int _tmain(int argc, _TCHAR* argv[])
{
	testing::InitGoogleTest(&argc, argv);
	RUN_ALL_TESTS();
	getchar();
	return 0;
}

