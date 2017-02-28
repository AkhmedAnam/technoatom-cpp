//------------------------------------
//! @file Stack.h
//! Implements a stack class
//!
//! @author Victor Tyunyakov, 2017
//------------------------------------

//------------------------------------
//! Stack class
//------------------------------------

#ifndef STACK_H
#define STACK_H


class Stack
{
public:
    typedef float value_type; //!< Elements type

    Stack();
    ~Stack();


    size_t capacity() const;
    //------------------------------------------
    //! Returns size of stack
    //! @return size of stack
    //------------------------------------------
    size_t size() const;

    //------------------------------------------
    //! Checks if the stack has no elements
    //! @return true if stack is empty, false otherwise
    //------------------------------------------
    bool empty() const;

    value_type top() const;

    //------------------------------------------
    //! Get an
    //------------------------------------------
    value_type pop();

    //------------------------------------------
    //! Pushes a value to the stack
    //! @param value is an element to be pushed
    //! @return success of operation
    //------------------------------------------
    bool push(const value_type value);



private:
    static const size_t m_capacity = 6;
    size_t m_size;
    value_type m_data[capacity];


};

#endif // STACK_H
