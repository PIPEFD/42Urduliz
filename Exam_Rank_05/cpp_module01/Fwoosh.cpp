/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fwoosh.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipe <pipe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 03:36:02 by pipe              #+#    #+#             */
/*   Updated: 2025/01/09 04:19:15 by pipe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fwoosh.hpp"

Fwoosh::Fwoosh( ) : ASpell("Fwoosh", "fwooshed")
{
    
}

Fwoosh::~Fwoosh()
{
    
}

ASpell *Fwoosh::clone() const
{
    return(new Fwoosh());
}