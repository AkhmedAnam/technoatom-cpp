//---------------------------------
//! @file stacktest.cpp
//! Implements a stack class tests
//!
//! @author Tyunyakov Victor, 2017
//---------------------------------

#include "Stack.h"

//---------------------------------
//! Macro to test
//! @param what is the object to test
//! @param case is what test to run
//---------------------------------

#define TEST( what, case ) \
    printf("Processing test %s at object %s", case, what);

int main() {
    TEST (Stack, PushSingleNumber) {
        Stack s;
        s.push(3802);
        ASSERT_EQ (s.pop() == 0xEDA);
        ASSERT_EQ (s.size() == 0);
    }

    TEST (Stack, CannotPushMore) {
        Stack s;
        for (int i = 0; i < s.capacity(); i++) {
            s.push(100 + i);
        }
        ASSERT_EQ (s.push (0xF00D) == false);
    }

    TEST (Stack, PopFromEmptyStack) {
        Stack s;
        Stack::value_type a == s.pop();
    }

    return 0;
}
