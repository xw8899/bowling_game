// BowlingScoring.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "bowling_game.h"

#include<gtest/gtest.h>

TEST(BowlingGameTest, TwoHitNoMark)
{
	BowlingGame bg = BowlingGame();
	bg.hit(3);
	bg.hit(5);
	EXPECT_EQ(8, bg.get_score());
}

TEST(BowlingGameTest, FourHitNoMark)
{
	BowlingGame bg = BowlingGame();
	bg.hit(3);
	bg.hit(5);
	bg.hit(4);
	bg.hit(4);
	EXPECT_EQ(16, bg.get_score());
}

TEST(BowlingGameTest, TestSimpleSpare)
{
	BowlingGame bg = BowlingGame();
	bg.hit(3);
	bg.hit(7);
	bg.hit(3);
	EXPECT_EQ(13, bg.get_score());
}

TEST(BowlingGameTest, TestSimpleFrameAfterSpare)
{
	BowlingGame bg = BowlingGame();
	bg.hit(3);
	bg.hit(7);
	bg.hit(3);
	bg.hit(2);
	EXPECT_EQ(13, bg.get_score());
}

TEST(BowlingGameTest, TestSimpleStrike)
{
	BowlingGame bg = BowlingGame();
	bg.hit(10);
	bg.hit(5);
	bg.hit(4);
	EXPECT_EQ(28, bg.get_score());
}

TEST(BowlingGameTest, get_score_of_exam)
{
	BowlingGame bg = BowlingGame();
	int scores[] = { 1, 4, 4, 5, 6, 4, 5, 5, 10, 0, 1, 7, 3, 6, 4, 10, 2, 8, 6 };
	for (int i = 0; i < sizeof(scores) / sizeof(int); i++)
	    bg.hit(scores[i]);
	EXPECT_EQ(133, bg.get_score());
}

TEST(BowlingGameTest, TestPerfectGame)
{
	BowlingGame bg = BowlingGame();
	for (int i = 0; i < 12; i++)
		bg.hit(10);
	EXPECT_EQ(300, bg.get_score());
}

TEST(BowlingGameTest, get_score_of_9_strike)
{
	BowlingGame bg = BowlingGame();
	for (int i = 0; i < 9; i++ )
	    bg.hit(10);
	bg.hit(5);
	bg.hit(4);
	EXPECT_EQ(263, bg.get_score());
}

int _tmain(int argc, _TCHAR* argv[])
{
	testing::InitGoogleTest(&argc, argv);
	RUN_ALL_TESTS();
	getchar();
	return 0;
}

