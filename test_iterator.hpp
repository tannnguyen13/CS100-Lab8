#ifndef __TEST_ITERATOR_HPP__
#define __TEST_ITERATOR_HPP__

#include "gtest/gtest.h"
#include "add.hpp"
#include "iterator.hpp"
//#include "binary_iterator.cpp"
#include "preorder_iterator.cpp"
#include "sub.hpp"
#include "op.hpp"
#include <vector>

using namespace std;
TEST(IterTest, Regular) {
	vector<Base*> vec;
	Op* three = new Op(3);
	Op* two = new Op(2);
	Add* add1 = new Add(three, two);
	Iterator* it = new PreorderIterator(add1);
	it->first();
	while(!it->is_done()) {
		vec.push_back(it->current());
		it->next();
	}
	ASSERT_EQ(vec.size(), 2);
	EXPECT_EQ(vec.at(0)->evaluate(), 3);
	EXPECT_EQ(vec.at(1)->evaluate(), 2);	
}

#endif
