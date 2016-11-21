#include <iostream>
#include <unordered_set>
#include <cstdlib>
#include <ctime>

class RandomizedSet {
  public:
    RandomizedSet() {
      std::srand(std::time(NULL));
    }

    bool insert(int val) {
      bool found;
      if (myset.find(val) == myset.end()) {
	myset.insert(val);
	found = true;
      }
      else
	found = false;
      return found;
    }

    bool remove(int val) {
      bool success;
      auto it = myset.find(val);
      if (it != myset.end()) {
	success = true;
	myset.erase(it);
      }
      else
	success = false;
      return success;
    }

    int getRandom() {
      size_t idx = rand()%myset.size();
      auto it = myset.begin();
      // while (idx-- > 0)
      // 	it++;
      std::advance(it,idx);
      return *it;
    }

  void print() {
    for (auto it = myset.begin(); it != myset.end(); ++it)
      std::cout << *it << " ";
    std::cout << std::endl;
  }

private:
  std::unordered_set<int> myset;
};

int main() {
  RandomizedSet randomSet;

  std::cout << std::boolalpha;
  std::cout << randomSet.insert(1) << std::endl;
  randomSet.print();

  std::cout << randomSet.remove(2) << std::endl;
  randomSet.print();

  std::cout << randomSet.insert(2) << std::endl;
  randomSet.print();

  randomSet.insert(3);
  randomSet.insert(4);
  randomSet.insert(5);

  std::cout << randomSet.getRandom() << std::endl;

  std::cout << randomSet.remove(1) << std::endl;
  randomSet.print();

  std::cout << randomSet.insert(2) << std::endl;
  randomSet.print();

  std::cout << randomSet.getRandom() << std::endl;
}
