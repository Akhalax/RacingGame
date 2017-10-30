#ifndef GAMEVIEW_H    
#define GAMEVIEW_H

const char obstacle = 219;
const char car = 'X';

const int fieldSize = 21;
const int arraySize = 25;
const int leftBorder = 0;
const int rightBorder = 18;

const int yDefault = 17;
const int xDefault = 9;

const int LEFT = 789456;
const int RIGHT = 789465;

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

	const int& get_y() const;
	int& get_x();
	void set_x(int x);
private:
	char road[arraySize][arraySize];

	const int y = yDefault;
	int x;

};

#endif GAMEVIEW_H

