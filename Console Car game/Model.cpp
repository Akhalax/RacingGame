#include "Model.h"
#include <random>
#include <windows.h>
#include <iostream>
#include <ctime>


Model::Model(int rand)
{
	speed = 100;
	points = 0;
	obstacleAltitude = 0;
	obstacleLatitude = rand;
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
	
	if (obstacleAltitude > lowerBorder) {
		obstacleAltitude = 0;
		rand.random();
		obstacleLatitude = rand.getValue();
	}
}

int Model::controlActionHandling(GameView* game_view)
{
	if (GetAsyncKeyState(VK_RIGHT) == codeKeyPressed)
	{
		if (game_view->checkCrush(RIGHT) == true)
			return END;
		game_view->updateCar(RIGHT);
		return 0;
	}
	else if (GetAsyncKeyState(VK_LEFT) == codeKeyPressed)
	{
		if (game_view->checkCrush(LEFT) == true)
			return END;
		game_view->updateCar(LEFT);
		return 0;
	}
	else if (GetAsyncKeyState(VK_UP) == codeKeyPressed)
	{
		changeSpeed(UP);
		return 0;
	}
	else if (GetAsyncKeyState(VK_DOWN) == codeKeyPressed)
	{
		changeSpeed(DOWN);
		return 0;
	}
	else if (GetAsyncKeyState(VK_ESCAPE) == codeKeyPressed)
	{
		return END;
	}
	else if (GetAsyncKeyState(VK_RETURN) == codeKeyPressed)
	{
		std::cin.get();
		return 0;
	}
}




