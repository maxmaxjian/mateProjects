#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>

class solution {
  public:
    int findKthNumber(int n, int k) {
      using std::vector;
      using std::string;
      auto lessthan = [](int i1, int i2) {
	string str1 = std::to_string(i1), str2 = std::to_string(i2);
	return std::lexicographical_compare(str1.begin(), str1.end(), str2.begin(), str2.end());
      };

      vector<int> vec;
      vec.reserve(n);
      for (int i = 1; i <= n; ++i)
	vec.push_back(i);
      std::sort(vec.begin(), vec.end(), lessthan);
      std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>(std::cout, " "));
      std::cout << std::endl;

      return vec[k-1];
    }
};

int main() {
  // int n = 14, k = 3;
  // int n = 13, k = 2;
  int n = 1000000, k = 5000;

  solution soln;
  int val = soln.findKthNumber(n, k);
  std::cout << "The " << k << "-th number in the lexicographical order is:\n"
	    << val << std::endl;
}
