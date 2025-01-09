#ifndef ATARGET_HPP
#define ATARGET_HPP

#include "ASpell.hpp"
class ASpell;


class ATarget
{
    protected:
        std::string _type;
    public:
        ATarget(std::string type);
        ATarget &operator=(const ATarget &rhs);
        ATarget (const ATarget &other);
        virtual ~ATarget();
        std::string getType() const;
        virtual ATarget *clone() const = 0;
        void getHitBySpell(ASpell const &spell) const;

};

#endif