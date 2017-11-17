/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Block.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyrillef <cyrillef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 13:04:19 by cyrillef          #+#    #+#             */
/*   Updated: 2017/11/15 16:24:04 by cyrillefrouin    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Block.h"

Block::Block()
{
	this->setType(1);
}

Block::Block(int &type)
{
	this->setType(type);
}

Block::~Block()
{

}

void		Block::setType(const int &type)
{
	this->type = type;
	this->passable = false;
	if (this->type != 1)
		this->passable = true;
}

const int	&Block::getType() const
{
	return (this->type);
}

void		Block::setPassable(const bool &passable)
{
	this->passable = passable;
}

const bool	&Block::getPassable()
{
	return (this->passable);
}
