#include "hashmap.h"

HashMap::HashMap() {
    table = new BST*[this->numBuckets];
    for (int i = 0; i < this->numBuckets; ++i) {
        table[i] = new BST();
    }
}

HashMap::HashMap(int numBuckets) {
    this->numBuckets = numBuckets;
    table = new BST*[this->numBuckets];
    for (int i = 0; i < this->numBuckets; ++i) {
        table[i] = new BST();
    }
}

HashMap::~HashMap() {
    delete[] table;
}

bool HashMap::isEmpty() {
    for (int i = 0; i < this->numBuckets; ++i) {
        if (!table[i]->isEmpty()) {
            return false;
        }
    }
    return true;
}

int HashMap::hashFunction(int key) {
    // https://stackoverflow.com/questions/664014/what-integer-hash-function-are-good-that-accepts-an-integer-hash-key
    unsigned int hashNum = key;
    hashNum ^= (key << 13);
    hashNum ^= (key >> 17);    
    hashNum ^= (key << 5);
    return hashNum % this->numBuckets;
}

void HashMap::insert(Hash* obj) {
    int hashValue = this->hashFunction(obj->key);
    BST *tree = table[hashValue];
    if (!tree->isEmpty()) {
        if(table[hashValue]->search(obj->key)) {
            std::cout << "Key: '" << std::to_string(obj->key) << "' already exists, please use another..." << std::endl;
            return;
        }
    }
    table[hashValue]->insert(obj);
}

bool HashMap::deleteHash(int key) {
    int hashValue = this->hashFunction(key);
    BST *tree = table[hashValue];
    if(tree->deleteNode(key)) {
        return true;
    }
    return false;
}

bool HashMap::searchValue(int key) {
    int hashValue = this->hashFunction(key);
    BST *tree = table[hashValue];
    TreeNode *node = tree->search(key);
    if (node != NULL) {
        std::cout << node->key->print() << std::endl;
        return true;
    }
    std::cout << "Key: '" << key << "' does not exist..." << std::endl;
    return false;
}

void HashMap::printTable() {
    for (int i = 0; i < this->numBuckets; ++i) {
        BST *tree = table[i];
        std::cout << "| Bucket " << i << " | ";
        tree->printTree(tree->root);
        std::cout << std::endl;
    }
    std::cout << std::endl;
}