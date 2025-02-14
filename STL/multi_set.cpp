#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    multiset<int> ms;

    ms.insert(1);
    ms.insert(1);
    ms.insert(1);  // allows dupes

    ms.erase(1);  // erases all 1s

    ms.count(1);  // will count the no. of 1s

    ms.erase(ms.find(1));  // taking address, erases only one element (first)

    return 0;
}
