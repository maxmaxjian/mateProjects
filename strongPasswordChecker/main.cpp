#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <algorithm>

class solution {
  // public:
  //   int strongPasswordChecker(const std::string & s) {
  //       int result;
  //       if (lengthChecker(s) && caseChecker(s) && repeatingCharsChecker(s))
  //           result = 0;
  //       else {
  //           std::vector<int> cands;
  //           std::vector<std::string> next;
  //           if (s.size() < 6) {
  //               auto temp = insert(s);
  //               // for (auto tmp : temp)
  //               //     next.push_back(tmp);
  //               next.push_back(temp);
  //           }
  //           else if (s.size() > 20) {
  //               auto temp = del(s);
  //               // for (auto tmp : temp)
  //               //     next.push_back(tmp);
  //               next.push_back(temp);
  //           }
  //           else if (!upperCase(s)) {
  //               auto temp = replace(s, "ABCDEFGHIJKLMNOPQRSTUVWXYZ");
  //               // for (auto tmp : temp)
  //               //     next.push_back(tmp);
  //               next.push_back(temp);
  //           }
  //           else if (!lowerCase(s)) {
  //               auto temp = replace(s, "abcdefghijklmnopqrstuvwxyz");
  //               // for (auto tmp : temp)
  //               //     next.push_back(tmp);
  //               next.push_back(temp);
  //           }
  //           else if (!digit(s)) {
  //               auto temp = replace(s, "0123456789");
  //               // for (auto tmp : temp)
  //               //     next.push_back(tmp);
  //               next.push_back(temp);
  //           }
  //           else if (!repeatingCharsChecker(s)) {
  //               auto temp = replace(s);
  //               // for (auto tmp : temp)
  //               //     next.push_back(tmp);
  //               next.push_back(temp);
  //           }
            
  //           for (auto nx : next) {
  //               std::cout << nx << std::endl;
  //               cands.push_back(1+strongPasswordChecker(nx));
  //           }
  //           result = *std::min_element(cands.begin(), cands.end());
  //       }
  //       return result;
  //   }

  // private:
  //   std::string insert(const std::string & s, const std::string & chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789") {
  //       std::vector<std::string> result;
  //       for (size_t i = 0; i <= s.size(); i++) {
  //           std::string temp = s;
  //           if (i == 0) {
  //               char ch = chars[rand()%chars.size()];
  //               while (ch == s[i+1])
  //                   ch = chars[rand()%chars.size()];
  //               temp.insert(temp.begin()+i, ch);
  //           }
  //           else if (i == s.size()) {
  //               char ch = chars[rand()%chars.size()];
  //               while (ch == s[i-1])
  //                   ch = chars[rand()%chars.size()];
  //               temp.insert(temp.begin()+i, ch);
  //           }
  //           else {
  //               char ch = chars[rand()%chars.size()];
  //               while (ch == s[i-1] && ch == s[i+1])
  //                   ch = chars[rand()%chars.size()];
  //               temp.insert(temp.begin()+i, ch);
  //           }
  //           result.push_back(temp);
  //       }
  //       return result.back();
  //   }

  //   std::string del(const std::string & s) {
  //       std::vector<std::string> result;
  //       for (size_t i = 0; i < s.size(); ++i) {
  //           std::string temp = s;
  //           temp.erase(temp.begin()+i);
  //           result.push_back(temp);
  //       }
  //       return result.front();
  //   }

  //   std::string replace(const std::string & s, const std::string & chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789") {
  //       // std::vector<std::string> result;
  //       // for (size_t i = 0; i < s.size(); i++) {
  //       //     std::string temp = s;
  //       //     if (i == 0) {
  //       //         char ch = chars[rand()%chars.size()];
  //       //         while (ch == s[i+1])
  //       //             ch = chars[rand()%chars.size()];
  //       //         temp.replace(i,1,1,ch);
  //       //     }
  //       //     else if (i == s.size()) {
  //       //         char ch = chars[rand()%chars.size()];
  //       //         while (ch == s[i-1])
  //       //             ch = chars[rand()%chars.size()];
  //       //         temp.replace(i,1,1,ch);
  //       //     }
  //       //     else {
  //       //         char ch = chars[rand()%chars.size()];
  //       //         while (ch == s[i-1] && ch == s[i+1])
  //       //             ch = chars[rand()%chars.size()];
  //       //         temp.replace(i,1,1,ch);
  //       //     }
  //       //     result.push_back(temp);
  //       // }
  //       // return result.front();

  //       size_t idx;
  //       for (idx = 1; idx < s.size()-1; idx++)
  //           if (s[idx-1]==s[idx] && s[idx]==s[idx+1])
  //               break;
  //       std::string temp = s;
  //       char ch = chars[rand()%chars.size()];
  //       while (ch == s[idx-1] && ch == s[idx+1])
  //           ch = chars[rand()%chars.size()];
  //       temp.replace(idx,1,1,ch);
  //       return temp;
  //   }

public:
  int strongPasswordChecker(const std::string & s) {
    int result;
    if (lengthChecker(s) && caseChecker(s) && repeatingCharsChecker(s))
      result = 0;
    else {
      const std::string UPPERCASES{"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
      const std::string LOWERCASES{"abcdefghijklmnopqrstuvwxyz"};
      const std::string DIGITS{"0123456789"};
      std::vector<std::string> next;
      if (!repeatingCharsChecker(s)) {
	size_t idx = find(s);
	if (s.size() < 6) {
	  if (!upperCase(s)) {
	    next.push_back(insertAt(s, idx, UPPERCASES));
	  }
	  else if (!lowerCase(s)) {
	    next.push_back(insertAt(s, idx, LOWERCASES));
	  }
	  else if (!digit(s)) {
	    next.push_back(insertAt(s, idx, DIGITS));
	  }
	  else {
	    next.push_back(insertAt(s, idx));
	  }
	}
	else if (s.size() > 20) {
	  next.push_back(deleteAt(s, idx));
	}
	else {
	  if (!upperCase(s)) {
	    next.push_back(replaceAt(s, idx, UPPERCASES));
	  }
	  else if (!lowerCase(s)) {
	    next.push_back(replaceAt(s, idx, LOWERCASES));
	  }
	  else if (!digit(s)) {
	    next.push_back(replaceAt(s, idx, DIGITS));
	  }
	  else {
	    next.push_back(replaceAt(s, idx));
	  }
	}
      }
      else {
	size_t idx = s.size()-1;
	if (s.size() < 6) {
	  if (!upperCase(s)) {
	    next.push_back(insertAt(s, idx, UPPERCASES));
	  }
	  else if (!lowerCase(s)) {
	    next.push_back(insertAt(s, idx, LOWERCASES));
	  }
	  else if (!digit(s)) {
	    next.push_back(insertAt(s, idx, DIGITS));
	  }
	  else {
	    next.push_back(insertAt(s, idx));
	  }
	}
	else if (s.size() > 20) {
	  next.push_back(deleteAt(s, idx));
	}
	else {
	  if (!upperCase(s)) {
	    next.push_back(replaceAt(s, idx, UPPERCASES));
	  }
	  else if (!lowerCase(s)) {
	    next.push_back(replaceAt(s, idx, LOWERCASES));
	  }
	  else if (!digit(s)) {
	    next.push_back(replaceAt(s, idx, DIGITS));
	  }
	  else {
	    next.push_back(replaceAt(s, idx));
	  }
	}
      }

      std::vector<int> cands;
      for (auto nx : next) {
	std::cout << nx << std::endl;
	cands.push_back(1+strongPasswordChecker(nx));
      }
      result = *std::min_element(cands.begin(), cands.end());
    }
    return result;
  }

private:
  std::string insertAt(const std::string & s, size_t idx, const std::string & chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789")
  {
    std::string result = s;
    char ch = chars[rand()%chars.size()];
    while (ch == s[idx])
      ch = chars[rand()%chars.size()];
    result.insert(result.begin()+idx,ch);
    return result;
  }

  std::string deleteAt(const std::string & s, size_t idx) {
    std::string result = s;
    result.erase(result.begin()+idx);
    return result;
  }

  std::string replaceAt(const std::string & s, size_t idx, const std::string & chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789")
  {
    std::string result = s;
    char ch = chars[rand()%chars.size()];
    while (ch == s[idx])
      ch = chars[rand()%chars.size()];
    result.replace(idx,1,1,ch);
    return result;
  }
  
    bool lengthChecker(const std::string & s) {
        return s.size() >= 6 && s.size() <= 20;
    }

    bool caseChecker(const std::string & s) {
        bool lowerCase = s.find_first_of("abcdefghijklmnopqrstuvwxyz") != std::string::npos;
        bool upperCase = s.find_first_of("ABCDEFGHIJKLMNOPQRSTUVWXYZ") != std::string::npos;
        bool digit = s.find_first_of("0123456789") != std::string::npos;
        return lowerCase && upperCase && digit;
    }

    bool upperCase(const std::string & s) {
        return s.find_first_of("ABCDEFGHIJKLMNOPQRSTUVWXYZ") != std::string::npos;
    }

    bool lowerCase(const std::string & s) {
        return s.find_first_of("abcdefghijklmnopqrstuvwxyz") != std::string::npos;
    }

    bool digit(const std::string & s) {
        return s.find_first_of("0123456789") != std::string::npos;
    }

    bool repeatingCharsChecker(const std::string & s) {
        for (size_t i = 1; i < s.size()-1; ++i)
            if (s[i]==s[i-1] && s[i]==s[i+1])
                return false;
        return true;
    }

  size_t find(const std::string & s) {
    size_t i = 1;
    while (i < s.size()-1) {
      if (s[i-1]==s[i] && s[i]==s[i+1])
	return i;
      i++;
    }
  }
};

int main() {
    std::string pw{"abcsw"};
    // std::string pw{"aaabccc"};
    // std::string pw{"a"};
    
    solution soln;
    int diff = soln.strongPasswordChecker(pw);
    std::cout << "The minimum number of edits is:\n"
              << diff << std::endl;
}
