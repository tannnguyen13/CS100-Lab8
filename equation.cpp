#ifndef __EQUATION_CPP__
#define __EQUATION_CPP__

#include <iostream>
#include "base.hpp"
#include "add.hpp"
#include "sub.hpp"
#include "mult.hpp"
#include "div.hpp"
#include "pow.hpp"
#include "rand.hpp"
#include "op.hpp"
using namespace std;
class Equation {
	public:	
		Base* parse(char** input, int length) {
			int k = 0;
			int total = 0;
			while(isdigit(input[1][k])) {
				if(k > 0)
					total *= 10;
				total += input[1][k]-48;
				k++;
			}
			Base *temp = new Op(total);
			for(unsigned int i = 2; i < length;i++) {
				k = 0;
				total = 0;
				if(input[i][0] == '+') {
					while(isdigit(input[i+1][k])) {
						if(k > 0)
							total *= 10;
						total += input[i+1][k] - 48;
						k++;
					}
					Base* temp2 = new Op(total);
					temp = new Add(temp, temp2);
					i++;
				}
				else if(input[i][0] == '-') {
					while(isdigit(input[i+1][k])) {
						if(k > 0)
							total *= 10;
						total += input[i+1][k] - 48;
						k++;
					}	
					Base* temp2 = new Op(total);
					temp = new Sub(temp, temp2);
					i++;
				}
				else if(input[i][0] == '/') {
					while(isdigit(input[i+1][k])) {
						if(k > 0)
							total *= 10;
						total += input[i+1][k] - 48;
						k++;
					}
					Base* temp2 = new Op(total);
					temp = new Div(temp, temp2);
					i++;
				}
				else if(input[i][0] == '*' && input[i][1] == '*') {
					while(isdigit(input[i+1][k])) {
						if(k > 0)
							total *= 10;
						total += input[i+1][k] - 48;
						k++;
					}
					Base* temp2 = new Op(total);
					temp = new Pow(temp, temp2);
					i++;
				}
				else if(input[i][0] == '*') {
					while(isdigit(input[i+1][k])) {
						if(k > 0)
							total *= 10;
						total += input[i+1][k] - 48;
						k++;
					}
					Base* temp2 = new Op(total);
					temp = new Mult(temp, temp2);
					i++;
				}
				else if(isdigit(input[i][0])) {}
				else {
					std::cout << "Invalid Input" << endl;
					delete temp;
					temp = nullptr;
					return temp;
				}	
			}
			return temp;
		}
};

#endif
