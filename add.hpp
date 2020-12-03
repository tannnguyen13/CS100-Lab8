#ifndef __ADD_HPP__
#define __ADD_HPP__

#include "base.hpp"
#include <string>

class Add : public Base {
	private:
		double value;
		std::string expression = "";
	public:
		Add(Base* base1, Base* base2) : Base() { 
			value = base1->evaluate() + base2->evaluate();
			expression = base1->stringify() + " + " + base2->stringify();
		}
		virtual double evaluate() { return value;}
		virtual std::string stringify() { return expression;}
};

#endif //__ADD_HPP__
