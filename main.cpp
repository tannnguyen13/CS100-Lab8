#include "base.hpp"
#include "equation.cpp"
#include "add.hpp"
#include "visitor.hpp"
#include "mult.hpp"
#include "div.hpp"
#include "pow.hpp"
#include "rand.hpp"
#include "binary_iterator.cpp"
#include "preorder_iterator.cpp"
#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {

	Equation* build = new Equation();
	Base* b = build->parse(argv, argc);
	Rand* randNum = new Rand();
	Add* dummy = new Add(b, randNum);
	CountVisitor* cv =  new CountVisitor();
	Iterator* it = new PreorderIterator(dummy);
	it->first();
	while(it->is_done() == false) {
		it->current()->accept(cv);
		it->next();
	}
	cout << "Ops: " << cv->op_count() << endl;
	cout << "Rands: " << cv->rand_count() << endl;
	cout << "Mults: " << cv->mult_count() << endl;
	cout << "Divs: " << cv->div_count() << endl;
	cout << "Add: " << cv->add_count() << endl;
	cout << "Subs: " << cv->sub_count() << endl;
	cout << "Pow: " << cv->pow_count() << endl;
	return 0;
}
	  
