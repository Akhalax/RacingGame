#include <iostream>
#include <conio.h>

#include "GameView.h"
#include "Model.h"

using namespace std;


int main()
{

	bool startup = true;
	
	GameView game_view;
	Model model;

	//the game loop
	while (true) {
		game_view.clearscreen();
		//places the car at its default location
		game_view.placeCarToDefalultPosition();

		//generates the obstacles
		model.generateAndUpdateObstacle(game_view);
		//displays the map
		game_view.displayField();


		int score;
		score = model.getScore();
		game_view.displayScore(score);

		//does so the game starts after a key is pressed
		if (startup) {
			_getch();
			startup = false;
		}
		if (model.controlActionHandling(game_view)==END)
		{
			return 0;
		}
		
		//checks if the car crashed
		if (game_view.checkCrush(0) == true) {
			game_view.gameOver();
			return 0;
		}

		
		model.wait();
	}
	return 0;
}
