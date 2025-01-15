#ifndef ASPELL_HPP
#define ASPELL_HPP

#include "ATarget.hpp"
#include <iostream>
#include <string>
class ATarget;

class ASpell
{
    private:
        std::string _name;
        std::string _effects;
        
    public:
        ASpell(std::string name, std::string effects);
        ASpell(const ASpell &other);
        ASpell &operator=(const ASpell &rhs);
        virtual ~ASpell();

        std::string getName() const;
        std::string getEffects() const;
        virtual ASpell *clone() const = 0;
        void launch(ATarget const &target) const;


     
};
#endif