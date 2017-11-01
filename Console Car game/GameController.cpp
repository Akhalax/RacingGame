#include <iostream>
#include <conio.h>

#include "GameView.h"
#include "Model.h"
#include "GameConstants.h"

using namespace std;


int main()
{

	bool startup = true;

	GameView* game_view = new GameView();
	Random* rand = new Random();
	Model* model = new Model(rand->getValue());



	while (true) {
		game_view->clearscreen();

		game_view->placeCarToDefalultPosition();

		model->generateAndUpdateObstacle(game_view);

		game_view->displayField();


		int score = model->getScore();
		game_view->displayScore(score);

		if (startup) {
			_getch();
			startup = false;
		}
		if (model->controlActionHandling(game_view)== GameConstats::END)
		{
			game_view->gameOver();
			break;
		}
		
		if (game_view->checkCrush(0) == true) {
			game_view->gameOver();
			break;
		}

		
		model->wait();
	}
	delete game_view;
	delete model;
	delete rand;
	return 0;
}
