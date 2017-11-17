/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MapGenerator.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyrillef <cyrillef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 16:15:10 by cyrillef          #+#    #+#             */
/*   Updated: 2017/11/15 23:27:42 by cyrillefrouin    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MapGenerator.h"

MapGenerator::MapGenerator(int sizeX, int sizeY, int sizeMin, int sizeMax, int maxTry)
{
	this->sizeX = sizeX;
	this->sizeY = sizeY;
	this->sizeMin = sizeMin;
	this->sizeMax = sizeMax;
	this->tries = maxTry;

	this->map = new Block*[this->sizeY];
	for (int y = 0; y < this->sizeY; y++) {
		this->map[y] = new Block[this->sizeX];
	}
	this->Generate();
}

MapGenerator::~MapGenerator()
{

}

bool									MapGenerator::TryRoom(int posX, int posY, int sizeX, int sizeY)
{
	if (posX + sizeX < this->sizeX)
		sizeX++;
	if (posX > 0) {
		sizeX++;
		posX--;
	}
	if (posY + sizeY < this->sizeY)
		sizeY++;
	if (posY > 0) {
		sizeY++;
		posY--;
	}
	for (int y = posY; y < posY + sizeY; y++) {
		for (int x = posX; x < posX + sizeX; x++) {
			if (this->map[y][x].getType() != 1)
				return (false);
		}
	}
	return (true);
}

void									MapGenerator::PlaceRoom(int posX, int posY, int sizeX, int sizeY)
{
	for (int y = posY; y < posY + sizeY; y++) {
		for (int x = posX; x < posX + sizeX; x++) {
			this->map[y][x].setType(-2);
		}
	}
}

void									MapGenerator::GenerateRooms()
{
	int									px = 0, py = 0, sx = 0, sy = 0;
	std::random_device					r;
	std::default_random_engine			gposX(r());
	std::uniform_int_distribution<int>	dposX(1, this->sizeX - 1);
	std::default_random_engine			gposY(r());
	std::uniform_int_distribution<int>	dposY(1, this->sizeY - 1);
	std::default_random_engine			gsizeX(r());
	std::uniform_int_distribution<int>	dsizeX(this->sizeMin, this->sizeMax);
	std::default_random_engine			gsizeY(r());
	std::uniform_int_distribution<int>	dsizeY(this->sizeMin, this->sizeMax);

	while (this->tries > 0) {
		px = dposX(gposX);
		py = dposY(gposY);
		sx = dsizeX(gsizeX);
		sy = dsizeY(gsizeY);
		if (DEBUG) {
			std::cout << px << "/" << this->sizeX << std::endl;
			std::cout << py << "/" << this->sizeY << std::endl;
			std::cout << px + sx << "/" << this->sizeX << std::endl;
			std::cout << py + sy << "/" << this->sizeY << std::endl;
		}
		if (px + sx < this->sizeX && py + sy < this->sizeY && this->TryRoom(px, py, sx, sy)) {
			this->PlaceRoom(px, py, sx, sy);
		} else {
			this->tries -= 1;
		}
	}
}


// remplit toutes les cases qui touchent pas
void									MapGenerator::GenerateCorridors()
{
	for (int y = 1; y < this->sizeY - 1; y++) {
		for (int x = 1; x < this->sizeX - 1; x++) {
			if ()
		}
	}
}

void									MapGenerator::Generate()
{
	this->GenerateRooms();
	this->GenerateCorridors();
	for (int y = 0; y < this->sizeY; y++) {
		for (int x = 0; x < this->sizeX; x++) {
			// if ()
		}
		std::cout << std::endl;
	}
}

Block									**MapGenerator::getMap()
{
	return (this->map);
}

int										MapGenerator::getSizeX()
{
	return (this->sizeX);
}


int										MapGenerator::getSizeY()
{
	return (this->sizeY);
}


int										MapGenerator::getSizeMin()
{
	return (this->sizeMin);
}


int										MapGenerator::getSizeMax()
{
	return (this->sizeMax);
}
