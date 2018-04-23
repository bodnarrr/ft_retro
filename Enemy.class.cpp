/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abodnar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/08 20:21:23 by abodnar           #+#    #+#             */
/*   Updated: 2018/04/08 20:21:24 by abodnar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Enemy.class.hpp"

Enemy::Enemy() : _posX(0), _posY(0), _prevX(0), _prevY(0) {

}

Enemy::Enemy(int x, int y): _prevX(0), _prevY(0) {

	this->_posX = x;
	this->_posY = y;
}

Enemy::Enemy(Enemy const &obj) {

	if (this != &obj) {

		*this = obj;
	}
}

Enemy& Enemy::operator=(Enemy const& obj) {

	this->_prevY = obj.getPrevY();
	this->_prevX = obj.getPrevX();
	this->_posX = obj.getPosX();
	this->_posY = obj.getPosY();

	return *this;
}

Enemy::~Enemy() {

}

bool Enemy::move() {

	if (this->_posX > 2) {

		this->_prevY = this->_posY;
		this->_prevX = this->_posX;
		this->_posX--;
		return true;
	}
	return false;

}

int Enemy::getPosX() const {
	return _posX;
}

int Enemy::getPosY() const {
	return _posY;
}

int Enemy::getPrevX() const {
	return _prevX;
}

int Enemy::getPrevY() const {
	return _prevY;
}
