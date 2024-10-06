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
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
  ListNode* dummyHead = new ListNode();
  ListNode* currentNode = dummyHead;

  while (list1 && list2) {
    if (list1->val < list2->val) {
      currentNode->next = list1;
      list1 = list1->next;
    } else {
      currentNode->next = list2;
      list2 = list2->next;
    }

    currentNode = currentNode->next;
  }

  currentNode->next = list1 ? list1 : list2;

  ListNode* result = dummyHead->next;
  delete dummyHead;
  return result;
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
    vector<int> nums1 = {1,2,4};
    vector<int> nums2 = {1,3,4};

    ListNode* list1 = buildList(nums1);
    ListNode* list2 = buildList(nums2);

    // expected [1,1,2,3,4,4]
    ListNode* result = mergeTwoLists(list1, list2);
    printList(result);
}
