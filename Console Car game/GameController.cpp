#include <iostream>

#include <conio.h>

#include "GameView.h"
#include "Model.h"

using namespace std;


int main()
{

	bool startup = true;

	auto game_view = new GameView();
	auto model = new Model();

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
		if (model->controlActionHandling(game_view)==END)
		{
			return 0;
		}
		

		if (game_view->checkCrush(0) == true) {
			game_view->gameOver();
			return 0;
		}

		
		model->wait();
	}
	return 0;
}
