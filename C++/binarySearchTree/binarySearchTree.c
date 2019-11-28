#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;
typedef int ElementType;
typedef struct BinarySearchTree
{
	ElementType value;
	BinarySearchTree *left;
	BinarySearchTree *right;
}BinarySearchTree;

// BinarySearchTree *insertTree(ElementType value, BinarySearchTree *tree)
// {
// 	if(NULL == tree)
// 	{
// 		tree->value = value;
// 		tree->left = NULL;
// 		tree->right = NULL;
// 	}
// 	else if(value < tree->value)
// 	{
// 		tree->left = insertTree(value,tree->left);
// 	}
// 	else if (value > tree->value)
// 	{
// 		tree->right = insertTree(value,tree->right);
// 	}
// 	else
// 	{
// 	}
// 	return tree;
// }

int main()
{
	vector<ElementType> src = {5,8,10,2,22,65,45};
	BinarySearchTree *tree;
	// for(int i = 0 ; i < src.size();i++)
	// {
	// 	tree = insertTree(src.at(i),tree);
	// }
	return 0;
}