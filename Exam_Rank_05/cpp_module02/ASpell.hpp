#ifndef ASPELL_HPP
#define ASPELL_HPP

#include "ATarget.hpp"
#include <string>
#include <iostream>
class ATarget;

class ASpell
{
    private:
        std::string _name;
        std::string _effects;
    public:
        ASpell();
        ASpell(std::string name, std::string effects);
        ASpell (const ASpell &other);
        ASpell &operator=(const ASpell &rhs);
        virtual ~ASpell();

        virtual ASpell* clone() const = 0;
        std::string getName() const;
        std::string getEffects() const;
        void launch(ATarget const &target) const;


};

#endif