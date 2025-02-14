#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    // declear a vector with a datatype
    vector<int> v;

    v.push_back(1);     // appends to the end
    v.emplace_back(2);  // similar to push_back
    // NOTE: emplace_back is faster than push_back

    // vector can be of a pair too
    vector<pair<int, int>> v2;

    v2.push_back({1, 2});
    v2.emplace_back(1, 2);  // it automatically assumes a pair without the {}

    vector<int> v3(5, 100);  // 5 is the size and 100 is the value
    // the above line means a vector of size 5 each
    // element is 100 = {100, 100, 100, 100, 100}

    vector<int> v3(5);  // vector of size 5 all default value 0
    // NOTE: the size can later be increased, its dynamic

    vector<int> v4(5, 20);
    vector<int> v5(v4);  // v5 becomes a copy of v4

    // v.begin() points to the memory, not the element
    vector<int>::iterator it = v.begin();

    cout << *(it);  // accessing the value from the memory using *
    it++;           // points to the next memory location
    cout << *(it);
    it += 2;
    cout << *(it);

    // priniting a vector
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
        cout << *(it) << " ";
    }

    // easier way, using auto variable. auto can automatically infer the type
    // without specifying
    for (auto it = v.begin(); it != v.end(); it++) {
        cout << *(it) << " ";
    }

    // for-each loop
    // i here is NOT an iterator, it's the value (of int type)
    for (auto i : v) {
        cout << i << " ";
    }

    // erase single element
    v.erase(v.begin() + 1);  // takes an address

    // erase a range of elements
    v.erase(v.begin() + 2,
            v.begin() + 4);  // [start, end) (end is not inclusive)

    // insertion
    vector<int> v(2, 100);
    v.insert(v.begin(), 300);  // insertion on the begin (takes address)

    v.insert(v.begin() + 1, 2, 10);  // (address, # of elements, element)

    vector<int> copy(2, 50);  // 50, 50
    v.insert(v.begin(), copy.begin(),
             copy.end());  // insert the vector copy in another vector (provide
                           // the range)

    // miscellaneous functions
    cout << v.size();

    v.pop_back();  // pop back the last element

    vector<int> v1;
    v1.swap(v);

    v.clear();  // trims down to empty vector

    cout << v.empty();  // checks if empty

    return 0;
}
