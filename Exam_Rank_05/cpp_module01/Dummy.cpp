/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dummy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipe <pipe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 03:48:55 by pipe              #+#    #+#             */
/*   Updated: 2025/01/09 04:15:31 by pipe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dummy.hpp"

Dummy::Dummy() : ATarget("Target Pratice Dummy")
{
    
}
Dummy::~Dummy()
{

}
ATarget *Dummy::clone() const
{
    return (new Dummy());
}