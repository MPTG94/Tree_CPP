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
    //treeLL
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
//    treeLR->getMinNode();
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
//    treeRR->getMinNode();
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
//    treeRL->getMinNode();
    delete treeRL;
    treeRL = nullptr;
    std::cout << std::endl;
    std::cout << "RL Test FINISH" << std::endl;
}

void TestAddALot(){
    std::cout <<"start to add and Remove many nodes" << std::endl;
    std::cout <<" let's hope the BF won't be more than 1 or less than -1" << std::endl;
    Tree<int> *treeBF = new Tree<int>();
    std::cout <<"start to add many nodes - first time" << std::endl;
    treeBF->Insert(1, new int(100));
    treeBF->Insert(2, new int(100));
    treeBF->Insert(3, new int(100));
    treeBF->Insert(4, new int(100));
    treeBF->Insert(5, new int(100));
    treeBF->Insert(6, new int(100));
    treeBF->Insert(7, new int(100));
    treeBF->Insert(8, new int(100));
    treeBF->Insert(11, new int(100));
    treeBF->Insert(12, new int(100));
    treeBF->Insert(13, new int(100));
    treeBF->Insert(14, new int(100));
    treeBF->Insert(15, new int(100));
    treeBF->Insert(16, new int(100));
    treeBF->Insert(17, new int(100));
    treeBF->Insert(18, new int(100));
    treeBF->Insert(21, new int(100));
    treeBF->Insert(22, new int(100));
    treeBF->Insert(23, new int(100));
    treeBF->Insert(34, new int(100));
    treeBF->Insert(35, new int(100));
    treeBF->Insert(36, new int(100));
    treeBF->Insert(37, new int(100));
    treeBF->Insert(38, new int(100));
    treeBF->Insert(91, new int(100));
    treeBF->Insert(92, new int(100));
    treeBF->Insert(93, new int(100));
    treeBF->Insert(94, new int(100));
    treeBF->Insert(95, new int(100));
    treeBF->Insert(96, new int(100));
    treeBF->Insert(97, new int(100));
    treeBF->Insert(98, new int(100));
    treeBF->Insert(91, new int(100));
    treeBF->Insert(92, new int(100));
    treeBF->Insert(93, new int(100));
    treeBF->Insert(94, new int(100));
    treeBF->Insert(95, new int(100));
    treeBF->Insert(96, new int(100));
    treeBF->Insert(97, new int(100));
    treeBF->Insert(98, new int(100));
    treeBF->Insert(61, new int(100));
    treeBF->Insert(62, new int(100));
    treeBF->Insert(63, new int(100));
    treeBF->Insert(64, new int(100));
    treeBF->Insert(65, new int(100));
    treeBF->Insert(66, new int(100));
    treeBF->Insert(67, new int(100));
    treeBF->Insert(68, new int(100));
    std::cout <<"start to Remove many nodes" << std::endl;
    treeBF->Remove(34);
    treeBF->Remove(35);
    treeBF->Remove(36);
    treeBF->Remove(37);
    treeBF->Remove(38);
    treeBF->Remove(91);
    treeBF->Remove(92);
    treeBF->Remove(93);
    treeBF->Remove(94);
    treeBF->Remove(95);
    treeBF->Remove(96);
    treeBF->Remove(97);
    treeBF->Remove(98);
    treeBF->Remove(61);
    treeBF->Remove(62);
    treeBF->Remove(63);
    treeBF->Remove(64);
    treeBF->Remove(65);
    treeBF->Remove(66);
    treeBF->Remove(67);
    treeBF->Remove(68);
    std::cout <<"start to add many nodes - second time" << std::endl;
    treeBF->Insert(1, new int(100));
    treeBF->Insert(2, new int(100));
    treeBF->Insert(3, new int(100));
    treeBF->Insert(4, new int(100));
    treeBF->Insert(5, new int(100));
    treeBF->Insert(6, new int(100));
    treeBF->Insert(7, new int(100));
    treeBF->Insert(8, new int(100));
    treeBF->Insert(11, new int(100));
    treeBF->Insert(12, new int(100));
    treeBF->Insert(13, new int(100));
    treeBF->Insert(14, new int(100));
    treeBF->Insert(15, new int(100));
    treeBF->Insert(16, new int(100));
    treeBF->Insert(17, new int(100));
    treeBF->Insert(18, new int(100));
    treeBF->Insert(21, new int(100));
    treeBF->Insert(22, new int(100));
    treeBF->Insert(23, new int(100));
    treeBF->Insert(34, new int(100));
    treeBF->Insert(35, new int(100));
    treeBF->Insert(36, new int(100));
    treeBF->Insert(37, new int(100));
    treeBF->Insert(38, new int(100));
    treeBF->Insert(91, new int(100));
    treeBF->Insert(92, new int(100));
    treeBF->Insert(93, new int(100));
    treeBF->Insert(94, new int(100));
    treeBF->Insert(95, new int(100));
    treeBF->Insert(96, new int(100));
    treeBF->Insert(97, new int(100));
    treeBF->Insert(98, new int(100));
    treeBF->Insert(91, new int(100));
    treeBF->Insert(92, new int(100));
    treeBF->Insert(93, new int(100));
    treeBF->Insert(94, new int(100));
    treeBF->Insert(95, new int(100));
    treeBF->Insert(96, new int(100));
    treeBF->Insert(97, new int(100));
    treeBF->Insert(98, new int(100));
    treeBF->Insert(61, new int(100));
    treeBF->Insert(62, new int(100));
    treeBF->Insert(63, new int(100));
    treeBF->Insert(64, new int(100));
    treeBF->Insert(65, new int(100));
    treeBF->Insert(66, new int(100));
    treeBF->Insert(67, new int(100));
    treeBF->Insert(68, new int(100));
    std::cout <<"start to Remove many nodes" << std::endl;
    treeBF->Remove(34);
    treeBF->Remove(35);
    treeBF->Remove(36);
    treeBF->Remove(37);
    treeBF->Remove(38);
    treeBF->Remove(91);
    treeBF->Remove(92);
    treeBF->Remove(93);
    treeBF->Remove(94);
    treeBF->Remove(95);
    treeBF->Remove(96);
    treeBF->Remove(97);
    treeBF->Remove(98);
    treeBF->Remove(61);
    treeBF->Remove(62);
    treeBF->Remove(63);
    treeBF->Remove(64);
    treeBF->Remove(65);
    treeBF->Remove(66);
    treeBF->Remove(67);
    treeBF->Remove(68);
    std::cout <<"start to add many nodes - third time" << std::endl;
    treeBF->Insert(1, new int(100));
    treeBF->Insert(2, new int(100));
    treeBF->Insert(3, new int(100));
    treeBF->Insert(4, new int(100));
    treeBF->Insert(5, new int(100));
    treeBF->Insert(6, new int(100));
    treeBF->Insert(7, new int(100));
    treeBF->Insert(8, new int(100));
    treeBF->Insert(11, new int(100));
    treeBF->Insert(12, new int(100));
    treeBF->Insert(13, new int(100));
    treeBF->Insert(14, new int(100));
    treeBF->Insert(15, new int(100));
    treeBF->Insert(16, new int(100));
    treeBF->Insert(17, new int(100));
    treeBF->Insert(18, new int(100));
    treeBF->Insert(21, new int(100));
    treeBF->Insert(22, new int(100));
    treeBF->Insert(23, new int(100));
    treeBF->Insert(34, new int(100));
    treeBF->Insert(35, new int(100));
    treeBF->Insert(36, new int(100));
    treeBF->Insert(37, new int(100));
    treeBF->Insert(38, new int(100));
    treeBF->Insert(91, new int(100));
    treeBF->Insert(92, new int(100));
    treeBF->Insert(93, new int(100));
    treeBF->Insert(94, new int(100));
    treeBF->Insert(95, new int(100));
    treeBF->Insert(96, new int(100));
    treeBF->Insert(97, new int(100));
    treeBF->Insert(98, new int(100));
    treeBF->Insert(91, new int(100));
    treeBF->Insert(92, new int(100));
    treeBF->Insert(93, new int(100));
    treeBF->Insert(94, new int(100));
    treeBF->Insert(95, new int(100));
    treeBF->Insert(96, new int(100));
    treeBF->Insert(97, new int(100));
    treeBF->Insert(98, new int(100));
    treeBF->Insert(61, new int(100));
    treeBF->Insert(62, new int(100));
    treeBF->Insert(63, new int(100));
    treeBF->Insert(64, new int(100));
    treeBF->Insert(65, new int(100));
    treeBF->Insert(66, new int(100));
    treeBF->Insert(67, new int(100));
    treeBF->Insert(68, new int(100));
    std::cout <<"start to Remove many nodes" << std::endl;
    treeBF->Remove(34);
    treeBF->Remove(35);
    treeBF->Remove(36);
    treeBF->Remove(37);
    treeBF->Remove(38);
    treeBF->Remove(91);
    treeBF->Remove(92);
    treeBF->Remove(93);
    treeBF->Remove(94);
    treeBF->Remove(95);
    treeBF->Remove(96);
    treeBF->Remove(97);
    treeBF->Remove(98);
    treeBF->Remove(61);
    treeBF->Remove(62);
    treeBF->Remove(63);
    treeBF->Remove(64);
    treeBF->Remove(65);
    treeBF->Remove(66);
    treeBF->Remove(67);
    treeBF->Remove(68);
    std::cout <<"start to add many nodes - fourth time" << std::endl;
    treeBF->Insert(1, new int(100));
    treeBF->Insert(2, new int(100));
    treeBF->Insert(3, new int(100));
    treeBF->Insert(4, new int(100));
    treeBF->Insert(5, new int(100));
    treeBF->Insert(6, new int(100));
    treeBF->Insert(7, new int(100));
    treeBF->Insert(8, new int(100));
    treeBF->Insert(11, new int(100));
    treeBF->Insert(12, new int(100));
    treeBF->Insert(13, new int(100));
    treeBF->Insert(14, new int(100));
    treeBF->Insert(15, new int(100));
    treeBF->Insert(16, new int(100));
    treeBF->Insert(17, new int(100));
    treeBF->Insert(18, new int(100));
    treeBF->Insert(21, new int(100));
    treeBF->Insert(22, new int(100));
    treeBF->Insert(23, new int(100));
    treeBF->Insert(34, new int(100));
    treeBF->Insert(35, new int(100));
    treeBF->Insert(36, new int(100));
    treeBF->Insert(37, new int(100));
    treeBF->Insert(38, new int(100));
    treeBF->Insert(91, new int(100));
    treeBF->Insert(92, new int(100));
    treeBF->Insert(93, new int(100));
    treeBF->Insert(94, new int(100));
    treeBF->Insert(95, new int(100));
    treeBF->Insert(96, new int(100));
    treeBF->Insert(97, new int(100));
    treeBF->Insert(98, new int(100));
    treeBF->Insert(91, new int(100));
    treeBF->Insert(92, new int(100));
    treeBF->Insert(93, new int(100));
    treeBF->Insert(94, new int(100));
    treeBF->Insert(95, new int(100));
    treeBF->Insert(96, new int(100));
    treeBF->Insert(97, new int(100));
    treeBF->Insert(98, new int(100));
    treeBF->Insert(61, new int(100));
    treeBF->Insert(62, new int(100));
    treeBF->Insert(63, new int(100));
    treeBF->Insert(64, new int(100));
    treeBF->Insert(65, new int(100));
    treeBF->Insert(66, new int(100));
    treeBF->Insert(67, new int(100));
    treeBF->Insert(68, new int(100));
    std::cout <<"start to Remove many nodes" << std::endl;
    treeBF->Remove(34);
    treeBF->Remove(35);
    treeBF->Remove(36);
    treeBF->Remove(37);
    treeBF->Remove(38);
    treeBF->Remove(91);
    treeBF->Remove(92);
    treeBF->Remove(93);
    treeBF->Remove(94);
    treeBF->Remove(95);
    treeBF->Remove(96);
    treeBF->Remove(97);
    treeBF->Remove(98);
    treeBF->Remove(61);
    treeBF->Remove(62);
    treeBF->Remove(63);
    treeBF->Remove(64);
    treeBF->Remove(65);
    treeBF->Remove(66);
    treeBF->Remove(67);
    treeBF->Remove(68);
    std::cout <<"start to add many nodes - fifth time" << std::endl;
    treeBF->Insert(1, new int(100));
    treeBF->Insert(2, new int(100));
    treeBF->Insert(3, new int(100));
    treeBF->Insert(4, new int(100));
    treeBF->Insert(5, new int(100));
    treeBF->Insert(6, new int(100));
    treeBF->Insert(7, new int(100));
    treeBF->Insert(8, new int(100));
    treeBF->Insert(11, new int(100));
    treeBF->Insert(12, new int(100));
    treeBF->Insert(13, new int(100));
    treeBF->Insert(14, new int(100));
    treeBF->Insert(15, new int(100));
    treeBF->Insert(16, new int(100));
    treeBF->Insert(17, new int(100));
    treeBF->Insert(18, new int(100));
    treeBF->Insert(21, new int(100));
    treeBF->Insert(22, new int(100));
    treeBF->Insert(23, new int(100));
    treeBF->Insert(34, new int(100));
    treeBF->Insert(35, new int(100));
    treeBF->Insert(36, new int(100));
    treeBF->Insert(37, new int(100));
    treeBF->Insert(38, new int(100));
    treeBF->Insert(91, new int(100));
    treeBF->Insert(92, new int(100));
    treeBF->Insert(93, new int(100));
    treeBF->Insert(94, new int(100));
    treeBF->Insert(95, new int(100));
    treeBF->Insert(96, new int(100));
    treeBF->Insert(97, new int(100));
    treeBF->Insert(98, new int(100));
    treeBF->Insert(91, new int(100));
    treeBF->Insert(92, new int(100));
    treeBF->Insert(93, new int(100));
    treeBF->Insert(94, new int(100));
    treeBF->Insert(95, new int(100));
    treeBF->Insert(96, new int(100));
    treeBF->Insert(97, new int(100));
    treeBF->Insert(98, new int(100));
    treeBF->Insert(61, new int(100));
    treeBF->Insert(62, new int(100));
    treeBF->Insert(63, new int(100));
    treeBF->Insert(64, new int(100));
    treeBF->Insert(65, new int(100));
    treeBF->Insert(66, new int(100));
    treeBF->Insert(67, new int(100));
    treeBF->Insert(68, new int(100));
    std::cout <<"start to Remove many nodes" << std::endl;
    treeBF->Remove(34);
    treeBF->Remove(35);
    treeBF->Remove(36);
    treeBF->Remove(37);
    treeBF->Remove(38);
    treeBF->Remove(91);
    treeBF->Remove(92);
    treeBF->Remove(93);
    treeBF->Remove(94);
    treeBF->Remove(95);
    treeBF->Remove(96);
    treeBF->Remove(97);
    treeBF->Remove(98);
    treeBF->Remove(61);
    treeBF->Remove(62);
    treeBF->Remove(63);
    treeBF->Remove(64);
    treeBF->Remove(65);
    treeBF->Remove(66);
    treeBF->Remove(67);
    treeBF->Remove(68);
    std::cout <<"start to add many nodes - sixth time" << std::endl;
    treeBF->Insert(1, new int(100));
    treeBF->Insert(2, new int(100));
    treeBF->Insert(3, new int(100));
    treeBF->Insert(4, new int(100));
    treeBF->Insert(5, new int(100));
    treeBF->Insert(6, new int(100));
    treeBF->Insert(7, new int(100));
    treeBF->Insert(8, new int(100));
    treeBF->Insert(11, new int(100));
    treeBF->Insert(12, new int(100));
    treeBF->Insert(13, new int(100));
    treeBF->Insert(14, new int(100));
    treeBF->Insert(15, new int(100));
    treeBF->Insert(16, new int(100));
    treeBF->Insert(17, new int(100));
    treeBF->Insert(18, new int(100));
    treeBF->Insert(21, new int(100));
    treeBF->Insert(22, new int(100));
    treeBF->Insert(23, new int(100));
    treeBF->Insert(34, new int(100));
    treeBF->Insert(35, new int(100));
    treeBF->Insert(36, new int(100));
    treeBF->Insert(37, new int(100));
    treeBF->Insert(38, new int(100));
    treeBF->Insert(91, new int(100));
    treeBF->Insert(92, new int(100));
    treeBF->Insert(93, new int(100));
    treeBF->Insert(94, new int(100));
    treeBF->Insert(95, new int(100));
    treeBF->Insert(96, new int(100));
    treeBF->Insert(97, new int(100));
    treeBF->Insert(98, new int(100));
    treeBF->Insert(91, new int(100));
    treeBF->Insert(92, new int(100));
    treeBF->Insert(93, new int(100));
    treeBF->Insert(94, new int(100));
    treeBF->Insert(95, new int(100));
    treeBF->Insert(96, new int(100));
    treeBF->Insert(97, new int(100));
    treeBF->Insert(98, new int(100));
    treeBF->Insert(61, new int(100));
    treeBF->Insert(62, new int(100));
    treeBF->Insert(63, new int(100));
    treeBF->Insert(64, new int(100));
    treeBF->Insert(65, new int(100));
    treeBF->Insert(66, new int(100));
    treeBF->Insert(67, new int(100));
    treeBF->Insert(68, new int(100));
    std::cout <<"start to Remove many nodes" << std::endl;
    treeBF->Remove(34);
    treeBF->Remove(35);
    treeBF->Remove(36);
    treeBF->Remove(37);
    treeBF->Remove(38);
    treeBF->Remove(91);
    treeBF->Remove(92);
    treeBF->Remove(93);
    treeBF->Remove(94);
    treeBF->Remove(95);
    treeBF->Remove(96);
    treeBF->Remove(97);
    treeBF->Remove(98);
    treeBF->Remove(61);
    treeBF->Remove(62);
    treeBF->Remove(63);
    treeBF->Remove(64);
    treeBF->Remove(65);
    treeBF->Remove(66);
    treeBF->Remove(67);
    treeBF->Remove(68);
    std::cout <<"start to add many nodes - seventh time" << std::endl;
    treeBF->Insert(1, new int(100));
    treeBF->Insert(2, new int(100));
    treeBF->Insert(3, new int(100));
    treeBF->Insert(4, new int(100));
    treeBF->Insert(5, new int(100));
    treeBF->Insert(6, new int(100));
    treeBF->Insert(7, new int(100));
    treeBF->Insert(8, new int(100));
    treeBF->Insert(11, new int(100));
    treeBF->Insert(12, new int(100));
    treeBF->Insert(13, new int(100));
    treeBF->Insert(14, new int(100));
    treeBF->Insert(15, new int(100));
    treeBF->Insert(16, new int(100));
    treeBF->Insert(17, new int(100));
    treeBF->Insert(18, new int(100));
    treeBF->Insert(21, new int(100));
    treeBF->Insert(22, new int(100));
    treeBF->Insert(23, new int(100));
    treeBF->Insert(34, new int(100));
    treeBF->Insert(35, new int(100));
    treeBF->Insert(36, new int(100));
    treeBF->Insert(37, new int(100));
    treeBF->Insert(38, new int(100));
    treeBF->Insert(91, new int(100));
    treeBF->Insert(92, new int(100));
    treeBF->Insert(93, new int(100));
    treeBF->Insert(94, new int(100));
    treeBF->Insert(95, new int(100));
    treeBF->Insert(96, new int(100));
    treeBF->Insert(97, new int(100));
    treeBF->Insert(98, new int(100));
    treeBF->Insert(91, new int(100));
    treeBF->Insert(92, new int(100));
    treeBF->Insert(93, new int(100));
    treeBF->Insert(94, new int(100));
    treeBF->Insert(95, new int(100));
    treeBF->Insert(96, new int(100));
    treeBF->Insert(97, new int(100));
    treeBF->Insert(98, new int(100));
    treeBF->Insert(61, new int(100));
    treeBF->Insert(62, new int(100));
    treeBF->Insert(63, new int(100));
    treeBF->Insert(64, new int(100));
    treeBF->Insert(65, new int(100));
    treeBF->Insert(66, new int(100));
    treeBF->Insert(67, new int(100));
    treeBF->Insert(68, new int(100));
    std::cout <<"start to Remove many nodes" << std::endl;
    treeBF->Remove(34);
    treeBF->Remove(35);
    treeBF->Remove(36);
    treeBF->Remove(37);
    treeBF->Remove(38);
    treeBF->Remove(91);
    treeBF->Remove(92);
    treeBF->Remove(93);
    treeBF->Remove(94);
    treeBF->Remove(95);
    treeBF->Remove(96);
    treeBF->Remove(97);
    treeBF->Remove(98);
    treeBF->Remove(61);
    treeBF->Remove(62);
    treeBF->Remove(63);
    treeBF->Remove(64);
    treeBF->Remove(65);
    treeBF->Remove(66);
    treeBF->Remove(67);
    treeBF->Remove(68);

    delete treeBF;
    treeBF = nullptr;
    std::cout << "you wish the problem would be in DS" << std::endl;

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
//    treeLRnRootC->getMinNode();
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
//    treeLLnRootC->getMinNode();
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
//    treeRRnRootC->getMinNode();
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
//    treeRLnRootC->getMinNode();
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
//    treeDeleteRootGetSuccessor->getMinNode();
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
//    treeDeleteRootNotSuccessor->getMinNode();
    delete treeDeleteRootNotSuccessor;
    treeDeleteRootNotSuccessor = nullptr;
    std::cout << std::endl;
    std::cout << "replace root with non successor Test FINISH" << std::endl;
}

void TestremoveNodeWithSuccessorNeighbour() {
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
//    treeDeleteNodeSuccessor->getMinNode();
    delete treeDeleteNodeSuccessor;
    std::cout << std::endl;
    std::cout << "replace node with successor neighbour Test FINISH" << std::endl;
}

void TestremoveNodeWithSuccessorNonNeighbour() {
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
//    treeDeleteNodeSuccessor->getMinNode();
    delete treeDeleteNodeSuccessor;
    std::cout << std::endl;
    std::cout << "replace node with successor non neighbour Test FINISH" << std::endl;
}

void TestremoveNodeCauseLR() {
    //node deletion causing LR case9
//	/*correct output
//	1 BF: 0 Height: 0
//	2 BF: 0 Height: 1
//	3 BF: 0 Height: 0
//	4 BF: 0 Height: 2
//	7 BF: -1 Height: 1
//	8 BF: 0 Height: 0*/
    std::cout << "Remove node and cause LR Test START" << std::endl;
    Tree<int> *tree = new Tree<int>();
    tree->Insert(7, new int(7));
    tree->Insert(2, new int(2));
    tree->Insert(8, new int(8));
    tree->Insert(1, new int(1));
    tree->Insert(4, new int(4));
    tree->Insert(9, new int(9));
    tree->Insert(3, new int(3));
    tree->Remove(9);
    tree->getMinNode();
    delete tree;
    std::cout << std::endl;
    std::cout << "Remove node and cause LR Test FINISH" << std::endl;
}

void TestremoveNodeCauseLL() {
    //node deletion causing LL case10
//	/*correct output
//	1 BF: 0 Height: 0
//	2 BF: 0 Height: 1
//	3 BF: 0 Height: 0
//	4 BF: 0 Height: 2
//	7 BF: -1 Height: 1
//	8 BF: 0 Height: 0*/
    std::cout << "Remove node and cause LL Test START" << std::endl;
    Tree<int> *tree = new Tree<int>();
    tree->Insert(7, new int(7));
    tree->Insert(3, new int(3));
    tree->Insert(8, new int(8));
    tree->Insert(2, new int(2));
    tree->Insert(4, new int(4));
    tree->Insert(9, new int(9));
    tree->Insert(1, new int(1));
    tree->Remove(9);
    tree->getMinNode();
    delete tree;
    std::cout << std::endl;
    std::cout << "Remove node and cause LL Test FINISH" << std::endl;
}

void TestremoveNodeCauseRR() {
    //node deletion causing RR case10
//	/*correct output
//	1 BF: 0 Height: 0
//	2 BF: 0 Height: 1
//	3 BF: 0 Height: 0
//	4 BF: 0 Height: 2
//	7 BF: -1 Height: 1
//	8 BF: 0 Height: 0*/
    std::cout << "Remove node and cause RR Test START" << std::endl;
    Tree<int> *tree = new Tree<int>();
    tree->Insert(3, new int(3));
    tree->Insert(2, new int(2));
    tree->Insert(8, new int(8));
    tree->Insert(7, new int(7));
    tree->Insert(1, new int(1));
    tree->Insert(9, new int(9));
    tree->Insert(10, new int(10));
    tree->Remove(1);
    tree->getMinNode();
    delete tree;
    std::cout << std::endl;
    std::cout << "Remove node and cause RR Test FINISH" << std::endl;
}

void TestremoveNodeCauseRL() {
    //node deletion causing RR case10
//	/*correct output
//	1 BF: 0 Height: 0
//	2 BF: 0 Height: 1
//	3 BF: 0 Height: 0
//	4 BF: 0 Height: 2
//	7 BF: -1 Height: 1
//	8 BF: 0 Height: 0*/
    std::cout << "Remove node and cause RL Test START" << std::endl;
    Tree<int> *tree = new Tree<int>();
    tree->Insert(3, new int(3));
    tree->Insert(2, new int(2));
    tree->Insert(13, new int(13));
    tree->Insert(7, new int(7));
    tree->Insert(1, new int(1));
    tree->Insert(14, new int(14));
    tree->Insert(10, new int(10));
    tree->Remove(1);
    tree->getMinNode();
    delete tree;
    std::cout << std::endl;
    std::cout << "Remove node and cause RL Test FINISH" << std::endl;
}

void TestremoveNodeCauseRLRR() {
    //node deletion causing RR case10
//	/*correct output
//	1 BF: 0 Height: 0
//	2 BF: 0 Height: 1
//	3 BF: 0 Height: 0
//	4 BF: 0 Height: 2
//	7 BF: -1 Height: 1
//	8 BF: 0 Height: 0*/
    std::cout << "Remove node and cause RL RR Test START" << std::endl;
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
    tree->getMinNode();
    delete tree;
    std::cout << std::endl;
    std::cout << "Remove node and cause RL RR Test FINISH" << std::endl;
}

void TestremoveNodeCauseRRRR() {
    //node deletion causing RR case10
//	/*correct output
//	1 BF: 0 Height: 0
//	2 BF: 0 Height: 1
//	3 BF: 0 Height: 0
//	4 BF: 0 Height: 2
//	7 BF: -1 Height: 1
//	8 BF: 0 Height: 0*/
    std::cout << "Remove node and cause RR RR Test START" << std::endl;
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
    tree->getMinNode();
    delete tree;
    std::cout << std::endl;
    std::cout << "Remove node and cause RR RR Test FINISH" << std::endl;
}

void TestremoveNodeCauseRLLL() {
    //node deletion causing RR case10
//	/*correct output
//	1 BF: 0 Height: 0
//	2 BF: 0 Height: 1
//	3 BF: 0 Height: 0
//	4 BF: 0 Height: 2
//	7 BF: -1 Height: 1
//	8 BF: 0 Height: 0*/
    std::cout << "Remove node and cause RL LL Test START" << std::endl;
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
    tree->getMinNode();
    delete tree;
    std::cout << std::endl;
    std::cout << "Remove node and cause RL LL Test FINISH" << std::endl;
}

void TestremoveNodeCauseLRLL() {
    //node deletion causing RR case10
//	/*correct output
//	1 BF: 0 Height: 0
//	2 BF: 0 Height: 1
//	3 BF: 0 Height: 0
//	4 BF: 0 Height: 2
//	7 BF: -1 Height: 1
//	8 BF: 0 Height: 0*/
    std::cout << "Remove node and cause LR LL Test START" << std::endl;
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
    tree->getMinNode();
    delete tree;
    std::cout << std::endl;
    std::cout << "Remove node and cause LR LL Test FINISH" << std::endl;
}

void TestremoveNodeCauseLR2() {
    //node deletion causing RR case10
//	/*correct output
//	1 BF: 0 Height: 0
//	2 BF: 0 Height: 1
//	3 BF: 0 Height: 0
//	4 BF: 0 Height: 2
//	7 BF: -1 Height: 1
//	8 BF: 0 Height: 0*/
    std::cout << "Remove node and cause LR 2 Test START" << std::endl;
    Tree<int> *tree = new Tree<int>();
    tree->Insert(5, new int(5));
    tree->Insert(3, new int(3));
    tree->Insert(6, new int(6));
    tree->Insert(2, new int(2));
    tree->Insert(4, new int(4));
    tree->Remove(5);
    tree->getMinNode();
    delete tree;
    std::cout << std::endl;
    std::cout << "Remove node and cause LR 2 Test FINISH" << std::endl;
}

void TestremoveNodeCauseLR3() {
    //node deletion causing RR case10
//	/*correct output
//	1 BF: 0 Height: 0
//	2 BF: 0 Height: 1
//	3 BF: 0 Height: 0
//	4 BF: 0 Height: 2
//	7 BF: -1 Height: 1
//	8 BF: 0 Height: 0*/
    std::cout << "Remove node and cause LR 3 Test START" << std::endl;
    Tree<int> *tree = new Tree<int>();
    tree->Insert(5, new int(5));
    tree->Insert(3, new int(3));
    tree->Insert(6, new int(6));
    tree->Insert(2, new int(2));
    tree->Remove(5);
    tree->getMinNode();
    delete tree;
    std::cout << std::endl;
    std::cout << "Remove node and cause LR 3 Test FINISH" << std::endl;
}

void TestRandomInput() {
    std::cout << "Random Input Test START" << std::endl;
    Tree<int> *tree = new Tree<int>();
    std::vector<int> vector;
    for (int i = 1; i <= 100; i++) vector.push_back(i);

    //Randomly Insert and removes nodes
    for (int k = 0; k < 20; ++k) {
        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
        shuffle(vector.begin(), vector.end(), std::default_random_engine(seed));
        for (std::vector<int>::iterator it = vector.begin(); it != vector.end(); ++it) {
            tree->Insert(*it, new int(*it));

        }
        tree->getMinNode();
        std::cout << std::endl;
        shuffle(vector.begin(), vector.end(), std::default_random_engine(seed));
        for (std::vector<int>::iterator it = vector.begin(); it != vector.end(); ++it) {
            tree->Remove(*it);
            tree->getMinNode();

        }
        delete tree;
        tree = new Tree<int>();
        std::cout << std::endl;
    }
    std::cout << std::endl;
    std::cout << "Random Input Test FINISH" << std::endl;
}

void TestFind() {
    std::cout << "Find Test START" << std::endl;
    Tree<int> *tree = new Tree<int>();
    tree->Insert(5, new int(5));
    TreeNode<int> *test = tree->Find(5);
    if (test) {
        std::cout << "found node with key: " << test->getKey() << std::endl;
    } else {
        std::cout << "can't Find node with key: " << test->getKey() << std::endl;
    }
    test = tree->Find(3);
    if (test) {
        std::cout << "found node with key: " << test->getKey() << std::endl;
    } else {
        std::cout << "can't Find node with given key" << std::endl;
    }
    tree->Insert(3, new int(3));
    tree->Insert(6, new int(6));
    tree->Insert(2, new int(2));
    tree->Insert(4, new int(4));
    tree->Remove(5);
    test = tree->Find(5);
    if (test) {
        std::cout << "found node with key: " << test->getKey() << std::endl;
    } else {
        std::cout << "can't Find node with given key" << std::endl;
    }
    tree->getMinNode();
    delete tree;
    std::cout << std::endl;
    std::cout << "Find Test FINISH" << std::endl;
}

void TestCreateAndremoveSoloRoot() {
    std::cout << "Create and Remove only root Test START" << std::endl;
    Tree<int> tree = Tree<int>();
    tree.Insert(1, new int(5));
    tree.Remove(1);
//    if (tree.IsEmpty()) {
//        std::cout << "The tree is now empty" << std::endl;
//    }
    std::cout << "Create and Remove only root Test FINISH" << std::endl;
}

void TestCreateRootAndRightChildremoveRoot() {
    std::cout << "Create root and right child Remove only root Test START" << std::endl;
    Tree<int> tree = Tree<int>();
    tree.Insert(1, new int(5));
    tree.Insert(2, new int(5));
    tree.Remove(1);
    if (tree.Find(1) == nullptr) {
        std::cout << "The previous root is deleted" << std::endl;
    }
    if (tree.Find(2) != nullptr) {
        std::cout << "The tree has a new correct root" << std::endl;
    }
    std::cout << "Create root and right child Remove only root Test FINISH" << std::endl;
}

void TestCreateRootAndLeftChildremoveRoot() {
    std::cout << "Create root and left child Remove only root Test START" << std::endl;
    Tree<int> tree = Tree<int>();
    tree.Insert(2, new int(5));
    tree.Insert(1, new int(5));
    tree.Remove(2);
    if (tree.Find(2) == nullptr) {
        std::cout << "The previous root is deleted" << std::endl;
    }
    if (tree.Find(1) != nullptr) {
        std::cout << "The tree has a new correct root" << std::endl;
    }
    std::cout << "Create root and left child Remove only root Test FINISH" << std::endl;
}

void TestCreateRootAndTwoChildrenremoveRoot() {
    std::cout << "Create root and two children Remove only root Test START" << std::endl;
    Tree<int> tree = Tree<int>();
    tree.Insert(2, new int(5));
    tree.Insert(1, new int(5));
    tree.Insert(3, new int(5));
    tree.Remove(2);
    if (tree.Find(2) == nullptr) {
        std::cout << "The previous root is deleted" << std::endl;
    }
    if (tree.Find(1) != nullptr) {
        std::cout << "One of the children still exists" << std::endl;
    }
    if (tree.Find(3) != nullptr) {
        std::cout << "Both of the children still exist" << std::endl;
    }
    std::cout << "Create root and two children Remove only root Test FINISH" << std::endl;
}

void TestTreeDeletionNullptr() {
    std::cout << "Tree Deletion Reference Nullptr Test START" << std::endl;
    Tree<int> *tree = new Tree<int>();
    tree->Insert(1, new int(5));
    TreeNode<int> *temp = tree->Find(1);
    if (temp) {
        std::cout << "Found node with key 1" << std::endl;
    }
    delete tree;
    std::cout << "Tree Deletion Reference Nullptr Test FINISH" << std::endl;
}

void TestTreeDelete2NodesTillEmpty() {
    std::cout << "Tree delete 2 nodes till empty Test START" << std::endl;
    Tree<int> *tree = new Tree<int>();
    tree->Insert(1, new int(5));
    tree->Insert(2, new int(5));
    tree->Remove(1);
    tree->Remove(2);
//    if (tree->IsEmpty()) {
//        std::cout << "the tree is now empty" << std::endl;
//    }
    delete tree;
    std::cout << "Tree delete 2 nodes till empty Test FINISH" << std::endl;
}

void TestGetNextFunc() {
    std::cout << "Tree Get next Test START" << std::endl;
    Tree<int> *tree = new Tree<int>();
    tree->Insert(1, new int(5));
    TreeNode<int> *retrieve = tree->Find(1);
//    TreeNode<int> *next = retrieve->getNext();
//    if (!next) {
//        std::cout << "no successor" << std::endl;
//    }
//    tree->Insert(2, new int(5));
//    tree->Remove(1);
//    tree->Remove(2);
//    if (tree->IsEmpty()) {
//        std::cout << "the tree is now empty" << std::endl;
//    }
    delete tree;
    std::cout << "Tree Get next Test FINISH" << std::endl;
}

void test1 (Tree<int>* t) {

    t->Insert(100, new int(100));
    t->Insert(200, new int(100));
    t->Insert(-100, new int(100));
    t->Insert(324, new int(100));
    t->Insert(100, new int(100));
    t->Insert(64, new int(100));
    t->Insert(11, new int(100));
    t->Insert(33, new int(100));
    t->Insert(4135, new int(100));
    t->Insert(451, new int(100));
    t->Insert(77, new int(100));
    t->Insert(-6, new int(100));
    t->Insert(2, new int(100));
    t->Insert(88, new int(100));
    t->Insert(-34, new int(100));
    t->Insert(-111, new int(100));
    t->Insert(234, new int(100));
    t->Insert(678, new int(100));
    t->Insert(89, new int(100));
    t->Insert(-12, new int(100));
    t->Insert(-21, new int(100));
    t->Insert(54, new int(100));
    t->Insert(-988, new int(100));
    t->Insert(676, new int(100));
    t->Remove(-100);
    t->Remove(676);
    t->Remove(-988);
    t->Remove(678);
    t->Remove(89);
    t->Remove(451);



}



int main() {
    TestLL();
    TestLR();
    TestRR();
    TestRL();
    TestLRDontChangeRoot();
    TestLLDontChangeRoot();
    TestRRDontChangeRoot();
    TestRLDontChangeRoot();
    TestReplaceRootWithSuccessor();
    TestReplaceRootWithNonSuccessor();
    TestremoveNodeWithSuccessorNeighbour();
    TestremoveNodeWithSuccessorNonNeighbour();
    TestremoveNodeCauseLR();
    TestremoveNodeCauseLL();
    TestremoveNodeCauseRR();
    TestremoveNodeCauseRL();
    TestremoveNodeCauseRLRR();
    TestremoveNodeCauseRRRR();
   TestremoveNodeCauseRLLL();
    TestremoveNodeCauseLRLL();
    TestremoveNodeCauseLR2();
    TestremoveNodeCauseLR3();
    TestFind();
    TestCreateAndremoveSoloRoot();
    TestCreateRootAndRightChildremoveRoot();
    TestCreateRootAndLeftChildremoveRoot();
    TestCreateRootAndTwoChildrenremoveRoot();
    TestTreeDeletionNullptr();
    TestTreeDelete2NodesTillEmpty();
//    TestRandomInput();
 //     TestAddALot();
//    test1(t);
//    for (int i = 0; i < 5000; ++i) {
//        t->Insert(i, new int(i));
//    }
//    t->getMinNode();
    Tree<int> *t =new Tree<int>();
    for(int i = 1 ; i<10000 ; i++){
        int k = rand() %1000;
        if (!t->Find(k)) {
            t->Insert(k, new int(1));
        }
    }
    for (int i=1; i<100; i++){
        int k=rand()%1000;
        t->Remove(k);
    }
    for(int i = 1 ; i<10000 ; i++){
        int k = rand() %1000;
        if (!t->Find(k)) {
            t->Insert(k, new int(1));
        }
    }
    for (int i=1; i<100; i++){
        int k=rand()%1000;
        t->Remove(k);
    }
    for(int i = 1 ; i<10000 ; i++){
        int k = rand() %1000;
        if (!t->Find(k)) {
            t->Insert(k, new int(1));
        }
    }
    for (int i=1; i<100; i++){
        int k=rand()%1000;
        t->Remove(k);
    }
    for(int i = 1 ; i<10000 ; i++){
        int k = rand() %1000;
        if (!t->Find(k)) {
            t->Insert(k, new int(1));
        }
    }
    for (int i=1; i<100; i++){
        int k=rand()%1000;
        t->Remove(k);
    }
    delete t;
    return 0;

    //std::cout << "result is: " << result->getKey() << *result->getData() << std::endl;
}

