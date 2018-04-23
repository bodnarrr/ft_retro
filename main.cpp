/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abodnar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 13:04:48 by abodnar           #+#    #+#             */
/*   Updated: 2018/04/07 13:04:49 by abodnar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ship.class.hpp"
#include "Screen.class.hpp"
#include "EnemyGen.class.hpp"

int main() {

	Screen screen;
	Ship ship;
	int i = 0;

	Bullet *bullets[MAXBULLETS];
	bzero(bullets, sizeof(Bullet*) * MAXBULLETS);

	Enemy *enemies[MAXENEMIES];
	bzero(enemies, sizeof(Enemy*) * MAXENEMIES);

	EnemyGen enemyGen;
	bool areEnemies = false;

	std::srand(std::time(NULL));

	int key = 0;

	while (key != 27 && ship.isAlive()) {

		screen.drawShip(ship);
		screen.drawBullets(bullets);
		screen.drawEnemies(enemies);

		ship.checkCollisions(enemies);

		for (int i = 0; i < MAXENEMIES; i++) {

			if (enemies[i] != NULL) {

				for (int j = 0; j < MAXBULLETS; j++) {

					if (bullets[j] != NULL &&
						enemies[i]->getPosX() == bullets[j]->getPosX() &&
						enemies[i]->getPosY() == bullets[j]->getPosY()
						) {

						screen.clearPosition(enemies[i]->getPosX(), enemies[i]->getPosY());
						delete bullets[j];
						bullets[j] = NULL;
						delete enemies[i];
						enemies[i] = NULL;
						break;

					}
				}
			}

		}

		/*
		 * 	Moving bullets
		 */

		for (int j = 0; j < MAXBULLETS; j++) {

			if (bullets[j] != NULL) {

				if (bullets[j]->move() == false) {

					screen.clearPosition(bullets[j]->getPrevX(), bullets[j]->getPrevY());
					screen.clearPosition(bullets[j]->getPosX(), bullets[j]->getPosY());

					delete bullets[j];
					bullets[j] = NULL;
				}
			}
		}


		/*
		 * 	Moving enemies
		 */

		for (int k = 0; k < MAXENEMIES; k++) {

			if (enemies[k] != NULL) {

				if (enemies[k]->move() == false) {

					screen.clearPosition(enemies[k]->getPrevX(), enemies[k]->getPrevY());
					delete enemies[k];
					enemies[k] = NULL;
				}
			}
		}

		i = 0;
		while (i < MAXENEMIES) {

			if (enemies[i] == NULL)
				break;
			i++;
		}
		if (i != MAXENEMIES) {

			if (std::rand() % GEN < TOGEN)
				enemies[i] = enemyGen.generate(&areEnemies);
		}

		key = wgetch(screen.getWin());
		switch (key) {

			case 'w':
				ship.moveUp();
				break;

			case 's':
				ship.moveDown();
				break;

			case 'a':
				ship.moveLeft();
				break;

			case 'd':
				ship.moveRight();
				break;

			case 'm':

				i = 0;
				while (i < MAXBULLETS) {

					if (bullets[i] == NULL)
						break;
					i++;
				}
				if (i != MAXBULLETS) {

					bullets[i] = ship.shoot();
				}
				break;

			default:
				break;
		}
		usleep(DELAYSCREEN);

	}

	screen.gameOver();
	sleep(2);

	return 0;
}
