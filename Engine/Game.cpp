/******************************************************************************************
 *	Chili DirectX Framework Version 16.07.20											  *
 *	Game.cpp																			  *
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

#include "MainWindow.h"
#include "Game.h"

Game::Game(MainWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd),

	x(400),
	y(300),
	gb(255),

	mov1x(100),
	mov1y(150),

	botIsEaten(false),
	ship1X(100),
	ship1Y(100),
	Ship1IsEaten(false),
	ship2X(300),
	ship2Y(300),
	Ship2IsEaten(false),
	ship3X(500),
	ship3Y(500),
	Ship3IsEaten(false),

	ufo1x(300),
	ufo1y(250),
	ufo1IsEaten(false),

	ufo2x(60),
	ufo2y(150),
	ufo2IsEaten(false),

	ufo3x(450),
	ufo3y(350),
	ufo3IsEaten(false),
	
	jet1x(650),
	jet1y(200),
	jet1IsEaten(false),
	
	jet2x(250),
	jet2y(500),
	jet2IsEaten(false),

	jet3x(350),
	jet3y(150),
	jet3IsEaten(false),

	level(1)

{
}

void Game::Go()
{
	gfx.BeginFrame();
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel(){
	

}
void Game::DrawReticle(int x, int y, int gb) {
	if (wnd.kbd.KeyIsPressed(VK_SPACE))
	{
		gb = 0;
	}
	gfx.PutPixel(x, y, 255, gb, gb);
	gfx.PutPixel(-5 + x,y, 255, gb, gb);
	gfx.PutPixel(-4 + x, y, 255, gb, gb);
	gfx.PutPixel(-3 + x, y, 255, gb, gb);
	gfx.PutPixel(3 + x, y, 255, gb, gb);
	gfx.PutPixel(4 + x, y, 255, gb, gb);
	gfx.PutPixel(5 + x, y, 255, gb, gb);
	gfx.PutPixel(x, -5 + y, 255, gb, gb);
	gfx.PutPixel(x, -4 + y, 255, gb, gb);
	gfx.PutPixel(x, -3 + y, 255, gb, gb);
	gfx.PutPixel(x, 3 + y, 255, gb, gb);
	gfx.PutPixel(x, 4 + y, 255, gb, gb);
	gfx.PutPixel(x, 5 + y, 255, gb, gb);
}
void Game::DrawShip(int x1, int y1) {
	
	gfx.PutPixel(x1 + 12, y1 + 0, Color(0, 255, 255));
	gfx.PutPixel(x1 + 12, y1 + 1, Color(0, 255, 255));
	gfx.PutPixel(x1 + 12, y1 + 2, Color(255, 0, 0));
	gfx.PutPixel(x1 + 11, y1 + 3, Color(255, 0, 0));
	gfx.PutPixel(x1 + 13, y1 + 3, Color(255, 0, 0));
	gfx.PutPixel(x1 + 12, y1 + 4, Color(255, 0, 0));
	for (int i = 5; i <= 20; i++)
	{
		gfx.PutPixel(x1 + 12, y1 + i, Color(128, 128, 128));
		gfx.PutPixel(x1 + 11, y1 + i, Color(64, 64, 64));
		gfx.PutPixel(x1 + 13, y1 + i, Color(64, 64, 64)); 
	}
	for (int i = 10; i <= 18; i++)
	{
		gfx.PutPixel(x1 + 7, y1 + i, Color(255, 255, 255));
		gfx.PutPixel(x1 + 8, y1 + i, Color(255, 255, 255));
	}
	gfx.PutPixel(x1 + 6, y1 + 14, Color(255, 255, 255));
	for (int i = 10; i <= 18; i++)
	{
		gfx.PutPixel(x1 + 16, y1 + i, Color(255, 255, 255));
		gfx.PutPixel(x1 + 17, y1 + i, Color(255, 255, 255));
	}
	gfx.PutPixel(x1 + 18, y1 + 14, Color(255, 255, 255));
	gfx.PutPixel(x1 + 11, y1 + 21, Color(255, 0, 0));
	gfx.PutPixel(x1 + 12, y1 + 22, Color(255, 0, 0));
	gfx.PutPixel(x1 + 13, y1 + 21, Color(255, 0, 0));
	gfx.PutPixel(x1 + 11, y1 + 23, Color(255, 255, 0));
	gfx.PutPixel(x1 + 12, y1 + 24, Color(255, 165, 0));
	gfx.PutPixel(x1 + 13, y1 + 23, Color(255, 255, 0));
}
void Game::DrawGameOver(int dx, int dy)
{
	Color white = { 255,255,255 };

	// G
	gfx.PutPixel(10 + dx, 0 + dy, white);
	gfx.PutPixel(11 + dx, 0 + dy, white);
	gfx.PutPixel(12 + dx, 0 + dy, white);
	gfx.PutPixel(10 + dx, 1 + dy, white);
	gfx.PutPixel(10 + dx, 2 + dy, white);
	gfx.PutPixel(10 + dx, 3 + dy, white);
	gfx.PutPixel(11 + dx, 3 + dy, white);
	gfx.PutPixel(12 + dx, 3 + dy, white);
	gfx.PutPixel(12 + dx, 2 + dy, white);
	gfx.PutPixel(12 + dx, 4 + dy, white);
	gfx.PutPixel(11 + dx, 4 + dy, white);
	gfx.PutPixel(10 + dx, 4 + dy, white);

	// A
	gfx.PutPixel(15 + dx, 0 + dy, white);
	gfx.PutPixel(16 + dx, 0 + dy, white);
	gfx.PutPixel(14 + dx, 1 + dy, white);
	gfx.PutPixel(17 + dx, 1 + dy, white);
	gfx.PutPixel(14 + dx, 2 + dy, white);
	gfx.PutPixel(15 + dx, 2 + dy, white);
	gfx.PutPixel(16 + dx, 2 + dy, white);
	gfx.PutPixel(17 + dx, 2 + dy, white);
	gfx.PutPixel(14 + dx, 3 + dy, white);
	gfx.PutPixel(17 + dx, 3 + dy, white);
	gfx.PutPixel(14 + dx, 4 + dy, white);
	gfx.PutPixel(17 + dx, 4 + dy, white);

	// M
	gfx.PutPixel(20 + dx, 0 + dy, white);
	gfx.PutPixel(20 + dx, 1 + dy, white);
	gfx.PutPixel(21 + dx, 1 + dy, white);
	gfx.PutPixel(22 + dx, 0 + dy, white);
	gfx.PutPixel(23 + dx, 1 + dy, white);
	gfx.PutPixel(24 + dx, 0 + dy, white);
	gfx.PutPixel(24 + dx, 1 + dy, white);
	gfx.PutPixel(20 + dx, 2 + dy, white);
	gfx.PutPixel(24 + dx, 2 + dy, white);
	gfx.PutPixel(20 + dx, 3 + dy, white);
	gfx.PutPixel(24 + dx, 3 + dy, white);
	gfx.PutPixel(20 + dx, 4 + dy, white);
	gfx.PutPixel(24 + dx, 4 + dy, white);

	// E
	gfx.PutPixel(27 + dx, 0 + dy, white);
	gfx.PutPixel(28 + dx, 0 + dy, white);
	gfx.PutPixel(29 + dx, 0 + dy, white);
	gfx.PutPixel(27 + dx, 1 + dy, white);
	gfx.PutPixel(27 + dx, 2 + dy, white);
	gfx.PutPixel(28 + dx, 2 + dy, white);
	gfx.PutPixel(27 + dx, 3 + dy, white);
	gfx.PutPixel(27 + dx, 4 + dy, white);
	gfx.PutPixel(28 + dx, 4 + dy, white);
	gfx.PutPixel(29 + dx, 4 + dy, white);

	// Space

	// O
	gfx.PutPixel(35 + dx, 0 + dy, white);
	gfx.PutPixel(36 + dx, 0 + dy, white);
	gfx.PutPixel(37 + dx, 0 + dy, white);
	gfx.PutPixel(35 + dx, 1 + dy, white);
	gfx.PutPixel(37 + dx, 1 + dy, white);
	gfx.PutPixel(35 + dx, 2 + dy, white);
	gfx.PutPixel(37 + dx, 2 + dy, white);
	gfx.PutPixel(35 + dx, 3 + dy, white);
	gfx.PutPixel(37 + dx, 3 + dy, white);
	gfx.PutPixel(35 + dx, 4 + dy, white);
	gfx.PutPixel(36 + dx, 4 + dy, white);
	gfx.PutPixel(37 + dx, 4 + dy, white);

	// V
	gfx.PutPixel(40 + dx, 0 + dy, white);
	gfx.PutPixel(44 + dx, 0 + dy, white);
	gfx.PutPixel(41 + dx, 1 + dy, white);
	gfx.PutPixel(43 + dx, 1 + dy, white);
	gfx.PutPixel(42 + dx, 2 + dy, white);
	gfx.PutPixel(42 + dx, 3 + dy, white);
	gfx.PutPixel(42 + dx, 4 + dy, white);

	// E
	gfx.PutPixel(47 + dx, 0 + dy, white);
	gfx.PutPixel(48 + dx, 0 + dy, white);
	gfx.PutPixel(49 + dx, 0 + dy, white);
	gfx.PutPixel(47 + dx, 1 + dy, white);
	gfx.PutPixel(47 + dx, 2 + dy, white);
	gfx.PutPixel(48 + dx, 2 + dy, white);
	gfx.PutPixel(47 + dx, 3 + dy, white);
	gfx.PutPixel(47 + dx, 4 + dy, white);
	gfx.PutPixel(48 + dx, 4 + dy, white);
	gfx.PutPixel(49 + dx, 4 + dy, white);

	// R
	gfx.PutPixel(52 + dx, 0 + dy, white);
	gfx.PutPixel(53 + dx, 0 + dy, white);
	gfx.PutPixel(54 + dx, 0 + dy, white);
	gfx.PutPixel(52 + dx, 1 + dy, white);
	gfx.PutPixel(54 + dx, 1 + dy, white);
	gfx.PutPixel(52 + dx, 2 + dy, white);
	gfx.PutPixel(53 + dx, 2 + dy, white);
	gfx.PutPixel(52 + dx, 3 + dy, white);
	gfx.PutPixel(54 + dx, 4 + dy, white);
	gfx.PutPixel(52 + dx, 4 + dy, white);
}
void Game::DrawL(int x, int y, Color c)
{
	for (int i = 0; i < 20; i++) gfx.PutPixel(x, y + i, c); // Vertical
	for (int i = 0; i < 12; i++) gfx.PutPixel(x + i, y + 19, c); // Bottom
}

void Game::DrawE(int x, int y, Color c)
{
	for (int i = 0; i < 20; i++) gfx.PutPixel(x, y + i, c); // Vertical
	for (int i = 0; i < 12; i++) gfx.PutPixel(x + i, y, c);     // Top
	for (int i = 0; i < 9; i++) gfx.PutPixel(x + i, y + 9, c);  // Middle
	for (int i = 0; i < 12; i++) gfx.PutPixel(x + i, y + 19, c); // Bottom
}

void Game::DrawV(int x, int y, Color c)
{
	for (int i = 0; i < 10; i++)
	{
		gfx.PutPixel(x + i, y + i * 2, c);
		gfx.PutPixel(x + 19 - i, y + i * 2, c);
	}
}

void Game::DrawWordLEVEL(int x, int y, Color c)
{
	DrawL(x, y, c);         // L
	DrawE(x + 20, y, c);    // E
	DrawV(x + 40, y, c);    // V
	DrawE(x + 65, y, c);    // E
	DrawL(x + 85, y, c);    // L
}

void Game::ComposeFrame()
{
	//level background
	
	for (int y = 0; y < 100; ++y)
	{
		for (int x = 0; x < 800; ++x)
		{
			gfx.PutPixel(x, y, 63, 89, 87);
		}
	}

	//Background

	for (int y = 100; y < 600; ++y)
	{
		for (int x = 0; x < 800; ++x)
		{
			gfx.PutPixel(x, y, Colors::Black);
		}
	}

	//draw level
	DrawWordLEVEL(50, 50, Colors::Green);


	//questions
	//level  = 1 do not use this
	// where is int main




	//drawing level counter
	for (int i = 40; i < 80; i++)
	{
		gfx.PutPixel(200, i, 0, 255, 0);
	}

	if (level >=2)
	{
		for (int i = 40; i < 80; i++)
		{
			gfx.PutPixel(230, i, 0, 255, 0);
		}
	}

	if (level >= 3)
	{
		for (int i = 40; i < 80; i++)
		{
			gfx.PutPixel(260, i, 0, 255, 0);
		}
	}

	// My Reticle
	DrawReticle(x, y, gb); //****

	
	
	int speed = 3;

	// slow speed

	if (wnd.kbd.KeyIsPressed(VK_SPACE))
	{
		speed = 1;
	}

	//speed boost

	if (wnd.kbd.KeyIsPressed(VK_CONTROL))
	{
		speed = 8;
	}
	
	//movement keys
	if (level != 4) {
		if (wnd.kbd.KeyIsPressed(VK_RIGHT))
		{
			x = x + speed;
		}

		if (wnd.kbd.KeyIsPressed(VK_LEFT))
		{
			x = x - speed;
		}

		if (wnd.kbd.KeyIsPressed(VK_UP))
		{
			y = y - speed;
		}

		if (wnd.kbd.KeyIsPressed(VK_DOWN))
		{
			y = y + speed;
		}

		//avoid crash
		if (x < 5)
		{
			x = 794;
		}
		if (x > 794)
		{
			x = 5;
		}

		if (y < 100)
		{
			y = 594;
		}

		if (y > 594)
		{
			y = 100;
		}

	}

	// level 1

	//moving bot
	if (mov1x >= 100 && mov1x < 700 && mov1y == 150)
	{
		mov1x += 1;
	}

	if (mov1x == 700 && mov1y < 500)
	{
		mov1y += 1;
	}

	if (mov1y == 500 && mov1x > 100)
	{
		mov1x -= 1;
	}

	if (mov1x == 100 && mov1y > 150)
	{
		mov1y -= 1;
	}

	
	if (level == 1) {
		if (!(botIsEaten && Ship1IsEaten && Ship2IsEaten && Ship3IsEaten))
		{
			//collision with Ships

			if (!botIsEaten)
			{
				if (wnd.kbd.KeyIsPressed(VK_SPACE)) {
					if (x + 20 > mov1x &&
						x < mov1x + 20 &&
						y + 20 > mov1y &&
						y < mov1y + 20)
					{
						botIsEaten = true;
					}
				}
				DrawShip(mov1x, mov1y);
			}


			if (!Ship1IsEaten)
			{
				if (wnd.kbd.KeyIsPressed(VK_SPACE)) {
					if (x + 20 > ship1X &&
						x < ship1X + 20 &&
						y + 20 > ship1Y &&
						y < ship1Y + 20)
					{
						Ship1IsEaten = true;
					}
				}
				DrawShip(ship1X, ship1Y);
			}

			if (!Ship2IsEaten)
			{
				if (wnd.kbd.KeyIsPressed(VK_SPACE)) {
					if (x + 20 > ship2X &&
						x < ship2X + 20 &&
						y + 20 > ship2Y &&
						y < ship2Y + 20)
					{
						Ship2IsEaten = true;
					}
				}
				DrawShip(ship2X, ship2Y);
			}

			if (!Ship3IsEaten)
			{
				if (wnd.kbd.KeyIsPressed(VK_SPACE)) {
					if (x + 20 > ship3X &&
						x < ship3X + 20 &&
						y + 20 > ship3Y &&
						y < ship3Y + 20)
					{
						Ship3IsEaten = true;
					}
				}
				DrawShip(ship3X, ship3Y);
			}

		}
		else
		{
			level = 2;
			//do not use level++


		}
	}

	//level 2
	if (level == 2)
	{
		if (!(ufo1IsEaten && ufo2IsEaten && ufo3IsEaten)){
			if (!ufo1IsEaten)
			{	
				//movement
				if (ufo1x >= 6 && ufo1x < 780)
				{
					ufo1x += 2;

				}
				if (ufo1x == 780)
				{
					ufo1x = 6;
				}

				//collision detection
				if (wnd.kbd.KeyIsPressed(VK_SPACE))
				{
					if (x + 20 > ufo1x &&
						x < ufo1x + 20 &&
						y + 20 > ufo1y &&
						y < ufo1y + 20
						)
					{
						ufo1IsEaten = true;
					}
				}
				DrawShip(ufo1x, ufo1y);
			}

			if (!ufo2IsEaten)
			{

				if (ufo2x >= 6 && ufo2x < 780)
				{
					ufo2x += 2;

				}
				if (ufo2x == 780)
				{
					ufo2x = 6;
				}

				if (wnd.kbd.KeyIsPressed(VK_SPACE))
				{
					if (x + 20 > ufo2x &&
						x < ufo2x + 20 &&
						y + 20 > ufo2y &&
						y < ufo2y + 20
						)
					{
						ufo2IsEaten = true;
					}
				}
				DrawShip(ufo2x, ufo2y);
			}

			if (!ufo3IsEaten)
			{
				if (ufo3y >= 106 && ufo3y < 570)
				{
					ufo3y += 2;

				}
				if (ufo3y == 570)
				{
					ufo3y = 106;
				}

				if (wnd.kbd.KeyIsPressed(VK_SPACE))
				{
					if (x + 20 > ufo3x &&
						x < ufo3x + 20 &&
						y + 20 > ufo3y &&
						y < ufo3y + 20
						)
					{
						ufo3IsEaten = true;
					}
				}
				DrawShip(ufo3x, ufo3y);
			}
		}
		else
		{
			level = 3;
		}
	}
		
	//level 3

	if (level >= 3)
	{
		if (!(jet1IsEaten && jet2IsEaten && jet3IsEaten)) {
			if (!jet1IsEaten)
			{
				//movement
				if (jet1x >= 6 && jet1x < 780)
				{
					jet1x += 2;
					jet1y += 3;

				}
				if (jet1x == 780)
				{
					jet1x = 6;
				}
				if (jet1y >= 570)
				{
					jet1y = 106;
				}
				//collision detection
				if (wnd.kbd.KeyIsPressed(VK_SPACE))
				{
					if (x + 20 > jet1x &&
						x < jet1x + 20 &&
						y + 20 > jet1y &&
						y < jet1y + 20
						)
					{
						jet1IsEaten = true;
					}
				}
				DrawShip(jet1x, jet1y);
			}

			if (!jet2IsEaten)
			{

				if (jet2x >= 6 && jet2x < 780)
				{
					jet2x += 2;

				}
				if (jet2x == 780)
				{
					jet2x = 6;
				}

				if (wnd.kbd.KeyIsPressed(VK_SPACE))
				{
					if (x + 20 > jet2x &&
						x < jet2x + 20 &&
						y + 20 > jet2y &&
						y < jet2y + 20
						)
					{
						jet2IsEaten = true;
					}
				}
				DrawShip(jet2x, jet2y);
			}

			if (!jet3IsEaten)
			{
				if (jet3y >= 106 && jet3y < 570)
				{
					jet3y += 2;

				}
				if (jet3y == 570)
				{
					jet3y = 106;
				}

				if (wnd.kbd.KeyIsPressed(VK_SPACE))
				{
					if (x + 20 > jet3x &&
						x < jet3x + 20 &&
						y + 20 > jet3y &&
						y < jet3y + 20
						)
					{
						jet3IsEaten = true;
					}
				}
				DrawShip(jet3x, jet3y);
			}
		}
		else
		{
			level = 4;
			DrawGameOver(350, 300);
		}
	}
}
