/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyrillef <cyrillef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 00:35:14 by cyrillef          #+#    #+#             */
/*   Updated: 2017/11/15 16:20:34 by cyrillefrouin    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Map.h"

Map::Map(int sizeX, int sizeY, int sizeMin, int sizeMax, int maxTry)
{
	MapGenerator	generator(sizeX, sizeY, sizeMin, sizeMax, maxTry);

	this->CopyGenerator(generator);
}

Map::Map(const char filename[])
{
	std::ifstream		file(filename);
	std::istringstream	stream;
	std::string			line;
	int					tmp = 0;

	this->filename = filename;
	if (file.is_open()) {
		// Getting map size
		std::getline(file, line);
		stream.str(line);
		stream >> tmp;
		this->sizeX = tmp;
		stream >> tmp;
		this->sizeY = tmp;

		// Allocating map arrays and filling
		this->map = new Block*[this->sizeY];
		for (int y = 0; y < this->sizeY; y++) {
			this->map[y] = new Block[this->sizeX];
			std::getline(file, line);
			std::istringstream	t(line);
			for (int x = 0; x < this->sizeX; x++) {
				t >> tmp;
				this->map[y][x].setType(tmp);
			}
		}
	} else {
		// throw new std::Exception("Couldn't open file");
	}
}

Map::~Map()
{
}

void				Map::CopyGenerator(MapGenerator generator)
{
	this->sizeX = generator.getSizeX();
	this->sizeY = generator.getSizeY();
	this->map = generator.getMap();
}

std::string			Map::getFilename() const
{
	return (this->filename);
}

Block				**Map::getMap() const
{
	return (this->map);
}

int					Map::getSizeX() const
{
	return (this->sizeX);
}

int					Map::getSizeY() const
{
	return (this->sizeY);
}
