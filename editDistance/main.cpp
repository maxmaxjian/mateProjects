#include <iostream>
#include <string>
#include <algorithm>

class solution {
  public:
    int minDistance(const std::string & word1, const std::string & word2) {
        return distFunc(word1, word1.size()-1, word2, word2.size()-1);
    }

  private:
    int distFunc(const std::string & s1, int i1, const std::string & s2, int i2) {
        int result;
        if (i1 < 0)
            result = i2+1;
        else if (i2 < 0)
            result = i1+1;
        else {
            if (s1[i1] == s2[i2])
                result = distFunc(s1, i1-1, s2, i2-1);
            else {
                result = std::min({distFunc(s1,i1-1,s2,i2), distFunc(s1,i1,s2,i2-1), distFunc(s1,i1-1,s2,i2-1)})+1;
            }
        }
        return result;
    }
};

int main() {
    std::string str1{"friday"}, str2{"ff"};

    solution soln;
    int editDist = soln.minDistance(str1, str2);
    std::cout << "The minimum edit ditance between " << str1 << " and " << str2 << " is:\n"
              << editDist << std::endl;
}
