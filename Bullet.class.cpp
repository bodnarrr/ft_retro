/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bullet.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abodnar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/08 00:15:51 by abodnar           #+#    #+#             */
/*   Updated: 2018/04/08 00:15:52 by abodnar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bullet.class.hpp"

Bullet::Bullet() : _posX(0), _posY(0), _prevX(0), _prevY(0) {


}

Bullet::Bullet(int x, int y) : _prevX(0) {

	struct winsize w = Game::getWindowSize();
	this->_posY = y;
	this->_posX = x;
	this->_screenHeight = w.ws_row;
	this->_screenWidth = w.ws_col;
}

Bullet& Bullet::operator=(Bullet const& bullet) {

	this->_posX = bullet.getPosX();
	this->_posY = bullet.getPosY();
	this->_prevX = bullet.getPrevX();
	this->_prevY = bullet.getPrevY();

	return *this;
}

bool Bullet::move() {

	if (this->_posX < this->_screenWidth - 8) {

		this->_prevY = this->_posY;
		this->_prevX = this->_posX;
		this->_posX++;
		return true;
	}
	return false;

}


Bullet::~Bullet() {

}

int Bullet::getPosX() const {

	return this->_posX;
}

int Bullet::getPosY() const {

	return this->_posY;
}

int Bullet::getPrevX() const {

	return this->_prevX;
}

int Bullet::getPrevY() const {

	return this->_prevY;
}