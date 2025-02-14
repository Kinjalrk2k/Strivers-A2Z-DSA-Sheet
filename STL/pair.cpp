#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    // provide the datatype (in respective order) and then list initialization
    pair<int, int> p = {1, 3};

    // accessing elements in a pair
    cout << p.first << " " << p.second << '\n';

    // pairs can be nested too
    pair<int, pair<int, int>> p2 = {1, {3, 4}};
    cout << p2.first << " " << p2.second.first << " " << p2.second.second
         << '\n';

    // pair can be in arrays too
    pair<int, int> arr[] = {{1, 2}, {3, 4}, {5, 6}};
    cout << arr[2].second << '\n';
    return 0;
}
