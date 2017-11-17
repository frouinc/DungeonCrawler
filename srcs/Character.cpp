/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyrillef <cyrillef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 13:26:07 by cyrillef          #+#    #+#             */
/*   Updated: 2017/11/10 14:18:33 by cyrillefrouin    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.h"

Character::Character()
{
	if (!this->texture.loadFromFile("../resources/character.png"))
	{
		std::cerr << "Can't open character.png" << std::endl;
	}
	this->texture.setSmooth(true);
}

Character::Character(const int &x, const int &y)
{
	this->posX = x;
	this->posY = y;
	if (!this->texture.loadFromFile("../resources/character.png"))
	{
		std::cerr << "Can't open character.png" << std::endl;
	}
	this->texture.setSmooth(true);
}

Character::~Character()
{

}

void				Character::move(const int &x, const int &y)
{
	this->posX += x;
	this->posY += y;
}


// GETTER & SETTERS

void				Character::setPosX(const int &x)
{
	this->posX = x;
}

const int			&Character::getPosX() const
{
	return (this->posX);
}

void				Character::setPosY(const int &y)
{
	this->posY = y;
}

const int			&Character::getPosY() const
{
	return (this->posY);
}

const sf::Texture	&Character::getTexture() const
{
	return (this->texture);
}
