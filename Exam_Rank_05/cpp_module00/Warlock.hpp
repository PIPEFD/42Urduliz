#ifndef WARLOCK_HPP
#define WARLOCK_HPP

#include <iostream>
#include <string>
class Warlock
{
    private:
        std::string _name;
        std::string _title;
        Warlock();
        Warlock &operator=(const Warlock &rhs);
        Warlock(const Warlock &other);
    public:
        Warlock (const std::string &title, const std::string &name);
        void setTitle(const std::string &newTitle);
        const std::string &getName() const;
        const std::string &getTitle() const;
        void introduce() const;
        ~Warlock();
};
        
#endif