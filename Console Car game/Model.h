#ifndef MODEL_H    
#define MODEL_H  
#include "GameView.h"
#include "Random.h"


 
class Model
{
public:
	Model(int rand_)
		: speed(100), points(0), obstacleAltitude(0), obstacleLatitude(rand_)
	{}
	~Model();

	void wait();
	void changeSpeed(int);

	 int getSpeed() const;
	 void setSpeed(int speed);
	 int getScore() const;
	 void setScore(int points);

	void generateAndUpdateObstacle(GameView& game_view);

	int controlActionHandling(GameView& game_view);


private:
	int speed;
	int points;
	int obstacleAltitude;
	int obstacleLatitude;
	Random rand;
};


#endif MODEL_H  