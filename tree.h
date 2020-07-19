
#ifndef TREE_H
#define TREE_H

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode *new_tree_node(int val);

struct TreeNode *new_tree_node(int val)
{
    struct TreeNode *new_node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    new_node->val = val;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

#endif