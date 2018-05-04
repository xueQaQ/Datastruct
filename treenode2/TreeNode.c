#include"TreeNode.h"

//实现初始化；要修改一个指针用**
void TreeInit(TreeNode** pRoot){
    if(pRoot == NULL){
        return;
    }
    *pRoot == NULL;
}
//实现创建一个树
void CreatTreeNode(TreeNode* root,TreeNodeType value){
    TreeNode* a = CreatTreeNode(&root);
    TreeNode* new_node = (TreeNode*)malloc(sizeof(TreeNode));
    new_node->data = value;
}

//实现先序遍历
void TreePreOrder(TreeNode* root){
    if(root == NULL){
        //空树
        return;
    }
    //1、先访问跟结点
    printf("%c",root->data);
    //2、递归遍历左子树
    TreePreOrder(root->lchild);
    //3、然后递归遍历右子树
    TreePreOrder(root->rchild);
    return;
}


//实现中序遍历
void TreeInOrder(TreeNode* root){
    if(root == NULL){
        return;
    }
    //左根右
    TreeInOrder(root->lchild);
    printf("%c",root->data);
    TreeInOrder(root->rchild);
}

//实现后续遍历
void TreeRigOrder(TreeNode* root){
    if(root == NULL){
        return;
    }
    //左右根
    TreeRigOrder(root->lchild);
    TreeRigOrder(root->rchild);
    printf("%c",root->data);
} 

//实现二叉树的销毁
void TreeDestory(TreeNode* root){
    if(root == NULL){
        return;
    }
    //后续遍历销毁
    TreeDestory(root->lchild);
    TreeDestory(root->rchild);
    TreeDestory(root);
    return;
}

//实现求节点个数
size_t TreeSize(TreeNode* root){
    size_t size = 0;
    _TreeSize(root,&size);
    return size;
}

//辅助方法
void _TreeSize(TreeNode* root,size_t* size){
    if(root == NULL){
        return;
    }
    ++(*size);
    _TreeSize(root->lchild,size);
    _TreeSize(root->rchild,size);
}

//实现二叉树叶子节点的个数
size_t TreeLeafSize(TreeNode* root){
    if(root == NULL){
        return;
    }
    if(root->lchild == NULL&&root->rchild == NULL){
       //root是叶子节点
        return 1;
    }
    //root不是叶子节点
    return TreeLeafSize(root->lchild)+TreeLeafSize(root->rchild);
}

//求二叉树第k层的节点
size_t TreeLevelSize(TreeNode* root,int k){
    if(root == NULL||k<1){
        return;
    }
    if(k == 1){
        return;
    }
    return TreeLevelSize(root->lchild,k-1)+(TreeLevelSize(root->rchild,k-1));
}

//二叉树的树高
size_t TreeHeight(TreeNode* root){
    if(root == NULL){
        return 0;
    }
    if(root->lchild == NULL&&root->rchild == NULL){
        return 1;
    }
    size_t lheight == TreeHeight(root->lchild);
    size_t rheifht == TreeHeight(root->rchild);
    return 1+(lheight>rheifht?lheight:rheifht);
}

//在二叉树中查找节点，给定一个数值，求出对应节点的指针
TreeNode* TreeFind(TreeNode* root,TreeNodeType to_find){
    if(root == NULL){
        return;
    }
    if(root->data == to_find){
        return root;
    }
    TreeNode* lresult = TreeFind(root->lchild,to_find);
    TreeNode* rresult = TreeFind(root->rchild,to_find);
    return lresult != NULL ? lresult:rresult;
}

//求child的父节点
TreeNode* Parent(TreeNode* root,TreeNode* child){
    if(root == NULL || child == NULL){
        return NULL;
    }
    if(root->lchild == child || root->rchild == child){
        return root;
    }
    TreeNode* lresult = Parent(root->lchild,child);
    TreeNode* rresult = Parent(root->rchild,child);
    return lresult != NULL?lresult:rresult;
}

//求当前节点的左子树和右子树
TreeNode* Lchild(TreeNode* node){
    if(node == NULL){
        return NULL;
    }
    return node->lchild;
}

