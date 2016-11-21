#include <iostream>
#include <string>
#include <stack>

class solution {
public:
  std::string longestValidParen(const std::string & s) {
    size_t begin, end;
    begin = 0;
    while (begin < s.size()) {
        end = s.size();
        while (end > begin && !isValid(s.substr(begin, end-begin)))
            end--;
        if (end == begin)
            begin = begin+1;
        else
            break;
    }


    size_t begin_new = end, end_new;
    while (begin_new < s.size()) {
        end_new = s.size();
        while (end_new > begin_new && !isValid(s.substr(begin_new, end_new-begin_new)))
            end_new--;
        if (end_new == begin_new)
            begin_new++;
        else {
            if (end_new-begin_new > end-begin) {
                begin = begin_new;
                end = end_new;
                begin_new = end_new;
            }
        }
    }

    return s.substr(begin, end-begin);
  }

private:
  bool isValid(const std::string & str) {
    std::stack<char> st;
    size_t idx = 0;
    while (idx < str.size()) {
      if (st.empty() || str[idx] == '(')
	st.push(str[idx]);
      else if (str[idx] == ')') {
	if (st.empty())
	  return false;
	else if (st.top() == ')'){
	  st.push(str[idx]);
	}
	else if (st.top() == '(')
	  st.pop();
      }
      idx++;
    }
    if (!st.empty())
      return false;
    return true;
  }
};

int main() {
    // std::string str{"(()"};
    std::string str{")()())"};

    solution soln;
    std::cout << "The longest substring that contains valid parentheses is:\n"
              << soln.longestValidParen(str) << std::endl;
}
