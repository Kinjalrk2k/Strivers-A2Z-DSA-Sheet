#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    set<int> st;

    st.insert(1);
    st.insert(2);
    st.emplace(2);
    st.insert(4);
    st.insert(3);

    // finding
    auto it = st.find(3);  // returns an iterator (address)

    auto it = st.find(6);  // if not found, then returns st.end() (pointer to
                           // right after the end)

    st.erase(5);            // takes logarithemic time
    int cnt = st.count(1);  // always 1 if it exists, else 0

    auto it1 = st.find(2);
    auto it2 = st.find(4);
    st.erase(it1, it2);  // erase in range [first, last)

    // TODO: lower_bound() and upper_bound()

    return 0;
}
