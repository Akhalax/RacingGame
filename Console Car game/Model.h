#ifndef MODEL_H    
#define MODEL_H  
#include "GameView.h"

const int UP = 1;
const int DOWN = 0;
const int END = 1254697;
 
class Model
{
public:
	Model();
	~Model();

	void wait();
	void changeSpeed(int);

	int getSpeed() const;
	void setSpeed(int speed);
	int getScore() const;
	void setScore(int points);

	void generateAndUpdateObstacle(GameView* game_view);

	int controlActionHandling(GameView* game_view);


	int random();


private:
	int speed;
	int points;
	int obstacleAltitude;
	int obstacleLatitude;
};


#endif MODEL_H  