#include <iostream>
#include <vector>
#include <bitset>
#include <iterator>
#include <algorithm>
#include <functional>

// template<int N>
// std::ostream & operator<<(std::ostream & os, const std::bitset<N> & bset) {
//   os << bset.to_string();
//   return os;
// }

// solution 1
// class solution {
// public:
//   int findMaximumXOR(std::vector<int> & nums) {
//     std::copy(nums.begin(), nums.end(), std::ostream_iterator<int>(std::cout, "\t"));
//     std::cout << std::endl;
//     std::vector<std::bitset<6>> temp(nums.begin(), nums.end());
//     std::copy(temp.begin(), temp.end(), std::ostream_iterator<std::bitset<6>>(std::cout, " "));
//     std::cout << std::endl;

//     std::vector<std::bitset<32>> bins(nums.begin(), nums.end());
//     size_t mIdx = std::distance(nums.begin(), std::max_element(nums.begin(), nums.end()));
//     auto mBin = bins[mIdx];
//     int first = mBin.size()-1;
//     while (first >= 0 && mBin[first] == 0)
//       first--;

//     std::vector<int> same;
//     same.reserve(nums.size());
//     for (size_t i = 0; i < bins.size(); ++i) {
//       int idx = first;
//       while (idx >= 0 && bins[i][idx] != mBin[idx])
// 	idx--;
//       same.push_back(idx);
//     }

//     auto it = std::min_element(same.begin(), same.end());

//     std::cout << "The two numbers found are:\n"
// 	      << nums[std::distance(same.begin(), it)] << ", " << nums[mIdx] << std::endl;
//     return std::bit_xor<int>()(nums[std::distance(same.begin(), it)], nums[mIdx]);
//   }
// };

// solution 2
// class solution {
// public:
//    int findMaximumXOR(std::vector<int> & nums) {
//      int result;
//      if (nums.size() == 2)
//        result = std::bit_xor<int>()(nums.front(), nums.back());
//      else {
//        std::vector<int> cands;
//        std::vector<int> rest(nums.begin()+1, nums.end());
//        for (size_t i = 0; i < rest.size(); ++i)
// 	 cands.push_back(std::bit_xor<int>()(nums[0], rest[i]));
//        cands.push_back(findMaximumXOR(rest));
//        result = *std::max_element(cands.begin(), cands.end());
//      }
//      return result;
//    }
// };

template<int N>
std::ostream & operator<<(std::ostream & os, const std::bitset<N> & bset) {
  os << bset.to_ulong();
  return os;
}

// solution 3
class solution {
public:
  int findMaximumXOR(std::vector<int> & nums) {
    // std::copy(nums.begin(), nums.end(), std::ostream_iterator<int>(std::cout, "\t"));
    // std::cout << std::endl;
    // std::vector<std::bitset<6>> temp(nums.begin(), nums.end());
    // std::copy(temp.begin(), temp.end(), std::ostream_iterator<std::bitset<6>>(std::cout, " "));
    // std::cout << std::endl;

      std::vector<std::bitset<32>> bins(nums.begin(), nums.end());
      size_t mx = std::distance(nums.begin(), std::max_element(nums.begin(), nums.end()));
      size_t highest = bins[mx].size()-1;
      while (bins[mx][highest] == 0)
          highest--;

      std::vector<std::bitset<32>> large;
      for (size_t i = 0; i < bins.size(); i++) {
          if (bins[i][highest] == 1)
              large.push_back(bins[i]);
      }

      std::vector<std::pair<std::bitset<32>, std::bitset<32>>> result;
      for (size_t i = 0; i < large.size(); i++) {
	size_t idx = highest-1;
	std::vector<std::bitset<32>> vec = bins;
	while (highest > idx && vec.size() > 1) {
	  std::cout << large[i].to_ulong() << ", which = " << idx << ":\n";
	  vec = feasibleSolns(large[i], idx, vec);
	  idx--;
	}
	if (vec.size() == 1)
	  result.push_back(std::make_pair(large[i], vec[0]));
      }

      // std::vector<int> rtn;
      // for (size_t i = 0; i < result.size(); i++) {
      // 	rtn.push_back(std::bit_xor<int>()(result[i].first.to_ulong(), result[i].second.to_ulong()));
      // 	// std::cout << result[i].first.to_ulong() << "," << result[i].second.to_ulong() << std::endl;
      // }
      std::vector<int> rtn;
      std::transform(result.begin(), result.end(), std::inserter(rtn, rtn.begin()), [](const std::pair<std::bitset<32>, std::bitset<32>> & pr){
	  // return std::bit_xor<int>()(pr.first.to_ulong(), pr.second.to_ulong());
	  return pr.first.to_ulong()^pr.second.to_ulong();
	});

      auto it = std::max_element(rtn.begin(), rtn.end());
      // std::cout << result[std::distance(rtn.begin(), it)].first.to_ulong() << "^" << result[std::distance(rtn.begin(), it)].second.to_ulong() << std::endl;

      return *it;
  }

private:
  std::vector<std::bitset<32>> feasibleSolns(const std::bitset<32> & curr, size_t which, const std::vector<std::bitset<32>> & cands) {
    std::vector<std::bitset<32>> result;
    for (size_t i = 0; i < cands.size(); ++i) {
      if (cands[i][which] != curr[which])
	result.push_back(cands[i]);
    }
    if (result.empty())
      result = cands;

    std::transform(result.begin(), result.end(), std::ostream_iterator<int>(std::cout, " "), [](const std::bitset<32> & bset){ return bset.to_ulong();});
    std::cout << std::endl;
    
    return result;
  }
};


int main() {
  std::vector<int> nums{3,10,5,25,2,8};
  // std::vector<int> nums{1,3,2,4,6,10,9};
  
  solution soln;
  int result = soln.findMaximumXOR(nums);
  std::cout << "The largest XOR of two numbers is:\n"
	    << result << std::endl;
}
