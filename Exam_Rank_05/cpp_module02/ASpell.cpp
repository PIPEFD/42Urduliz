#include "ASpell.hpp"

ASpell::ASpell(std::string name, std::string effects) : _name(name), _effects(effects)
{

}

ASpell::ASpell(const ASpell &other)
{
    *this = other;
}
ASpell::~ASpell()
{

}
ASpell &ASpell::operator=(const ASpell &rhs)
{
    _name = rhs.getName();
    _effects = rhs.getEffects();

    return (*this);
}


std::string ASpell::getName() const
{
    return(_name);
}


std::string ASpell::getEffects() const
{
    return(_effects);
}

void ASpell::launch(ATarget const &target) const 
{
    target.getHitBySpell(*this);
}