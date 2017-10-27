#include "GameView.h"
#include <iostream>
#include <windows.h>




GameView::GameView()
{
	x = xDefault;
	drawGameField();
	placeCarToDefalultPosition();
}


GameView::~GameView()
{
}

void GameView::drawGameField()
{
	for (int i = 0; i < fieldSize; ++i) {
		for (int j = 0; j < fieldSize; ++j) {
			road[i][leftBorder] = '|';
			road[i][rightBorder] = '|';
			road[i][j] = ' ';
		}
	}
}

void GameView::placeCarToDefalultPosition()
{
	road[yDefault][x] = 'X';
	road[yDefault][x + 1] = '|';
	road[yDefault][x - 1] = '|';
	road[yDefault + 1][x - 1] = 'o';
	road[yDefault + 1][x + 1] = 'o';
	road[yDefault - 1][x - 1] = 'o';
	road[yDefault - 1][x + 1] = 'o';

}

void GameView::displayField()
{
	for (int i = 0; i < fieldSize-1; ++i) {
		for (int j = 0; j < fieldSize-1; ++j) {
			std::cout << road[i][j];
			if (j >= 19) {
				std::cout << std::endl;
			}
		}
	}
}

void GameView::updateObstacle(int obstacleAltitude, int obstacleLatitude, char character)
{
	road[obstacleAltitude][obstacleLatitude] = character;
	road[obstacleAltitude][obstacleLatitude] = character;
	road[obstacleAltitude][obstacleLatitude + 1] = character;
	road[obstacleAltitude][obstacleLatitude - 1] = character;
	road[obstacleAltitude + 1][obstacleLatitude - 1] = character;
	road[obstacleAltitude + 1][obstacleLatitude + 1] = character;
	road[obstacleAltitude - 1][obstacleLatitude - 1] = character;
	road[obstacleAltitude - 1][obstacleLatitude + 1] = character;
}

void GameView::updateCar(int side)
{
	if (side == LEFT)
	{
		if (road[y][x - 3] != '|')
		{
			road[y][x] = ' ';
			road[y][x + 1] = ' ';
			road[y][x - 1] = ' ';
			road[y + 1][x - 1] = ' ';
			road[y + 1][x + 1] = ' ';
			road[y - 1][x - 1] = ' ';
			road[y - 1][x + 1] = ' ';
			x -= 3;
			road[y][x] = 'X';
			road[y][x + 1] = '|';
			road[y][x - 1] = '|';
			road[y + 1][x - 1] = 'o';
			road[y + 1][x + 1] = 'o';
			road[y - 1][x - 1] = 'o';
			road[y - 1][x + 1] = 'o';
			return;
		}
	}
	else if (road[y][x + 3] != '|') {
		road[y][x] = ' ';
		road[y][x + 1] = ' ';
		road[y][x - 1] = ' ';
		road[y + 1][x - 1] = ' ';
		road[y + 1][x + 1] = ' ';
		road[y - 1][x - 1] = ' ';
		road[y - 1][x + 1] = ' ';
		x += 3;
		road[y][x] = 'X';
		road[y][x + 1] = '|';
		road[y][x - 1] = '|';
		road[y + 1][x - 1] = 'o';
		road[y + 1][x + 1] = 'o';
		road[y - 1][x - 1] = 'o';
		road[y - 1][x + 1] = 'o';
	}
}

char GameView::getXYroad(int x_i, int y_i)
{
	return road[x_i][y_i];
}

void GameView::displayScore(int points)
{
	std::cout << "    Points: " << points;
}

void GameView::clearscreen()
{
	HANDLE hOut;
	COORD Position;

	hOut = GetStdHandle(STD_OUTPUT_HANDLE);

	Position.X = 0;
	Position.Y = 0;
	SetConsoleCursorPosition(hOut, Position);
}

int GameView::y1() const
{
	return y;
}

int GameView::x1() const
{
	return x;
}

void GameView::set_x(int x)
{
	this->x = x;
}

void GameView::gameOver()
{
	std::cout << "\n\nYou crashed!\n" << std::endl;
	std::cin.get();
}

bool GameView::checkCrush(int side = 0)
{
	switch (side)
	{
	case 0:
	{
		bool didCrached = road[y - 2][x] == obstacle || road[y - 2][x - 1] == obstacle || road[y - 2][x + 1] == obstacle;
		if (didCrached)
		{
			return true;
		}
		return false;
	}
	case LEFT:
	{
		if (road[y][x - 3] == obstacle)
		{
			return  true;
		}
		else return false;
	}
	case  RIGHT:
	{
		if (road[y][x + 3] == obstacle)
		{
			return  true;
		}
		else return false;
	}
	}
}


