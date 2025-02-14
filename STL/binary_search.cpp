#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    int a[] = {1, 4, 5, 8, 9};
    int n = 5;

    bool res = binary_search(a, a + n, 3);
    bool res = binary_search(a, a + n, 4);

    int a[] = {1, 4, 5, 6, 9, 9};

    // - a returns index
    int ind = lower_bound(a, a + n, 4) -
              a;  // lower_bound returns iterator to first occurance of 4
    int ind = lower_bound(a, a + n, 7) -
              a;  // 7 not present, then points to the next greater element 9
    int ind = lower_bound(a, a + n, 10) -
              a;  // immediate greater than 10, out of list
    // for vectors, use .begin() and .end()

    int ind = upper_bound(a, a + n, 4) -
              a;  // upper_bound returns iterator to next greater than 4
    int ind = upper_bound(a, a + n, 7) - a;   // 9
    int ind = upper_bound(a, a + n, 10) - a;  // out of list

    return 0;
}
