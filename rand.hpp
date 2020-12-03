#ifndef __RAND_HPP__
#define __RAND_HPP__

#include "base.hpp"
#include <cstdlib>
#include <string>

class Rand : public Base {
	private:
		double randVal;
	public:
		Rand(): Base() {randVal = rand() % 100;}
		virtual double evaluate() {return randVal;}
		virtual std::string stringify() {return std::to_string(randVal);}
		
		virtual Base* get_right() { return nullptr;}
		virtual Base* get_left() {return nullptr;}

		virtual void accept(CountVisitor cv) {return cv->visit_rand();}
                virtual Iterator* create_iterator() {return new NullIterator(this);}	
};

#endif //__RAND_HPP__
