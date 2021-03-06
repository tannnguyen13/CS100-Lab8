#ifndef __ADD_HPP__
#define __ADD_HPP__

#include "base.hpp"
#include "iterator.hpp"
#include <string>

class Add : public Base {
	private:
		double value;
		std::string expression = "";

		Base* right;
		Base* left;
	public:
		Add(Base* base1, Base* base2) : Base() {
			right = base2;
			left = base1;	 
			value = base1->evaluate() + base2->evaluate();
			expression = base1->stringify() + " + " + base2->stringify();
		}
		virtual double evaluate() { return value;}
		virtual std::string stringify() { return expression;}

		virtual Base* get_right() { return right;}
		virtual Base* get_left() { return left;}
		virtual void accept(CountVisitor* cv) {return cv->visit_add();}
		virtual Iterator* create_iterator() {return new BinaryIterator(this);}
};

#endif //__ADD_HPP__
