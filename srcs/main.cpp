/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyrillef <cyrillef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 14:30:07 by cyrillef          #+#    #+#             */
/*   Updated: 2017/11/09 14:55:43 by cyrillefrouin    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DungeonCrawler.h"

int main()
{
	Game *game = new Game();

	game->Start();
	game->Loop();
	game->End();
	return (0);
}
