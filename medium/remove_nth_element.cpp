#include <iostream>
#include <vector>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

// BEST approach
ListNode* removeNthFromEnd(ListNode* head, int n) {
  ListNode* result = new ListNode(0, head);
  ListNode* slow = result;
  ListNode* fast = head;

  for (int i = 0; i < n; ++i) {
    fast = fast->next;
  }

  while (fast) {
    slow = slow->next;
    fast = fast->next;
  }

  ListNode* nodeToDelete = slow->next;
  slow->next = slow->next->next;
  delete nodeToDelete;

  return result->next;
}

// TODO: make this function common to other executables
ListNode* buildList(const vector<int>& elements) {
  if (elements.empty()) {
    return nullptr;
  }

  ListNode* head = new ListNode(elements.front());
  ListNode* currentNode = head;
  for (int i = 1; i < elements.size(); ++i) {
    currentNode->next = new ListNode(elements[i]);
    currentNode = currentNode->next;
  }

  return head;
}

void printList(ListNode* head) {
  while (head) {
    cout << head->val << ", ";
    head = head->next;
  }
  cout << endl;
}

int main() {
  const vector<int> nums = {1, 2, 3, 4, 5};
  ListNode* head = buildList(nums);
  const int nodeNumber = 2;

  // const vector<int> nums = {7};
  // ListNode* head = buildList(nums);
  // const int nodeNumber = 1;

  // const vector<int> nums = {1, 2};
  // ListNode* head = buildList(nums);
  // const int nodeNumber = 2;

  printList(head);
  ListNode* result = removeNthFromEnd(head, nodeNumber);
  printList(result);
}
