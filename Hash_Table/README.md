# Hash Table
In this C++ program, a Hash Table is created that uses **Binary Search Tree** separate chaining. The default amount of buckets is 10, but in `main.cpp`, that can be changed using the `hashmap()` overloaded function. The program takes in an object of `<integer, string>`, where the integer is the users number, but also represents the key of the object. The string represents the name of the user.

The user will be able to insert, remove, and search for items within the Hash Table. The implementation is done in `main.cpp`.

The idea of this project was to get familiar with Hash Tables and possibly get overall faster time complexity with the implementation of a BST. With a small number of inputs, you would most likely see a decrease in execution time because of the overhead and space used to create a BST for each bucket. However, you would see better results when thousands of entries have been inputted.

## Future Ideas
- Have user input on the CLI
- Be able to input a `.csv` file to import many users/objects
- Be able to edit an existing user/object

## Contributors
- [Ian Rasmussen](https://github.com/ianrasmussen05)

## References
- To get a [hash function](https://stackoverflow.com/questions/664014/what-integer-hash-function-are-good-that-accepts-an-integer-hash-key) for integers