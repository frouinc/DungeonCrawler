/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DungeonCrawler.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyrillef <cyrillef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 14:29:16 by cyrillef          #+#    #+#             */
/*   Updated: 2017/11/09 15:06:49 by cyrillefrouin    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DUNGEON_CRAWLER_H
# define DUNGEON_CRAWLER_H

# include <iostream>
# include <SFML/Graphics.hpp>
# include "config.h"

typedef struct		s_infos
{

}					t_infos;

typedef struct		s_events
{
	// Informations
	bool			quit;

	// Directions
	bool			left;
	bool			down;
	bool			right;
	bool			up;
}					t_events;

class				Game
{
private:
	sf::Window		window;
	t_events		events;
	// t_infos			infos;

	int				Event();
	int				Update();
	int				Display();

public:
	Game();
	~Game();

	int				Start();
	int				Loop();
	int				End();
};

#endif
