#include <iostream>
#include <vector>
#include <utility>
#include <iterator>
#include <algorithm>

class solution {
public:
    int firstMissingPositive(const std::vector<int> & nums) {
	auto cpy = nums;
	std::copy(cpy.begin(), cpy.end(), std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;
	for (size_t i = 0; i < cpy.size(); ) {
	    if (cpy[i] > 0 && cpy[i] < cpy.size()) {
		if (cpy[i] != i && cpy[i] != cpy[cpy[i]])
		    std::swap(cpy[i], cpy[cpy[i]]);
		else
		    i++;
	    }
	    else
		i++;
	}
	std::copy(cpy.begin(), cpy.end(), std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;

	for (size_t i = 1; i < cpy.size(); i++)
	    if (cpy[i] != i)
		return i;
	return cpy.size();
    }
};

int main() {
    std::vector<int> nums{-2,2,2,-1};
    // std::vector<int> nums{3,4,-1,1};

    solution soln;
    int missing = soln.firstMissingPositive(nums);
    std::cout << "The first missing positive is:\n"
	      << missing << std::endl;
}
