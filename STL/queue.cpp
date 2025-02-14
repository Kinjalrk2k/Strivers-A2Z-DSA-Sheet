#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    queue<int> q;

    // push is actually enqueue
    q.push(1);
    q.push(2);
    q.emplace(3);

    q.back() += 5;  // add 5 to the last element

    // printing back and front of the queue
    cout << q.back();
    cout << q.front();

    q.pop();  // dequeue
    return 0;
}
