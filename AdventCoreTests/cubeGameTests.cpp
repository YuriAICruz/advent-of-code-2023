#pragma once
#include "gtest/gtest.h"
#include "src/CubeGame/cubeGame.h"
#include "src/listUtils.h"
#include "src/reader.h"

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
        core::cubeGame("Game 12: 3 blue, 4 red; 1 red, 2 green, 6 blue; 2 green"),
        core::cubeGame("Game 32: 1 blue, 2 green; 3 green, 4 blue, 1 red; 1 green, 1 blue"),
        core::cubeGame("Game 3: 8 green, 6 blue, 20 red; 5 blue, 4 red, 13 green; 5 green, 1 red"),
        core::cubeGame("Game 4: 1 green, 3 red, 6 blue; 3 green, 6 red; 3 green, 15 blue, 14 red"),
        core::cubeGame("Game 116: 6 red, 1 blue, 3 green; 2 blue, 1 red, 2 green")
    };

    int i = 0;
    int idsSum = 0;
    for (core::cubeGame game : games)
    {
        if (game.max_value("red") <= 12 && game.max_value("blue") <= 14 && game.max_value("green") <= 13)
        {
            idsSum += game.id;
            EXPECT_GT(12, game.max_value("red"));
            EXPECT_GT(13, game.max_value("green"));
            EXPECT_GT(14, game.max_value("blue"));
            EXPECT_GT(2286, game.power());
        }
        else
        {
            EXPECT_TRUE(game.max_value("red") > 12 || game.max_value("green") > 13 || game.max_value("blue") > 14);
        }
        i++;
    }

    EXPECT_EQ(160, idsSum);
    EXPECT_LE(61, core::listUtils::sum(games, &getRed));
}

TEST(CubeGame, FullData)
{
    auto read = core::reader{"Data/2_cube_game_input.txt"};

    std::string line;
    int idsSum = 0;
    std::list<core::cubeGame> list;
    while (read.getNextLine(line))
    {
        auto game = core::cubeGame(line);

        if (game.max_value("red") <= 12 && game.max_value("green") <= 13 && game.max_value("blue") <= 14)
        {
            list.push_back(game);
            idsSum += game.id;
        }
    }

    EXPECT_EQ(2449, idsSum);
}

TEST(CubeGame, FullDataPower)
{
    auto read = core::reader{"Data/2_cube_game_input.txt"};

    std::string line;
    int powerSum = 0;
    std::list<core::cubeGame> list;
    while (read.getNextLine(line))
    {
        auto game = core::cubeGame(line);

        powerSum += game.power();
    }

    EXPECT_EQ(63981, powerSum);
}
