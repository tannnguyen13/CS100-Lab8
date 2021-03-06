#ifndef __OP_HPP__
#define __OP_HPP__

#include "base.hpp"
#include "iterator.hpp"
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

	virtual Base* get_right() { return nullptr; }
	virtual Base* get_left() { return nullptr; }

	virtual void accept(CountVisitor* cv) {return cv->visit_op();}
        virtual Iterator* create_iterator() {return new NullIterator(this);}	
   private:
	double opVal;
	std::stringstream number;

};

#endif //__OP_HPP__
