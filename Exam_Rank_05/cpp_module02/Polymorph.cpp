#include "Polymorph.hpp"

Polymorph::Polymorph() : ASpell("fuego", " ")
{

}
        
Polymorph::~Polymorph()
{

}
ASpell* Polymorph::clone() const
{
    return(new Polymorph());
}