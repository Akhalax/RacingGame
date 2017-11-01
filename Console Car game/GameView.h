#ifndef GAMEVIEW_H    
#define GAMEVIEW_H
#include "GameConstants.h"


class GameView
{
public:
	GameView();
	~GameView();

	void drawGameField();
	void placeCarToDefalultPosition();
	void displayField();
	void updateObstacle(int, int, char);
	void updateCar(int);

	char getXYroad(int, int);

	void displayScore(int points);

	void clearscreen();

	void gameOver();
	bool checkCrush(int);

	inline int getY() const;
	inline int getX() const;
	inline void setX(int x);

private:
	char road[GameConstats::ARRAY_SIZE][GameConstats::ARRAY_SIZE];

	const int y = GameConstats::Y_DEFAULT;
	int x;


};

#endif GAMEVIEW_H

