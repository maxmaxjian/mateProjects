// #include <iostream>
// #include <string>
// #include <unordered_map>
// #include <deque>

// using std::string;
// using std::unordered_map;
// using std::deque;

// class solution {
// public:
//   int longestSubstring(const string & s, int k) {
//     unordered_map<char, deque<size_t>> dict;
//     size_t begin = s.size(), end = 0, i;
//     i = 0;
//     while (i < s.size() && !valLtTwo(dict)) {
//       if (dict.find(s[i]) == dict.end())
// 	dict[s[i]] = deque<size_t>();
//       dict[s[i]].push_back(i);
//       i++;
//     }

//     // for (auto it = dict.begin(); it != dict.end(); ++it) {
//     //   if (it->second.front() < begin)
//     // 	begin = it->second.front();
//     //   if (it->second.back() > end)
//     // 	end = it->second.back();
//     // }
//     // std::cout << "begin = " << begin << ", end = " << end << std::endl;
//     // std::cout << s.substr(begin, end-begin+1) << std::endl;

//     while (i < s.size() && valLtTwo(dict)) {
//       if (dict.find(s[i]) == dict.end())
// 	dict[s[i]] = deque<size_t>();
//       dict[s[i]].push_back(i);
//       i++;
//     }

//     size_t begin_new(s.size()), end_new(0);
//     for (auto it = dict.begin(); it != dict.end(); ++it) {
//       if (it->second.front()<begin_new)
// 	begin_new = it->second.front();
//       if (it->second.back() > end_new)
// 	end_new = it->second.back();
//     }

//     std::cout << "begin_new = " << begin_new << ", end_new = " << end_new-1 << std::endl;
//     std::cout << s.substr(begin_new, end_new-begin_new) << std::endl;

//     return 0;
//   }

// private:
//   bool valLtTwo(unordered_map<char,deque<size_t>> & a_map) {
//     if (!a_map.empty()) {
//       for (auto it = a_map.begin(); it != a_map.end(); ++it)
// 	if (it->second.size() < 2)
// 	  return false;
//       return true;
//     }
//     else
//       return false;
//   }
// };

#include <iostream>
#include <unordered_map>
#include <vector>
#include <utility>
#include <algorithm>

class solution {
public:
  std::string longestSubstring(const std::string & s, int k) {
    std::unordered_map<char,std::vector<size_t>> dict;
    for (size_t i = 0; i < s.size(); i++) {
      if (dict.find(s[i]) == dict.end())
	dict[s[i]] = std::vector<size_t>();
      dict[s[i]].push_back(i);
    }

    std::vector<size_t> indx;
    for (auto it = dict.begin(); it != dict.end(); ++it) {
      if (it->second.size() < k) {
	for (auto ix : it->second) {
	  // std::cout << ix << " ";
	  indx.push_back(ix);
	}
      }
    }
    // std::cout << std::endl;
    std::sort(indx.begin(), indx.end());

    std::vector<std::pair<size_t,size_t>> intv;
    for (size_t i = 0; i < indx.size(); ++i) {
      if (i == 0) {
	if (indx[i] > 0) {
	  intv.push_back(std::make_pair(0, indx[i]-1));
	}
      }
      else {
	if (indx[i] >= indx[i-1]+2)
	  intv.push_back(std::make_pair(indx[i-1]+1, indx[i]-1));
      }
    }
    if (s.size() >= indx.back()+2)
      intv.push_back(std::make_pair(indx.back()+1, s.size()-1));

    std::cout << "Candidate intervals are:" << std::endl;
    for (size_t i = 0; i < intv.size(); ++i)
      std::cout << "[" << intv[i].first << "," << intv[i].second << "] ";
    std::cout << std::endl;

    size_t idx = 0;
    while (idx < intv.size() && !allCharsLtK(s.substr(intv[idx].first, intv[idx].second-intv[idx].first+1), k))
      idx++;

    for (size_t i = idx+1; i < intv.size(); ++i) {
      if (!allCharsLtK(s.substr(intv[i].first, intv[i].second-intv[i].first+1), k) && intv[i].second-intv[i].first > intv[idx].second-intv[idx].first)
	idx = i;
    }
    
    return s.substr(intv[idx].first, intv[idx].second-intv[idx].first+1);
  }

private:
  bool allCharsLtK(const std::string & s, int k) {
    std::unordered_map<char, size_t> count;
    for (size_t i = 0; i < s.size(); ++i) {
      if (count.find(s[i]) == count.end())
	count[s[i]] = 0;
      count[s[i]] += 1;
    }

    if (count.empty())
      return false;
    else {
      for (auto it = count.begin(); it != count.end(); ++it)
	if (it->second < k)
	  return false;
      return true;
    }
  }
};


int main() {
  // std::string s{"aaabbcacdc"};
  // int k = 3;

  std::string s{"ababbc"};
  int k = 2;

  solution soln;
  std::string substr = soln.longestSubstring(s, k);
  std::cout << "The longest substring is:\n"
	    << substr << std::endl;
}
