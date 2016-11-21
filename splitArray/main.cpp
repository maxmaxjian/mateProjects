#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using std::vector;

class solution {
  public:
    int splitArray(const vector<int> & nums, int m) {
      int result;
      if (m == 1)
	result = std::accumulate(nums.begin(), nums.end(), 0);
      else {
	vector<int> cands;
	int i = 1;
	while (nums.size()-i >= m-1) {
	  vector<int> rest(nums.begin()+i , nums.end());
	  int temp = std::max(std::accumulate(nums.begin(), nums.begin()+i, 0), splitArray(rest, m-1));
	  cands.push_back(temp);
	  i++;
	}
	result = *std::min_element(cands.begin(), cands.end());
      }
      
      return result;
    }
};

int main() {
  vector<int> nums{7,2,5,10,8};
  int m = 2;

  solution soln;
  int minmax = soln.splitArray(nums, m);
  std::cout << "The minimum of the largest sum is:\n"
	    << minmax << std::endl;
}
