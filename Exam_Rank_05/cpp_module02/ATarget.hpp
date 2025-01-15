#ifndef ATARGET_HPP
#define ATARGET_HPP

#include "ASpell.hpp"
#include <iostream>
#include <string>
class ASpell;

class ATarget
{
    private:
        std::string _type;
        
    public:
        ATarget(const std::string type);
        ATarget(const ATarget &other);
        ATarget &operator=(const ATarget &rhs);
        virtual ~ATarget();

        std::string getType() const;
        virtual ATarget *clone() const = 0;
        void getHitBySpell(ASpell const &spell) const;

     
};
#endif