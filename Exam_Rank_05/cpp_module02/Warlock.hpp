#ifndef WARLOCK_HPP
#define WARLOCK_HPP

#include <iostream>
#include <string>
#include <map>
#include "ASpell.hpp"
#include "ATarget.hpp"
#include "SpellBook.hpp"
class Warlock
{
    private:
        std::string _name;
        std::string _title;

        
        SpellBook _SpellBook;
        Warlock();
        Warlock &operator=(const Warlock &rhs);
        Warlock(const Warlock &other);
    public:
        Warlock (const std::string &title, const std::string &name);
        void setTitle(const std::string &newTitle);
        const std::string &getName() const;
        const std::string &getTitle() const;
        void introduce() const;

        void learnSpell(ASpell *spell);
        void forgetSpell(std::string spellname);
        void launchSpell(std::string spellName, ATarget const &target);

        ~Warlock();
};
        
#endif