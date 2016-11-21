#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>

class solution {
public:
    std::vector<std::string> fullJustify(const std::vector<std::string> & words, int maxWidth) {
	std::vector<std::string> rows;
	for (auto it = words.begin(); it != words.end(); ) {
	    std::vector<std::string> row;
	    while (it != words.end() && lengthOf(row)+1+it->size() <= maxWidth) {
                row.push_back(*it);
                ++it;
            }
            // std::copy(row.begin(), row.end(), std::ostream_iterator<std::string>(std::cout, " "));
            // std::cout << std::endl;

            rows.push_back(combineAndExpand(row, maxWidth));
            std::cout << rows.back() << std::endl;
	}
        
        return rows;
    }

  private:
    int lengthOf(const std::vector<std::string> & vec) {
        int len = std::accumulate(vec.begin(), vec.end(), 0,
                                  [](int i, const std::string & s){
                                      return i+s.length();
                                  });
        return vec.size() == 1 ? len : len+vec.size()-1;
    }

    std::string combineAndExpand(const std::vector<std::string> & vec, int maxWidth) {
        std::string result;
        if (vec.size() == 1) {
            result += vec[0];
            result += std::string(maxWidth-vec[0].size(), '-');
        }
        else if (vec.size() > 1) {
            int rest = maxWidth - std::accumulate(vec.begin(), vec.end(), 0,
                                                  [](int i, const std::string & s){
                                                      return i+s.size();
                                                  });
            std::vector<int> numSpaces(vec.size()-1, rest/(vec.size()-1));
            int r = rest%(vec.size()-1);
            std::transform(numSpaces.begin(), numSpaces.end(), numSpaces.begin(),
                           [&](int i){
                               return r-- > 0 ? i+1 : i;
                           });
            
            result += vec[0];
            std::vector<std::string> temp;
            std::transform(vec.begin()+1, vec.end(), numSpaces.begin(),
                           std::inserter(temp, temp.begin()), [](const std::string & s, int i){
                               return std::string(i, '-')+s;
                           });
            result += std::accumulate(temp.begin(), temp.end(), std::string(), [](const std::string & s1, const std::string s2){
                return s1+s2;
            });
        }
        return result;
    }
};

int main() {
    std::vector<std::string> words{"This", "is", "an", "example", "of", "text", "justification."};
    int maxWidth = 17;

    solution soln;
    auto result = soln.fullJustify(words, maxWidth);
}


