#include <iomanip>
#include <iostream>
#include <vector>
#define GREEN "\033[32m"   /* Green */
#define WHITE "\033[37m"   /* White */
#define RED "\033[31m"     /* Red */
#define YELLOW "\033[33m"  /* Yellow */
#define MAGENTA "\033[35m" /* Magenta */

using namespace std;
typedef int ElementType;
typedef struct BinarySearchTreeNode {
  ElementType value;
  BinarySearchTreeNode *left;
  BinarySearchTreeNode *right;
} BinarySearchTreeNode;

BinarySearchTreeNode *insertTree(ElementType value,
                                 BinarySearchTreeNode *tree) {
  if (nullptr == tree) {
    tree = new BinarySearchTreeNode();
    // cout << "sizeof BinarySearchTreeNode left is : " << sizeof(tree->left) <<
    // endl;
    if (nullptr == tree) {
      cout << RED << "new memory failed" << endl;
      cout << WHITE << endl;
      return nullptr;
    } else {
      cout << YELLOW << "Insert success, inserted value is :" << value << endl;
      cout << WHITE << endl;
      tree->value = value;
      tree->left = nullptr;
      tree->right = nullptr;
    }
  } else if (value < tree->value) {
    // cout << GREEN << "insert in left tree!" << endl;
    // cout << WHITE << endl;
    tree->left = insertTree(value, tree->left);
  } else if (value > tree->value) {
    // cout << MAGENTA << "insert in right tree!" << endl;
    // cout << WHITE << endl;
    tree->right = insertTree(value, tree->right);
  } else {
  }
  return tree;
}

BinarySearchTreeNode *findMin(BinarySearchTreeNode *tree) {
  if (nullptr == tree) {
    return nullptr;
  } else if (nullptr == tree->left) {
    return tree;
  } else {
    return findMin(tree->left);
  }
}

BinarySearchTreeNode *findTree(ElementType value, BinarySearchTreeNode *tree) {
  if (tree == nullptr) {
    return nullptr;
  }

  if (value < tree->value) {
    cout << GREEN << "find in left tree!" << endl;
    cout << WHITE << endl;
    return findTree(value, tree->left);
  } else if (value > tree->value) {
    cout << MAGENTA << "find in right tree!  " << tree->value << endl;
    cout << WHITE << endl;

    return findTree(value, tree->right);
  } else {
    return tree;
  }
}

BinarySearchTreeNode *deleteTree(ElementType value,
                                 BinarySearchTreeNode *tree) {
  if (nullptr == tree) {
    cout << RED << "this tree is empty!" << endl;
    cout << WHITE << endl;
    return nullptr;
  } else if (value < tree->value) {
    tree->left = deleteTree(value, tree->left);
  } else if (value > tree->value) {
    tree->right = deleteTree(value, tree->right);
  } else if (nullptr != tree->left && nullptr != tree->right) {
    BinarySearchTreeNode *tempTree = findMin(tree->right);
    tree->value = tempTree->value;
    tree->right = deleteTree(tree->value, tree->right);
  } else {
    BinarySearchTreeNode *tempTree1 = tree;
    ;
    if (nullptr == tree->left) {
      tree = tree->right;
    } else if (nullptr == tree->right) {
      tree = tree->left;
    } else {
    }
    delete tempTree1;
    tempTree1 = nullptr;
  }
  return tree;
}

int main() {
  vector<ElementType> src = {5, 8, 10, 2, 22, 65, 45};
  BinarySearchTreeNode *tree = nullptr;
  // cout << "sizeof BinarySearchTreeNode is : " << sizeof(BinarySearchTreeNode)
  // << endl;
  // cout << "sizeof ElementType is : " << sizeof(ElementType) << endl;

  for (int i = 0; i < src.size(); i++) {
    tree = insertTree(src.at(i), tree);
  }
  BinarySearchTreeNode *find_ret = nullptr;
  find_ret = findTree(22, tree);

  if (find_ret != nullptr) {
    cout << "i foud the value use findTree and the value is : "
         << find_ret->value << endl;
  } else {
    cout << RED << "sorry, i can not find the value in tree " << endl;
    cout << WHITE << endl;
  }

  BinarySearchTreeNode *temp = findMin(tree);
  cout << " Min value of the tree is : " << temp->value << endl;

  deleteTree(2, tree);
  BinarySearchTreeNode *temp1 = findMin(tree);
  cout << " Min value of the tree is : " << temp1->value << endl;

  return 0;
}