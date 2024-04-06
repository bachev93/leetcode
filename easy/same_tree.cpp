#include <iostream>

using namespace std;

// Definition for a binary tree node.
  struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

// Base solution
bool isSameTree(TreeNode* p, TreeNode* q) {
  if(!p && !q) {
      return true;
  }

  if(p && q && p->val == q->val) {
      return isSameTree(p->left, q->left) && isSameTree(p->right, q->right); 
  }

  return false;
}

// some improvement in base solution
bool isSameTree2(TreeNode* p, TreeNode* q) {
  if(!p || !q) {
      return p == q;
  }

  return p->val == q->val && isSameTree2(p->left, q->left) && isSameTree2(p->right, q->right);
}

int main()
{
  cout << "same tree: " << isSameTree(nullptr, new TreeNode(10)) << endl;
  return 0;
}
