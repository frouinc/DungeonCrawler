/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MapGenerator.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyrillef <cyrillef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 16:16:49 by cyrillef          #+#    #+#             */
/*   Updated: 2017/11/15 17:58:29 by cyrillefrouin    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_GENERATOR_H
# define MAP_GENERATOR_H

# include <random>

# include "DungeonCrawler.h"
# include "Block.h"

class				MapGenerator
{
private:
	Block			**map;
	int				sizeX;
	int				sizeY;
	int				sizeMin;
	int				sizeMax;
	int				tries;

	bool			TryRoom(int, int, int, int);
	void			PlaceRoom(int, int, int, int);
	void			GenerateRooms();
	void			GenerateCorridors();
	void			Generate();

public:
	MapGenerator(int, int, int, int, int);
	~MapGenerator();

	Block			**getMap();
	int				getSizeX();
	int				getSizeY();
	int				getSizeMin();
	int				getSizeMax();
};

#endif
