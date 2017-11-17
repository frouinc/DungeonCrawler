/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyrillef <cyrillef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 13:21:49 by cyrillef          #+#    #+#             */
/*   Updated: 2017/11/10 14:17:28 by cyrillefrouin    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_H
# define CHARACTER_H

# include "DungeonCrawler.h"

class					Character
{
private:
	int					posX;
	int					posY;
	sf::Texture			texture;

public:
	Character();
	Character(const int &x, const int &y);
	~Character();

	void				move(const int &x, const int &y);

	// GETTER & SETTERS
	void				setPosX(const int &);
	const int			&getPosX() const;
	void				setPosY(const int &);
	const int			&getPosY() const;
	const sf::Texture	&getTexture() const;
};

#endif
