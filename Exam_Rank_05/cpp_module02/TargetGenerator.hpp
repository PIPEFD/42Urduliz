#ifndef TARGETGENERATOR_HPP
#define TARGETGENERATOR_HPP


#include "ATarget.hpp"
#include <map>
class TargetGenerator
{
    private:
        std::map <std::string, ATarget*> _target;
        TargetGenerator &operator=(const TargetGenerator &rhs);
        TargetGenerator(const TargetGenerator &other);
    public:
        TargetGenerator();
        ~TargetGenerator();

        void learnTargetType(ATarget *);
        void forgetTargetType(std::string const &);
        ATarget *createTarget(std::string const &);

};
#endif