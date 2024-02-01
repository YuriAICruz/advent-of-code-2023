#pragma once
#include "gtest/gtest.h"
#include "src/CubeGame/cubeGame.h"
#include "src/listUtils.h"

int getRed(core::cubeGame game)
{
    return game.sum("red");
}
int getGreen(core::cubeGame game)
{
    return game.sum("green");
}
int getBlue(core::cubeGame game)
{
    return game.sum("blue");
}

TEST(CubeGame, SumSets)
{
    auto game = core::cubeGame("Game 1: 3 blue, 4 red; 1 red, 2 green, 6 blue; 2 green");

    EXPECT_EQ(1, game.id);
    EXPECT_EQ(9, game.sum("blue"));
}

TEST(CubeGame, BigIdNumber)
{
    auto game = core::cubeGame("Game 152: 3 blue, 4 red; 1 red, 2 green, 6 blue; 2 green");

    EXPECT_EQ(152, game.id);
}

TEST(CubeGame, IsPossible)
{
    std::list<core::cubeGame> games;
    games = {
        core::cubeGame("Game 1: 3 blue, 4 red; 1 red, 2 green, 6 blue; 2 green"),
        core::cubeGame("Game 2: 1 blue, 2 green; 3 green, 4 blue, 1 red; 1 green, 1 blue"),
        core::cubeGame("Game 3: 8 green, 6 blue, 20 red; 5 blue, 4 red, 13 green; 5 green, 1 red"),
        core::cubeGame("Game 4: 1 green, 3 red, 6 blue; 3 green, 6 red; 3 green, 15 blue, 14 red"),
        core::cubeGame("Game 5: 6 red, 1 blue, 3 green; 2 blue, 1 red, 2 green")
    };

    int i = 0;
    for (core::cubeGame game : games)
    {
        if(i == 0 || i == 1 || i == 4)
        {
            EXPECT_GT(12, game.sum("red"));
            EXPECT_GT(13, game.sum("green"));
            EXPECT_GT(14, game.sum("blue"));
        }
        else
        {
            EXPECT_TRUE(game.sum("red") > 12 || game.sum("green") > 13 || game.sum("blue") > 14);
        }
        i++;
    }

    EXPECT_LE(61, core::listUtils::sum(games, &getRed));
}

