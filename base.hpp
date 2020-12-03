#ifndef __BASE_HPP__
#define __BASE_HPP__

#include <string>
#include "iterator.hpp"

class Base {
    public:
        /* Constructors */
        Base() { };

        /* Pure Virtual Functions */
	virtual Iterator* create_iterator() = 0;
	virtual Base* get_left() = 0;
	virtual Base* get_right() = 0;
        virtual double evaluate() = 0;
        virtual std::string stringify() = 0;
};

#endif //__BASE_HPP__
