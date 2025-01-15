#include "Fireball.hpp"

Fireball::Fireball() : ASpell("fuego", " ")
{

}
        
Fireball::~Fireball()
{

}
ASpell* Fireball::clone() const
{
    return(new Fireball());
}