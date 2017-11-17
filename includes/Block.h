/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Block.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyrillef <cyrillef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 13:00:09 by cyrillef          #+#    #+#             */
/*   Updated: 2017/11/10 13:12:03 by cyrillefrouin    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BLOCK_H
# define BLOCK_H

class			Block
{
private:
	int			type;
	bool		passable;

public:
	Block();
	Block(int &type);
	~Block();

	void		setType(const int &type);
	const int	&getType() const;
	void		setPassable(const bool &passable);
	const bool	&getPassable();
};

#endif
