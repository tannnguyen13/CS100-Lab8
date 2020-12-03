#ifndef __POW_HPP__
#define __POW_HPP__

#include "base.hpp"
#include <string>
#include <math.h>

class Pow : public Base {
	private:
		double value;
		std::string expression;
	public:
		Pow(Base* base1, Base* base2) : Base() {
			value = pow((base1->evaluate()),(base2->evaluate()));
			expression = base1->stringify() + " ** " + base2->stringify();
		}
		virtual double evaluate() { return value;}
		virtual std::string stringify() { return expression;}
};

#endif //__MULT_HPP__
