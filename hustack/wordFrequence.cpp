#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct TreeNode {
  char *text;
  int f;
  struct TreeNode *left;
  struct TreeNode *right;
} TreeNode;

TreeNode *createNode(char *text) {
  TreeNode *node = (TreeNode *)malloc(sizeof(TreeNode));
  node->text = (char*)malloc(22 * sizeof(char));
  strcpy(node->text, text);
  node->left = NULL;
  node->right = NULL;
  node->f = 1;

  return node;
}

TreeNode *insertBST(char *text, TreeNode *root) {
  if (root == NULL) {
    return createNode(text);
  }

  if (strcmp(text, root->text) ==  0) {
    root->f++;
    return root;
  }
  if (strcmp(text, root->text) < 0)
    root->left = insertBST(text, root->left);
  else
    root->right = insertBST(text, root->right);

  return root;
}

void preOrder(TreeNode *root) {
  if (!root)
    return;

  printf("%s %d\n", root->text, root->f);
  preOrder(root->left);
  preOrder(root->right);
}

void postOrder(TreeNode *root) {
  if (!root)
    return;

  preOrder(root->left);
  preOrder(root->right);
  printf("%s %d\n", root->text, root->f);
}

void inOrder(TreeNode *root) {
  if (!root)
    return;

  inOrder(root->left);
  printf("%s %d\n", root->text, root->f);
  inOrder(root->right);
}

int main(void) {
  TreeNode *root = NULL;

  char text[22];
  while (scanf("%s", text) != EOF) 
    root = insertBST(text, root);

  inOrder(root);
  return 0;
}
