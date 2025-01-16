#ifndef ATARGET_HPP
#define ATARGET_HPP

#include "ASpell.hpp"
#include <string>
#include <iostream>
class ASpell;

class ATarget
{
    private:
        std::string _type;
    public:
        ATarget();
        ATarget(std::string type);
        ATarget (const ATarget &other);
        ATarget &operator=(const ATarget &rhs);
        virtual ~ATarget();
        virtual ATarget *clone() const = 0;
        std::string getType() const;
        void getHitBySpell(ASpell const &spell) const;


};

#endif