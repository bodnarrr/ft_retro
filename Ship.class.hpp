/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ship.class.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abodnar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 13:35:13 by abodnar           #+#    #+#             */
/*   Updated: 2018/04/07 13:35:13 by abodnar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHIP_CLASS_HPP

# define SHIP_CLASS_HPP
# include "Bullet.class.hpp"
#include "Enemy.class.hpp"
# include <sys/ioctl.h>
# include <unistd.h>
# include <ncurses.h>
# include <curses.h>

class Ship {

	public:

		Ship();
		Ship(Ship const& obj);
		Ship& operator=(Ship const& obj);
		~Ship();

		void moveUp();
		void moveDown();
		void moveLeft();
		void moveRight();
		void checkCollisions(Enemy **enemies);

		Bullet *shoot();

		int getPosX() const;
		int getPosY() const;
		int getPrevX() const;
		int getPrevY() const;

		int getPoints() const;
		bool isAlive() const;




	private:

		int _posX;
		int _prevX;
		int _posY;
		int _prevY;
		int _points;
		bool _alive;
		int _screenWidth;
		int _screenHeight;

};

#endif
