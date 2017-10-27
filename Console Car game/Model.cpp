#include "Model.h"
#include <random>
#include <windows.h>
#include <iostream>
#include <ctime>


Model::Model()
{
	speed = 100;
	points = 0;
	obstacleAltitude = 0;
	obstacleLatitude = random();
}


Model::~Model()
{
}

void Model::wait()
{
	Sleep(speed);
	++points;
}

void Model::changeSpeed(int state)
{
	if (state == UP)
		speed -= 15;
	else if (state == DOWN)
		speed += 15;

	if (speed < 10) speed = 15;
}

int Model::getSpeed() const
{
	return speed;
}

void Model::setSpeed(int speed)
{
	this->speed = speed;
}

int Model::getScore() const
{
	return points;
}

void Model::setScore(int points)
{
	this->points = points;
}

void Model::generateAndUpdateObstacle(GameView*  game_view)
{
	game_view->updateObstacle(obstacleAltitude, obstacleLatitude, ' ');
	obstacleAltitude++;
	game_view->updateObstacle(obstacleAltitude, obstacleLatitude, obstacle);
	
	if (obstacleAltitude > 20) {
		obstacleAltitude = 0;
		obstacleLatitude = random();
	}
}

int Model::controlActionHandling(GameView* game_view)
{
	if (GetAsyncKeyState(VK_RIGHT) == -32767)
	{
		if (game_view->checkCrush(RIGHT) == true)
			return END;
		game_view->updateCar(RIGHT);
		return 0;
	}
	else if (GetAsyncKeyState(VK_LEFT) == -32767)
	{
		if (game_view->checkCrush(LEFT) == true)
			return END;
		game_view->updateCar(LEFT);
		return 0;
	}
	else if (GetAsyncKeyState(VK_UP) == -32767)
	{
		changeSpeed(UP);
		return 0;
	}
	else if (GetAsyncKeyState(VK_DOWN) == -32767)
	{
		changeSpeed(DOWN);
		return 0;
	}
	else if (GetAsyncKeyState(VK_ESCAPE) == -32767)
	{
		return END;
	}
	else if (GetAsyncKeyState(VK_RETURN) == -32767)
	{
		std::cin.get();
		return 0;
	}
}

int Model::random()
{
	std::mt19937 gen(time(0));
	std::uniform_int_distribution<int> distribution(2, 16);
	return distribution(gen);
}


