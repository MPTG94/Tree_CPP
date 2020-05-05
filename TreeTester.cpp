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
    TestRemoveNodeWithSuccessorNonNeighbour();

//
//	//node deletion causing LR case9
//	/*correct output
//	1 BF: 0 Height: 0
//	2 BF: 0 Height: 1
//	3 BF: 0 Height: 0
//	4 BF: 0 Height: 2
//	7 BF: -1 Height: 1
//	8 BF: 0 Height: 0*/
//	tree.addNode(7,7);
//	tree.addNode(2,2);
//	tree.addNode(8,8);
//	tree.addNode(1,1);
//	tree.addNode(4,4);
//	tree.addNode(9,9);
//	tree.addNode(3,3);
//	tree.removeNode(9);
//	tree.printTree();
//	tree.treeClear();
//
//	//node deletion causing LL case10
//	/*correct output
//	1 BF: 0 Height: 0
//	2 BF: 1 Height: 1
//	3 BF: 0 Height: 2
//	4 BF: 0 Height: 0
//	7 BF: 0 Height: 1
//	8 BF: 0 Height: 0*/
//	tree.addNode(7,7);
//	tree.addNode(3,3);
//	tree.addNode(8,8);
//	tree.addNode(2,2);
//	tree.addNode(4,4);
//	tree.addNode(9,9);
//	tree.addNode(1,1);
//	tree.removeNode(9);
//	tree.printTree();
//	tree.treeClear();
//
//	//node deletion causing RR case11
//	/*correct output
//	2 BF: 0 Height: 0
//	3 BF: 0 Height: 1
//	7 BF: 0 Height: 0
//	8 BF: 0 Height: 2
//	9 BF: -1 Height: 1
//	10 BF: 0 Height: 0*/
//	tree.addNode(3,3);
//	tree.addNode(2,2);
//	tree.addNode(8,8);
//	tree.addNode(7,7);
//	tree.addNode(1,1);
//	tree.addNode(9,9);
//	tree.addNode(10,10);
//	tree.removeNode(1);
//	tree.printTree();
//	tree.treeClear();
//
//	//node deletion causing RL case12
//	/*correct output
//	* 2 BF: 0 Height: 0
//	3 BF: 1 Height: 1
//	7 BF: 0 Height: 2
//	10 BF: 0 Height: 0
//	13 BF: 0 Height: 1
//	14 BF: 0 Height: 0*/
//	tree.addNode(3,3);
//	tree.addNode(2,2);
//	tree.addNode(13,13);
//	tree.addNode(7,7);
//	tree.addNode(1,1);
//	tree.addNode(14,14);
//	tree.addNode(10,10);
//	tree.removeNode(1);
//	tree.printTree();
//	tree.treeClear();
//
//	//double rotations RL and RR case 13
//	/*correct output
//	3 BF: 0 Height: 0
//	5 BF: 0 Height: 1
//	7 BF: 0 Height: 0
//	9 BF: 0 Height: 2
//	11 BF: 0 Height: 0
//	13 BF: 1 Height: 1
//	15 BF: 0 Height: 3
//	17 BF: 0 Height: 0
//	19 BF: -1 Height: 2
//	21 BF: -1 Height: 1
//	23 BF: 0 Height: 0*/
//	tree.addNode(9,9);
//	tree.addNode(3,3);
//	tree.addNode(15,15);
//	tree.addNode(1,1);
//	tree.addNode(7,7);
//	tree.addNode(13,13);
//	tree.addNode(19,19);
//	tree.addNode(5,5);
//	tree.addNode(11,11);
//	tree.addNode(17,17);
//	tree.addNode(21,21);
//	tree.addNode(23,23);
//	tree.removeNode(1);
//	tree.printTree();
//	tree.treeClear();
//
//	//double rotations RR and RR case 14
//	/*correct output
//	3 BF: 0 Height: 0
//	7 BF: 0 Height: 1
//	8 BF: 0 Height: 0
//	9 BF: 0 Height: 2
//	11 BF: 0 Height: 0
//	13 BF: 1 Height: 1
//	15 BF: 0 Height: 3
//	17 BF: 0 Height: 0
//	19 BF: -1 Height: 2
//	21 BF: -1 Height: 1
//	23 BF: 0 Height: 0*/
//	tree.addNode(9,9);
//	tree.addNode(3,3);
//	tree.addNode(15,15);
//	tree.addNode(1,1);
//	tree.addNode(7,7);
//	tree.addNode(13,13);
//	tree.addNode(19,19);
//	tree.addNode(8,8);
//	tree.addNode(11,11);
//	tree.addNode(17,17);
//	tree.addNode(21,21);
//	tree.addNode(23,23);
//	tree.removeNode(1);
//	tree.printTree();
//	tree.treeClear();
//
//	//double rotations RL and LL case 15
//	/*correct output
//	6 BF: 0 Height: 0
//	7 BF: 1 Height: 1
//	8 BF: 1 Height: 2
//	9 BF: 0 Height: 0
//	10 BF: 0 Height: 3
//	11 BF: -1 Height: 1
//	12 BF: 0 Height: 0
//	15 BF: 0 Height: 2
//	17 BF: 0 Height: 0
//	18 BF: 0 Height: 1
//	20 BF: 0 Height: 0
//	 */
//	tree.addNode(15,15);
//	tree.addNode(10,10);
//	tree.addNode(20,20);
//	tree.addNode(8,8);
//	tree.addNode(11,11);
//	tree.addNode(17,17);
//	tree.addNode(21,21);
//	tree.addNode(7,7);
//	tree.addNode(9,9);
//	tree.addNode(12,12);
//	tree.addNode(18,18);
//	tree.addNode(6,6);
//	tree.removeNode(21);
//	tree.printTree();
//	tree.treeClear();
//
//	//double rotations LR and LL case 16
//	/*correct output
//	6 BF: 0 Height: 0
//	7 BF: 1 Height: 1
//	8 BF: 1 Height: 2
//	9 BF: 0 Height: 0
//	10 BF: 0 Height: 3
//	11 BF: -1 Height: 1
//	12 BF: 0 Height: 0
//	15 BF: 0 Height: 2
//	20 BF: 0 Height: 0
//	21 BF: 0 Height: 1
//	22 BF: 0 Height: 0 */
//	tree.addNode(15,15);
//	tree.addNode(10,10);
//	tree.addNode(20,20);
//	tree.addNode(8,8);
//	tree.addNode(11,11);
//	tree.addNode(17,17);
//	tree.addNode(22,22);
//	tree.addNode(7,7);
//	tree.addNode(9,9);
//	tree.addNode(12,12);
//	tree.addNode(21,21);
//	tree.addNode(6,6);
//	tree.removeNode(17);
//	tree.printTree();
//	tree.treeClear();
//
//	//delete node cause LR
//	/*correct output
//	 * 2 BF: 0 Height: 0
//	3 BF: -1 Height: 2
//	4 BF: 0 Height: 0
//	6 BF: 1 Height: 1*/
//
//	tree.addNode(5,5);
//	tree.addNode(3,3);
//	tree.addNode(6,6);
//	tree.addNode(2,2);
//	tree.addNode(4,4);
//	tree.removeNode(5);
//	tree.printTree();
//	tree.treeClear();
//
//	//delete node cause LR
//	/*correct output
//	 * 2 BF: 0 Height: 0
//	3 BF: 0 Height: 1
//	6 BF: 0 Height: 0*/
//	tree.addNode(5,5);
//	tree.addNode(3,3);
//	tree.addNode(6,6);
//	tree.addNode(2,2);
//	tree.removeNode(5);
//	tree.printTree();
//	tree.treeClear();
//
//	std::vector<int> vector;
//	 for (int i=1; i<=100; i++) vector.push_back(i);
//
//	 //Randomly insert and removes nodes
//	 for (int k = 0; k < 20; ++k) {
//		 unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
//		 shuffle (vector.begin(), vector.end(), std::default_random_engine(seed));
//		 for (std::vector<int>::iterator it = vector.begin() ; it != vector.end(); ++it){
//				tree.addNode(*it,*it);
//
//		 }
//		 tree.printTree();
//		 shuffle (vector.begin(), vector.end(), std::default_random_engine(seed));
//		 for (std::vector<int>::iterator it = vector.begin() ; it != vector.end(); ++it){
//				tree.removeNode(*it);
//				tree.printTree();
//
//		 }
//		 tree.treeClear();
//		 tree.printTree();
//		 std::cout << '\n';
//	}

    return 0;
}

