//---------------------------------
//! @file stacktest.cpp
//! Implements a stack class tests
//!
//! @author Tyunyakov Victor, 2017
//---------------------------------

#include <cstddef>
#include <cassert>
#include <iostream>

#include "stack.h"

//---------------------------------
//! Macro to get name of object
//! @param a the object
//---------------------------------
#define NAME(a) #a

//---------------------------------
//! Macro to test
//! @param what is the object to test
//! @param test_case is what test to run
//---------------------------------
#define TEST(what, test_case) \
    std::cout << "Processing test " << NAME(test_case) << " at object " << NAME(what) << std::endl; \
    test_case(); \
    std::cout << "Test SUCCESS!" << std::endl;

//---------------------------------
//! Macro to test whether left hand standing expression equals right hand standing
//! @param lhs left hand standing expression
//! @param rhs right hand standing expression
//---------------------------------
#define ASSERT_EQ( lhs, rhs) \
    std::cout << "Assertion equal between values " << lhs << " and " << rhs << std::endl; \
    if ((rhs) != (lhs)) { \
        assert(!"Assertion equal FAILED!"); \
    }

void PushSingleNumber();
void CannotPushMore();
void TopFromEmptyStack();
void PopFromEmptyStack();
void PrintTest();
void DumpTest();

int main() {
    TEST (Stack, PushSingleNumber);
    TEST (Stack, CannotPushMore);
    TEST (Stack, TopFromEmptyStack);
    TEST (Stack, PopFromEmptyStack);
    TEST (Stack, PrintTest);
    TEST (Stack, DumpTest);
    return 0;
}

void PushSingleNumber() {
    Stack s;
    s.push(3802);
    ASSERT_EQ(s.top(), 0xEDA);
    s.pop();
    ASSERT_EQ(s.size(), 0);
}

void CannotPushMore() {
   Stack s;
   for (std::size_t i = 0; i < s.capacity(); i++) {
       s.push(100 + i);
   }
   ASSERT_EQ (s.push (0xF00D), false);
}

void TopFromEmptyStack() {
    Stack s;
    Stack::value_type a = s.top();
}

void PopFromEmptyStack() {
    Stack s;
    s.pop();
}

void PrintTest() {
    Stack s;
    s.push(5.0f);
    s.push(6.0f);
    std::cout << s.to_string() << std::endl;
}

void DumpTest() {
    Stack s;
    s.push(5.0f);
    s.push(6.0f);
    s.dump();
    s.dump();
}
