#ifndef _BST_H
#define _BST_H

#include "TreeNode.h"

class BST
{
  public:
    BST();
    ~BST();

    void insert(Hash *hash);
    TreeNode* search(int id);
    bool deleteNode(int id);
    bool isEmpty();
    TreeNode* getMin();
    TreeNode* getMax();
    TreeNode* getSuccessor(TreeNode *d);
    void printTree(TreeNode *node);
    void deleteTree(TreeNode *root);

    TreeNode *root;
};

#endif
