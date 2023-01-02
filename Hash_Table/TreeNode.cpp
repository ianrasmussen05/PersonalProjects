#include "TreeNode.h"

TreeNode::TreeNode()
{
  key = 0;
  left = NULL;
  right = NULL;
}

TreeNode::TreeNode(Hash *hash)
{
  key = hash;
  left = NULL;
  right = NULL;
}

TreeNode::~TreeNode()
{
  delete key;
  delete left;
  delete right;
}
