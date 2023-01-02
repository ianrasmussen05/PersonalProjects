#include "TreeNode.h"
#include "BST.h"
#include "hashmap.h"

int main(int argc, char* argv[]) {
    HashMap *HT = new HashMap(100);
    // Hash *hash1 = new Hash{5, "Ian"};
    // Hash *hash2 = new Hash{81, "Miles"};
    // Hash *hash3 = new Hash{70, "Dad"};
    // Hash *hash4 = new Hash{68, "Mom"};
    // Hash *hash5 = new Hash{66, "Evil Man"};

    if (HT->isEmpty()) {
        std::cout << "Table is empty!" << std::endl;
    }

    for (int i = 0; i < 1000; ++i) {
        HT->insert(new Hash{i, "Ian"});
    }
    HT->insert(new Hash{6, "tom"}); // won't insert, obj already exists

    //HT->printTable();
    HT->deleteHash(66);
    HT->searchValue(66);
    HT->searchValue(5);

    HT->printTable();

    delete HT;

    return 0;
}