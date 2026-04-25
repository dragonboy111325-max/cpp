#include <iostream>
#include <list> 
#include <utility> // For std::pair

using namespace std;

class Hashtable {
private:
    static const int tableSize = 8;
    
    list<pair<int, int>> table[tableSize];

public:
    int h ashFunction(int key) {
        return key % tableSize;
    }

    void insert(int key, int value) {
        int index = hashFunction(key);
        
        table[index].emplace_back(key, value);
    }

    int search(int key) {
        int index = hashFunction(key);
        
        for (const auto &p : table[index]) {
            if (p.first == key) {
                return p.second;
            }
        }
        return -1; // Not found
    }
};

int main() {
    Hashtable hashTable;

 
    hashTable.insert(2, 20);
    hashTable.insert(3, 30);
    hashTable.insert(4, 40);

    int result1 = hashTable.search(2);
    int result2 = hashTable.search(3);
    int result3 = hashTable.search(4);

    cout << "Result 1: " << result1 << endl;
    cout << "Result 2: " << result2 << endl;
    cout << "Result 3: " << result3 << endl;

    return 0;
}