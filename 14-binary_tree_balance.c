#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree.
 *
 * @tree: Pointer to the root node of the tree to measure the height.
 *
 * Return: The height of the tree
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
 * binary_tree_balance - measures the balance factor of a binary tree.
 *
 * @tree: a pointer to the root node of the tree to measure the balance factor.
 *
 * Return: The balance factor. If tree is NULL, return 0.
 */

int binary_tree_balance(const binary_tree_t *tree)
{
	int left_height, right_height;

	if (tree == NULL)
		return (0);

	if (tree->left != NULL)
		left_height = 1 + binary_tree_height(tree->left);
	else
		left_height = 0;

	if (tree->right != NULL)
		right_height = 1 + binary_tree_height(tree->right);
	else
		right_height = 0;

	return (left_height - right_height);
}
