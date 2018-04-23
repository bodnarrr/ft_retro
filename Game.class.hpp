/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.class.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abodnar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 18:54:32 by abodnar           #+#    #+#             */
/*   Updated: 2018/04/07 18:54:32 by abodnar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_CLASS_HPP

# define GAME_CLASS_HPP
# include <sys/ioctl.h>
# include <unistd.h>

class Game {

public:

	static winsize getWindowSize();

};


#endif
