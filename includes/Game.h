/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyrillef <cyrillef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 00:27:23 by cyrillef          #+#    #+#             */
/*   Updated: 2017/11/10 17:13:20 by cyrillefrouin    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include "DungeonCrawler.h"
# include "Map.h"
# include "Character.h"
# include "Display.h"

typedef struct			s_events
{
	// Informations
	bool				quit;

	// Directions
	bool				left;
	bool				down;
	bool				right;
	bool				up;
}						t_events;

class					Game
{
private:
	Display				display;
	t_events			events;
	Map					map;
	Character			character;

	int					Event();
	int					Update();
	void				GetKeys();
	void				UpdateCharacter();
	void				UpdateCamera();
	int					Display();

public:
	Game();
	~Game();

	int					Start();
	int					Loop();
	int					End();
};

#endif
