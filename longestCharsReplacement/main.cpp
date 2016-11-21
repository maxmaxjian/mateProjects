#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
// #include <utility>
#include <iterator>
#include <algorithm>

class solution {
public:
  int characterReplacement(const std::string & s, int k) {
    std::unordered_map<char,std::vector<size_t>> dict;
    for (auto ch : s) {
      if (dict.find(ch) == dict.end()) {
	// std::cout << ch << std::endl;
	size_t begin, end;
	begin = s.find_first_of(ch);
	while (begin != std::string::npos) {
	  // std::cout << "begin = " << begin << std::endl;
	  end = s.find_first_not_of(ch, begin);
	  // std::cout << "end = " << end << std::endl;
	  if (dict.find(ch) == dict.end())
	    dict[ch] = std::vector<size_t>();
	  if (end == std::string::npos) {
	    for (size_t i = begin; i < s.size(); ++i)
	      dict[ch].push_back(i);
	  }
	  else {
	    for (size_t i = begin; i < end; ++i)
	      dict[ch].push_back(i);
	  }
	  begin = s.find_first_of(ch, end);
	}
	// if (begin != std::string::npos && end == std::string::npos) {
	// 	if (dict.find(ch) != dict.end())
	// 	  dict[ch] = std::vector<std::pair<size_t,size_t>>();
	// 	dict[ch].push_back(std::make_pair(begin, s.size()));
	// }
      }
    }

    for (auto it = dict.begin(); it != dict.end(); ++it) {
      std::cout << it->first << ": ";
      // for (auto i : it->second)
      // 	std::cout << i << " ";
      std::copy(it->second.begin(), it->second.end(), std::ostream_iterator<size_t>(std::cout, " "));
      std::cout << std::endl;
    }

    std::vector<std::vector<size_t>> cands;
    for (auto it = dict.begin(); it != dict.end(); ++it) {
      auto result = mLenAddK(it->second, s.size(), k);
      for (auto tmp : result) {
	std::copy(tmp.begin(), tmp.end(), std::ostream_iterator<size_t>(std::cout," "));
	std::cout << std::endl;
	cands.push_back(tmp);
      }
    }

    // return *std::max_element(cands.begin(), cands.end());
    std::vector<int> rtn;
    for (auto vec : cands) {
      rtn.push_back(longestContiguous(vec));
      std::cout << rtn.back() << " ";
    }
    std::cout << std::endl;

    return *std::max_element(rtn.begin(), rtn.end());
  }

private:
  std::vector<std::vector<size_t>> mLenAddK(const std::vector<size_t> & indx, size_t mxIdx, int k) {
    using std::vector;
    vector<vector<size_t>> result;
    if (k == 1) {
      vector<vector<size_t>> cands;
      size_t i = 0;
      if (indx.front() > 0) {
	while (i+1<indx.front()) {
	  i++;
	}
      }
      else {
	auto it = indx.begin();
	while (i == *it) {
	  i++;
	  it++;
	}
      }
      while (i < mxIdx) {
	auto temp = indx;
	if (std::find(temp.begin(), temp.end(), i) == temp.end()) {
	  auto it = std::lower_bound(temp.begin(), temp.end(), i);
	  temp.insert(temp.begin()+std::distance(temp.begin(),it), i);
	  cands.push_back(temp);
	}
	i++;
      }
      size_t idx = 0;
      for (size_t i = idx+1; i < cands.size(); ++i) {
	if (longestContiguous(cands[i]) > longestContiguous(cands[idx]))
	  idx = i;
      }
      for (size_t i = 0; i < cands.size(); ++i)
	if (longestContiguous(cands[i]) == longestContiguous(cands[idx]))
	  result.push_back(cands[i]);
    }
    else {
      vector<vector<size_t>> cands;
      auto next = mLenAddK(indx, mxIdx, 1);
      for (auto nx : next) {
	auto temp = mLenAddK(nx, mxIdx, k-1);
	for (auto tmp : temp)
	  cands.push_back(tmp);
      }

      size_t idx = 0;
      for (size_t i = idx+1; i < cands.size(); ++i) {
	if (longestContiguous(cands[i]) > longestContiguous(cands[idx]))
	  idx = i;
      }
      for (size_t i = 0; i < cands.size(); ++i)
	if (longestContiguous(cands[i]) == longestContiguous(cands[idx]))
	  result.push_back(cands[i]);
    }
    return result;
  }

  int longestContiguous(const std::vector<size_t> & idx) {
    int len;
    size_t begin, end;
    begin = 0;
    size_t i;
    for (i = begin+1; i < idx.size(); ++i) {
      if (i-begin != idx[i]-idx[begin]) {
	end = i-1;
	break;
      }
    }
    if (i == idx.size())
      end = i-1;
    len = end-begin+1;
    begin = end+1;
    while (begin < idx.size()) {
      size_t i;
      for (i = begin+1; i < idx.size(); ++i) {
	if (i-begin != idx[i]-idx[begin]) {
	  end = i-1;
	  break;
	}
      }
      if (i == idx.size())
	end = i-1;
      if (end-begin+1 > len)
	len = end-begin+1;
      begin = end+1;
    }
    return len;
  }
};

int main() {
  std::string str{"ABAB"};
  int k = 2;

  // std::string str{"AABABBA"};
  // int k = 1;

  solution soln;
  auto len = soln.characterReplacement(str, k);
  std::cout << "The length of the longest string is:\n"
	    << len << std::endl;
}
