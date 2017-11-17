/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Display.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyrillef <cyrillef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 17:04:02 by cyrillef          #+#    #+#             */
/*   Updated: 2017/11/10 17:30:24 by cyrillefrouin    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPLAY_H
# define DISPLAY_H

# include "DungeonCrawler.h"
# include "Map.h"
# include "Character.h"

class						Display
{
private:
	sf::RenderWindow		window;
	sf::View				camera;
	sf::Texture				texturePack;

public:
	Display();
	~Display();

	void					DrawMap(const Map &map);
	void					DrawCharacter(const Character &character);
	void					Close();
	bool					IsOpen();

	sf::RenderWindow		&getWindow();
	sf::View				&getCamera();
	sf::Texture				&getTexturePack();
};

#endif
