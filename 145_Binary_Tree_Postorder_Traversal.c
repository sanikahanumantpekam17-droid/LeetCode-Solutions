
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

/**
 * Note: The returned array must be malloced,
 * assume caller calls free().
 */
#include <stdlib.h>

void postorder(struct TreeNode* root, int* result, int* size) {
    if (root == NULL)
        return;

    postorder(root->left, result, size);
    postorder(root->right, result, size);
    result[(*size)++] = root->val;
}

int* postorderTraversal(struct TreeNode* root, int* returnSize) {
    *returnSize = 0;

    int* result = (int*)malloc(100 * sizeof(int));

    if (result == NULL)
        return NULL;

    postorder(root, result, returnSize);

    return result;
}
