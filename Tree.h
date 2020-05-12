//
// Created by Mor on 04/05/2020.
//

#ifndef TREETEST2_TREE_H
#define TREETEST2_TREE_H

#include <iostream>
#include <algorithm>

using std::max;

typedef enum {
    SUCCESS = 0,
    FAILURE,
    ALLOCATION_ERROR
} StatusType;

template<class T>
class TreeNode {
private:
    int key;
    T *value;
    int nodeHeight = 1;
    TreeNode<T> *parent = nullptr;
    TreeNode<T> *left = nullptr;
    TreeNode<T> *right = nullptr;
public:
    TreeNode(int key, T *value);

    ~TreeNode();

    int getKey();

    void setKey(int gKey);

    T *getValue();

    void setValue(T *value);

    void removeValue();

    TreeNode<T> *getLeft();

    void setLeft(TreeNode<T> *nLeft);

    TreeNode<T> *getRight();

    void setRight(TreeNode<T> *nRight);

    TreeNode<T> *getParent();

    void setParent(TreeNode<T> *nParent);

    int getHeight();

    void setHeight(int height);

    static TreeNode<T> *find(TreeNode<T> *node, int gKey);

    TreeNode<T> *findMin(TreeNode<T> *node);

    TreeNode<T> *getNext();

    static void printPreOrder(TreeNode<T> *node);

    static void printInOrder(TreeNode<T> *node);

    static void printPostOrder(TreeNode<T> *node);

    static int calculateHeight(TreeNode<T> *root) {
        // update heights
        TreeNode<T> *subRightTree = root->getRight();
        TreeNode<T> *subLeftTree = root->getLeft();
        int subLeftHeight = 0;
        int subRightHeight = 0;
        if (subLeftTree) {
            subLeftHeight = subLeftTree->getHeight();
        }
        if (subRightTree) {
            subRightHeight = subRightTree->getHeight();
        }
        return 1 + max(subLeftHeight, subRightHeight);
    }

    static int getBalance(TreeNode<T> *node) {
        if (node == nullptr) {
            return 0;
        }
        TreeNode<T> *iLeft = node->getLeft();
        TreeNode<T> *iRight = node->getRight();
        int leftHeight = 0;
        int rightHeight = 0;
        if (iLeft) {
            leftHeight = iLeft->getHeight();
        }
        if (iRight) {
            rightHeight = iRight->getHeight();
        }
        return leftHeight - rightHeight;
    }
};

template<class T>
TreeNode<T>::TreeNode(int key, T *value): key(key), value(value) {

}

template<class T>
TreeNode<T>::~TreeNode() {
    if (this->right != nullptr) {
        delete this->right;
    }
    if (this->left != nullptr) {
        delete this->left;
    }
    if (this->value != nullptr) {
        delete this->value;
    }
}

template<class T>
int TreeNode<T>::getKey() {
    return this->key;
}

template<class T>
void TreeNode<T>::setKey(int gKey) {
    this->key = gKey;
}

template<class T>
T *TreeNode<T>::getValue() {
    return this->value;
}

template<class T>
void TreeNode<T>::setValue(T *value) {
    delete this->value;
    this->value = value;
}

template<class T>
void TreeNode<T>::removeValue() {
    this->value = nullptr;
}

template<class T>
TreeNode<T> *TreeNode<T>::getLeft() {
    return this->left;
}

template<class T>
void TreeNode<T>::setLeft(TreeNode<T> *nLeft) {
    this->left = nLeft;
}

template<class T>
TreeNode<T> *TreeNode<T>::getRight() {
    return this->right;
}

template<class T>
void TreeNode<T>::setRight(TreeNode<T> *nRight) {
    this->right = nRight;
}

template<class T>
TreeNode<T> *TreeNode<T>::getParent() {
    return this->parent;
}

template<class T>
void TreeNode<T>::setParent(TreeNode<T> *nParent) {
    this->parent = nParent;
}

template<class T>
int TreeNode<T>::getHeight() {
    return this->nodeHeight;
}

template<class T>
void TreeNode<T>::setHeight(int height) {
    this->nodeHeight = height;
}

template<class T>
TreeNode<T> *TreeNode<T>::find(TreeNode<T> *node, int gKey) {
    if (!node) {
        return nullptr;
    } else if (node->getKey() == gKey) {
        // The current node is the one we're looking for
        return node;
    } else if (node->getKey() > gKey) {
        // The current node is a father of the node we're looking for
        return find(node->getLeft(), gKey);
    } else {
        // The current node is a father of the node we're looking for
        return find(node->getRight(), gKey);
    }
}

template<class T>
TreeNode<T> *TreeNode<T>::findMin(TreeNode<T> *node) {
    if (node == nullptr) {
        return nullptr;
    } else if (node->getLeft() == nullptr) {
        // This node has no left child, which means it is the following node in the tree
        return node;
    } else {
        return findMin(node->getLeft());
    }
}

template<class T>
TreeNode<T> *TreeNode<T>::getNext() {
    TreeNode<T> *current = this;
    if (current->getRight() != nullptr) {
        // This node has a right child, which means if we follow the branch
        // once to the right and then all the way to the left, we will find the
        // correct following child
        return findMin(current->getRight());
    } else {
        TreeNode<T> *parent = current->getParent();
        while (parent != nullptr) {
            TreeNode<T> *child = parent->getLeft();
            if (child && child->getKey() == current->getKey()) {
                // The node we started with is the left child of the current parent,
                // which means the parent is the next node in the tree.
                return parent;
            }
            current = parent;
            parent = current->getParent();
        }
        return parent;
    }
}

template<class T>
void TreeNode<T>::printPreOrder(TreeNode<T> *node) {
    if (!node) {
        return;
    }

    // Print the data of our node
    std::cout << node->getKey() << ", ";

    // Print the left subtree
    printPreOrder(node->getLeft());

    // Print the right subtree
    printPreOrder(node->getRight());
}

template<class T>
void TreeNode<T>::printInOrder(TreeNode<T> *node) {
    if (!node) {
        return;
    }

    // Print the left subtree
    printInOrder(node->getLeft());

    // Print the data of our node
    std::cout << node->getKey() << ", ";

    // Print the right subtree
    printInOrder(node->getRight());
}

template<class T>
void TreeNode<T>::printPostOrder(TreeNode<T> *node) {
    if (!node) {
        return;
    }

    // Print the left subtree
    printPostOrder(node->getLeft());

    // Print the right subtree
    printPostOrder(node->getRight());

    // Print the data of our node
    std::cout << node->getKey() << ", ";
}

template<class T>
class Tree {
private:
    TreeNode<T> *root;

    void InsertNode(TreeNode<T> *iRoot, TreeNode<T> *ins);

    void RemoveNode(TreeNode<T> *iRoot, int key);

public:
    Tree();

    ~Tree();

    StatusType Insert(int key, T *value);

    StatusType Remove(int key);

    int Height(TreeNode<T> *root) const;

    TreeNode<T> *Find(int key);

    TreeNode<T> *RightRotate(TreeNode<T> *node);

    TreeNode<T> *LeftRotate(TreeNode<T> *node);

    bool IsEmpty();

    void PrintPreOrder();

    void PrintInOrder();

    void PrintPostOrder();
};

template<class T>
Tree<T>::Tree(): root(nullptr) {

}

template<class T>
Tree<T>::~Tree() {
    if (root) {
        delete root;
        root = nullptr;
    }
}

template<class T>
StatusType Tree<T>::Insert(int key, T *value) {
    TreeNode<T> *nNode = new TreeNode<T>(key, value);

    if (!nNode) {
        return ALLOCATION_ERROR;
    }

    if (!root) {
        // Tree is empty, setting new node as first node
        root = nNode;
    } else {
        InsertNode(root, nNode);
    }
    return SUCCESS;
}

template<class T>
void Tree<T>::InsertNode(TreeNode<T> *iRoot, TreeNode<T> *ins) {
    bool trueRoot = false;
    if (iRoot == nullptr) {
        return;
    }
    if (!iRoot->getParent()) {
        trueRoot = true;
    }
    // Before using insert we already check if the key exists in the tree,
    // so no need to check this here.
    if (ins->getKey() < iRoot->getKey()) {
        if (iRoot->getLeft()) {
            // iRoot has a left child, continue searching for correct spot to place
            // new node
            InsertNode(iRoot->getLeft(), ins);
        } else {
            iRoot->setLeft(ins);
            ins->setParent(iRoot);
        }

    } else {
        if (iRoot->getRight()) {
            // iRoot has a right child, continue searching for correct spot to place
            // new now
            InsertNode(iRoot->getRight(), ins);
        } else {
            iRoot->setRight(ins);
            ins->setParent(iRoot);
        }
    }

    // update heights
    TreeNode<T> *subRightTree = iRoot->getRight();
    TreeNode<T> *subLeftTree = iRoot->getLeft();
    int subLeftHeight = 0;
    int subRightHeight = 0;
    if (subLeftTree) {
        subLeftHeight = subLeftTree->getHeight();
    }
    if (subRightTree) {
        subRightHeight = subRightTree->getHeight();
    }
    iRoot->setHeight(1 + max(subLeftHeight, subRightHeight));

    int balance = TreeNode<T>::getBalance(iRoot);
    if(balance>2 || balance<-2){
        std::cout <<"BF problem in adding with key " << iRoot->getKey() << " BF is " << balance << std::endl;
    }
    // balancing the tree if necessary
    // LL case
    if (balance > 1 && ins->getKey() < subLeftTree->getKey()) {
        iRoot = RightRotate(iRoot);
    }

    // RR case
    if (balance < -1 && ins->getKey() > subRightTree->getKey()) {
        iRoot = LeftRotate(iRoot);
    }

    // LR case
    if (balance > 1 && ins->getKey() > subLeftTree->getKey()) {
        iRoot->setLeft(LeftRotate(iRoot->getLeft()));
        iRoot = RightRotate(iRoot);
    }

    // RL case
    if (balance < -1 && ins->getKey() < subRightTree->getKey()) {
        iRoot->setRight(RightRotate(iRoot->getRight()));
        iRoot = LeftRotate(iRoot);
    }
    if (trueRoot) {
        this->root = iRoot;
        TreeNode<T> *temp = this->root;
        temp->setParent(nullptr);
    } else {
        TreeNode<T> *temp = iRoot->getParent();
        if (temp->getKey() > iRoot->getKey()) {
            temp->setLeft(iRoot);
        } else {
            temp->setRight(iRoot);
        }
    }
}

template<class T>
StatusType Tree<T>::Remove(int key) {
    if (!root) {
        // Tree is empty, setting new node as first node
        return FAILURE;
    } else {
        RemoveNode(root, key);
    }
    return SUCCESS;
}

template<class T>
void Tree<T>::RemoveNode(TreeNode<T> *iRoot, int key) {
    bool trueRoot = false;
    if (!iRoot->getParent()) {
        trueRoot = true;
    }
    // called find before, know that a matching key exist
    if (iRoot->getKey() > key) {
        // should search at the left side
        RemoveNode(iRoot->getLeft(), key);
    } else if (iRoot->getKey() < key) {
        // should search at the right side
        RemoveNode(iRoot->getRight(), key);
    } else {
        // find a matching key :)
        if (iRoot->getLeft() == nullptr || iRoot->getRight() == nullptr) {
            // Node has either 1 child or none
            TreeNode<T> *temp = iRoot->getLeft() ? iRoot->getLeft() : iRoot->getRight();
            TreeNode<T> *parentTemp = iRoot->getParent();

            if (temp == nullptr) {
                // no child
                if (parentTemp) {
                    if (parentTemp->getKey() > key) {
                        // the node to be deleted is the left son
                        parentTemp->setLeft(nullptr);
                    } else {
                        // the node to be deleted is the right son
                        parentTemp->setRight(nullptr);
                    }
                }
                // We removed a node with no children, we removed his pointer
                // from his parent node, now we can safely delete him.
                if (trueRoot) {
                    this->root = nullptr;
                }
                iRoot->setLeft(nullptr);
                iRoot->setRight(nullptr);
                delete iRoot;
                iRoot = nullptr;
                return;
            } else {
                // one child case
                if (parentTemp) {
                    temp->setParent(parentTemp);
                    if (parentTemp->getKey() > key) {
                        // The node to be deleted is the left son
                        // connecting his only child to the left side of the original parent
                        parentTemp->setLeft(temp);
                    } else {
                        // The node to be deleted is the right son
                        // connecting his only child to the right side of the original parent
                        parentTemp->setRight(temp);
                    }
                } else {
                    this->root = temp;
                    temp->setParent(nullptr);
                }
                // We removed a node with one child, we removed his pointer
                // from his parent node, and set his child as the new child of his parent
                // now we can safely delete him.
                iRoot->setLeft(nullptr);
                iRoot->setRight(nullptr);
                delete iRoot;
                iRoot = nullptr;
                return;
            }
        } else {
            // node with 2 children case
            TreeNode<T> *temp = iRoot->findMin(iRoot->getRight());
            // Replacing the key and value of the node we want to delete with his successor
            iRoot->setKey(temp->getKey());
            iRoot->setValue(temp->getValue());
            temp->removeValue();
            // Removing the successor from his original place
            RemoveNode(iRoot->getRight(), temp->getKey());
        }
    }

    // update heights
    TreeNode<T> *subRightTree = iRoot->getRight();
    TreeNode<T> *subLeftTree = iRoot->getLeft();
    int subLeftHeight = 0;
    int subRightHeight = 0;
    if (subLeftTree) {
        subLeftHeight = subLeftTree->getHeight();
    }
    if (subRightTree) {
        subRightHeight = subRightTree->getHeight();
    }
    iRoot->setHeight(1 + max(subLeftHeight, subRightHeight));

    // Calculating the new balance factor
    int balance = TreeNode<T>::getBalance(iRoot);
    if(balance>2 || balance<-2){
        std::cout <<"BF problem in removing with key " << iRoot->getKey() << "BF is " << balance << std::endl;
    }
    // LL case
    if (balance > 1 && TreeNode<T>::getBalance(iRoot->getLeft()) >= 0) {
        iRoot = RightRotate(iRoot);
    }

    // LR case
    if (balance > 1 && TreeNode<T>::getBalance(iRoot->getLeft()) < 0) {
        iRoot->setLeft(LeftRotate(iRoot->getLeft()));
        iRoot = RightRotate(iRoot);
    }

    // RR case
    if (balance < -1 && TreeNode<T>::getBalance(iRoot->getRight()) <= 0) {
        iRoot = LeftRotate(iRoot);
    }

    // RL case
    if (balance < -1 && TreeNode<T>::getBalance(iRoot->getRight()) > 0) {
        iRoot->setRight(RightRotate(iRoot->getRight()));
        iRoot = LeftRotate(iRoot);
    }
    if (trueRoot) {
        this->root = iRoot;
        TreeNode<T> *temp = this->root;
        temp->setParent(nullptr);
    } else {
        TreeNode<T> *temp = iRoot->getParent();
        if (temp->getKey() > iRoot->getKey()) {
            temp->setLeft(iRoot);
        } else {
            temp->setRight(iRoot);
        }
    }
}

template<class T>
int Tree<T>::Height(TreeNode<T> *root) const {
    int height = 0;
    if (root != nullptr) {
        int left = Height(root->getLeft());
        int right = Height(root->getRight());
        height = 1 + max(left, right);
    }
    return height;
}

template<class T>
TreeNode<T> *Tree<T>::Find(int key) {
    if (!root) {
        return nullptr;
    }
    return TreeNode<T>::find(root, key);
}

template<class T>
TreeNode<T> *Tree<T>::LeftRotate(TreeNode<T> *node) {
    TreeNode<T> *y = node->getRight();
    TreeNode<T> *t = y->getLeft();

    y->setLeft(node);
    if (node) {
        y->setParent(node->getParent());
        node->setParent(y);
    }
    node->setRight(t);
    if (t) {
        t->setParent(node);
    }

    // update heights
    node->setHeight(TreeNode<T>::calculateHeight(node));

    y->setHeight(TreeNode<T>::calculateHeight(y));

    return y;

}

template<class T>
TreeNode<T> *Tree<T>::RightRotate(TreeNode<T> *node) {
    TreeNode<T> *x = node->getLeft();
    TreeNode<T> *t = x->getRight();

    x->setRight(node);
    if (node) {
        x->setParent(node->getParent());
        node->setParent(x);
    }
    node->setLeft(t);
    if (t) {
        t->setParent(node);
    }

    // update heights
    node->setHeight(TreeNode<T>::calculateHeight(node));

    x->setHeight(TreeNode<T>::calculateHeight(x));

    return x;
}

template<class T>
bool Tree<T>::IsEmpty() {
    return root == nullptr;
}

template<class T>
void Tree<T>::PrintPreOrder() {
    TreeNode<T>::printPreOrder(root);
}

template<class T>
void Tree<T>::PrintInOrder() {
    TreeNode<T>::printInOrder(root);
}

template<class T>
void Tree<T>::PrintPostOrder() {
    TreeNode<T>::printPostOrder(root);
}

#endif //TREETEST2_TREE_H

