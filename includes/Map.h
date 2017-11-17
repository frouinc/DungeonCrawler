/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyrillef <cyrillef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 00:28:31 by cyrillef          #+#    #+#             */
/*   Updated: 2017/11/15 16:18:30 by cyrillefrouin    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include <iostream>
# include <string>
# include <fstream>
# include <sstream>

# include "Block.h"
# include "MapGenerator.h"

class					Map
{
private:
	std::string			filename;
	Block				**map;
	int					sizeX;
	int					sizeY;
	void				CopyGenerator(MapGenerator);

public:
	Map(int, int, int, int, int);
	Map(const char filename[]);
	~Map();


	std::string			getFilename() const;
	Block				**getMap() const;
	int					getSizeX() const;
	int					getSizeY() const;
};

#endif
