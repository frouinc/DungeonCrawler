/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyrillef <cyrillef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 14:36:53 by cyrillef          #+#    #+#             */
/*   Updated: 2017/11/09 15:06:45 by cyrillefrouin    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DungeonCrawler.h"

Game::Game()
{
	// Debug mode
	if (DEBUG)
		std::cout << "Debug mode Version " << DungeonCrawler_VERSION_MAJOR << "." << DungeonCrawler_VERSION_MINOR << std::endl;

	// Init events
	this->events.quit = 0;
	this->events.left = 0;
	this->events.down = 0;
	this->events.right = 0;
	this->events.up = 0;
}

Game::~Game()
{

}

int				Game::Start()
{
	this->window.create(sf::VideoMode(800, 600), "DungeonCrawler");
	this->window.setFramerateLimit(30);
	return (1);
}

int				Game::Loop()
{
	while (window.isOpen()) {
		this->Event();
		this->Update();
		this->Display();
	}
	return (1);
}

int				Game::End()
{
	this->window.close();
	delete(this);
	return (1);
}

int				Game::Event()
{
	sf::Event event;

	while (this->window.pollEvent(event)) {
		if (event.type == sf::Event::Closed) {
			this->events.quit = 1;
			return (0);
		}
	}
	return (1);
}

int				Game::Update()
{
	if (this->events.quit)
		this->window.close();
	return (1);
}

int				Game::Display()
{
	this->window.display();
	return (1);
}
