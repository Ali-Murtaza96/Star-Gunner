/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.h																				  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#pragma once

#include "Keyboard.h"
#include "Mouse.h"
#include "Graphics.h"

class Game
{
public:
	Game( class MainWindow& wnd );
	Game( const Game& ) = delete;
	Game& operator=( const Game& ) = delete;
	void Go();
private:
	void ComposeFrame();
	void UpdateModel();
	void DrawReticle(int x, int y,int gb);
	void DrawShip(int x, int y);
	void DrawGameOver(int x, int y);
	void Game::DrawL(int x, int y, Color c);
	void Game::DrawE(int x, int y, Color c);
	void Game::DrawV(int x, int y, Color c);
	void Game::DrawWordLEVEL(int x, int y, Color c);



	/********************************/
	/*  User Functions              */
	/********************************/
private:
	MainWindow& wnd;
	Graphics gfx;
	/********************************/
	/*  User Variables              */
	/********************************/
	int x;
	int y;
	int gb;

	//level 1
	int mov1x;
	int mov1y;
	bool botIsEaten;

	int ship1X;
	int ship1Y;
	bool Ship1IsEaten;

	int ship2X;
	int ship2Y;
	bool Ship2IsEaten;

	int ship3X;
	int ship3Y;
	bool Ship3IsEaten;

	//level 2
	int ufo1x;
	int ufo1y;
	bool ufo1IsEaten;

	int ufo2x;
	int ufo2y;
	bool ufo2IsEaten;

	//level 3
	int jet1x;
	int jet1y;
	bool jet1IsEaten;

	int jet2x;
	int jet2y;
	bool jet2IsEaten;

	int jet3x;
	int jet3y;
	bool jet3IsEaten;

	int ufo3x;
	int ufo3y;
	bool ufo3IsEaten;


	int level;
};