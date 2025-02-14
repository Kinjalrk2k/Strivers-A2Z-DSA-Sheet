#include <bits/stdc++.h>

using namespace std;

bool comp(pair<int, int> p1, pair<int, int> p2) {
    // comparators are boolean functions
    if (p1.second < p2.second) {
        // which means they are in the expected order
        return true;
    }

    if (p1.second > p2.first) {
        return false;
    }

    // second is now same
    if (p1.first > p2.first) {
        return true;
    }

    return false;
}

int main(int argc, char const *argv[]) {
    int a[] = {1, 5, 2, 3};
    vector<int> av = {1, 5, 2, 3};

    // sorting
    sort(a, a + 4);              // [start, end)
    sort(av.begin(), av.end());  // for vector
    sort(a + 2, a + 4);          // sort part of the array

    // in descending order
    sort(a, a + 4, greater<int>());  // greater<int>() is a comparator

    pair<int, int> ap[] = {{1, 2}, {2, 1}, {4, 1}};

    /*
     * sort according to 2nd element ascending
     * if second element is same, sort according to the 1st element descending
     */

    // here we need a custom comparator
    sort(ap, ap + 4, comp);

    // count setbits of a number
    int num = 7;
    int set_bits = __builtin_popcount(num);

    long long num = 16494821401221;
    int set_bits = __builtin_popcountll(num);

    // get dictionary permutations
    string s = "123";
    do {
        // print the original one, then keep moving to next permutations
        cout << s << endl;
    } while (next_permutation(s.begin(), s.end()));
    // NOTE: if you want to print all permutations, start with the sorted list

    int *maxi = max_element(a, a + 4);  // gives the address

    return 0;
}
