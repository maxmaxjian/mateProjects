#include <iostream>
#include <string>
// #include <unordered_map>
#include <vector>
#include <algorithm>

class solution {
public:
  std::string originalDigits(std::string & s) {
    std::vector<char> result;
    std::string str{s};
    while (str.find('z') != std::string::npos) {
      result.push_back('0');
      remove(str, "zero");
    }
    while (str.find('w')!= std::string::npos) {
      result.push_back('2');
      remove(str, "two");
    }
    while (str.find('u')!= std::string::npos) {
      result.push_back('4');
      remove(str, "four");
    }
    while (str.find('x')!= std::string::npos) {
      result.push_back('6');
      remove(str, "six");
    }
    while (str.find('g')!= std::string::npos) {
      result.push_back('8');
      remove(str, "eight");
    }
    while (str.find('o')!= std::string::npos) {
      result.push_back('1');
      remove(str, "one");
    }
    while (str.find('h')!= std::string::npos) {
      result.push_back('3');
      remove(str, "three");
    }
    while (str.find('f')!= std::string::npos) {
      result.push_back('5');
      remove(str, "five");
    }
    while (str.find('v')!= std::string::npos) {
      result.push_back('7');
      remove(str, "seven");
    }
    while (str.find('i')!= std::string::npos) {
      result.push_back('9');
      remove(str, "nine");
    }
    if (!str.empty())
      std::cerr << "Invalid string!" << std::endl;
    else {
      std::sort(result.begin(), result.end());
      return std::string(result.begin(), result.end());
    }
  }

private:
  // std::vector<std::vector<char>> getDigits(const string & s) {
  //   std::vector<std::vector<char>> result;
  //   if (s.size()  3)
  //   if (exist(s, "one")) {
  //     result.push_back(std::vector<char>{'1'});
  //     auto cpy = remove(s, "one");
  //     auto temp = 
  //   }
  // }
  
  
  // bool exist(const std::string & s, const std::string & p) {
  //   if (s.size() < p.size())
  //     return false;
  //   else {
  //     std::unordered_map<char,int> smap, pmap;
  //     for (auto ch : s) {
  // 	if (smap.find(ch) == smap.end())
  // 	  smap[ch] = 0;
  // 	smap[ch]++;
  //     }
  //     for (auto ch : p) {
  // 	if (pmap.find(ch) == pmap.end())
  // 	  pmap[ch] = 0;
  // 	pmap[ch]++;
  //     }
  //     for (auto it = pmap.begin(); it != pmap.end(); ++it) {
  // 	auto jt = smap.find(it->first);
  // 	if (jt == smap.end())
  // 	  return false;
  // 	else if (jt->second < it->second)
  // 	  return false;
  //     }
  //     return true;
  //   }
  // }

  void remove(std::string & s, const std::string & p) {
    for (auto ch : p)
      s.erase(s.find(ch),1);
  }
};

int main() {
  // std::string dgtStr{"owoztneoer"};
  std::string dgtStr{"fviefuro"};

  solution soln;
  auto result = soln.originalDigits(dgtStr);
  std::cout << "The sorted digits are:\n"
	    << result << std::endl;
}
