/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ship.class.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abodnar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 13:35:10 by abodnar           #+#    #+#             */
/*   Updated: 2018/04/07 13:35:10 by abodnar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ship.class.hpp"
#include "Screen.class.hpp"

Ship::Ship() : _posX(2), _prevX(0), _prevY(0), _points(0), _alive(true) {

	struct winsize w = Game::getWindowSize();
	this->_posY = w.ws_row / 2;
	this->_screenHeight = w.ws_row;
	this->_screenWidth = w.ws_col;

}

Ship::Ship (Ship const& obj) {

	if (this != &obj) {

		*this = obj;
	}
}

Ship& Ship::operator=(Ship const& obj) {

	_posX = obj.getPosX();
	_posY = obj.getPosY();
	_points = obj.getPoints();
	_alive = obj.isAlive();

	return *this;
}

Ship::~Ship() {

}

void Ship::moveUp() {

	if (this->_posY > 5) {

		this->_prevY = this->_posY;
		this->_prevX = this->_posX;
		this->_posY--;
	}
}
void Ship::moveDown() {

	if (this->_posY < this->_screenHeight - 3) {

		this->_prevY = this->_posY;
		this->_prevX = this->_posX;
		this->_posY++;
	}
}

void Ship::moveLeft() {

	if (this->_posX > 2) {

		this->_prevY = this->_posY;
		this->_prevX = this->_posX;
		this->_posX--;
	}
}

void Ship::moveRight() {

	if (this->_posX < this->_screenWidth - 10) {

		this->_prevY = this->_posY;
		this->_prevX = this->_posX;
		this->_posX++;
	}
}

void Ship::checkCollisions(Enemy **enemies) {

	for (int i = 0; i < MAXENEMIES; i++) {

		if(enemies[i] != NULL) {

			if (this->_posX == enemies[i]->getPosX() &&
				this->_posY == enemies[i]->getPosY()
				)
				this->_alive = false;
		}
	}
}

Bullet *Ship::shoot() {

	Bullet *res;
	res = new Bullet(this->_posX + 1, this->_posY);
	return res;
}


int Ship::getPosX() const {

	return _posX;
}

int Ship::getPosY() const {

	return _posY;
}

int Ship::getPrevX() const {

	return _prevX;
}

int Ship::getPrevY() const {

	return _prevY;
}

int Ship::getPoints() const {

	return _points;
}

bool Ship::isAlive() const {

	return _alive;
}
