/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abodnar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/08 20:21:27 by abodnar           #+#    #+#             */
/*   Updated: 2018/04/08 20:21:28 by abodnar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_CLASS_HPP

# define ENEMY_CLASS_HPP

class Enemy {

public:

	Enemy();
	Enemy(int x, int y);
	Enemy(Enemy const& obj);
	Enemy& operator=(Enemy const& obj);
	~Enemy();

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


};


#endif
