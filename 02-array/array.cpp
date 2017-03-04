#include <cstddef>
#include <cassert>
#include <stdexcept>

#include "array.h"
using namespace ava;

const std::string Array::OUT_OF_RANGE_EXC_TEXT = "Pos is more than size of the array!";

Array::Array(std::size_t size):
  m_size(size),
  m_data(new value_type[size]) {
}

Array::Array(const Array& that) {

}

Array::~Array() {
  delete[] m_data;
  m_data = nullptr;
}

//Perfoms copy-swap idiom
const Array& Array::operator=(const Array& other) {
	Array temp_arr(other);
	swap(*this, temp_arr);
	return *this;
}

Array::value_type& Array::operator[](const std::size_t pos) const {
  if (pos >= m_size) {
    throw std::out_of_range(OUT_OF_RANGE_EXC_TEXT);
  }
  return m_data[pos];
}

Array::value_type& Array::front() const {
  return m_data[0];
}

Array::value_type& Array::back() const {
  if (m_size > 0) {
    return m_data[m_size - 1];
  } else {
      return front();
  }
}

Array::value_type *Array::data() const {
  return &front();
}

bool Array::empty() const {
  return m_size == 0;
}

std::size_t Array::size() const {
  return m_size;
}

void Array::fill(const Array::value_type &value) {
  for (std::size_t i = 0; i < size(); i++) {
    m_data[i] = value;
  }
}
