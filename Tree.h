//
// Created by Mor on 04/05/2020.
//

#ifndef TREETEST2_TREE_H
#define TREETEST2_TREE_H

#include <algorithm>

using std::max;

/**
 * Generic Template Class for a TreeNode
 * Made Specifically for use as a balanced AVL tree node meant to store dynamic
 * user data
 */
template<class T>
class TreeNode {
private:
    int key;
    T *data;
    int height;
    TreeNode<T> *left;
    TreeNode<T> *right;
    TreeNode<T> *parent;

    TreeNode<T> *Rebalance();

    int getBalanceFactor();

    void SwapNodesParent(TreeNode<T> *replacement);

    void updateNodeHeight();

    TreeNode<T> *LeftRightRotate();

    TreeNode<T> *RightLeftRotatet();

    TreeNode<T> *LeftRotate();

    TreeNode<T> *RightRotate();

    TreeNode<T> *DeleteNode();

public:
    TreeNode(int key, T *nData = nullptr, TreeNode *parent = nullptr);

    int getKey();

    T *getData();

    TreeNode<T> *Insert(int nodeKey, T *nodeData = nullptr, TreeNode<T> *result = nullptr);

    TreeNode<T> *Remove(int nodeKey);

    TreeNode<T> *Find(int searchKey);

    TreeNode<T> *findMin();

    TreeNode<T> *findMax();

    TreeNode<T> *getNext();

    TreeNode<T> *getLeft();

    void setLeft(TreeNode<T> *ptr);

    TreeNode<T> *getRight();

    void setRight(TreeNode<T> *ptr);

    TreeNode<T> *getParent();

    void setParent(TreeNode<T> *ptr);

    int SaveNodesInOrder(int *keys, int size);

    int CountSuccessorNodes(int *keys, int size);

    void DeleteTreeData();

    ~TreeNode();
};

/**
 * =============================================================================
 * Private Tree Node Functions
 * =============================================================================
 */

/**
 * Checks the balance factor of the tree and rebalances it using the AVL tree
 * rotation algorithms, returns the root of the new subtree at the end
 * @tparam T Pointer to dynamically allocated object of type T
 * @return The new root of the subtree after rebalancing
 */
template<class T>
TreeNode<T> *TreeNode<T>::Rebalance() {
    // Getting the balance factor of the current node
    int balance = getBalanceFactor();

    if (balance > 1) {
        // The tree is left heavy
        int leftSubtreeBalance = left->getBalanceFactor();
        if (leftSubtreeBalance >= 0) {
            return LeftRotate();
        } else {
            return LeftRightRotate();
        }
    } else if (balance < -1) {
        // The tree is right heavy
        int rightSubtreeBalance = right->getBalanceFactor();
        if (rightSubtreeBalance > 0) {
            return RightLeftRotatet();
        } else {
            return RightRotate();
        }
    }
    return this;
}

/**
 * Calculates the balance factor of the current node
 * @tparam T Pointer to dynamically allocated object of type T
 * @return The balance factor of the current node
 */
template<class T>
int TreeNode<T>::getBalanceFactor() {
    updateNodeHeight();
    int leftHeight = 0;
    int rightHeight = 0;
    if (right != nullptr) {
        rightHeight = right->height;
    }
    if (left != nullptr) {
        leftHeight = left->height;
    }
    return leftHeight - rightHeight;
}

/**
 * Updates the pointers of the "next in line" node in order to make sure proper linkage
 * of the subtree after deletion
 * @tparam T Pointer to dynamically allocated object of type T
 * @param replacement The successor node
 */
template<class T>
void TreeNode<T>::SwapNodesParent(TreeNode<T> *replacement) {
    if (replacement != nullptr) {
        replacement->parent = this->parent;
    }
    if (this->parent != nullptr) {
        if (this->parent->left != nullptr && this->parent->left->key == this->key) {
            this->parent->left = replacement;
        } else {
            this->parent->right = replacement;
        }
    }
}

/**
 * Updates the height of the node based on it's children
 * @tparam T Pointer to dynamically allocated object of type T
 */
template<class T>
void TreeNode<T>::updateNodeHeight() {
    int leftHeight = 0;
    int rightHeight = 0;
    if (left != nullptr) {
        leftHeight = left->height;
    }
    if (right != nullptr) {
        rightHeight = right->height;
    }

    height = 1 + max(leftHeight, rightHeight);
}

/**
 * Performs a left right rotation based on AVL tree rotation algorithms
 * @tparam T Pointer to dynamically allocated object of type T
 * @return The new root of the rotated subtree
 */
template<class T>
TreeNode<T> *TreeNode<T>::LeftRightRotate() {
    left->RightRotate();
    return this->LeftRotate();
}

/**
 * Performs a right left rotation based on AVL tree rotation algorithms
 * @tparam T Pointer to dynamically allocated object of type T
 * @return The new root of the rotated subtree
 */
template<class T>
TreeNode<T> *TreeNode<T>::RightLeftRotatet() {
    right->LeftRotate();
    return this->RightRotate();
}

/**
 * Performs a left rotation based on AVL tree rotation algorithms
 * @tparam T Pointer to dynamically allocated object of type T
 * @return The new root of the rotated subtree
 */
template<class T>
TreeNode<T> *TreeNode<T>::LeftRotate() {
    TreeNode<T> *newRoot = left;
    left = left->right;
    if (left != nullptr) {
        left->parent = this;
    }
    // Moving newRoot to the place of "this"
    newRoot->right = this;
    newRoot->parent = this->parent;
    if (this->parent != nullptr) {
        // Checking if newRoot is a right child or left child of the original parent
        if (this->parent->left != nullptr && this->parent->left->key == this->key) {
            this->parent->left = newRoot;
        } else {
            this->parent->right = newRoot;
        }
    }
    this->parent = newRoot;
    // Updating node heights after switches
    this->updateNodeHeight();
    newRoot->updateNodeHeight();
    return newRoot;
}

/**
 * Performs a right rotation based on AVL tree rotation algorithms
 * @tparam T Pointer to dynamically allocated object of type T
 * @return The new root of the rotated subtree
 */
template<class T>
TreeNode<T> *TreeNode<T>::RightRotate() {
    TreeNode<T> *newRoot = right;
    right = right->left;
    if (right != nullptr) {
        right->parent = this;
    }
    // Moving newRoot to the place of "this"
    newRoot->left = this;
    newRoot->parent = this->parent;
    if (this->parent != nullptr) {
        // Checking if newRoot is a right child or left child of the original parent
        if (this->parent->left != nullptr && this->parent->left->key == this->key) {
            this->parent->left = newRoot;
        } else {
            this->parent->right = newRoot;
        }
    }

    this->parent = newRoot;
    // Updating node heights after switches
    this->updateNodeHeight();
    newRoot->updateNodeHeight();
    return newRoot;
}

/**
 * Deletes the node from the tree, returns the new root of the node's subtree
 * after it's removal
 * @tparam T Pointer to dynamically allocated object of type T
 * @return The new root of the node's subtree after it's removal
 */
template<class T>
TreeNode<T> *TreeNode<T>::DeleteNode() {
    // Search for the next node to act as subtree root
    if (left != nullptr) {
        TreeNode<T> *next = left->findMax();
        if (left->right != nullptr) {
            next->parent->right = next->left;
            if (next->left != nullptr) {
                next->left->parent = next->parent;
            }
            next->left = this->left;
            this->left->parent = next;
        }
        // Performing pointer and parent swap between the next node and the
        // node we need to delete
        this->SwapNodesParent(next);
        next->right = this->right;
        if (this->right != nullptr) {
            this->right->parent = next;
        }
        delete this;
        return next->Rebalance();
    } else if (right != nullptr) {
        TreeNode<T> *next = this->right;
        // Performing pointer and parent swap between the next node and the
        // node we need to delete
        this->SwapNodesParent(next);
        delete this;
        return next->Rebalance();
    } else {
        // The node we want to delete has no leafs, so it's subtree will remain empty
        // after deletion.
        this->SwapNodesParent(nullptr);
        delete this;
        return nullptr;
    }
}

/**
 * =============================================================================
 * Public Tree Node Functions
 * =============================================================================
 */

/**
 * Creates a new TreeNode for insertion to an AVL tree
 * Provided key is a dynamically allocated data of type T
 * @tparam T Pointer to dynamically allocated object of type T
 * @param key A unique key for the node
 * @param nData The dynamically allocated object of type T
 * @param parent A pointer to the parent of the node in the tree
 */
template<class T>
TreeNode<T>::TreeNode(int key, T *nData, TreeNode *parent):
        key(key), data(nData), height(1), left(nullptr), right(nullptr), parent(parent) {};

/**
 * Returns the key of the node
 * @tparam T Pointer to dynamically allocated object of type T
 * @return The key of the tree node
 */
template<class T>
int TreeNode<T>::getKey() {
    return key;
}

/**
 * Returns the stored data object in the node
 * @tparam T Pointer to dynamically allocated object of type T
 * @return The data stored in the tree node
 */
template<class T>
T *TreeNode<T>::getData() {
    return data;
}

/**
 * Insert a new node to the subtree tree and returns the new root of the subtree
 * after rotations and rebalance
 * @tparam T Pointer to dynamically allocated object of type T
 * @param nodeKey The key of the new node
 * @param nodeData The data object of the new node
 * @param result A pointer to save a reference to the new node in
 * @return The new root of the rebalanced tree after insert
 */
template<class T>
TreeNode<T> *TreeNode<T>::Insert(int nodeKey, T *nodeData, TreeNode<T> *result) {
    // Search for the right place to insert the node
    if (nodeKey > key) {
        // The node will be a right child of this node
        if (right == nullptr) {
            // Found the correct spot to insert the node
            right = new TreeNode(nodeKey, nodeData, this);
            // Saving the new object to the result pointer for future retrieval
            result = right;
        } else {
            // Need to continue searching for the right spot of the new node
            right->Insert(nodeKey, nodeData, result);
        }
    } else if (nodeKey < key) {
        // The node will be a left child of this node
        if (left == nullptr) {
            // Found the correct spot to insert the node
            left = new TreeNode(nodeKey, nodeData, this);
            // Saving the new object to the result pointer for future retrieval
            result = left;
        } else {
            // Need to continue searching for the right spot of the new node
            left->Insert(nodeKey, nodeData, result);
        }
    } else {
        // The input key already exists in the tree, returning nullptr without
        // modifying the tree or the input data
        return nullptr;
    }
    // Rebalancing tree after insertion
    return Rebalance();
}

/**
 * Removes a node with input key from the tree
 * @tparam T Pointer to dynamically allocated object of type T
 * @param nodeKey The key of the node to remove
 * @return The new root of the subtree after removal of the node
 */
template<class T>
TreeNode<T> *TreeNode<T>::Remove(int nodeKey) {
    // Searching for the node to remove
    if (nodeKey < key) {
        // The delete target is a left child of the current node
        if (left != nullptr) {
            left->Remove(nodeKey);
        } else {
            return this;
        }
    } else if (nodeKey > key) {
        // The delete target is a right child of the current node
        if (right != nullptr) {
            right->Remove(nodeKey);
        } else {
            return this;
        }
    } else {
        // Found the node we need to delete
        // Using delete handler to remove the node from the tree
        return this->DeleteNode();
    }
    // Rebalancing tree after removal
    return Rebalance();
}

/**
 * Searches for a tree node with the input key and returns a pointer to it
 * @tparam T Pointer to dynamically allocated object of type T
 * @param searchKey The key of the node to search for
 * @return A pointer to the tree node if it is found, nullptr otherwise
 */
template<class T>
TreeNode<T> *TreeNode<T>::Find(int searchKey) {
    if (searchKey == key) {
        // We found the node we were looking for
        return this;
    } else if (searchKey < key) {
        // The node we are looking for is a left child of this node
        if (left != nullptr) {
            return left->Find(searchKey);
        } else {
            return nullptr;
        }
    } else {
        // The node we are looking for is a right child of this node
        if (right != nullptr) {
            return right->Find(searchKey);
        } else {
            return nullptr;
        }
    }
}

/**
 * Finds the minimal node from this point downward in the tree
 * @tparam T Pointer to dynamically allocated object of type T
 * @return The minimal node
 */
template<class T>
TreeNode<T> *TreeNode<T>::findMin() {
    if (left != nullptr) {
        return left->findMin();
    }
    return this;
}

/**
 * Finds the maximal node from this point downward in the tree
 * @tparam T Pointer to dynamically allocated object of type T
 * @return The maximal node
 */
template<class T>
TreeNode<T> *TreeNode<T>::findMax() {
    if (right != nullptr) {
        return right->findMax();
    }
    return this;
}

/**
 * Finds the successor to the current node
 * @tparam T Pointer to dynamically allocated object of type T
 * @return The successor of the current node
 */
template<class T>
TreeNode<T> *TreeNode<T>::getNext() {
    TreeNode<T> *current = this;
    if (current->right() != nullptr) {
        // This node has a right child, which means if we follow the branch
        // once to the right and then all the way to the left, we will find the
        // correct following child
        return findMin(current->right);
    } else {
        TreeNode<T> *parent = current->parent;
        while (parent != nullptr) {
            TreeNode<T> *child = parent->left;
            if (child && child->key == current->key) {
                // The node we started with is the left child of the current parent,
                // which means the parent is the next node in the tree.
                return parent;
            }
            current = parent;
            parent = current->parent;
        }
        return parent;
    }
}

/**
 * Returns the left child of the node
 * @tparam T Pointer to dynamically allocated object of type T
 * @return The left child of the node
 */
template<class T>
TreeNode<T> *TreeNode<T>::getLeft() {
    return left;
}

/**
 * Sets the left child of the node
 * @tparam T Pointer to dynamically allocated object of type T
 * @param ptr The new left child of the node
 */
template<class T>
void TreeNode<T>::setLeft(TreeNode<T> *ptr) {
    left = ptr;
}

/**
 * Returns the right child of the node
 * @tparam T Pointer to dynamically allocated object of type T
 * @return The right child of the node
 */
template<class T>
TreeNode<T> *TreeNode<T>::getRight() {
    return right;
}

/**
 * Sets the right child of the node
 * @tparam T Pointer to dynamically allocated object of type T
 * @param ptr The new right child of the node
 */
template<class T>
void TreeNode<T>::setRight(TreeNode<T> *ptr) {
    right = ptr;
}

/**
 * Returns the parent of the node
 * @tparam T Pointer to dynamically allocated object of type T
 * @return The parent of the node
 */
template<class T>
TreeNode<T> *TreeNode<T>::getParent() {
    return parent;
}

/**
 * Sets the parent of the node
 * @tparam T Pointer to dynamically allocated object of type T
 * @param ptr The new parent of the node
 */
template<class T>
void TreeNode<T>::setParent(TreeNode<T> *ptr) {
    parent = ptr;
}

/**
 * Traverses the tree in order from the current node downward
 * Saves encountered keys to an input array as the input amount specifies
 * returns the amount of keys traveresed and saved
 * @tparam T Pointer to dynamically allocated object of type T
 * @param keys an array to save the keys to
 * @param size the number of keys to traverse and save
 * @return the number of keys found
 */
template<class T>
int TreeNode<T>::SaveNodesInOrder(int *keys, int size) {
    if (size <= 0 || keys == nullptr) {
        return 0;
    }

    int index = 0;
    if (left != nullptr) {
        index += left->SaveNodesInOrder(keys, size);
        if (index >= size) {
            return index;
        }
    }

    keys[index++] = key;

    if (index < size && right != nullptr) {
        index += right->SaveNodesInOrder(keys + index, size - index);
    }
    return index;
}

/**
 * Traverses the tree from the minimal node upward and saves the keys encountered
 * up to the amount of keys specified in size
 * @tparam T Pointer to dynamically allocated object of type T
 * @param keys an array to save the keys to
 * @param size the number of keys to traverse and save
 * @return the number of keys found
 */
template<class T>
int TreeNode<T>::CountSuccessorNodes(int *keys, int size) {
    if (size <= 0 || keys == nullptr) {
        return 0;
    }
    int index = 0;
    TreeNode<T> *current = this;
    while (current && index < size) {
        keys[index++] = current->key;
        if (current->right) {
            index += current->right->SaveNodesInOrder(keys + index, size - index);
        }
        current = current->parent;
    }
    return index;
}

/**
 * Completely deletes the tree from the given node downward, including all dynamically
 * allocated data in each node
 * also marks every deleted node as nullptr
 * @tparam T Pointer to dynamically allocated object of type T
 */
template<class T>
void TreeNode<T>::DeleteTreeData() {
    if (left != nullptr) {
        left->DeleteTreeData();
        delete left;
        left = nullptr;
    }
    if (right != nullptr) {
        right->DeleteTreeData();
        delete right;
        right = nullptr;
    }
}

/**
 * Deletes the data stored in this node,
 * marks the data as deleted and deletes the node itself
 * (does not delete child nodes)
 * @tparam T Pointer to dynamically allocated object of type T
 */
template<class T>
TreeNode<T>::~TreeNode() {
    if (data != nullptr) {
        delete data;
        data = nullptr;
    }
}

/**
 * Generic Template Class for an AVL Tree
 * Stores and organizes AVL tree nodes meant to store dynamic user data
 * @tparam T Pointer to dynamically allocated object of type T
 */
template<class T>
class Tree {
    TreeNode<T> *root;
    TreeNode<T> *minimalKeyNode;

public:
    Tree();

    TreeNode<T> *GetRoot();

    TreeNode<T> *Find(int key);

    void Insert(int key, T *data = nullptr);

    TreeNode<T> *InsertGetBack(int key, T *data);

    void Remove(int key);


    TreeNode<T> *getMinNode();

    int CountSuccessorNodes(int *keys, int size);

    bool IsRootNull();

    ~Tree();
};

/**
 * =============================================================================
 * Public Tree Functions
 * =============================================================================
 */

/**
 * Creates an empty AVL Tree to store nodes with type T
 * @tparam T Pointer to dynamically allocated object of type T
 */
template<class T>
Tree<T>::Tree(): root(nullptr), minimalKeyNode(nullptr) {};

/**
 * Returns a pointer to the root of the tree
 * @tparam T Pointer to dynamically allocated object of type T
 * @return A pointer to the root of the tree
 */
template<class T>
TreeNode<T> *Tree<T>::GetRoot() {
    return root;
}

/**
 * Searches for a node by key in the tree and returns it if it exists
 * @tparam T Pointer to dynamically allocated object of type T
 * @param key The key of the node to find
 * @return A pointer to the node if it's found in the tree, nullptr otherwise
 */
template<class T>
TreeNode<T> *Tree<T>::Find(int key) {
    if (root == nullptr) {
        return nullptr;
    }

    return root->Find(key);
}

/**
 * Inserts a new node with the given key and data to the tree
 * If the key already exists in the tree, nothing will be done
 * (This also means the dynamic data sent to the function will not
 * be freed)
 * @tparam T Pointer to dynamically allocated object of type T
 * @param key The key of the new node
 * @param data The data of the new node
 */
template<class T>
void Tree<T>::Insert(int key, T *data) {
    if (root == nullptr) {
        // The tree is empty, inserting the new node as the root
        root = new TreeNode<T>(key, data);
        minimalKeyNode = root;
    } else {
        root = root->Insert(key, data);

        // Updating the pointer to the minimal node if the node we inserted
        // has a lower key than existing nodes
        if (!minimalKeyNode || key < minimalKeyNode->getKey()) {
            this->minimalKeyNode = root->findMin();
        }
    }
}

/**
 * Insert a new node to the subtree tree and returns a pointer to the new node
 * @tparam T Pointer to dynamically allocated object of type T
 * @param key The key of the new node
 * @param data The data object of the new node
 * @param result A pointer to save a reference to the new node in
 * @return A pointer to the newely inserted ndoe
 */
template<class T>
TreeNode<T> *Tree<T>::InsertGetBack(int key, T *data) {
    if (root == nullptr) {
        root = new TreeNode<T>(key, data);
        // The tree is empty, inserting the new node as the root
        minimalKeyNode = root;
        return root;
    } else {
        TreeNode<T> *result = nullptr;
        root = root->Insert(key, data, result);

        // Updating the pointer to the minimal node if the node we inserted
        // has a lower key than existing nodes
        if (!minimalKeyNode || key < minimalKeyNode->getKey()) { // in case we Insert new min by key data
            this->minimalKeyNode = root->findMin();
        }
        return result;
    }
}

/**
 * Removes a node with the given key from the tree
 * @tparam T Pointer to dynamically allocated object of type T
 * @param key The key of the node to remove
 */
template<class T>
void Tree<T>::Remove(int key) {
    bool flag = minimalKeyNode != nullptr && minimalKeyNode->getKey() == key;
    if (root != nullptr) {
        root = root->Remove(key);
        if (flag) {
            if (root != nullptr) {
                minimalKeyNode = root->findMin();
            } else {
                minimalKeyNode = nullptr;
            }
        }
    }
}

/**
 * Returns the node with the lowest key in the tree
 * @tparam T Pointer to dynamically allocated object of type T
 * @return A pointer to the node with the lowest key in the tree
 */
template<class T>
TreeNode<T> *Tree<T>::getMinNode() {
    return minimalKeyNode;
}

/**
 * Traverses the tree from the minimal node upward and saves the keys encountered
 * up to the amount of keys specified in size
 * @tparam T Pointer to dynamically allocated object of type T
 * @param keys an array to save the keys to
 * @param size the number of keys to traverse and save
 * @return the number of keys found
 */
template<class T>
int Tree<T>::CountSuccessorNodes(int *keys, int size) {
    if (size <= 0 || keys == nullptr || minimalKeyNode == nullptr) {
        return 0;
    }

    return minimalKeyNode->CountSuccessorNodes(keys, size);
}

/**
 * Checks if the tree is empty
 * @tparam T Pointer to dynamically allocated object of type T
 * @return True if the root of the tree is a nullptr, False otherwiese
 */
template<class T>
bool Tree<T>::IsRootNull() {
    return (root == nullptr);
}

/**
 * Deletes all nodes stored in the tree, including the dynamic data stored in them
 * and then sets the root of the tree to nullptr
 * @tparam T Pointer to dynamically allocated object of type T
 */
template<class T>
Tree<T>::~Tree() {
    if (root != nullptr) {
        root->DeleteTreeData();
        delete root;
        root = nullptr;
    }
}

#endif //TREETEST2_TREE_H

