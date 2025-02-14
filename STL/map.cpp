#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    map<int, int> mpp;
    // map<int, pair<int, int>> mpp;
    // map<pair<int, int>, int> mpp;

    mpp[1] = 2;  // in key 1, store 2
    mpp.insert({3, 1});
    mpp.insert({2, 4});

    // key and value is accessed using .first and .second
    for (auto it : mpp) {
        cout << it.first << ": " << it.second << endl;
    }

    cout << mpp[5];  // prints 0 or NULL

    // address of the key
    auto it = mpp.find(3);
    cout << (*it).second;  // the value

    // lower_bound and upper_bound is present too

    return 0;
}
