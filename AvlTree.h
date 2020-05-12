//
// Created by Mor on 13/05/2020.
//

#ifndef TREE_AVLTREE_H
#define TREE_AVLTREE_H

#include <iostream>
#include <algorithm>
#include <cmath>

const int DEF_BALANCE = 0;
const int POS_BALANCE = 2;
const int NEG_BALANCE = -2;

/*  AVL node  */
template<class S>
class AVLnode {
public:
    int key;
    S *data;
    int height;
    AVLnode *left, *right, *parent;

    int getSize();

    AVLnode(int k, S *d, AVLnode *p) :
            key(k), data(d), height(0), left(NULL), right(NULL), parent(p) {
    }

    ~AVLnode() {
        left = NULL;
        right = NULL;
        parent = NULL;
    }

};

template<class S>
int AVLnode<S>::getSize() {
    int leftSize = this->left ? left->getSize() : 0;
    int rightSize = this->right ? right->getSize() : 0;
    return leftSize + rightSize + 1;
}

/*  AVL tree  */
template<class S>
class AVLtree {
private:
    void avlRotateRR(AVLnode<S> *node);

    void avlRotateLL(AVLnode<S> *node);

    void avlRotateLR(AVLnode<S> *node);

    void avlRotateRL(AVLnode<S> *node);

    int getHeight(AVLnode<S> *node);

    int getBF(AVLnode<S> *node);

    void adjustHeight(AVLnode<S> *node);

    void rebalance(AVLnode<S> *node);

public:
    AVLnode<S> *root;

    AVLtree() :
            root(NULL) {
    }

    ~AVLtree() {
        clearTree(root);
    }

    void insertKey(int key, S *data);

    void removeKey(int key, bool delete_data = true);

    bool findKey(int key);

    S *getData(int key);

    AVLnode<S> *getNodeByKey(int key);

    AVLnode<S> *findMaxKey();

    void inorder(AVLnode<S> *node);

    void inorderInsert(AVLnode<S> *node, AVLnode<S> **nodes, int *i);

    void revinorderInsert(AVLnode<S> *node, AVLnode<S> **nodes, int *i);

    void inorderPrint(AVLnode<S> *node, AVLnode<S> **nodes, int *i);

    void revinorderPrint(AVLnode<S> *node, AVLnode<S> **nodes, int *i);

    void treePrint(AVLnode<S> *node, int level);

    AVLnode<S> *createEmptyTree(int numOfObjects);

    AVLnode<S> *createEmptyTreeHelper(int numOfObjects, int height,
                                      AVLnode<S> *parent);

    void removeExtraNodes(int *amount, AVLnode<S> *node);

    void createAvlFromArray(int numOfObjects, AVLnode<S> **array);

    void cleanTreeData(AVLnode<S> *node);

    void clearTree(AVLnode<S> *node);
};

template<class S>
void AVLtree<S>::avlRotateRR(AVLnode<S> *node) {
    AVLnode<S> *temp = node->right;
    node->right = temp->left;
    if (temp->left != NULL)
        temp->left->parent = node;
    if (node->parent == NULL) {
        root = temp;
        temp->parent = NULL;
    } else if (node->parent->left == node)
        node->parent->left = temp;
    else
        node->parent->right = temp;
    temp->parent = node->parent;
    temp->left = node;
    node->parent = temp;
    adjustHeight(temp->left);
    adjustHeight(temp->right);
    adjustHeight(temp);
}

template<class S>
void AVLtree<S>::avlRotateLL(AVLnode<S> *node) {
    AVLnode<S> *temp = node->left;
    node->left = temp->right;
    if (temp->right != NULL)
        temp->right->parent = node;
    if (node->parent == NULL) {
        root = temp;
        temp->parent = NULL;
    } else if (node->parent->left == node)
        node->parent->left = temp;
    else
        node->parent->right = temp;
    temp->parent = node->parent;
    temp->right = node;
    node->parent = temp;
    adjustHeight(temp->left);
    adjustHeight(temp->right);
    adjustHeight(temp);
}

template<class S>
void AVLtree<S>::avlRotateLR(AVLnode<S> *node) {
    avlRotateRR(node->left);

    return avlRotateLL(node);
}

template<class S>
void AVLtree<S>::avlRotateRL(AVLnode<S> *node) {
    avlRotateLL(node->right);
    return avlRotateRR(node);
}

template<class S>
int AVLtree<S>::getHeight(AVLnode<S> *node) {
    if (node == NULL)
        return -1;
    return (1 + std::max(getHeight(node->left), getHeight(node->right)));
}

template<class S>
int AVLtree<S>::getBF(AVLnode<S> *node) {
    if (node == NULL)
        return DEF_BALANCE;
    else
        return getHeight(node->left) - getHeight(node->right);
}

template<class S>
void AVLtree<S>::adjustHeight(AVLnode<S> *node) {
    if (node == NULL)
        return;
    node->height = getHeight(node);
}

template<class S>
void AVLtree<S>::rebalance(AVLnode<S> *node) {
    while (node != NULL) {
        adjustHeight(node);
        if (getBF(node) == POS_BALANCE) {
            if (getBF(node->left) >= DEF_BALANCE)
                avlRotateLL(node);
            else
                avlRotateLR(node);
        } else if (getBF(node) == NEG_BALANCE) {
            if (getBF(node->right) <= DEF_BALANCE)
                avlRotateRR(node);
            else
                avlRotateRL(node);
        }
        node = node->parent;
    }
}

template<class S>
void AVLtree<S>::insertKey(int key, S *data) {
    if (root == NULL) {
        root = new AVLnode<S>(key, data, NULL);
        return;
    } else if (!findKey(key)) {
        AVLnode<S> *node = root;
        AVLnode<S> *parent = NULL;
        while (node != NULL) {
            parent = node;
            if (node->key > key)
                node = node->left;
            else
                node = node->right;
        }
        AVLnode<S> *newNode = new AVLnode<S>(key, data, parent);
        if (parent->key > key)
            parent->left = newNode;
        else
            parent->right = newNode;
        rebalance(newNode);
    }
}

template<class S>
void AVLtree<S>::removeKey(int key, bool delete_data) {
    if (root == NULL)
        return;
    if (findKey(key)) {
        AVLnode<S> *node = getNodeByKey(key);
        AVLnode<S> *parent = node->parent;
        AVLnode<S> *bal_node = NULL;
        if (delete_data)
            delete node->data;
        if ((node->left == NULL) && (node->right == NULL)) {
            if (parent) {
                if (parent->right == node)
                    parent->right = NULL;
                else
                    parent->left = NULL;
            } else
                root = NULL;
            bal_node = parent;
            delete node;
        } else if ((node->left == NULL) && (node->right != NULL)) {
            if (parent) {
                if (parent->right == node) {
                    parent->right->key = node->right->key;
                    parent->right->data = node->right->data;
                } else {
                    parent->left->key = node->right->key;
                    parent->left->data = node->right->data;
                }
            } else {
                root->key = node->right->key;
                root->data = node->right->data;
            }
            bal_node = parent;
            node->right->parent = parent;
            delete node->right;
            node->right = NULL;
        } else if ((node->left != NULL) && (node->right == NULL)) {
            if (parent) {
                if (parent->right == node) {
                    parent->right->key = node->left->key;
                    parent->right->data = node->left->data;
                } else {
                    parent->left->key = node->left->key;
                    parent->left->data = node->left->data;
                }
            } else {
                root->key = node->left->key;
                root->data = node->left->data;
            }
            bal_node = parent;
            node->left->parent = parent;
            delete node->left;
            node->left = NULL;
        } else {
            AVLnode<S> *next = node->right;
            while (next->left != NULL)
                next = next->left;
            if (parent) {
                if (parent->right == node) {
                    parent->right->key = next->key;
                    parent->right->data = next->data;
                } else {
                    parent->left->key = next->key;
                    parent->left->data = next->data;
                }
            } else {
                root->key = next->key;
                root->data = next->data;
            }
            if (next->parent->left == next)
                next->parent->left = next->right;
            else
                next->parent->right = next->right;
            if (next->right)
                next->right->parent = next->parent;
            bal_node = next->parent;
            next->parent = parent;
            delete next;
        }
        if (bal_node)
            rebalance(bal_node);
        else
            rebalance(root);
    }
}

template<class S>
bool AVLtree<S>::findKey(int key) {
    if (root == NULL)
        return false;
    else {
        AVLnode<S> *node = root;
        while (node != NULL) {
            if (node->key == key)
                return true;
            bool goLeft = node->key > key;
            if (goLeft)
                node = node->left;
            else
                node = node->right;
        }
        return false;
    }
}

template<class S>
S *AVLtree<S>::getData(int key) {
    if (!findKey(key) || root == NULL) {
        return NULL;
    } else {
        AVLnode<S> *node = root;
        while (node != NULL) {
            if (node->key == key)
                return node->data;
            bool goLeft = node->key > key;
            if (goLeft)
                node = node->left;
            else
                node = node->right;
        }
    }
    return NULL;
}

template<class S>
AVLnode<S> *AVLtree<S>::getNodeByKey(int key) {
    if (!findKey(key) || root == NULL) {
        return NULL;
    } else {
        AVLnode<S> *node = root;
        while (node != NULL) {
            if (node->key == key)
                return node;
            bool goLeft = node->key > key;
            if (goLeft)
                node = node->left;
            else
                node = node->right;
        }
    }
    return NULL;
}

template<class S>
AVLnode<S> *AVLtree<S>::findMaxKey() {
    if (root == NULL)
        return NULL;
    AVLnode<S> *node = root;
    while (node->right != NULL)
        node = node->right;
    return node;
}

template<class S>
void AVLtree<S>::inorder(AVLnode<S> *node) {
    if (node == NULL)
        return;
    else {
        inorder(node->left);
        if ((getBF(node) == 2) || (getBF(node) == -2)) {
            std::cout << *node->key << "Problem!!!" << " ";
            return;
        } else
            std::cout << *node->key << "(" << getBF(node) << ")" << " ";
        inorder(node->right);
    }
}

template<class S>
void AVLtree<S>::inorderInsert(AVLnode<S> *node, AVLnode<S> **nodes,
                               int *i) {
    if (node == NULL)
        return;
    else {
        inorderInsert(node->left, nodes, i);
        node->key = nodes[*i]->key;
        node->data = nodes[*i]->data;
        (*i)++;
        inorderInsert(node->right, nodes, i);

    }
}

template<class S>
void AVLtree<S>::revinorderInsert(AVLnode<S> *node, AVLnode<S> **nodes,
                                  int *i) {
    if (node == NULL)
        return;
    else {
        revinorderPrint(node->right, nodes, i);
        node->key = nodes[*i]->key;
        node->data = nodes[*i]->data;
        (*i)++;
        revinorderPrint(node->left, nodes, i);
    }
}

template<class S>
void AVLtree<S>::inorderPrint(AVLnode<S> *node, AVLnode<S> **nodes,
                              int *i) {
    if (node == NULL)
        return;
    else {
        inorderPrint(node->left, nodes, i);
        nodes[*i] = node;
        (*i)++;
        inorderPrint(node->right, nodes, i);
    }
}

template<class S>
void AVLtree<S>::revinorderPrint(AVLnode<S> *node, AVLnode<S> **nodes,
                                 int *i) {
    if (node == NULL)
        return;
    else {
        revinorderPrint(node->right, nodes, i);
        nodes[(*i)] = node;
        (*i)++;
        revinorderPrint(node->left, nodes, i);
    }
}

template<class S>
void AVLtree<S>::treePrint(AVLnode<S> *node, int level) {
    int i;
    if (node != NULL) {
        treePrint(node->right, level + 1);
        std::cout << std::endl;
        if (node == root)
            std::cout << "Root -> ";
        for (i = 0; i < level && node != root; i++)
            std::cout << "        ";
        std::cout << node->key;
        treePrint(node->left, level + 1);
    }
}

template<class S>
AVLnode<S> *AVLtree<S>::createEmptyTree(int numOfObjects) {
    int amount = 1;
    int power = 1;
    // find the tree size
    while (amount < numOfObjects) {
        power++;
        amount = pow(2, power) - 1;
    }
    AVLnode<S> *newTree = new AVLnode<S>(NULL, NULL, NULL);
    newTree->height = power;

    newTree->left = createEmptyTreeHelper((amount - 1) / 2, power - 1, newTree);
    newTree->right = createEmptyTreeHelper((amount - 1) / 2, power - 1,
                                           newTree);

    int numToRemove = newTree->getSize() - numOfObjects;
    this->removeExtraNodes(&numToRemove, newTree);
    return newTree;
}

template<class S>
AVLnode<S> *AVLtree<S>::createEmptyTreeHelper(int numOfObjects,
                                              int height, AVLnode<S> *parent) {
    if (numOfObjects == 0) {
        return NULL;
    }
    AVLnode<S> *node = new AVLnode<S>(NULL, NULL, parent);
    node->height = height;
    node->left = createEmptyTreeHelper((numOfObjects - 1) / 2, height - 1,
                                       node);
    node->right = createEmptyTreeHelper((numOfObjects - 1) / 2, height - 1,
                                        node);
    return node;
}

template<class S>
void AVLtree<S>::removeExtraNodes(int *amount, AVLnode<S> *node) {
    if (*amount == 0 || !node) {
        return;
    }
    this->removeExtraNodes(amount, node->right);
    AVLnode<S> *nextNode = node->left;
    if (!node->right && !node->left) {
        if (node->parent) {
            if (node->parent->right == node) {
                node->parent->right = NULL;
            } else {
                node->parent->left = NULL;
            }
        }
        *amount = *amount - 1;
        delete node;
    }
    this->removeExtraNodes(amount, nextNode);
}

template<class S>
void AVLtree<S>::createAvlFromArray(int numOfObjects,
                                    AVLnode<S> **array) {
    int n = 0;

    if (numOfObjects == 0 || array == NULL) {
        return;
    }

    AVLnode<S> *newTree = this->createEmptyTree(numOfObjects);

    this->inorderInsert(newTree, array, &n);

    this->root = newTree;
}

template<class S>
void AVLtree<S>::cleanTreeData(AVLnode<S> *node) {
    if (node == NULL)
        return;
    else {
        cleanTreeData(node->right);
        node->data = NULL;

        cleanTreeData(node->left);
    }
}

template<class S>
void AVLtree<S>::clearTree(AVLnode<S> *node) {
    if (node != NULL) {
        clearTree(node->left);
        clearTree(node->right);
        if (node->data) {
            delete node->data;
        }
        delete node;
    }
}

#endif //TREE_AVLTREE_H
