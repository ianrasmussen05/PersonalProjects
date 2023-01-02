#ifndef _TREENODE_H
#define _TREENODE_H

#include <string>
#include <iostream>

typedef struct {
    int key;
    std::string value;

    std::string print() {
        std::string str = "Key: " + std::to_string(key) + ", Value: " + value;
        return str;
    }
} Hash;

class TreeNode
{
  public:
    TreeNode();
    TreeNode(Hash *hash);
    ~TreeNode();

    Hash *key;
    TreeNode *left;
    TreeNode *right;
};

#endif
