#include <iostream>
#include <vector>
#include <iterator>
#include <ctime>

class solution {
public:
  int search(std::vector<int> & nums, int target) {
    if (nums.size() == 1) {
      if (nums[0] == target)
	return 0;
      else
	return -1;
    }
    else {
      int lb = 0, ub = nums.size()-1, mid;
      while (lb < ub-1) {
	if (nums[lb] == target)
	  return lb;
	if (nums[ub] == target)
	  return ub;
	
	mid = (lb+ub)/2;
	if (nums[mid] == target)
	  return mid;
	else if (nums[lb] < target) {
	  if (nums[mid] < target) {
	    if (nums[lb] < nums[mid])
	      lb = mid;
	    else if (nums[lb] > nums[mid])
	      ub = mid;
	  }
	  else if (nums[mid] > target)
	    ub = mid;
	}
	else if (nums[ub] > target) {
	  if (nums[mid] > target) {
	    if (nums[ub] > nums[mid])
	      ub = mid;
	    else if (nums[ub] < nums[mid])
	      lb = mid;
	  }
	  else if (nums[mid] < target)
	    lb = mid;
	}
      }

      if (lb+1 == ub) {
	if (nums[lb] == target)
	  return lb;
	else if (nums[ub] == target)
	  return ub;
	else
	  return -1;
      }
    }
  }
};

int main() {
  srand(time(0));
  std::vector<int> nums{0,1,2,4,5,6,7};

  int offset = rand()%nums.size()+1;
  std::vector<int> rotated(nums.size());
  for (size_t i = 0; i < rotated.size(); i++)
    rotated[i] = nums[(i+offset)%nums.size()];

  std::copy(rotated.begin(), rotated.end(), std::ostream_iterator<int>(std::cout, " "));
  std::cout << std::endl;
  
  int target = nums[rand()%rotated.size()];
  std::cout << "The target value is: " << target << std::endl;
  
  solution soln;
  int found = soln.search(rotated, target);
  std::cout << "The target value is found at:\n"
	    << found << std::endl;
}
