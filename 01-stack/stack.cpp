//------------------------------------
//! @file stack.cpp
//! Definition of a stack class
//!
//! @author Victor Tyunyakov, 2017
//------------------------------------

//------------------------------------
//! Stack class
//------------------------------------
#include <fstream>
#include <sstream>
#include <cassert>
#include <iostream>
#include <iomanip>

#include "stack.h"


#define ASSERT_OK() \
    if(!ok()) { \
        dump(); \
        assert(!"Object is not ok!"); \
    }

const std::string Stack::m_dump_file = "stack_dump.txt";

Stack::Stack():
    m_size(0) {
    ASSERT_OK();
}

Stack::~Stack() {
    ASSERT_OK();
    m_size = POISON_INT;
}

std::size_t Stack::capacity() const
{
    ASSERT_OK();
    return m_capacity;
}

std::size_t Stack::size() const
{
    ASSERT_OK();
    return m_size;
}

bool Stack::empty() const
{
    ASSERT_OK();
    return m_size == 0;
}

Stack::value_type Stack::top() const
{
    ASSERT_OK();
    return m_data[m_size - 1];
}

void Stack::pop()
{
    ASSERT_OK();
    if (m_size > 0) {
        m_size--;
    }
    ASSERT_OK();
}

bool Stack::push(const Stack::value_type value)
{
    ASSERT_OK();
    if (m_size >= m_capacity) {
        ASSERT_OK();
        return false;
    }
    m_data[m_size++] = value;
    ASSERT_OK();
    return true;
}

std::string Stack::to_string() const
{
    ASSERT_OK();
    std::ostringstream oss;
    oss << "Stack (";
    std::string state = this->ok() ? "ok" : "ERROR";
    oss << state << ")\n";
    oss << "address: " << this << std::endl;
    oss << "{\n";
    oss << "\tsize     = " << m_size << std::endl;
    oss << "\tcapacity = " << m_capacity << std::endl;
    oss << "\tdata[" << m_capacity << "]:\n\t{\n";
    for (std::size_t i = 0; i < m_size; i++) {
        oss << "\t * [" << i << "] = " << m_data[i] << std::endl;
    }
    for (std::size_t i = m_size; i < m_capacity; i++) {
        oss << "\t   "
               "[" << i << "] = " << m_data[i] << " (TRASH)\n";
    }
    oss << "\t}\n}";
    ASSERT_OK();
    return oss.str();
}

bool Stack::ok() const {
    return m_size <= m_capacity;
}

void Stack::dump() const {
    std::ofstream dump_file;
    dump_file.open(m_dump_file, std::ios::app);
    if (dump_file.is_open()) {
        auto t = std::time(nullptr);
        auto tm = *std::localtime(&t);
        dump_file << "Dump Time: " << std::put_time(&tm, "%d.%m.%Y %H:%M:%S") << std::endl;
        dump_file << this->to_string() << std::endl;
        dump_file.close();
    } else {
        assert("Error occured while opening dump file!");
    }
}
