#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;

  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// my approach (just intuition)
ListNode *reverseList(ListNode *head) {
  if (head == nullptr) {
    return head;
  }

  vector<int> vals;
  while (head) {
    vals.push_back(head->val);
    head = head->next;
  }

  auto res = new ListNode(vals.back());
  if (vals.size() == 1) {
    return res;
  }

  auto next_node = res;
  for (int i = vals.size() - 2; i >= 0; --i) {
    next_node->next = new ListNode(vals[i]);
    next_node = next_node->next;
  }

  return res;
}

// iterative approach
ListNode *reverseList2(ListNode *head) {
  ListNode *prev = nullptr;
  auto curr = head;
  while (curr != nullptr) {
    auto tmp = curr->next;
    curr->next = prev;
    prev = curr;
    curr = tmp;
  }

  return prev;
}

// recursive approach
ListNode *reverseList3(ListNode *head) {
  if (head == nullptr || head->next == nullptr) {
    return head;
  }

  ListNode *p = reverseList3(head->next);
  head->next->next = head;
  head->next = nullptr;
  return p;
}

int main() {
  auto head = new ListNode(1);
  auto next_node = head;

  for (auto i = 2; i < 4; ++i) {
    next_node->next = new ListNode(i);
    next_node = next_node->next;
  }

  auto new_head = reverseList2(head);

  while (new_head) {
    cout << new_head->val << ", ";
    new_head = new_head->next;
  }

  return 0;
}
