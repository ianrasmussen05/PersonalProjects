#ifndef _HASH_MAP
#define _HASH_MAP

#include <iostream>
#include <string>
#include <list>

#include "TreeNode.h"
#include "BST.h"

#define TABLE_SIZE 10

class HashMap {
    private:
        int numBuckets = TABLE_SIZE;
        BST **table;

    public:
        HashMap();
        HashMap(int numBuckets);
        ~HashMap();

        bool isEmpty();
        int hashFunction(int key);
        void insert(Hash* obj);
        bool deleteHash(int key);
        bool searchValue(int key);
        void printTable();
};

#endif