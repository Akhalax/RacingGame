#include "Model.h"
#include <random>
#include <windows.h>
#include <iostream>
#include <ctime>
#include "GameConstants.h"



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
	if (state == GameConstats::UP)
	{
		speed -= 15;
	}
	else if (state == GameConstats::DOWN)
	{
		speed += 15;
	}

	if (speed < 10)
	{
		speed = 15;
	}
}

int Model::getSpeed() const
{
	return speed;
}

inline void Model::setSpeed(int speed)
{
	this->speed = speed;
}

 int Model::getScore() const
{
	return points;
}

inline void Model::setScore(int points)
{
	this->points = points;
}

void Model::generateAndUpdateObstacle(GameView&  game_view)
{
	game_view.updateObstacle(obstacleAltitude, obstacleLatitude, ' ');
	obstacleAltitude++;
	game_view.updateObstacle(obstacleAltitude, obstacleLatitude, GameConstats::OBSTACLE);
	
	if (obstacleAltitude > GameConstats::LOWER_BORDER) {
		obstacleAltitude = 0;
		rand.random();
		obstacleLatitude = rand.getValue();
	}
}

int Model::controlActionHandling(GameView& game_view)
{
	bool success = true;
	if (GetAsyncKeyState(VK_RIGHT) == GameConstats::CODE_KEY_PRESSED)
	{
		if (game_view.checkCrush(GameConstats::RIGHT) == true)
			return GameConstats::END;
		game_view.updateCar(GameConstats::RIGHT);
	}
	else if (GetAsyncKeyState(VK_LEFT) == GameConstats::CODE_KEY_PRESSED)
	{
		if (game_view.checkCrush(GameConstats::LEFT) == true)
			return GameConstats::END;
		game_view.updateCar(GameConstats::LEFT);
	}
	else if (GetAsyncKeyState(VK_UP) == GameConstats::CODE_KEY_PRESSED)
	{
		changeSpeed(GameConstats::UP);
	}
	else if (GetAsyncKeyState(VK_DOWN) == GameConstats::CODE_KEY_PRESSED)
	{
		changeSpeed(GameConstats::DOWN);
	}
	else if (GetAsyncKeyState(VK_ESCAPE) == GameConstats::CODE_KEY_PRESSED)
	{
		success = false;
	}
	else if (GetAsyncKeyState(VK_RETURN) == GameConstats::CODE_KEY_PRESSED)
	{
		std::cin.get();
	}
	if (success)
	{
		return 0;
	}
	else
	{
		return GameConstats::END;
	}
}




