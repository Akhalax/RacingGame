#include "GameView.h"
#include <iostream>
#include <windows.h>
#include "GameConstants.h"


GameView::GameView()
{
	x = GameConstats::X_DEFAULT;
	drawGameField();
	placeCarToDefalultPosition();
}


GameView::~GameView()
{
}

void GameView::drawGameField()
{
	for (int i = 0; i < GameConstats::FIELD_SIZE; ++i) {
		for (int j = 0; j < GameConstats::FIELD_SIZE; ++j) {
			road[i][GameConstats::LEFT_BORDER] = '|';
			road[i][GameConstats::RIGHT_BORDER] = '|';
			road[i][j] = ' ';
		}
	}
}

void GameView::placeCarToDefalultPosition()
{
	road[GameConstats::Y_DEFAULT][x] = 'X';
	road[GameConstats::Y_DEFAULT][x + 1] = '|';
	road[GameConstats::Y_DEFAULT][x - 1] = '|';
	road[GameConstats::Y_DEFAULT + 1][x - 1] = 'o';
	road[GameConstats::Y_DEFAULT + 1][x + 1] = 'o';
	road[GameConstats::Y_DEFAULT - 1][x - 1] = 'o';
	road[GameConstats::Y_DEFAULT - 1][x + 1] = 'o';

}

void GameView::displayField()
{
	for (int i = 0; i < GameConstats::FIELD_SIZE-1; ++i) {
		for (int j = 0; j < GameConstats::FIELD_SIZE-1; ++j) {
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
	if (side == GameConstats::LEFT)
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
		const bool didCrashed = road[y - 2][x] == GameConstats::OBSTACLE || road[y - 2][x - 1] == GameConstats::OBSTACLE || road[y - 2][x + 1] == GameConstats::OBSTACLE;
		return didCrashed;
	}
	case GameConstats::LEFT:
	{
		return road[y][x - 3] == GameConstats::OBSTACLE;
	}
	case GameConstats::RIGHT:
	{
		return road[y][x + 3] == GameConstats::OBSTACLE;
	}
	}
}

inline int GameView::getY() const
{
	return y;
}

inline int GameView::getX() const
{
	return x;
}

inline void GameView::setX(int x)
{
	this->x = x;
}


