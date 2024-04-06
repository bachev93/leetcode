#include <iostream>
#include <unordered_set>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;

  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// hash table approach
bool hasCycle(ListNode *head) {
  unordered_set<ListNode *> node_ptr_set;

  while (head != nullptr) {
    if (node_ptr_set.count(head)) {
      return true;
    }

    node_ptr_set.insert(head);
    head = head->next;
  }

  return false;
}

// O(1) Floyd's cycle finding algorithm
bool hasCycle2(ListNode *head) {
  if (head == nullptr) {
    return false;
  }

  auto slow = head;
  auto fast = head->next;
  while (slow != fast) {
    if (fast == nullptr || fast->next == nullptr) {
      return false;
    }

    slow = slow->next;
    fast = fast->next->next;
  }

  return true;
}

int main() {
  auto head = new ListNode(1);
  auto next_node = head;

  for (auto i = 2; i < 4; ++i) {
    next_node->next = new ListNode(i);
    next_node = next_node->next;
  }

  return 0;
}
