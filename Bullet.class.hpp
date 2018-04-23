/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bullet.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abodnar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/08 00:15:54 by abodnar           #+#    #+#             */
/*   Updated: 2018/04/08 00:15:55 by abodnar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BULLET_CLASS_HPP

# define BULLET_CLASS_HPP

# include "Game.class.hpp"



class Bullet {

	public:

		Bullet();
		Bullet(int x, int y);
		Bullet(Bullet const& bullet);
		Bullet& operator=(Bullet const& bullet);
		~Bullet();

		bool move();

		int getPosX() const;
		int getPosY() const;
		int getPrevX() const;
		int getPrevY() const;

	private:

		int _posX;
		int _posY;
		int _prevX;
		int _prevY;
		int _screenHeight;
		int _screenWidth;
};


#endif
