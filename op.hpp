#ifndef __OP_HPP__
#define __OP_HPP__

#include "base.hpp"
#include <string>
#include <sstream>
#include <iomanip>
#include <limits>

class Op : public Base {
    public:
        Op(double value) : Base() { 
		opVal = value;
		number << std::fixed << std::setprecision(1) << value;
	}
        virtual double evaluate() { return opVal; }
        virtual std::string stringify() { return number.str(); }
   private:
	double opVal;
	std::stringstream number;
};

#endif //__OP_HPP__
