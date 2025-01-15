#include "Warlock.hpp"

Warlock::Warlock()
{

}

Warlock::Warlock(const Warlock &other)
{
    *this = other;

}

Warlock::Warlock(std::string const &name, std::string const &title) : _name(name), _title(title)
{
    std::cout << "ENtra" << std::endl;
}
Warlock &Warlock::operator=(const Warlock &rhs)
{
    _title = rhs._title;
    _name = rhs._name;
    return(*this);
}

Warlock::~Warlock()
{

}

void Warlock::setTitle(std::string const & newTitle)
{
    _title = newTitle;
}

std::string const &Warlock::getName() const
{
    return(_name);   
}


std::string const &Warlock::getTitle() const
{
    return(_title);
}
void    Warlock::introduce()
{
    
}

void Warlock::learnSpell(ASpell *spell)
{
    _SpellBook.learnSpell(spell);
}

void Warlock::forgetSpell(std::string &spellName)
{
    _SpellBook.forgetSpell(spellName);
}

void Warlock::launchSpell(std::string spellName, ATarget const &target)
{
    if(_SpellBook.createSpell(spellName))
        _SpellBook.createSpell(spellName)->launch(target);
}