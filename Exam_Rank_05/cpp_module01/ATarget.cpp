/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ATarget.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipe <pipe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 03:06:39 by pipe              #+#    #+#             */
/*   Updated: 2025/01/09 04:38:47 by pipe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ATarget.hpp"

ATarget::ATarget(std::string type) : _type(type)
{
    
}
ATarget::ATarget(const ATarget &other)
{
    *this = other;
}

ATarget &ATarget::operator=(const ATarget &rhs)
{
    _type = rhs.getType();
    return (*this);
}
ATarget::~ATarget()
{
    
}

std::string ATarget::getType() const
{
    return (_type);
}

void ATarget::getHitBySpell(ASpell const &spell) const
{
    std::cout << _type << " has been" << spell.getEffects() << "!" << std::endl;
}