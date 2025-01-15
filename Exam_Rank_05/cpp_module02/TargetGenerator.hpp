#ifndef TARGETGENERATOR_HPP
#define TARGETGENERATOR_HPP

#include "ATarget.hpp"
#include <map>
class TargetGenerator
{
    private:
    TargetGenerator(const TargetGenerator &other);
    TargetGenerator &operator=(const TargetGenerator &rhs);
    std::map < std::string, ATarget*> _target;

    public:
    TargetGenerator();
    ~TargetGenerator();

    void learnTargetType(ATarget*);
    void forgetTargetType(std::string const &);
    ATarget *createTarget(std::string const &);
};

#endif