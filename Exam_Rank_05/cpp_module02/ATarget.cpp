
#include "ATarget.hpp"

ATarget::ATarget()
{

}
ATarget::ATarget(std::string type) : _type(type)
{

}
ATarget::ATarget (const ATarget &other)
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
    
    std::cout << _type << " has been " << spell.getEffects() << "!" << std::endl;

}

