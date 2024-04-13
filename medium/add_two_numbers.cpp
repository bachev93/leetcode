#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void print_vector(const vector<int>& v, const string& title) {
  cout << title << "= [";
  for(auto elem : v) {
    cout << elem << ", ";
  }
  cout << "]" << endl;
}

// solution from leetcode, BEST
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
  ListNode* dummyHead = new ListNode(0);
  ListNode* tail = dummyHead;
  int carry = 0;

  while (l1 != nullptr || l2 != nullptr || carry != 0) {
    int digit1 = (l1 != nullptr) ? l1->val : 0;
    int digit2 = (l2 != nullptr) ? l2->val : 0;

    int sum = digit1 + digit2 + carry;
    int digit = sum % 10;
    carry = sum / 10;

    ListNode* newNode = new ListNode(digit);
    tail->next = newNode;
    tail = tail->next;

    l1 = (l1 != nullptr) ? l1->next : nullptr;
    l2 = (l2 != nullptr) ? l2->next : nullptr;
  }

  ListNode* result = dummyHead->next;
  delete dummyHead;
  return result;
}

// my ADAPTED BRUTEFORCE solution
ListNode* addTwoNumbers2(ListNode* l1, ListNode* l2) {
  vector<int> val1;
  while(l1) {
    val1.push_back(l1->val);
    l1 = l1->next;
  }
  
  vector<int> val2;
  while(l2) {
    val2.push_back(l2->val);
    l2 = l2->next;
  }

  const auto max_size = max(val1.size(), val2.size()) + 1;
  val1.resize(max_size);
  val2.resize(max_size);
  for(uint i = 0; i < val1.size() - 1; ++i) {
    const auto sum = val1[i] + val2[i];
    val1[i] = sum % 10;
    val1[i + 1] += sum / 10;
  }
  if(val1.back() == 0) {
    val1.pop_back();
  }

  ListNode* result_list = new ListNode(val1.front());
  ListNode* head = result_list;
  for(auto it = val1.cbegin() + 1; it != val1.cend(); ++it) {
    result_list->next = new ListNode(*it);
    result_list = result_list->next;
  }

  return head;
}

// my original BRUTEFORCE solution
ListNode* addTwoNumbers3(ListNode* l1, ListNode* l2) {
  vector<int> val1;
  while(l1) {
    val1.push_back(l1->val);
    l1 = l1->next;
  }
  
  vector<int> val2;
  while(l2) {
    val2.push_back(l2->val);
    l2 = l2->next;
  }

  const auto max_size = max(val1.size(), val2.size());
  vector<int> result_val(max_size + 1);
  for(uint i = 0; i < max_size; ++i) {
    int sum{0};
    if(i < val1.size() && i < val2.size()) {
        sum = val1[i] + val2[i];
    } else if(i >= val1.size()) {
        sum = val2[i];
    } else if(i >= val2.size()) {
        sum = val1[i];
    }

    sum = result_val[i] + sum;
    result_val[i] = sum % 10;
    result_val[i + 1] = sum / 10;
  }
  if(result_val.back() == 0) {
    result_val.pop_back();
  }
  
  ListNode* result_list = new ListNode(result_val.front());
  ListNode* head = result_list;
  for(auto it = result_val.cbegin() + 1; it != result_val.cend(); ++it) {
    result_list->next = new ListNode(*it);
    result_list = result_list->next;
  }

  return head;
}

int main() {
  ListNode* l1 = new ListNode(2);
  l1->next = new ListNode(4);
  l1->next->next = new ListNode(3);

  ListNode* l2 = new ListNode(5);
  l2->next = new ListNode(6);
  l2->next->next = new ListNode(4);

  auto result = addTwoNumbers(l1, l2);
  cout << "add two numbers" << endl;
  while(result) {
    cout << result->val << ", ";
    result = result->next;
  }
  cout << endl;

  return 0;
}
