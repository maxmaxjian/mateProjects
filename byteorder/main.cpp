#include <iostream>

int main() {
  union myType {
    short s;
    char ch[sizeof(short)];
  };

  myType mytyp;
  mytyp.s = 0x0102;
  std::cout << int(mytyp.ch[0]) << std::endl
	    << int(mytyp.ch[1]) << std::endl;
}
