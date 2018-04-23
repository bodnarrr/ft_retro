/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EnemyGen.class.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abodnar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/08 21:08:57 by abodnar           #+#    #+#             */
/*   Updated: 2018/04/08 21:08:57 by abodnar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_GEN_CLASS_HPP

# define ENEMY_GEN_CLASS_HPP
# include "Enemy.class.hpp"
# include <cstdlib>

class EnemyGen {

	public:

		EnemyGen();
		EnemyGen(EnemyGen const& obj);
		EnemyGen& operator=(EnemyGen const& obj);
		~EnemyGen();

		int getWidth() const;
		int getHeight() const;

		Enemy *generate(bool *areEnemies);

	private:

		int _w;
		int _h;
};

#endif
