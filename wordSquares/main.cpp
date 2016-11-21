#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

class solution {
  public:
    std::vector<std::vector<std::string>> wordSquares(const std::vector<std::string> & words) {
        using std::vector;
        using std::string;

        vector<vector<string>> result;
        for (auto first : words) {
            // std::cout << "starting with " << first << ":\n";
            vector<vector<string>> curr{vector<string>{first}};
            for (size_t i = 1; i < first.size(); ++i) {
                vector<string> next;
                for (size_t j = 0; j < words.size(); ++j) {
                    if (words[j].front() == first[i])
                        next.push_back(words[j]);
                }
                vector<vector<string>> cands;
                for (auto nx : next) {
                    // std::cout << nx << " ";
                    for (auto tmp : curr) {
                        tmp.push_back(nx);
                        cands.push_back(tmp);
                    }
                }
                // if (!cands.empty())
                curr = cands;
            }
            for (auto tmp : curr) {
                // std::copy(tmp.begin(), tmp.end(), std::ostream_iterator<string>(std::cout, " "));
                // std::cout << std::endl;
                if (isSquare(tmp)) {
                    std::copy(tmp.begin(), tmp.end(), std::ostream_iterator<string>(std::cout, "\n"));
                    std::cout << std::endl;                    
                    result.push_back(tmp);
                }
            }
        }        

        return result;
    }

  private:
    bool isSquare(const std::vector<std::string> & words) {
        for (size_t i = 0; i < words.size(); ++i)
            for (size_t j = 0; j < words[0].size(); ++j)
                if (words[i][j] != words[j][i])
                    return false;
        return true;
    }
};

int main() {
    // std::vector<std::string> words{"area", "lead", "wall", "lady", "ball"};
    
    std::vector<std::string> words{"abat", "baba", "atan", "atal"};

    solution soln;
    auto sqrs = soln.wordSquares(words);
}
