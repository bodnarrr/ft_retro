/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EnemyGen.class.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abodnar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/08 21:08:36 by abodnar           #+#    #+#             */
/*   Updated: 2018/04/08 21:08:38 by abodnar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "EnemyGen.class.hpp"
#include "Game.class.hpp"
#include <iostream>

EnemyGen::EnemyGen() {

	struct winsize w = Game::getWindowSize();
	this->_w = w.ws_col;
	this->_h = w.ws_row;
}

EnemyGen::EnemyGen(EnemyGen const &obj) {

	if (this != &obj) {

		*this = obj;
	}
}

EnemyGen& EnemyGen::operator=(EnemyGen const &obj) {

	this->_h = obj.getHeight();
	this->_w = obj.getWidth();
	return *this;
}

EnemyGen::~EnemyGen() {

}

int EnemyGen::getHeight() const {

	return this->_h;
}

int EnemyGen::getWidth() const {

	return this->_w;
}

Enemy *EnemyGen::generate(bool *areEnemies){

	Enemy *ret;
	int y = std::rand() % this->_h;

	if (y > 4 && y < this->_h - 2) {

		ret = new Enemy(this->_w - 4, y);
		*areEnemies = true;
		return ret;
	}
	return NULL;

}
