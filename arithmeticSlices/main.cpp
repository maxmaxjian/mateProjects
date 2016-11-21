#include <iostream>
#include <vector>
#include <utility>

using std::vector;
using std::pair;

class solution {
  public:
    int numOfArithmeticSlices(const vector<int> & arr) {
      vector<pair<size_t,size_t>> intvl;
        size_t begin = 0, end;
        end = findArithmeticSeq(arr, begin);
	// std::cout << "begin = " << begin << ", end = " << end << std::endl;
	while (end < arr.size()) {
	  while (end > begin+1) {
	    intvl.push_back(std::make_pair(begin, end));
	    begin = end;
	    if (begin <= arr.size()-3) {
	      end = findArithmeticSeq(arr, begin);
	      // std::cout << "begin = " << begin << ", end = " << end << std::endl;
	    }
	    else
	      break;
	  }
	  begin++;
	  if (begin <= arr.size()-3) {
	    end = findArithmeticSeq(arr, begin);
	  }
	  else
	    break;
	}

	int num = 0;
	for (auto intv : intvl) {
	  std::cout << "[" << intv.first << "," << intv.second << "] ";
	  int len = intv.second-intv.first+1;
	  num += (len-1)*(len-2)/2;
	}
	std::cout << std::endl;

	return num;
    }

  private:
    size_t findArithmeticSeq(const vector<int> & arr, size_t start) {
      // size_t lb = start, ub = arr.size()-1, mid;
      // while (lb < ub-1) {
      // 	mid = (lb+ub)/2;
      // 	if (isArithmeticSeq(arr, start, mid))
      // 	  lb = mid;
      // 	else
      // 	  ub = mid;
      // }
      // return lb;

      size_t result = arr.size()-1;
      while (result > start && !isArithmeticSeq(arr, start, result))
	result--;
      return result;
    }

    bool isArithmeticSeq(const vector<int> & arr, size_t begin, size_t end) {
        if (end-begin < 2)
            return false;
        else {
	  for (size_t i = begin+1; i < end; ++i)
	    if (arr[i-1]+arr[i+1] != 2*arr[i])
	      return false;
	  return true;
        }
    }
};

int main() {
    // vector<int> nums{1,2,3,4};
  vector<int> nums{-1,1,3,3,3,2,1,0};

    solution soln;
    int num = soln.numOfArithmeticSlices(nums);
    std::cout << "The total number of arithmetic slices is:\n"
	      << num << std::endl;
}
