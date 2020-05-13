//
// Created by Mor on 04/05/2020.
//

#ifndef TREETEST2_TREE_H
#define TREETEST2_TREE_H

#include <iostream> // TODO only for testing

using std::cout;
using std::endl;

/**
 * This is a generic template for an AVL node, the nodes of AVL Tree
 * the nodes of a tree can have unique data stored in them *
 */
template<class T>
class TreeNode {
    T *data;
    int key;
    TreeNode<T> *left, *right, *parent;
    int height;

    void updateHeight();

    TreeNode<T> *r_rotation();

    TreeNode<T> *l_rotation();

    TreeNode<T> *lr_rotation();

    TreeNode<T> *rl_rotation();

    TreeNode<T> *balanceTree();

    int getBalanceFactor();

    TreeNode<T> *removeAUX(int keyRemove);

    void adjustParent(TreeNode<T> *takePlace);

public:
    TreeNode(int key, T *data_in = nullptr, TreeNode *parent = nullptr);

    ~TreeNode();

    void clearAll();

    TreeNode<T> *Insert(int keyAdd, T *dataAdd = nullptr, TreeNode<T> *result = nullptr);

    TreeNode<T> *remove(int keyRemove);

    TreeNode<T> *Find(int keyFind);

    TreeNode<T> *getMinNode();

    TreeNode<T> *getMaxNode();

    T *getData();

    int getKey();

    TreeNode<T> *getLeftSon();

    TreeNode<T> *getRightSon();

    TreeNode<T> *getParent();

    int mapInOrder(int *keys, int size);

    int mapSucc(int *keys, int size);

    // test funcs: // TODO delete or put in doc
    void printInOrder();

    void printInOrderAUX();

    int countNodes();

    bool checkBalancedAVL();
};


/**
 * creates node
 * @tparam T
 * @param key
 * @param data_in
 * @param parent
 */
template<class T>
TreeNode<T>::TreeNode(int key, T *data_in, TreeNode *parent):
        data(data_in), key(key), left(nullptr), right(nullptr), parent(parent), height(1) {};

/**
 * delete node and it release its data
 * does not delete its parent or sons!
 * @tparam T
 */
template<class T>
TreeNode<T>::~TreeNode() {
    if (data != nullptr) {
        delete data;
        data = nullptr;
    }
}

/**
 * delete the node and all its sons, grandsons and so on
 * use when we want to delete not just the current node (this) but all the data that connects to it
 * @param T
 */
template<class T>
void TreeNode<T>::clearAll() {
    if (left != nullptr) {
        left->clearAll();
        delete left;
        left = nullptr;
    }
    if (right != nullptr) {
        right->clearAll();
        delete right;
        right = nullptr;
    }
}

/**
 * @tparam T
 * @return the custom data of the node
 */
template<class T>
T *TreeNode<T>::getData() {
    return data;
}

/**
 * @tparam T
 * @return node's key
 */
template<class T>
int TreeNode<T>::getKey() {
    return key;
}

/**
 * @tparam T
 * @return ptr to left son
 */
template<class T>
TreeNode<T> *TreeNode<T>::getLeftSon() {
    return left;
}

/**
 * @tparam T
 * @return ptr to right son
 */
template<class T>
TreeNode<T> *TreeNode<T>::getRightSon() {
    return right;
}

/**
 * @tparam T
 * @return ptr to node's parent
 */
template<class T>
TreeNode<T> *TreeNode<T>::getParent() {
    return parent;
}

/**
 * @tparam T
 * @param keyFind
 * @return a node given its key (if not found return nullptr)
 */
template<class T>
TreeNode<T> *TreeNode<T>::Find(int keyFind) {
    if (keyFind == key) {
        return this;
    } else if (keyFind < key) {
        if (left != nullptr) {
            return left->Find(keyFind);
        } else {
            return nullptr;
        }
    } else {
        if (right != nullptr) {
            return right->Find(keyFind);
        } else {
            return nullptr;
        }
    }
}


/**
 *
 * @tparam T
 * @param keyAdd
 * @param dataAdd
 * @return add a new node in this connected nodes data structure, with param keyAdd and dataAdd
 * the Insert is by AVL-ordering-by-key
 * if during Insert founds that keyAdd already in struct, does not do anything
 */
template<class T>
TreeNode<T> *TreeNode<T>::Insert(int keyAdd, T *dataAdd, TreeNode<T> *result) {

    if (keyAdd > key) {
        if (right == nullptr) {
            right = new TreeNode(keyAdd, dataAdd, this);
            result = right;
        } else {
            right->Insert(keyAdd, dataAdd, result);
        }
    } else if (keyAdd < key) {
        if (left == nullptr) {
            left = new TreeNode(keyAdd, dataAdd, this);
            result = left;
        } else {
            left->Insert(keyAdd, dataAdd, result);
        }
    } else {
        return nullptr; // indicate already in tree. no actions or changing in tree
    }
    return balanceTree();
}

/**
 * updeate node's height
 * @tparam T
 */
template<class T>
void TreeNode<T>::updateHeight() {
    int tmpRight = 0, tmpLeft = 0;
    if (left != nullptr) {
        tmpLeft = left->height;
    }
    if (right != nullptr) {
        tmpRight = right->height;
    }

    if (tmpLeft > tmpRight) {
        height = tmpLeft + 1;
    } else {
        height = tmpRight + 1;
    }
}

/**
 * single right rotation
 * @tparam T
 * @return update root of sub-node-struct
 */
template<class T>
TreeNode<T> *TreeNode<T>::r_rotation() {
    TreeNode<T> *tmpRight = right;
    right = right->left;
    if (right != nullptr) {
        right->parent = this;
    }
    tmpRight->left = this;
    tmpRight->parent = this->parent;
    if (this->parent != nullptr) {
        if (this->parent->left != nullptr && this->parent->left->key == this->key) {
            this->parent->left = tmpRight;
        } else {
            this->parent->right = tmpRight;
        }
    }
    this->parent = tmpRight;
    this->updateHeight();
    tmpRight->updateHeight();
    return tmpRight;
}

/**
 * single left rotation
 * @tparam T
 * @return update root of sub-node-struct
 */
template<class T>
TreeNode<T> *TreeNode<T>::l_rotation() {
    TreeNode<T> *tmpLeft = left;
    left = left->right;
    if (left != nullptr) {
        left->parent = this;
    }
    tmpLeft->right = this;
    tmpLeft->parent = this->parent;
    if (this->parent != nullptr) {
        if (this->parent->left != nullptr && this->parent->left->key == this->key) {
            this->parent->left = tmpLeft;
        } else {
            this->parent->right = tmpLeft;
        }
    }
    this->parent = tmpLeft;
    this->updateHeight();
    tmpLeft->updateHeight();
    return tmpLeft;
}

/**
 * one right rotation and than left rotation
 * @tparam T
 * @return update root of sub-node-struct
 */
template<class T>
TreeNode<T> *TreeNode<T>::lr_rotation() {
    left->r_rotation();
    return this->l_rotation();
}

/**
 * one left rotation and than right rotation
 * @tparam T
 * @return update root of sub-node-struct
 */
template<class T>
TreeNode<T> *TreeNode<T>::rl_rotation() {
    right->l_rotation();
    return this->r_rotation();
}

template<class T>
int TreeNode<T>::getBalanceFactor() {
    updateHeight();
    int tmpRight = 0, tmpLeft = 0;
    if (right != nullptr) {
        tmpRight = right->height;
    }
    if (left != nullptr) {
        tmpLeft = left->height;
    }
    return tmpLeft - tmpRight;
}

/**
 * balances nodes (as AVL tree)
 * @tparam T
 * @return update root of sub-node-struct
 */
template<class T>
TreeNode<T> *TreeNode<T>::balanceTree() {
    int bf = getBalanceFactor(); // bf = Balance Factor

    if (bf > 1) {
        int sub_bf = left->getBalanceFactor();
        if (sub_bf >= 0) {
            return l_rotation();
        } else {
            return lr_rotation();
        }
    } else if (bf < -1) {
        int sub_bf = right->getBalanceFactor();
        if (sub_bf > 0) {
            return rl_rotation();
        } else {
            return r_rotation();
        }
    }
    return this;
}

/**
 * Find if keyRemove is one of nodes key and Remove it from struct
 * @tparam T
 * @param keyRemove
 * @return update root of sub-node-struct
 */
template<class T>
TreeNode<T> *TreeNode<T>::remove(int keyRemove) {
    if (keyRemove < key) { //if key is lower than root, Find left subtree
        if (left != nullptr) {
            left->remove(keyRemove);
        } else {
            return this;
        }
    } else if (keyRemove > key) { //if key is bigger than root, Find right subtree
        if (right != nullptr) {
            right->remove(keyRemove);
        } else {
            return this;
        }
    } else { //key found, current node holds key
        return this->removeAUX(keyRemove); // calls a function that actually delete current node
    }
    return balanceTree();
}

/**
 * delete this (Current) from node-struct
 * @tparam T
 * @param keyRemove
 * @return update root of sub-node-struct
 */
template<class T>
TreeNode<T> *TreeNode<T>::removeAUX(int keyRemove) {
    if (left != nullptr) { //Find successor of node
        TreeNode<T> *successor = left->getMaxNode();
        if (left->right != nullptr) {
            successor->parent->right = successor->left;
            if (successor->left != nullptr) {
                successor->left->parent = successor->parent;
            }
            successor->left = this->left;
            this->left->parent = successor;
        }
        this->adjustParent(successor);
        successor->right = this->right;
        if (this->right != nullptr) {
            this->right->parent = successor;
        }
        delete this;
        return successor->balanceTree();
    } else if (right != nullptr) {
        TreeNode<T> *successor = this->right;
        this->adjustParent(successor);
        delete this;
        return successor->balanceTree();
    } else { // no sons to delete node
        this->adjustParent(nullptr);
        delete this;
        return nullptr;
    }
}

/**
 * adjust parents between nodes that been delete and its successor
 * @tparam T
 * @param takePlace - successor
 */
template<class T>
void TreeNode<T>::adjustParent(TreeNode<T> *takePlace) {
    if (takePlace != nullptr) {
        takePlace->parent = this->parent;
    }
    if (this->parent != nullptr) {
        if (this->parent->left != nullptr && this->parent->left->key == this->key) {
            this->parent->left = takePlace;
        } else {
            this->parent->right = takePlace;
        }
    }
}

/**
 *
 * @tparam T
 * @return min by key node in struct
 */
template<class T>
TreeNode<T> *TreeNode<T>::getMinNode() {
    if (left != nullptr) {
        return left->getMinNode();
    }
    return this;
}

/**
 *
 * @tparam T
 * @return max by key node in struct
 */
template<class T>
TreeNode<T> *TreeNode<T>::getMaxNode() {
    if (right != nullptr) {
        return right->getMaxNode();
    }
    return this;
}

/**
 * scan the node-struct by "in-order" method
 * (from current down. does not go up to parent)
 * @tparam T
 * @param keys - arr. assign the  #size lowest keys in the tree into this arr
 * @param size - num of data to copy into keys[]
 * @return the number of keys that were assign to keys[]
 */
template<class T>
int TreeNode<T>::mapInOrder(int *keys, int size) {
    if (size <= 0 || keys == nullptr) {
        return 0;
    }

    int index = 0;
    if (left != nullptr) {
        index += left->mapInOrder(keys, size);
        if (index >= size) {
            return index;
        }
    }

    keys[index++] = key;

    if (index < size && right != nullptr) {
        index += right->mapInOrder(keys + index, size - index);
    }
    return index;
}

/**
 * scan the node-struct by "successor in-order" method
 * (from current up. does not go to current sons)
 * @tparam T
 * @param keys - arr. assign the  #size lowest keys in the tree into this arr
 * @param size - num of data to copy into keys[]
 * @return the number of keys that were assign to keys[]
 */
template<class T>
int TreeNode<T>::mapSucc(int *keys, int size) {
    if (size <= 0 || keys == nullptr) {
        return 0;
    }
    int index = 0;
    TreeNode<T> *current = this;
    while (current && index < size) {
        keys[index++] = current->key;
        if (current->right) {
            index += current->right->mapInOrder(keys + index, size - index);
        }
        current = current->parent;
    }
    return index;
}


// TODO used only for testing. delete or make as doc
template<class T>
void TreeNode<T>::printInOrder() {

    int tmpCalc = 1;
    for (int i = 0; i < height + 1; ++i) {
        tmpCalc = tmpCalc * 2;
    }
    tmpCalc--;

    int tmpCount = countNodes();

    cout << "**** print in order: num of Nodes: " << tmpCount << ", max height: " << height <<
         ". AVL test (height^2+1)-1>=nodes num (1 is OK): " << (tmpCalc >= tmpCount) << " ****" << std::endl;
    cout << "[";
    printInOrderAUX();
    cout << "]" << endl;
    cout << endl;
}

template<class T>
void TreeNode<T>::printInOrderAUX() {
    if (left != nullptr) {
        left->printInOrderAUX();
    }
    cout << ", " << key;
    if (right != nullptr) {
        right->printInOrderAUX();
    }
}

template<class T>
int TreeNode<T>::countNodes() {
    checkBalancedAVL();

    int tmpR = 0, tmpL = 0;

    if (right != nullptr) {
        tmpR = right->countNodes();
    }
    if (left != nullptr) {
        tmpL = left->countNodes();
    }
    return 1 + tmpL + tmpR;
}

/**
 * check no out of balanced nodes in struct
 * @tparam T
 * @return
 */
template<class T>
bool TreeNode<T>::checkBalancedAVL() {
    int flag = getBalanceFactor();
    if (flag > 1 || flag < -1) {
        cout << "BUG !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! BUG" << endl;
        cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! FOUND OUT OF BALANCED NODE !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
        cout << "BUG !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! BUG" << endl;
        return false;
    }
    return true;
}

/**
 * This is a generic template for an AVL Tree - the nodes of a tree can have unique data stored in them.
 * For example, a node may hold another AVL Tree inside it
 * in this implementation, the tree "take control" on its data in the meaning it become the charge of its release/delete
*/
template<class T>
class Tree {
    TreeNode<T> *root;
    TreeNode<T> *min_node; // lowest by key data in tree

public:
    Tree();

    ~Tree();

    void Insert(int key, T *data = nullptr);

    TreeNode<T> *InsertGetBack(int key, T *data);

    void Remove(int key);

    bool IsRootNull();

    TreeNode<T> *Find(int key);

    TreeNode<T> *getMinNode();

    int mapSucc(int *keys, int size);

};

/**
 * Initialize an empty AVL tree
 */
template<class T>
Tree<T>::Tree(): root(nullptr), min_node(nullptr) {};


/**
 * delete tree and release all its data
 */
template<class T>
Tree<T>::~Tree() {
    if (root != nullptr) {
        root->clearAll();
        delete root;
        root = nullptr;
    }
}

/**
 * Insert a single data represent by key to the tree
 * if key already shows in tree - nothing will be done
 * @param key the key of the data (node)
 * @param data
 */
template<class T>
void Tree<T>::Insert(int key, T *data) {
    if (root == nullptr) { // in case the tree is empty
        root = new TreeNode<T>(key, data);
        min_node = root;
    } else {
        root = root->Insert(key, data);

        if (!min_node || key < min_node->getKey()) { // in case we Insert new min by key data
            this->min_node = root->getMinNode();
        }
    }
}

template<class T>
TreeNode<T> *Tree<T>::InsertGetBack(int key, T *data) {
    if (root == nullptr) { // in case the tree is empty
        root = new TreeNode<T>(key, data);
        min_node = root;
        return root;
    } else {
        TreeNode<T> *result = nullptr;
        root = root->Insert(key, data, result);

        if (!min_node || key < min_node->getKey()) { // in case we Insert new min by key data
            this->min_node = root->getMinNode();
        }
        return result;
    }
}

/**
 * Remove the data (node) with the key value from the tree
 * @param key
 */
template<class T>
void Tree<T>::Remove(int key) {
    bool flag = min_node != nullptr && min_node->getKey() == key;
    if (root != nullptr) {
        root = root->remove(key);
        if (flag) {
            if (root != nullptr) {
                min_node = root->getMinNode();
            } else {
                min_node = nullptr;
            }
        }
    }
}

/**
 * @param key
 * @return Returns a node given its key
 * return nullptr if not found
 */
template<class T>
TreeNode<T> *Tree<T>::Find(int key) {
    if (root == nullptr) {
        return nullptr;
    }

    return root->Find(key);
}

/**
 * @return true if tree has no data, false otherwise
 */
template<class T>
bool Tree<T>::IsRootNull() {
    return (root == nullptr);
}

/**
 * @return min by key node in the tree
 */
template<class T>
TreeNode<T> *Tree<T>::getMinNode() {
    return min_node;
}

/**
 * scan the tree by "successor in-order" method
 * @tparam T
 * @param keys - arr. assign the  #size lowest keys in the tree into this arr
 * @param size - num of data to copy into keys[]
 * @return the number of keys that were assign to keys[]
 */
template<class T>
int Tree<T>::mapSucc(int *keys, int size) {
    if (size <= 0 || keys == nullptr || min_node == nullptr) {
        return 0;
    }

    return min_node->mapSucc(keys, size);
}

#endif //TREETEST2_TREE_H

