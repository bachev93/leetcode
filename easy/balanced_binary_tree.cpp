#include <algorithm>
#include <iostream>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right)
      : val(x), left(left), right(right) {}
};

// 1st aproach, BEST
int maxdepth(TreeNode* root, bool& res) {
  if (root == NULL) {
    return 0;
  }

  int l = maxdepth(root->left, res);
  int r = maxdepth(root->right, res);
  if (abs(l - r) > 1) {
    res = false;
  }

  return max(l, r) + 1;
}

bool isBalanced(TreeNode* root) {
  bool res = true;
  maxdepth(root, res);
  return res;
}

// 2nd approach
int height(TreeNode* root) {
  if (!root) {
    return 0;
  }

  const auto left_height = height(root->left);
  const auto right_height = height(root->right);
  return max(left_height, right_height) + 1;
}

bool isBalanced2(TreeNode* root) {
  if (!root) {
    return true;
  }

  const auto left = isBalanced2(root->left);
  const auto right = isBalanced2(root->right);
  const auto diff = abs(height(root->left) - height(root->right)) <= 1;
  if (left && right && diff) {
    return true;
  }

  return false;
}

int main() {
  cout << "balanced binary tree: " << isBalanced(nullptr) << endl;
  return 0;
}