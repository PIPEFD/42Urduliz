/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ASpell.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipe <pipe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 03:08:24 by pipe              #+#    #+#             */
/*   Updated: 2025/01/09 04:38:17 by pipe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ASpell.hpp"

ASpell::ASpell(std::string name, std::string effects) : _name(name), _effects(effects)
{
    
}

ASpell::ASpell(const ASpell &other)
{
    *this = other;
}
ASpell &ASpell::operator=(ASpell const &rhs)
{
    _name = rhs.getName();
    _effects = rhs.getEffects();
    return (*this);
}
ASpell::~ASpell()
{
    
}
std::string ASpell::getName() const
{
    return (_name);
}

std::string ASpell::getEffects() const
{
    return (_effects);
}

void ASpell::launch(ATarget const &target) const
{
    target.getHitBySpell(*this);
}