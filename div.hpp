#ifndef __DIV_HPP__
#define __DIV_HPP__

#include "base.hpp"
#include <string>

class Div : public Base {
	private:
		double value;
		std::string expression;

		Base* right;
		Base* left;
	public:
		Div(Base* base1, Base* base2) : Base() {
			right = base2;
			right = base1
			value = base1->evaluate() / base2->evaluate();
			expression = base1->stringify() + " / " + base2->stringify();
		}
		virtual double evaluate() { return value;}
		virtual std::string stringify() { return expression;}
		virtual Base* get_right() { return right;}
		virtual Base* get_left() { return left;}
};

#endif //__DIV_HPP__
