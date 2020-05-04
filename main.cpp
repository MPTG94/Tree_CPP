#include <iostream>
#include <langinfo.h>
#include "Tree.h"

class myData {
private:
    int artistId = 0;
    int numberOfPlays = 0;
public:
    myData();

    myData(int artistId, int numberOfPlays) : artistId(artistId), numberOfPlays(numberOfPlays) {

    }

    void Print() {
        std::cout << "ID is: " << this->artistId << std::endl;
    }

    int getArtistId() const {
        return artistId;
    }

    void setArtistId(int artistId) {
        myData::artistId = artistId;
    }

    int getNumberOfPlays() const {
        return numberOfPlays;
    }

    void setNumberOfPlays(int numberOfPlays) {
        myData::numberOfPlays = numberOfPlays;
    }
};

void addNewNode(Tree<myData>* dataTree ){
    myData* data2 = new myData(2,2);
    dataTree->Insert(2, data2);
    TreeNode<myData> *foo = dataTree->Find(2);
    myData *bar = foo->getValue();
    bar->Print();
}

int main() {
    Tree<myData> *dataTree = new Tree<myData>();
    if (!dataTree) {
        return 0;
    }
    myData* data1 = new myData(1,1);
    if (dataTree->Insert(1,data1) != SUCCESS) {
        delete dataTree;
        return 0;
    }
    addNewNode(dataTree);
    TreeNode<myData> *foo = dataTree->Find(2);
    myData *bar = foo->getValue();
    bar->Print();
    dataTree->PrintInOrder();
    delete dataTree;
    return 0;
}
