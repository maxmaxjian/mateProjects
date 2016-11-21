#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using std::vector;

class solution {
  public:
    int integerBreak(int n) {
        vector<vector<int>> cands;
        for (int numOfInts = 2; numOfInts <= n; numOfInts++) {
            auto temp = maxProd(n, numOfInts);
            for (auto vec : temp) {
                if (vec.front() != 1) {
                    std::for_each(vec.begin(), vec.end(), [](const int i){std::cout << i << " ";});
                    std::cout << std::endl;
                    cands.push_back(vec);
                }
            }
        }
        vector<int> prods;
        for (auto & vec : cands) {
            prods.push_back(std::accumulate(vec.begin(), vec.end(), 1, [](const int &i, const int &j){ return i*j;}));
        }

        return *std::max_element(prods.begin(), prods.end());
    }

  private:
    vector<vector<int>> maxProd(int n, int numOfInts) {
        vector<vector<int>> result;
        if (n > numOfInts) {
            if (numOfInts == 1) {
                vector<int> temp{n};
                result.push_back(temp);
            }
            else {
                vector<vector<int>> cands;
                for (int i = 1; i < n; ++i) {
                    auto temp = maxProd(n-i, numOfInts-1);
                    for (auto vec : temp) {
                        vec.insert(vec.begin(), i);
                        std::sort(vec.begin(), vec.end());
                        if (vec.front() != 1)
                            cands.push_back(vec);
                    }
                }

                auto lessthan = [](const vector<int> & v1, const vector<int> &v2) {
                    if (v1.size() != v2.size())
                        return v1.size() < v2.size();
                    else {
                        for (size_t i = 0; i < v1.size(); ++i)
                            if (v1[i] != v2[i])
                                return v1[i] < v2[i];
                        return false;
                    }
                };

                auto equals = [](const vector<int> & v1, const vector<int> &v2) {
                            if (v1.size() != v2.size())
                                return false;
                            else {
                                for (size_t i = 0; i < v1.size(); ++i)
                                    if (v1[i] != v2[i])
                                        return false;
                                return true;
                            }
                        };

                        std::sort(cands.begin(), cands.end(), lessthan);
                        auto ite = std::unique(cands.begin(), cands.end(), equals);
                        cands.resize(std::distance(cands.begin(),ite));
            
                vector<int> prods;
                for (auto vec : cands) {
                    prods.push_back(std::accumulate(vec.begin(), vec.end(), 1, [](const int &i, const int &j){ return i*j;}));
                }

                auto it = std::max_element(prods.begin(), prods.end());
                for (size_t i = 0; i < prods.size(); ++i) {
                    if (prods[i] == *it)
                        result.push_back(cands[i]);
                }
            }
        }
        return result;
    }
};

int main() {
    int n = 25;
    solution soln;
    int maxProd = soln.integerBreak(n);
    std::cout << "The maximum product is:\n";
    std::cout << maxProd << std::endl;
}
