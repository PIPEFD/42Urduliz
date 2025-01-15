#include "Dummy.hpp"

Dummy::Dummy() : ATarget("")
{

}
        
Dummy::~Dummy()
{

}
ATarget* Dummy::clone() const
{
    return(new Dummy());
}