/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Screen.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abodnar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 15:31:28 by abodnar           #+#    #+#             */
/*   Updated: 2018/04/07 15:31:29 by abodnar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Screen.class.hpp"

Screen::Screen() {

	struct winsize w = Game::getWindowSize();
	this->_w = w.ws_col;
	this->_h = w.ws_row;


	initscr();
	timeout(0);
	nodelay(stdscr, true);
	noecho();
	cbreak();
	curs_set(FALSE);
	start_color();
	this->_win = newwin(0, 0, 0, 0);
	box(this->_win, 0, 0);

	refresh();
	wrefresh(this->_win);

	keypad(this->_win, true);
	nodelay(this->_win, true);

	this->_hello();

}

Screen::Screen(Screen const& scr) {

	if (this != &scr) {

		*this = scr;
	}
}

Screen& Screen::operator=(Screen const& scr) {

	this->_win = scr.getWin();
	this->_w = scr.getWidth();
	this->_h = scr.getHeight();

	return *this;
}


Screen::~Screen() {

	endwin();
}

void Screen::_hello() {

	std::string helloText = "Hello, it's our wonderful game!";

	wmove(this->_win, this->_h / 2, this->_w / 2 - helloText.length() / 2);
	wprintw(this->_win, "Hello, it's our wonderful game!");
	REFRESH;

	sleep(1);

	wmove(this->_win, this->_h / 2, this->_w / 2 - helloText.length() / 2);
	for (int i = 0; i < (int)helloText.length(); i++) {

		wprintw(this->_win, " ");
	}
	wrefresh(this->_win);

	this->_startGame();
}

void Screen::drawShip(Ship const& ship) {

	wmove(this->_win, ship.getPrevY(), ship.getPrevX());
	wprintw(this->_win, " ");
//	REFRESH;

	wmove(this->_win, ship.getPosY(), ship.getPosX());
	wprintw(this->_win, "}");

	box(this->_win, 0, 0);

	REFRESH;
}

void Screen::drawBullets(Bullet **bullets) {

	for (int i = 0; i < MAXBULLETS; i++) {

		if (bullets[i] != NULL) {

			if (bullets[i]->getPosX() != (this->_w - 8)) {

				mvwprintw(this->_win, bullets[i]->getPrevY(), bullets[i]->getPrevX(), " ");
				mvwprintw(this->_win, bullets[i]->getPosY(), bullets[i]->getPosX(), "-");
			}
			else {

				mvwprintw(this->_win, bullets[i]->getPosY(), bullets[i]->getPosX(), " ");
			}

		}
		REFRESH;
	}
}

void Screen::drawEnemies(Enemy **enemies) {

	for (int i = 0; i < MAXENEMIES; i++) {

		if (enemies[i] != NULL) {

			if (enemies[i]->getPosX() != 2) {

				mvwprintw(this->_win, enemies[i]->getPrevY(), enemies[i]->getPrevX(), " ");
				mvwprintw(this->_win, enemies[i]->getPosY(), enemies[i]->getPosX(), "*");
			}
			else {

				mvwprintw(this->_win, enemies[i]->getPosY(), enemies[i]->getPosX(), " ");
			}

		}
		REFRESH;
	}
}

void Screen::clearPosition(int x, int y) {

	mvwprintw(this->_win, y, x, " ");
	REFRESH;
}

void Screen::_startGame() {


	wmove(this->_win, 3, 1);
	for (int i = 0; i < this->_w - 2; i++) {
		wprintw(this->_win, "_");
	}
	REFRESH;

}

void Screen::gameOver() {

	std::string helloText = "GAME OVER!";

	wclear(this->_win);
	box(this->_win, 0, 0);
	wmove(this->_win, this->_h / 2, this->_w / 2 - helloText.length() / 2);
	wprintw(this->_win, "GAME OVER!");
	REFRESH;

	sleep(3);

	wmove(this->_win, this->_h / 2, this->_w / 2 - helloText.length() / 2);
	for (int i = 0; i < (int) helloText.length(); i++) {

		wprintw(this->_win, " ");
	}
	wrefresh(this->_win);

}

WINDOW *Screen::getWin() const {
	
	return this->_win;
}

int Screen::getWidth() const {
	
	return this->_w;
}

int Screen::getHeight() const {
	
	return this->_h;
}
