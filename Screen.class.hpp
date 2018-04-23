/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Screen.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abodnar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 15:31:31 by abodnar           #+#    #+#             */
/*   Updated: 2018/04/07 15:31:32 by abodnar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCREEN_CLASS_HPP

# define SCREEN_CLASS_HPP
# include "Ship.class.hpp"
#include "Enemy.class.hpp"
# include <ncurses.h>
# include <curses.h>
# include <iostream>
# include <sys/ioctl.h>
# include <unistd.h>

# define REFRESH wrefresh(this->_win)
# define DELAYSCREEN 15000
# define TOGEN 15
# define GEN 100
# define MAXBULLETS 500
# define MAXENEMIES 50

class Screen {

	public:

		Screen();
		Screen(Screen const& scr);
		Screen & operator=(Screen const& scr);
		~Screen();

		WINDOW *getWin() const;
		int getWidth() const;
		int getHeight() const;
		void drawShip(Ship const& ship);
		void drawBullets(Bullet **bullets);
		void drawEnemies(Enemy **enemies);
		void clearPosition(int x, int y);
		void gameOver();

	private:

		WINDOW *_win;

		int _w;
		int _h;

		void _hello();
		void _startGame();
};

#endif
