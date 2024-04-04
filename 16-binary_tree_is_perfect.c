#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree.
 *
 * @tree: Pointer to the root node of the tree to measure the height.
 *
 * This function recursively calculates the height of a binary tree.
 * It traverses the tree by moving down from the root to the leaf nodes,
 * calculating the height by counting the number of edges in the longest path
 * from the root to a leaf.
 *
 * left_height: Height of the left subtree.
 *
 * right_height: Height of the right subtree.
 *
 * Return: The height of the tree as a size_t value.
 * Returns 0 for an empty tree.
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height = 0, right_height = 0;

	if (tree == NULL)
		return (0);

	if (tree->left != NULL)
		left_height = binary_tree_height(tree->left) + 1;

	if (tree->right != NULL)
		right_height = binary_tree_height(tree->right) + 1;

	if (left_height > right_height)
	{
		return (left_height);
	}
	else
	{
		return (right_height);
	}
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect.
 *
 * @tree: Pointer to the root node of the tree to check.
 *
 * A binary tree is perfect if all internal nodes have two children and
 * all leaves are at the same level. This function checks if the tree
 * meets these conditions.
 *
 * left_height: Height of the left subtree.
 *
 * right_height: Height of the right subtree.
 *
 * left_perfect: Indicates if the left subtree is perfect.
 *
 * right_perfect: Indicates if the right subtree is perfect.
 *
 * Return: 1 if the tree is perfect, 0 otherwise or if tree is NULL.
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t left_height, right_height, left_perfect, right_perfect;

	if (tree == NULL)
		return (0);

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	if (left_height != right_height)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
		return (1);

	if (tree->left && tree->right)
	{
		left_perfect = binary_tree_is_perfect(tree->left);
		right_perfect = binary_tree_is_perfect(tree->right);

		return (left_perfect && right_perfect);
	}

	return (0);
}
