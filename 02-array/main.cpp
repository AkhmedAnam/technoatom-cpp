#include <iostream>
#include <array>

#include "array.h"
using namespace std;

void Print_Ava_Array(const ava::Array to_print, char* header_message) {
	std::cout << header_message << std::endl;
	std::size_t arr_length = to_print.size();
	for (size_t i = 0; i < arr_length; i++) {
		std::cout << "[" << i << "] = " << to_print[i] << std::endl;
	}
}

int main(int argc, char *argv[])
{
  std::array<int, 5> arr = {1, 2, 3};
  cout << arr.size() << endl;
  cout << arr.max_size() << endl;

  ava::Array a(3);
  a.front() = 1;
  a.back() = 5;
  a[1] = 3;
  for (size_t i = 0; i < a.size(); i++) {
    cout << a[i] << endl;
  }

  //asignment operator test
  {
	  std::size_t array_length = 5U;
	  ava::Array first(array_length), second(array_length), third(array_length);
	  for (size_t i = 0; i < array_length; i++) {
		  first[i] = (ava::Array::value_type)(i * i);
		  second[i] = (ava::Array::value_type)(3 * i);
		  third[i] = (ava::Array::value_type)(5 * i);
	  }
	  Print_Ava_Array(first, "First array. Formula: arr[i] = i * i\n");
	  Print_Ava_Array(second, "Second array. Formula: arr[i] = 3 * i\n");
	  Print_Ava_Array(third, "Third array. Formula: arr[i] = 5 * i\n\n");
	  first = second = third;
	  std::cout << "Arrays after expression first = second = third:\n\n";
	  Print_Ava_Array(first, "First array. Formula: arr[i] = i * i\n");
	  Print_Ava_Array(second, "Second array. Formula: arr[i] = 3 * i\n");
	  Print_Ava_Array(third, "Third array. Formula: arr[i] = 5 * i\n\n");
  }

  try{
	cout << a[6] << endl;
  }
  catch(exception & ex){
	  cout << ex.what() << endl;
  }
  return 0;
}
