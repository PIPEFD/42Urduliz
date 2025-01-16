#include "Warlock.hpp"

Warlock::Warlock(const std::string &name,  const std::string &title) : _name(name), _title(title)
{
    std::cout << _name << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock()
{
    std::cout << _name << ": My job here is done!" << std::endl;

}

void Warlock::setTitle(const std::string &newTitle)
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

void Warlock::introduce()const
{
    std::cout << _name << ": I am " << _name << ", " << _title << "!" << std::endl;
}

void Warlock::learnSpell(ASpell *spell)
{
    _SpellBook.learnSpell(spell);
    
}
void Warlock::forgetSpell(std::string spellname)
{
    _SpellBook.forgetSpell(spellname);
}
void Warlock::launchSpell(std::string spellName, ATarget const &target)
{
    if (_SpellBook.createSpell(spellName))
    {
        _SpellBook.createSpell(spellName)->launch(target);
    }

}