/*
 * testAVLTree.cpp
 */


#include <vector>
#include <ostream>
#include <random>
#include <chrono>
#include <algorithm>
#include "Tree.h"

void TestLL() {
    //basic LL root change
    std::cout << "LL Test START" << std::endl;
    Tree<int> *treeLL = new Tree<int>();
    treeLL->Insert(3, new int(3));
    treeLL->Insert(2, new int(2));
    treeLL->Insert(1, new int(1));
    treeLL->PrintInOrder();
    delete treeLL;
    treeLL = nullptr;
    std::cout << std::endl;
    std::cout << "LL Test FINISH" << std::endl;
}

void TestLR() {
    //basic LR root change
    std::cout << "LR Test START" << std::endl;
    Tree<int> *treeLR = new Tree<int>();
    treeLR->Insert(3, new int(3));
    treeLR->Insert(1, new int(1));
    treeLR->Insert(2, new int(2));
    treeLR->PrintInOrder();
    delete treeLR;
    treeLR = nullptr;
    std::cout << std::endl;
    std::cout << "LR Test FINISH" << std::endl;
}

void TestRR() {
    //basic RR root change
    std::cout << "RR Test START" << std::endl;
    Tree<int> *treeRR = new Tree<int>();
    treeRR->Insert(1, new int(1));
    treeRR->Insert(2, new int(2));
    treeRR->Insert(3, new int(3));
    treeRR->PrintInOrder();
    delete treeRR;
    treeRR = nullptr;
    std::cout << std::endl;
    std::cout << "RR Test FINISH" << std::endl;
}

void TestRL() {
    //basic RL root change
    std::cout << "RL Test START" << std::endl;
    Tree<int> *treeRL = new Tree<int>();
    treeRL->Insert(1, new int(1));
    treeRL->Insert(3, new int(3));
    treeRL->Insert(2, new int(2));
    treeRL->PrintInOrder();
    delete treeRL;
    treeRL = nullptr;
    std::cout << std::endl;
    std::cout << "RL Test FINISH" << std::endl;
}

void TestLRDontChangeRoot() {
    //basic LR not root change
//	/*correct output
//	1 BF: 0 Height: 0
//	2 BF: 0 Height: 1
//	3 BF: 0 Height: 0
//	4 BF: 1 Height: 2
//	5 BF: 0 Height: 0
//	6 BF: 1 Height: 3
//	7 BF: 0 Height: 0
//	8 BF: 1 Height: 1 */
    std::cout << "LR don't change root Test START" << std::endl;
    Tree<int> *treeLRnRootC = new Tree<int>();
    treeLRnRootC->Insert(6, new int(6));
    treeLRnRootC->Insert(4, new int(4));
    treeLRnRootC->Insert(8, new int(8));
    treeLRnRootC->Insert(3, new int(3));
    treeLRnRootC->Insert(5, new int(5));
    treeLRnRootC->Insert(7, new int(7));
    treeLRnRootC->Insert(1, new int(1));
    treeLRnRootC->Insert(2, new int(2));
    treeLRnRootC->PrintInOrder();
    delete treeLRnRootC;
    treeLRnRootC = nullptr;
    std::cout << std::endl;
    std::cout << "LR don't change root Test FINISH" << std::endl;
}

void TestLLDontChangeRoot() {
    //basic LL not root change
//	/*correct output
//	1 BF: 0 Height: 0
//	2 BF: 0 Height: 1
//	3 BF: 0 Height: 0
//	4 BF: 1 Height: 2
//	5 BF: 0 Height: 0
//	6 BF: 1 Height: 3
//	7 BF: 0 Height: 0
//	8 BF: 1 Height: 1 */
    std::cout << "LL don't change root Test START" << std::endl;
    Tree<int> *treeLLnRootC = new Tree<int>();
    treeLLnRootC->Insert(6, new int(6));
    treeLLnRootC->Insert(4, new int(4));
    treeLLnRootC->Insert(8, new int(8));
    treeLLnRootC->Insert(3, new int(3));
    treeLLnRootC->Insert(5, new int(5));
    treeLLnRootC->Insert(7, new int(7));
    treeLLnRootC->Insert(2, new int(2));
    treeLLnRootC->Insert(1, new int(1));
    treeLLnRootC->PrintInOrder();
    delete treeLLnRootC;
    treeLLnRootC = nullptr;
    std::cout << std::endl;
    std::cout << "LL don't change root Test FINISH" << std::endl;
}

void TestRRDontChangeRoot() {
    //basic RR not root change
//	/*correct output
//	 * 1 BF: 0 Height: 0
//	2 BF: 0 Height: 1
//	3 BF: 0 Height: 0
//	5 BF: 1 Height: 2
//	7 BF: 0 Height: 0*/
    std::cout << "RR don't change root Test START" << std::endl;
    Tree<int> *treeRRnRootC = new Tree<int>();
    treeRRnRootC->Insert(5, new int(5));
    treeRRnRootC->Insert(7, new int(7));
    treeRRnRootC->Insert(1, new int(1));
    treeRRnRootC->Insert(2, new int(2));
    treeRRnRootC->Insert(3, new int(3));
    treeRRnRootC->PrintInOrder();
    delete treeRRnRootC;
    treeRRnRootC = nullptr;
    std::cout << std::endl;
    std::cout << "RR don't change root Test FINISH" << std::endl;
}

void TestRLDontChangeRoot() {
    //basic RL not root change
//	/*correct output
//	 * 1 BF: 0 Height: 0
//	2 BF: 0 Height: 1
//	3 BF: 0 Height: 0
//	5 BF: 1 Height: 2
//	7 BF: 0 Height: 0*/
    std::cout << "RL don't change root Test START" << std::endl;
    Tree<int> *treeRLnRootC = new Tree<int>();
    treeRLnRootC->Insert(5, new int(5));
    treeRLnRootC->Insert(7, new int(7));
    treeRLnRootC->Insert(1, new int(1));
    treeRLnRootC->Insert(3, new int(3));
    treeRLnRootC->Insert(2, new int(2));
    treeRLnRootC->PrintInOrder();
    delete treeRLnRootC;
    treeRLnRootC = nullptr;
    std::cout << std::endl;
    std::cout << "RL don't change root Test FINISH" << std::endl;
}

void TestReplaceRootWithSuccessor() {
    //root deletion no roll successor is a neighbour
//	/*correct output
//	2 BF: 0 Height: 0
//	3 BF: 1 Height: 1
//	5 BF: 1 Height: 2
//	6 BF: 0 Height: 0*/
    std::cout << "replace root with successor Test START" << std::endl;
    Tree<int> *treeDeleteRootGetSuccessor = new Tree<int>();
    treeDeleteRootGetSuccessor->Insert(4, new int(4));
    treeDeleteRootGetSuccessor->Insert(5, new int(5));
    treeDeleteRootGetSuccessor->Insert(3, new int(3));
    treeDeleteRootGetSuccessor->Insert(2, new int(2));
    treeDeleteRootGetSuccessor->Insert(6, new int(6));
    treeDeleteRootGetSuccessor->Remove(4);
    treeDeleteRootGetSuccessor->PrintInOrder();
    delete treeDeleteRootGetSuccessor;
    treeDeleteRootGetSuccessor = nullptr;
    std::cout << std::endl;
    std::cout << "replace root with successor Test FINISH" << std::endl;
}

void TestReplaceRootWithNonSuccessor() {
    //root deletion no roll successor is not a neighbour
//	/*correct output
//	2 BF: 0 Height: 0
//	3 BF: 1 Height: 1
//	5 BF: 0 Height: 2
//	6 BF: 0 Height: 0
//	7 BF: 0 Height: 1
//	8 BF: 0 Height: 0 */
    std::cout << "replace root with non successor Test START" << std::endl;
    Tree<int> *treeDeleteRootNotSuccessor = new Tree<int>();
    treeDeleteRootNotSuccessor->Insert(4, new int(4));
    treeDeleteRootNotSuccessor->Insert(3, new int(3));
    treeDeleteRootNotSuccessor->Insert(7, new int(7));
    treeDeleteRootNotSuccessor->Insert(2, new int(2));
    treeDeleteRootNotSuccessor->Insert(5, new int(5));
    treeDeleteRootNotSuccessor->Insert(8, new int(8));
    treeDeleteRootNotSuccessor->Insert(6, new int(6));
    treeDeleteRootNotSuccessor->Remove(4);
    treeDeleteRootNotSuccessor->PrintInOrder();
    delete treeDeleteRootNotSuccessor;
    treeDeleteRootNotSuccessor = nullptr;
    std::cout << std::endl;
    std::cout << "replace root with non successor Test FINISH" << std::endl;
}

void TestRemoveNodeWithSuccessorNeighbour() {
    //node deletion no roll successor is a neighbour case7
//	/*correct output
//	1 BF: 0 Height: 0
//	2 BF: 1 Height: 1
//	4 BF: 1 Height: 2
//	5 BF: 0 Height: 0
//	7 BF: 1 Height: 3
//	8 BF: -1 Height: 1
//	9 BF: 0 Height: 0*/
    std::cout << "replace node with successor neighbour Test START" << std::endl;
    Tree<int> *treeDeleteNodeSuccessor = new Tree<int>();
    treeDeleteNodeSuccessor->Insert(7, new int(7));
    treeDeleteNodeSuccessor->Insert(3, new int(3));
    treeDeleteNodeSuccessor->Insert(8, new int(8));
    treeDeleteNodeSuccessor->Insert(2, new int(2));
    treeDeleteNodeSuccessor->Insert(4, new int(4));
    treeDeleteNodeSuccessor->Insert(9, new int(9));
    treeDeleteNodeSuccessor->Insert(5, new int(5));
    treeDeleteNodeSuccessor->Insert(1, new int(1));
    treeDeleteNodeSuccessor->Remove(3);
    treeDeleteNodeSuccessor->PrintInOrder();
    delete treeDeleteNodeSuccessor;
    std::cout << std::endl;
    std::cout << "replace node with successor neighbour Test FINISH" << std::endl;
}

void TestRemoveNodeWithSuccessorNonNeighbour() {
    //node deletion no roll successor is not a neighbour case8
//	/*correct output
//	1 BF: 0 Height: 0
//	2 BF: 1 Height: 1
//	5 BF: 0 Height: 2
//	6 BF: 0 Height: 0
//	7 BF: 0 Height: 1
//	8 BF: 0 Height: 0
//	9 BF: 0 Height: 3
//	10 BF: 0 Height: 0
//	12 BF: -1 Height: 2
//	13 BF: -1 Height: 1
//	14 BF: 0 Height: 0*/
    std::cout << "replace node with successor non neighbour Test START" << std::endl;
    Tree<int> *treeDeleteNodeSuccessor = new Tree<int>();
    treeDeleteNodeSuccessor->Insert(9, new int(9));
    treeDeleteNodeSuccessor->Insert(3, new int(3));
    treeDeleteNodeSuccessor->Insert(12, new int(12));
    treeDeleteNodeSuccessor->Insert(2, new int(2));
    treeDeleteNodeSuccessor->Insert(7, new int(7));
    treeDeleteNodeSuccessor->Insert(10, new int(10));
    treeDeleteNodeSuccessor->Insert(13, new int(13));
    treeDeleteNodeSuccessor->Insert(1, new int(1));
    treeDeleteNodeSuccessor->Insert(5, new int(5));
    treeDeleteNodeSuccessor->Insert(8, new int(8));
    treeDeleteNodeSuccessor->Insert(14, new int(14));
    treeDeleteNodeSuccessor->Insert(6, new int(6));
    treeDeleteNodeSuccessor->Remove(3);
    treeDeleteNodeSuccessor->PrintInOrder();
    delete treeDeleteNodeSuccessor;
    std::cout << std::endl;
    std::cout << "replace node with successor non neighbour Test FINISH" << std::endl;
}

void TestRemoveNodeCauseLR() {
    //node deletion causing LR case9
//	/*correct output
//	1 BF: 0 Height: 0
//	2 BF: 0 Height: 1
//	3 BF: 0 Height: 0
//	4 BF: 0 Height: 2
//	7 BF: -1 Height: 1
//	8 BF: 0 Height: 0*/
    std::cout << "remove node and cause LR Test START" << std::endl;
    Tree<int> *tree = new Tree<int>();
    tree->Insert(7, new int(7));
    tree->Insert(2, new int(2));
    tree->Insert(8, new int(8));
    tree->Insert(1, new int(1));
    tree->Insert(4, new int(4));
    tree->Insert(9, new int(9));
    tree->Insert(3, new int(3));
    tree->Remove(9);
    tree->PrintInOrder();
    delete tree;
    std::cout << std::endl;
    std::cout << "remove node and cause LR Test FINISH" << std::endl;
}

void TestRemoveNodeCauseLL() {
    //node deletion causing LL case10
//	/*correct output
//	1 BF: 0 Height: 0
//	2 BF: 0 Height: 1
//	3 BF: 0 Height: 0
//	4 BF: 0 Height: 2
//	7 BF: -1 Height: 1
//	8 BF: 0 Height: 0*/
    std::cout << "remove node and cause LL Test START" << std::endl;
    Tree<int> *tree = new Tree<int>();
    tree->Insert(7, new int(7));
    tree->Insert(3, new int(3));
    tree->Insert(8, new int(8));
    tree->Insert(2, new int(2));
    tree->Insert(4, new int(4));
    tree->Insert(9, new int(9));
    tree->Insert(1, new int(1));
    tree->Remove(9);
    tree->PrintInOrder();
    delete tree;
    std::cout << std::endl;
    std::cout << "remove node and cause LL Test FINISH" << std::endl;
}

void TestRemoveNodeCauseRR() {
    //node deletion causing RR case10
//	/*correct output
//	1 BF: 0 Height: 0
//	2 BF: 0 Height: 1
//	3 BF: 0 Height: 0
//	4 BF: 0 Height: 2
//	7 BF: -1 Height: 1
//	8 BF: 0 Height: 0*/
    std::cout << "remove node and cause RR Test START" << std::endl;
    Tree<int> *tree = new Tree<int>();
    tree->Insert(3, new int(3));
    tree->Insert(2, new int(2));
    tree->Insert(8, new int(8));
    tree->Insert(7, new int(7));
    tree->Insert(1, new int(1));
    tree->Insert(9, new int(9));
    tree->Insert(10, new int(10));
    tree->Remove(1);
    tree->PrintInOrder();
    delete tree;
    std::cout << std::endl;
    std::cout << "remove node and cause RR Test FINISH" << std::endl;
}

void TestRemoveNodeCauseRL() {
    //node deletion causing RR case10
//	/*correct output
//	1 BF: 0 Height: 0
//	2 BF: 0 Height: 1
//	3 BF: 0 Height: 0
//	4 BF: 0 Height: 2
//	7 BF: -1 Height: 1
//	8 BF: 0 Height: 0*/
    std::cout << "remove node and cause RL Test START" << std::endl;
    Tree<int> *tree = new Tree<int>();
    tree->Insert(3, new int(3));
    tree->Insert(2, new int(2));
    tree->Insert(13, new int(13));
    tree->Insert(7, new int(7));
    tree->Insert(1, new int(1));
    tree->Insert(14, new int(14));
    tree->Insert(10, new int(10));
    tree->Remove(1);
    tree->PrintInOrder();
    delete tree;
    std::cout << std::endl;
    std::cout << "remove node and cause RL Test FINISH" << std::endl;
}

void TestRemoveNodeCauseRLRR() {
    //node deletion causing RR case10
//	/*correct output
//	1 BF: 0 Height: 0
//	2 BF: 0 Height: 1
//	3 BF: 0 Height: 0
//	4 BF: 0 Height: 2
//	7 BF: -1 Height: 1
//	8 BF: 0 Height: 0*/
    std::cout << "remove node and cause RL RR Test START" << std::endl;
    Tree<int> *tree = new Tree<int>();
    tree->Insert(9, new int(9));
    tree->Insert(3, new int(3));
    tree->Insert(15, new int(15));
    tree->Insert(1, new int(1));
    tree->Insert(7, new int(7));
    tree->Insert(13, new int(13));
    tree->Insert(19, new int(19));
    tree->Insert(5, new int(5));
    tree->Insert(11, new int(11));
    tree->Insert(17, new int(17));
    tree->Insert(21, new int(21));
    tree->Insert(23, new int(23));
    tree->Remove(1);
    tree->PrintInOrder();
    delete tree;
    std::cout << std::endl;
    std::cout << "remove node and cause RL RR Test FINISH" << std::endl;
}

void TestRemoveNodeCauseRRRR() {
    //node deletion causing RR case10
//	/*correct output
//	1 BF: 0 Height: 0
//	2 BF: 0 Height: 1
//	3 BF: 0 Height: 0
//	4 BF: 0 Height: 2
//	7 BF: -1 Height: 1
//	8 BF: 0 Height: 0*/
    std::cout << "remove node and cause RR RR Test START" << std::endl;
    Tree<int> *tree = new Tree<int>();
    tree->Insert(9, new int(9));
    tree->Insert(3, new int(3));
    tree->Insert(15, new int(15));
    tree->Insert(1, new int(1));
    tree->Insert(7, new int(7));
    tree->Insert(13, new int(13));
    tree->Insert(19, new int(19));
    tree->Insert(8, new int(8));
    tree->Insert(11, new int(11));
    tree->Insert(17, new int(17));
    tree->Insert(21, new int(21));
    tree->Insert(23, new int(23));
    tree->Remove(1);
    tree->PrintInOrder();
    delete tree;
    std::cout << std::endl;
    std::cout << "remove node and cause RR RR Test FINISH" << std::endl;
}

void TestRemoveNodeCauseRLLL() {
    //node deletion causing RR case10
//	/*correct output
//	1 BF: 0 Height: 0
//	2 BF: 0 Height: 1
//	3 BF: 0 Height: 0
//	4 BF: 0 Height: 2
//	7 BF: -1 Height: 1
//	8 BF: 0 Height: 0*/
    std::cout << "remove node and cause RL LL Test START" << std::endl;
    Tree<int> *tree = new Tree<int>();
    tree->Insert(15, new int(15));
    tree->Insert(10, new int(10));
    tree->Insert(20, new int(20));
    tree->Insert(8, new int(8));
    tree->Insert(11, new int(11));
    tree->Insert(17, new int(17));
    tree->Insert(21, new int(21));
    tree->Insert(7, new int(7));
    tree->Insert(9, new int(9));
    tree->Insert(12, new int(12));
    tree->Insert(18, new int(18));
    tree->Insert(6, new int(6));
    tree->Remove(21);
    tree->PrintInOrder();
    delete tree;
    std::cout << std::endl;
    std::cout << "remove node and cause RL LL Test FINISH" << std::endl;
}

void TestRemoveNodeCauseLRLL() {
    //node deletion causing RR case10
//	/*correct output
//	1 BF: 0 Height: 0
//	2 BF: 0 Height: 1
//	3 BF: 0 Height: 0
//	4 BF: 0 Height: 2
//	7 BF: -1 Height: 1
//	8 BF: 0 Height: 0*/
    std::cout << "remove node and cause LR LL Test START" << std::endl;
    Tree<int> *tree = new Tree<int>();
    tree->Insert(15, new int(15));
    tree->Insert(10, new int(10));
    tree->Insert(20, new int(20));
    tree->Insert(8, new int(8));
    tree->Insert(11, new int(11));
    tree->Insert(17, new int(17));
    tree->Insert(22, new int(22));
    tree->Insert(7, new int(7));
    tree->Insert(9, new int(9));
    tree->Insert(12, new int(12));
    tree->Insert(21, new int(21));
    tree->Insert(6, new int(6));
    tree->Remove(17);
    tree->PrintInOrder();
    delete tree;
    std::cout << std::endl;
    std::cout << "remove node and cause LR LL Test FINISH" << std::endl;
}

void TestRemoveNodeCauseLR2() {
    //node deletion causing RR case10
//	/*correct output
//	1 BF: 0 Height: 0
//	2 BF: 0 Height: 1
//	3 BF: 0 Height: 0
//	4 BF: 0 Height: 2
//	7 BF: -1 Height: 1
//	8 BF: 0 Height: 0*/
    std::cout << "remove node and cause LR 2 Test START" << std::endl;
    Tree<int> *tree = new Tree<int>();
    tree->Insert(5, new int(5));
    tree->Insert(3, new int(3));
    tree->Insert(6, new int(6));
    tree->Insert(2, new int(2));
    tree->Insert(4, new int(4));
    tree->Remove(5);
    tree->PrintInOrder();
    delete tree;
    std::cout << std::endl;
    std::cout << "remove node and cause LR 2 Test FINISH" << std::endl;
}

void TestRemoveNodeCauseLR3() {
    //node deletion causing RR case10
//	/*correct output
//	1 BF: 0 Height: 0
//	2 BF: 0 Height: 1
//	3 BF: 0 Height: 0
//	4 BF: 0 Height: 2
//	7 BF: -1 Height: 1
//	8 BF: 0 Height: 0*/
    std::cout << "remove node and cause LR 3 Test START" << std::endl;
    Tree<int> *tree = new Tree<int>();
    tree->Insert(5, new int(5));
    tree->Insert(3, new int(3));
    tree->Insert(6, new int(6));
    tree->Insert(2, new int(2));
    tree->Remove(5);
    tree->PrintInOrder();
    delete tree;
    std::cout << std::endl;
    std::cout << "remove node and cause LR 3 Test FINISH" << std::endl;
}

void TestRandomInput() {
    std::cout << "Random Input Test START" << std::endl;
    Tree<int> *tree = new Tree<int>();
    std::vector<int> vector;
    for (int i=1; i<=100; i++) vector.push_back(i);

    //Randomly insert and removes nodes
    for (int k = 0; k < 20; ++k) {
        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
        shuffle (vector.begin(), vector.end(), std::default_random_engine(seed));
        for (std::vector<int>::iterator it = vector.begin() ; it != vector.end(); ++it){
            tree->Insert(*it,new int(*it));

        }
        tree->PrintInOrder();
        std::cout << std::endl;
        shuffle (vector.begin(), vector.end(), std::default_random_engine(seed));
        for (std::vector<int>::iterator it = vector.begin() ; it != vector.end(); ++it){
            tree->Remove(*it);
            tree->PrintInOrder();

        }
        delete tree;
        tree = new Tree<int>();
        std::cout << std::endl;
    }
    std::cout << std::endl;
    std::cout << "Random Input Test FINISH" << std::endl;
}

int main() {
//    TestLL();
//    TestLR();
//    TestRR();
//    TestRL();
//    TestLRDontChangeRoot();
//    TestLLDontChangeRoot();
//    TestRRDontChangeRoot();
//    TestRLDontChangeRoot();
//    TestReplaceRootWithSuccessor();
//    TestReplaceRootWithNonSuccessor();
//    TestRemoveNodeWithSuccessorNeighbour();
//    TestRemoveNodeWithSuccessorNonNeighbour();
//    TestRemoveNodeCauseLR();
//    TestRemoveNodeCauseLL();
//    TestRemoveNodeCauseRR();
//    TestRemoveNodeCauseRL();
//    TestRemoveNodeCauseRLRR();
//    TestRemoveNodeCauseRRRR();
//    TestRemoveNodeCauseRLLL();
//    TestRemoveNodeCauseLRLL();
    TestRemoveNodeCauseLR2();
//    TestRemoveNodeCauseLR3();
//    TestRandomInput();
    return 0;
}

