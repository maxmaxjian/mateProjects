#include <iostream>
#include <vector>
#include <tuple>
#include <string>
#include <chrono>
#include <algorithm>

struct myStruct {
  std::string myStr;
  double myDble;
  int myInt;

  myStruct(int i, double d, const std::string & s)
    : myStr(s), myDble(d), myInt(i){}

  myStruct(const myStruct & other) {
    myInt = other.myInt;
    myDble = other.myDble;
    myStr = other.myStr;
  }
  
  myStruct(myStruct && other) {
    myInt = other.myInt;
    myDble = other.myDble;
    myStr = other.myStr;
  }

  myStruct & operator=(myStruct && other) {
    if (this != &other) {
      myInt = other.myInt;
      myDble = other.myDble;
      myStr = other.myStr;
    }
    return *this;
  }

  void swap(myStruct & other) {
    std::swap(myInt, other.myInt);
    std::swap(myDble, other.myDble);
    myStr.swap(other.myStr);
  }
};

template<typename T, int N>
class elapsedTime {
private:
  T myIns;
  int numElem;
  
public:
  elapsedTime(const T & ins)
    : myIns(ins), numElem(N) {}

  auto operator()() {
    auto start = std::chrono::steady_clock::now();
    std::vector<T> vec;
    for (int i = 0; i < numElem; i++) {
      // auto temp = myIns;
      // vec.push_back(temp);
      vec.push_back(myIns);
    }
    for (int i = 1; i < numElem; i++)
      std::swap(vec[i-1], vec[i]);
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> dur = end-start;
    return dur.count();
  }
};

int main() {
  struct myStruct stru(1,2.5,"string");
  std::tuple<int, double, std::string> myTup(std::make_tuple(1,2.5,"string"));

  constexpr int nElem = 10000000;
  int numRuns = 10;
  for (int i = 0; i < numRuns; i++) {    
    std::cout << "Tuple:\t" << elapsedTime<std::tuple<int,double,std::string>, nElem>(myTup)() << std::endl;
    std::cout << "struct:\t" << elapsedTime<myStruct, nElem>(stru)() << std::endl << std::endl;
  }
}
