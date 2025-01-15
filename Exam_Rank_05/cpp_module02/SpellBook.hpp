#ifndef SPELLBOOK_HPP
#define SPELLBOOK_HPP

#include "ASpell.hpp"
#include <map>
class SpellBook
{
    private:
        SpellBook(const SpellBook &other);
        SpellBook &operator=(SpellBook const &rhs);
        std::map < std::string, ASpell*> _SpellBook;
    public:
        SpellBook();
        ~SpellBook();

        void learnSpell(ASpell*);
        void forgetSpell(std::string const &);
        ASpell *createSpell(std::string const &);
        

};

#endif