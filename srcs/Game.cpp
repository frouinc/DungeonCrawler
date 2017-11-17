/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyrillef <cyrillef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 14:36:53 by cyrillef          #+#    #+#             */
/*   Updated: 2017/11/15 17:44:42 by cyrillefrouin    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Game.h"

Game::Game() : map(40, 40, 3, 6, 2000)
{
	// Debug mode
	if (DEBUG)
		std::cout << "Debug mode Version " << DungeonCrawler_VERSION_MAJOR << "." << DungeonCrawler_VERSION_MINOR << std::endl;

	// Init events
	this->events.quit = false;
	this->events.left = false;
	this->events.down = false;
	this->events.right = false;
	this->events.up = false;
}

Game::~Game()
{

}

int					Game::Start()
{
	bool			flag = false;

	// Find suitable position for player
	for (int y = 0; y < this->map.getSizeY(); y++)
	{
		for (int x = 0; x < this->map.getSizeX(); x++)
		{
			if (this->map.getMap()[y][x].getPassable()) {
				this->character.setPosX(x);
				this->character.setPosY(y);
				flag = true;
				break ;
			}
		}
		if (flag)
			break ;
	}

	// Preload texture texture
	return (1);
}

int					Game::Loop()
{
	while (this->display.IsOpen()) {
		this->Event();
		this->Update();
		this->Display();
	}
	return (1);
}

int					Game::End()
{
	this->display.Close();
	delete(this);
	return (1);
}

int					Game::Event()
{
	sf::Event event;

	while (this->display.getWindow().pollEvent(event)) {
		if (event.type == sf::Event::Closed) {
			this->events.quit = true;
			return (0);
		} else if (event.type == sf::Event::KeyPressed) {
			switch (event.key.code) {
				case sf::Keyboard::Left :
					this->events.left = true;
					break ;
				case sf::Keyboard::Right :
					this->events.right = true;
					break ;
				case sf::Keyboard::Down :
					this->events.down = true;
					break ;
				case sf::Keyboard::Up :
					this->events.up = true;
					break ;
				default :
					break ;
			}
		}
	}
	return (1);
}

void				Game::UpdateCharacter()
{
	int			x = 0, y = 0;
	Character	&c = this->character;

	if (this->events.right && c.getPosX() + 1 < this->map.getSizeX())
		x++;
	if (this->events.left && c.getPosX() > 0)
		x--;
	if (this->events.down && c.getPosY() + 1 < this->map.getSizeY())
		y++;
	if (this->events.up && c.getPosY() > 0)
		y--;
	// if (this->map.getMap()[c.getPosY() + y][c.getPosX() + x].getPassable())
		this->character.move(x, y);
}

void				Game::UpdateCamera()
{
	int			x = 0, y = 0;

	x = this->character.getPosX() * SCALE + SCALE / 2;
	y = this->character.getPosY() * SCALE + SCALE / 2;

	// TOP AND LEFT
	if (x - WINDOW_X / 2 < 0)
		x = WINDOW_X / 2;
	if (y - WINDOW_Y / 2 < 0)
		y = WINDOW_Y / 2;

	// BOTTOM AND RIGHT
	if (x + WINDOW_X / 2 >= this->map.getSizeX() * SCALE)
		x = this->map.getSizeX() * SCALE - WINDOW_X / 2;
	if (y + WINDOW_Y / 2 >= this->map.getSizeY() * SCALE)
		y = this->map.getSizeY() * SCALE - WINDOW_Y / 2;

	this->display.getCamera().setCenter(x, y);
	this->display.getWindow().setView(this->display.getCamera());
}

int					Game::Update()
{
	if (this->events.quit)
		this->display.getWindow().close();
	this->UpdateCharacter();
	this->UpdateCamera();

	this->events.left = false;
	this->events.down = false;
	this->events.right = false;
	this->events.up = false;
	return (1);
}

int					Game::Display()
{
	this->display.DrawMap(this->map);
	this->display.DrawCharacter(this->character);
	this->display.getWindow().display();
	return (1);
}
