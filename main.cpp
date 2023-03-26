#include <iostream>
#include <fstream>
#include <random>
#include <vector>
#include "DynamicArray.h"
#include "add.h"

using namespace std;



int main()
{

    random_device rd; // non-deterministic random number generator
    mt19937 gen(rd()); //  32-bit pseudo-random number engine seeded with rd()
    uniform_int_distribution<int32_t> dist(1, 1000000); // distribute results between 1 and 1000000 inclusive


    int x = 1;
    int v = 2;
    cout << add(x, v);
    // DynamicArray z;
    // z.insertHead(3);
    // z.displayArray();
    // z.insertHead(2);
    // z.displayArray();
    // z.insertHead(1);
    // z.displayArray();
    // z.removeHead();
    // z.displayArray();
    // cout << *z.tail << "\n";
    // cout << z.tail << "\n";
    // z.insertTail(5);
    // z.displayArray();
    // z.remove(3);
    // z.displayArray();
    // cout << z.tail << "\n";
    // cout << *z.tail << "\n";
    // z.removeTail();
    // cout << z.tail << "\n";
    // cout << *z.tail << "\n";
    // z.insertTail(7);
    // cout << z.tail << "\n";
    // cout << *z.tail << "\n";
    // z.insertTail(9);
    // z.remove(4);
    // z.displayArray();


} 