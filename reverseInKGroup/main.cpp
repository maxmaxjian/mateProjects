#include <iostream>
#include <vector>
#include <memory>
#include <iterator>
#include <algorithm>
#include <ctime>

struct Node {
    int val;
    std::shared_ptr<Node> next;

    Node(int v, const std::shared_ptr<Node> & nx)
        : val(v), next(nx) {}
};

using pNode = std::shared_ptr<Node>;

pNode createList(const std::vector<int> & nums) {
    pNode head = nullptr;
    for (auto it = nums.rbegin(); it != nums.rend(); ++it)
        head = std::make_shared<Node>(*it, head);
    return head;
}

void printList(const pNode & node) {
    if (node != nullptr) {
        pNode p = node;
        while (p != nullptr) {
            std::cout << p->val << " ";
            p = p->next;
        }
        std::cout << std::endl;
    }
}

class solution {
  public:
    pNode reverseKGroup(const pNode & head, int k) {
      if (getLength(head) < k) {
	return head;
      }
      else {
	pNode newhead = head;
	pNode curr = head;
	int count = 1;
	while (count < k) {
	  auto temp = curr->next;
	  curr->next = temp->next;
	  temp->next = newhead;
	  newhead = temp;
	  count++;
	}
	curr->next = reverseKGroup(curr->next, k);
	return newhead;
      }
    }

private:
  int getLength(const pNode & head) {
    int len = 0;
    pNode p = head;
    while (p != nullptr) {
      len++;
      p = p->next;
    }
    return len;
  }
};

int main() {
  // srand(time(0));
  // std::vector<int> nums;
  // std::generate_n(std::inserter(nums, nums.begin()), 10, [](){
  //     return int(rand()%20);
  //   });
  std::vector<int> nums{1,2,3,4,5};
  
  pNode list = createList(nums);
  std::cout << "Before reversing:\n";
  printList(list);

  int k = 2;
  solution soln;
  pNode rev = soln.reverseKGroup(list, k);
  std::cout << "After reversing:\n";
  printList(rev);
}
