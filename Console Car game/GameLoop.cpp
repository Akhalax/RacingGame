#include "GameLoop.h"
#include "GameConstants.h"
#include <conio.h>
#include "Model.h"


GameLoop::GameLoop()
{
}


GameLoop::~GameLoop()
{
}

void GameLoop::startGame()
{
	bool startup = true;

	GameView game_view;
	Random rand;
	Model model{ rand.getValue() };

	
	while (true) {
		game_view.clearscreen();

		game_view.placeCarToDefalultPosition();

		model.generateAndUpdateObstacle(game_view);

		game_view.displayField();


		int score = model.getScore();
		game_view.displayScore(score);

		if (startup) {
			_getch();
			startup = false;
		}
		if (model.controlActionHandling(game_view) == GameConstats::END)
		{
			game_view.gameOver();
			return;
		}

		if (game_view.checkCrush(0) == true) {
			game_view.gameOver();
			return;
		}

		model.wait();
	}
}
