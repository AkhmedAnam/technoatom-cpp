//------------------------------------
//! @file stack.h
//! Declaration of a stack class
//!
//! @author Victor Tyunyakov, 2017
//------------------------------------

//------------------------------------
//! Stack class
//------------------------------------

#ifndef STACK_H
#define STACK_H

#include <cstddef>
#include <string>

class Stack
{
public:
    typedef float value_type; //!< Elements type

    Stack();
    ~Stack();

    //------------------------------------------
    //! Returns the max number of elements to be stored in the stack
    //! @return the max possible number of elements in the stack
    //------------------------------------------
    std::size_t capacity() const;

    //------------------------------------------
    //! Returns the number of elements in the stack
    //! @return the number of elements in the stack
    //------------------------------------------
    std::size_t size() const;

    //------------------------------------------
    //! Checks if the stack has no elements
    //! @return true if stack is empty, false otherwise
    //------------------------------------------
    bool empty() const;

    //------------------------------------------
    //! Returns reference to the top element in the stack. This is the most recently pushed element.
    //! @return reference to the last element of stack. If stack is empty, returns NaN
    //------------------------------------------
    value_type top() const;

    //------------------------------------------
    //! Removes last element from the stack
    //------------------------------------------
    void pop();

    //------------------------------------------
    //! Pushes a value to the stack
    //! @param value is an element to be pushed
    //! @return success of operation
    //------------------------------------------
    bool push(const value_type value);

    //------------------------------------------
    //! Checks whether the stack is in its normal state, not broken.
    //! @return true if stack is ok, false otherwise
    //------------------------------------------
    bool ok() const;

    //------------------------------------------
    //! Assambles string representing all possible information about stack.
    //! @return string representation of stack object
    //------------------------------------------
    std::string to_string() const;

    //------------------------------------------
    //! Prints all possible stack information to the dump file.
    //------------------------------------------
    void dump() const;

private:
    static const std::size_t m_capacity = 6;
    static const std::size_t POISON_INT = m_capacity + 1;
    static const std::string dump_file;
    std::size_t m_size;
    value_type m_data[m_capacity];


};

#endif // STACK_H
