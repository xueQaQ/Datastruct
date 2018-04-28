#pragma once

#define FOR_BINTREE
#ifdef FOR_BINTREE
struct TreeNode;
typedef struct TreeNode* SeqQueueType;
#else
typedef char TreeNodeType;
#define

//使用孩子表示法表示方法
typedef struct TreeNode{
    TreeNodeType data;
    struct TreeNode* lchild;
    struct TreeNode* rchild;
}TreeNode;

//初始化二叉树
void TreeInit(TreeNode** pRoot);

//创建一个树
void CreatTreeNode(TreeNode* root,TreeNodeType value);

//遍历
//先序遍历
void TreePreOrder(TreeNode* root);

//中序遍历
void TreeInOrder(TreeNode* root);

//右序遍历
void TreeRigOrder(TreeNode* root);

//二叉树的销毁
void TreeDestory(TreeNode* root);

//求节点的个数
size_t TreeSize(TreeNode* root);

//辅助函数
_TreeSize(TreeNode* root,size_t* size);

//二叉树叶子节点的个数
size_t TreeLeafSize(TreeNode* root);

//二叉树第k层节点的个数
size_t TreeLevelSize(TreeNode* root);

//二叉树树高
size_t TreeHeight(TreeNode* root);
