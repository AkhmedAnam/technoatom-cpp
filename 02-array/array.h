#ifndef ARRAY_H
#define ARRAY_H

#include <string>

namespace ava {
class Array {
  public:
    typedef float value_type;

    explicit Array(std::size_t size);
    ~Array();
    Array(const Array& that) = delete;
    const Array& operator=(const Array& that) = delete;

    //! Returns a reference to the element at specified locationpos,
    //! with bounds checking.
    //! If pos is not within the range of the array,
    //! an exception of type std::out_of_range is thrown.
    //!
    //! @param pos is position of the element to return
    //! @return reference of the element to return
    value_type& operator[](const std::size_t pos) const;

    //! Returns a reference to the first element in the array.
    //! Calling front on an empty array is undefined.
    //!
    //! @return reference to the first element
    value_type& front() const;

    //! Returns a reference to the last element in the array.
    //! Calling back on an empty array is undefined.
    //!
    //! @return reference to the last element
    value_type& back() const;

    //! Returns pointer to the underlying array serving as element storage.
    //! The pointer is such that range
    //! [data(); data() + size()) is always a valid range,
    //! even if the array is empty
    //! (data() is not dereferenceable in that case).
    //!
    //! @return pointer to the underlying element storage
    value_type* data() const;

    //! Checks if the array has no elements.
    //!
    //! @return true if the array is empty, false otherwise
    bool empty() const;

    //! Returns the number of elements in the array.
    //!
    //! @return the number of elements in the array
    std::size_t size() const;

    //! Assigns the given value value to all elements in the array.
    //!
    //! @param value is the value to assign to the elements
    void fill(const value_type& value);

    //! Exchanges the contents of the array with those of other.
    //! Does not cause references to associate with the other array.
    //!
    //! @param that is array to exchange the contents with
    void swap(const Array& that);

  private:
    static const std::string OUT_OF_RANGE_EXC_TEXT;

    std::size_t m_size;
    value_type* m_data;
};
} // namespace ava
#endif // ARRAY_H
