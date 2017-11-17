/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Display.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyrillef <cyrillef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 17:10:35 by cyrillef          #+#    #+#             */
/*   Updated: 2017/11/17 16:29:56 by cfrouin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Display.h"

Display::Display()
{
	if (!this->texturePack.loadFromFile("../resources/textures.png"))
	{
		std::cerr << "Can't open textures.png" << std::endl;
	}
	this->texturePack.setSmooth(true);

	this->window.create(sf::VideoMode(WINDOW_X, WINDOW_Y), "DungeonCrawler");
	this->window.setFramerateLimit(FPS);
	this->window.setKeyRepeatEnabled(false);
	this->camera.reset(sf::FloatRect(0, 0, 800, 600));
}

Display::~Display()
{

}

void					Display::DrawMap(const Map &map)
{
	sf::Sprite	sprite;

	sprite.setTexture(this->texturePack);
	sprite.setScale(sf::Vector2f(SCALE / TEXTURE_SIZEF, SCALE / TEXTURE_SIZEF));
	for (int y = 0; y < map.getSizeY(); y++) {
		for (int x = 0; x < map.getSizeX(); x++) {
			sprite.setTextureRect(sf::IntRect(TEXTURE_SIZE * map.getMap()[y][x].getType(), 0, TEXTURE_SIZE, TEXTURE_SIZE));
			sprite.setPosition(sf::Vector2f(SCALE * x, SCALE * y));
			this->window.draw(sprite);
		}
	}
}

void					Display::DrawCharacter(const Character &character)
{
	sf::Sprite	sprite;

	sprite.setTexture(character.getTexture());
	sprite.setScale(sf::Vector2f(SCALE / TEXTURE_SIZEF, SCALE / TEXTURE_SIZEF));
	sprite.setPosition(sf::Vector2f(SCALE * character.getPosX(), SCALE * character.getPosY()));
	this->window.draw(sprite);
}

void					Display::Close()
{
	this->window.close();
}

bool					Display::IsOpen()
{
	return (this->window.isOpen());
}

sf::RenderWindow		&Display::getWindow()
{
	return (this->window);
}

sf::View				&Display::getCamera()
{
	return (this->camera);
}

sf::Texture				&Display::getTexturePack()
{
	return (this->texturePack);
}
