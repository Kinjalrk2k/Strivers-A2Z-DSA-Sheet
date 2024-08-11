#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    priority_queue<int> pq;

    pq.push(5);
    pq.push(2);
    pq.push(8);
    pq.emplace(10);

    cout << pq.top();  // top

    // min heap or storing min element at the top
    priority_queue<int, vector<int>, greater<int>> pq;

    pq.push(5);
    pq.push(2);
    pq.push(8);
    pq.emplace(10);

    cout << pq.top();  // 2

    return 0;
}
