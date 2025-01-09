#ifndef WARLOCK_HPP

#define WARLOCK_HPP
#include <iostream>

#include "ASpell.hpp"

class Warlock
{
    private:
        std::string _name;
        std::string _title;
        std::map < std::string, ASpell *> _SpellBook;


        Warlock();
        Warlock &operator=(const Warlock &rhs);
        Warlock (const Warlock &other);

        public:
            Warlock(const std::string &name, const std::string &title);

            void setTitle(const std::string &newTitle);

            std::string const &getName() const;
            std::string const &getTitle() const;

            void introduce() const;

            void learnSpell(ASpell *spell);
            void forgetSpell(std::string SpellName);
            void launchSpell(std::string SpellName, ATarget const &target);
            ~Warlock();
};

#endif