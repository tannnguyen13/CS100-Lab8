#ifndef __TEST_ITERATOR_HPP__
#define __TEST_ITERATOR_HPP__

#include "gtest/gtest.h"
#include "add.hpp"
#include "iterator.hpp"
#include "binary_iterator.cpp"
#include "preorder_iterator.cpp"
#include "sub.hpp"
#include "base.hpp"
#include "mult.hpp"
#include "pow.hpp"
#include "op.hpp"
#include <vector>
#include "div.hpp"

using namespace std;
TEST(IterTest, AddTest) {
	Op* three = new Op(3);
	Op* two = new Op(2);
	
	Add* temp1 = new Add(three, two);
	Add* temp2 = new Add(three, two);
	Add* temp3 = new Add(temp1, temp2);

	CountVisitor *temp = new CountVisitor();
	PreorderIterator *tempt = new PreorderIterator(temp3);

	tempt->first();
	while(tempt->is_done() == false) {
		tempt->current()->accept(temp);
		tempt->next();
	}
	EXPECT_EQ(temp->add_count(),2);
	EXPECT_EQ(temp->op_count(), 4);
}

TEST(IterTest, SubAndDivTest) {
        Op* three = new Op(3);
        Op* two = new Op(2);

        Sub* temp1 = new Sub(three, two);
        Div* temp2 = new Div(three, two);
        Add* temp3 = new Add(temp1, temp2);

        CountVisitor *temp = new CountVisitor();
        PreorderIterator *tempt = new PreorderIterator(temp3);

        tempt->first();
        while(tempt->is_done() == false) {
                tempt->current()->accept(temp);
                tempt->next();
        }
        EXPECT_EQ(temp->sub_count(),1);
	EXPECT_EQ(temp->div_count(),1);
        EXPECT_EQ(temp->op_count(), 4);
}

TEST(IterTest, MultAndPowTest) {
        Op* three = new Op(3);
        Op* two = new Op(2);

        Mult* temp1 = new Mult(three, two);
        Pow* temp2 = new Pow(three, two);
        Add* temp3 = new Add(temp1, temp2);

        CountVisitor *temp = new CountVisitor();
        PreorderIterator *tempt = new PreorderIterator(temp3);

        tempt->first();
        while(tempt->is_done() == false) {
                tempt->current()->accept(temp);
                tempt->next();
        }
        EXPECT_EQ(temp->pow_count(),1);
        EXPECT_EQ(temp->mult_count(),1);
        EXPECT_EQ(temp->op_count(), 4);
}

#endif
