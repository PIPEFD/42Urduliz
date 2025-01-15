#include "Fwoosh.hpp"

Fwoosh::Fwoosh() : ASpell("fuego", " ")
{

}
        
Fwoosh::~Fwoosh()
{

}
ASpell* Fwoosh::clone() const
{
    return(new Fwoosh());
}