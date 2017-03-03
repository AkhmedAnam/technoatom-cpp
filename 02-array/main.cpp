#include <iostream>
#include <array>

#include <array.h>
using namespace std;

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

  cout << a[6] << endl;

  return 0;
}
