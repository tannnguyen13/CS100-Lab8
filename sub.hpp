#ifndef __SUB_HPP__
#define __SUB_HPP__

#include "base.hpp"
#include <string>

class Sub : public Base {
	private:
		double value;
		std::string expression;
	public:
		Sub(Base* base1, Base* base2) : Base() {
			value = base1->evaluate() - base2->evaluate();
			expression = base1->stringify() + " - " + base2->stringify();
		}
		virtual double evaluate() { return value;}
		virtual std::string stringify() { return expression;}
};

#endif //__SUB_HPP__
