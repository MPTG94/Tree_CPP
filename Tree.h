//
// Created by Mor on 04/05/2020.
//

#ifndef TREETEST2_TREE_H
#define TREETEST2_TREE_H

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

    TreeNode<T> *getLeft();

    void setLeft(TreeNode<T> *nLeft);

    TreeNode<T> *getRight();

    void setRight(TreeNode<T> *nRight);

    TreeNode<T> *getParent();

    void setParent(TreeNode<T> *nParent);

    static TreeNode<T> *find(TreeNode<T> *node, int gKey);

    TreeNode<T> *findMin(TreeNode<T> *node);

    TreeNode<T> *getNext();

    int getBalance(TreeNode<T> *node);
};

template<class T>
TreeNode<T>::TreeNode(int key, T *value): key(key), value(value) {

}

template<class T>
int TreeNode<T>::getKey() {
    return this->key;
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
            if (parent->getKey() == child->getKey()) {
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
TreeNode<T> *TreeNode<T>::findMin(TreeNode<T> *node) {
    if (node == nullptr) {
        return nullptr;
    } else if (node->getLeft() == nullptr) {
        // This node has no left child, which means it is the following node in the tree
        return this;
    } else {
        return findMin(node->getLeft());
    }
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
void TreeNode<T>::setKey(int gKey) {
    this->key = gKey;

}

template<class T>
int TreeNode<T>::getBalance(TreeNode<T> *node) {
    if (node = nullptr)
        return 0;
    return height(node->getLeft()) -
           height(node->getRight());
    return 0;
}

template<class T>
class Tree {
private:
    TreeNode<T> *root;

    void InsertNode(TreeNode<T> *iRoot, TreeNode<T> *ins);

public:
    Tree();

    ~Tree();

    StatusType Insert(int key, T *value);

    StatusType Remove(int key);

    int Height(TreeNode<T> *root) const;

    TreeNode<T> *Find(int key);

    void RotateLeftOnce(TreeNode<T> *node);

    void RotateLeftTwice(TreeNode<T> *node);

    void RotateRightOnce(TreeNode<T> *node);

    void RotateRightTwice(TreeNode<T> *node);
};

template<class T>
Tree<T>::Tree(): root(nullptr) {

}

template<class T>
TreeNode<T> *Tree<T>::Find(int key) {
    if (!root) {
        return nullptr;
    }
    return TreeNode<T>::find(root, key);
}

template<class T>
void Tree<T>::RotateLeftOnce(TreeNode<T> *node) {
    TreeNode<T> *otherNode = node->getLeft();
    node->setLeft(otherNode->getRight());
    otherNode->setRight(node);
    node = otherNode;
}

template<class T>
void Tree<T>::RotateLeftTwice(TreeNode<T> *node) {
    RotateRightOnce(node->getLeft());
    RotateLeftOnce(node);
}

template<class T>
void Tree<T>::RotateRightOnce(TreeNode<T> *node) {
    TreeNode<T> *otherNode = node->getRight();
    node->setRight(otherNode->getLeft());
    otherNode->setLeft(node);
    node = otherNode;
}

template<class T>
void Tree<T>::RotateRightTwice(TreeNode<T> *node) {
    RotateLeftOnce(node->getRight());
    RotateRightOnce(node);
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
    if (iRoot == nullptr) {
        return;
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
        // Now fixing balance issues
        if (Height(iRoot->getLeft()) - Height(iRoot->getRight()) == 2) {
            TreeNode<T> *check = iRoot->getLeft();
            if (ins->getKey() < check->getKey()) {
                RotateLeftOnce(iRoot);
            } else {
                RotateLeftTwice(iRoot);
            }
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
        // Now fixing balance issues
        if (Height(iRoot->getRight()) - Height(iRoot->getLeft()) == 2) {
            TreeNode<T> *check = iRoot->getRight();
            if (ins->getKey() > check->getKey()) {
                RotateRightOnce(iRoot);
            } else {
                RotateRightTwice(iRoot);
            }
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
Tree<T>::~Tree() {
    delete root;
    root = nullptr;
}

template<class T>
StatusType Tree<T>::Remove(int key) {
    //called find before, know that a matching key exist
    if (root == nullptr) {
        return FAILURE;
    } else if (root->getKey() > key) {
        //should search at the left side
        this->getLeft().remove(key);
    } else if (root->getKey() < key) {
        //should search at the right side
        this->getRight.Remove(key);
    } else {
        //find a matching key :)
        if (root->getLeft() == nullptr || root->getRight() == nullptr) {
            TreeNode<T> temp = root->getLeft() ? root->getLeft() : root->findMin();
            TreeNode<T> fatherTemp = root->getParent();

            if (temp == nullptr) {
                //no child
                if (root->getKey() > key) {
                    //the node to be deleted is the right son
                    fatherTemp.setLeft(nullptr);
                } else {
                    temp.setRight(nullptr);
                }
                delete root;
            } else {
                //one child case
                temp.setParent(root->getParent());
                if (root->getKey() > key) {
                    fatherTemp.setLeft(temp);
                } else {
                    fatherTemp.setRight(temp);
                }
                delete root;
            }
        } else {
            //node with 2 children
            TreeNode<T> temp = root->findMin(root->getRight());
            root->setKey(temp.getKey());
            root->setValue(temp.getValue());
            Remove(temp.getKey());
        }
    }

    int balance = root->getBalance(root);

    //LL case
    if (balance > 1 && root->getBalance(root->getLeft()) >= 0) {
        RotateRightOnce(root);
    }

    //LR case
    if (balance > 1 && root->getBalance(root->getLeft()) < 0) {
        RotateLeftTwice(root);
    }

    //RR case
    if (balance < -1 & root->getBalance(root->getRight()) <= 0) {
        RotateRightOnce(root);
    }

    //RL case
    if (balance < -1 && root->getBalance(root->getRight()) > 0) {
        return RotateRightTwice(root);
    }

    return SUCCESS;
}

#endif //TREETEST2_TREE_H

