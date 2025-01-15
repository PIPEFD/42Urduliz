/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BrickWall.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipe <pipe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 01:37:33 by pipe              #+#    #+#             */
/*   Updated: 2025/01/10 01:42:49 by pipe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BrickWall.hpp"

BrickWall() :ATarget("Inconspicuous Red-brick Wall")
{
    
}

~BrickWall()
{
    
}
*Atarget BrickWall::clone() const
{
    return(new BrickWall());
}