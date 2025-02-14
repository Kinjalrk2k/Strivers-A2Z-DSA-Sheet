#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    stack<int> st;

    st.push(1);
    st.push(2);
    st.push(3);
    st.push(3);
    st.emplace(5);  // same as push

    cout << st.top();

    st.pop();

    cout << st.size();
    cout << st.empty();

    stack<int> st1, st2;
    st1.swap(st2);
    return 0;
}
