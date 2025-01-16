#ifndef SPELLBOOK_HPP
#define SPELLBOOK_HPP


#include "ASpell.hpp"
#include <map>
class SpellBook
{
    private:
        std::map <std::string, ASpell*> _SpellBook;
        SpellBook &operator=(const SpellBook &rhs);
        SpellBook(const SpellBook &other);
    public:
        SpellBook();
        ~SpellBook();

        void learnSpell(ASpell *spell);
        void forgetSpell(std::string const &);
        ASpell *createSpell(std::string const &);

};
#endif