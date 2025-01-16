
#include "SpellBook.hpp"

SpellBook::SpellBook()
{

}
SpellBook::SpellBook (const SpellBook &other)
{
    *this = other;
}
SpellBook &SpellBook::operator=(const SpellBook &rhs)
{
    _SpellBook = rhs._SpellBook;
    return (*this);
}
SpellBook::~SpellBook()
{

}
void SpellBook::learnSpell(ASpell *spell)
{
    if (spell)
        _SpellBook[spell->getName()] = spell->clone();
}
void SpellBook::forgetSpell(std::string const &spellName)
{
    if (_SpellBook.find(spellName) != _SpellBook.end())
        _SpellBook.erase(_SpellBook.find(spellName));
}
ASpell *SpellBook::createSpell(std::string const &spellName)
{
    ASpell *tmp = NULL;
    if (_SpellBook.find(spellName) != _SpellBook.end())
        tmp = _SpellBook[spellName];
    return(tmp);
        
}

