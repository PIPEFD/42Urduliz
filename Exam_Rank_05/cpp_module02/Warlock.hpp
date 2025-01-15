#ifndef WARLOCK_HPP
#define WARLOCK_HPP

#include <iostream>
#include <string>
#include "ATarget.hpp"
#include "ASpell.hpp"
#include "SpellBook.hpp"

class Warlock
{
    private:
        std::string _name;
        std::string _title;
        SpellBook _SpellBook;
        Warlock();
        Warlock(Warlock const &other);
        Warlock &operator=(Warlock const &rhs);
    public:
        Warlock(std::string const &name, std::string const &title);
        ~Warlock();

        void	setTitle(std::string const & newTitle);
        std::string const &getName() const;
        std::string const &getTitle() const;
        void introduce();

        void learnSpell(ASpell *spell);
        void forgetSpell(std::string &SpellName);
        void launchSpell(std::string SpellName, ATarget const &target);
};
#endif