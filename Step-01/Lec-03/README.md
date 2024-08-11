# STL (Standard Template Library) in C++

Learning STL from Striver's [TakeUForward](https://www.youtube.com/@takeUforward) video

- [Complete C++ STL in 1 Video | Time Complexity and Notes](https://www.youtube.com/watch?v=RRVYpIET_RU)

## C++ STL

C++ STL is divied into 4 parts

- Algorithms
- Containers
- Functions
- Iterators

## Pair

```cpp
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

```

## Vectors

- Arrays once declared to have a specific size, cannot be later modified (static memory allocation of arrays)
- Vector is a container which is dynamic in nature. You can always increase the size of the vector

#### Functions

- `push_back`: Appends data at the back of the list
- `emplace_back`: Similar to `push_back` but is faster. Why?
- Vectors can be accessed like arrays using indices or use the `.at(i)` method

#### Iterators

- `.begin()`: Points to the beginning
- `.end()`: End doesn't point to the last element. It points to somewhere right after the last element (Think of this about the `NULL` at the end of the linked list)
- `.rend()`: Reverses the vector and then points to the end (same as `.end()`)
- `.rbegin()`: Reverses the vector and points to the front

> Note:
> `rend()` and `rbegin()` doesn't reverse the vector in any sense. It just points and works like it's going in the reverse direction.
>
> ```cpp
> vector<int>::iterator it = v.rbegin();
> it++; // moves on the reverse direction
> ```

- `.back()`: The actual last element

#### Printing a vector

```cpp
// printing a vector
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
```

#### Erasing

```cpp
// erase single element
v.erase(v.begin() + 1);  // takes an address

// erase a range of elements
v.erase(v.begin()+2, v.begin()+4); // [start, end) (end is not inclusive)
```

#### Insertion

```cpp
// insertion
vector<int> v(2, 100);
v.insert(v.begin(), 300);  // insertion on the begin (takes address)

v.insert(v.begin() + 1, 2, 10);  // (address, # of elements, element)

vector<int> copy(2, 50);  // 50, 50
v.insert(v.begin(), copy.begin(), copy.end()); // insert the vector copy in another vector (provide the range)
```

#### Miscellaneous functions

```cpp
cout << v.size();

v.pop_back();  // pop back the last element

vector<int> v1;
v1.swap(v);

v.clear();  // trims down to empty vector

cout << v.empty();  // checks if empty
```

## Lists

- Similar functions to that of vectors
- internally its a doubly linked list
- [vector vs. list in STL | Stackoverflow](https://stackoverflow.com/a/2209564/10537134)

## Deque

- Exactly similar to list and vector
- [STL Containers - difference between vector, list and deque | Stackoverflow](https://stackoverflow.com/a/9650272/10537134)

## Stack

- LIFO - Last In Fast Out
- Indexing access is not allowed
- All operations are O(1)

```cpp
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
```

## Queue

- FIFO - First In First Out

```cpp
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
```

## Priority Queue

- Priority queue
- The largest element stays at the top
- Internally a tree data structure is used, not stored in a linear fashion
- Minimum priority queue is known as Min Heap
- Maximum Priority queue is known as Max Heap
- Time Complexities:
  - Push: O(log(n))
  - Top: O(1)
  - Pop: O(log(n))

```cpp
priority_queue<int> pq;

pq.push(5);
pq.push(2);
pq.push(8);
pq.emplace(10);

cout << pq.top();  // 10

// min heap or storing min element at the top
priority_queue<int, vector<int>, greater<int>> pq;

pq.push(5);
pq.push(2);
pq.push(8);
pq.emplace(10);

cout << pq.top();  // 2
```

## Set

- Stores unique
- Stores in sorted order
- Everything works in O(log(n))

```cpp
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
```

## Binary Search (Needs re-learning)

[Binary Search with C++ STL | 4 Problems followed up | Lower Bound and Upper Bound explained](https://www.youtube.com/watch?v=edJ19qIL8WQ)

#### Check if X exists in the sorted array or not

```cpp
int a[] = {1, 4, 5, 8, 9};
int n = 5;

bool res = binary_search(a, a + n, 3);
bool res = binary_search(a, a + n, 4);
```

#### Lower bound

```cpp
int a[] = {1, 4, 5, 6, 9, 9};

// - a returns index
int ind = lower_bound(a, a + n, 4) - a; // lower_bound returns iterator to first occurance of 4
int ind = lower_bound(a, a + n, 7) - a; // 7 not present, then points to the next grater element 9
int ind = lower_bound(a, a + n, 10) - a; // immediate greater than 10, out of list
// for vectors, use .begin() and .end()
```

#### Upper bound

```cpp
int ind = upper_bound(a, a + n, 4) - a;  // upper_bound returns iterator to next greater than 4
int ind = upper_bound(a, a + n, 7) - a;   // 9
int ind = upper_bound(a, a + n, 10) - a;  // out of list
```

## MultiSet

- Similar to set, it'll save sorted and will allow duplicates
- If we erase an element, all the occurances gets erased

```cpp
multiset<int> ms;

ms.insert(1);
ms.insert(1);
ms.insert(1);  // allows dupes

ms.erase(1);  // erases all 1s

ms.count(1);  // will count the no. of 1s

ms.erase(ms.find(1));  // taking address, erases only one element (first
```

## Unordered Set

- Everything is similar to set, but the order is randomized
- Average case of the methods is O(1)
- For worst case, it's O(n)

## Maps

- Stores unique keys in sorted order

```cpp
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
```

## Multimap

- Same as map, duplicate keys can be present, still in sorted order

## Unordered Map

- Same as map, but not in sorted order, unique keys

## Algorithms

#### Sorting

```cpp
int a[] = {1, 5, 2, 3};
vector<int> av = {1, 5, 2, 3};

// sorting
sort(a, a + 4);              // [start, end)
sort(av.begin(), av.end());  // for vector
sort(a + 2, a + 4);          // sort part of the array
```

#### Sorting with comparator

- Predefined comparator

```cpp
// in descending order
sort(a, a + 4, greater<int>());  // greater<int>() is a comparator
```

- Custom comparator

```cpp
pair<int, int> ap[] = {{1, 2}, {2, 1}, {4, 1}};

/*
* sort according to 2nd element ascending
* if second element is same, sort according to the 1st element descending
*/

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

// here we need a custom comparator
sort(ap, ap + 4, comp);
```

#### Count Set bits

```cpp
// count setbits of a number
int num = 7;
int set_bits = __builtin_popcount(num);

long long num = 16494821401221;
int set_bits = __builtin_popcountll(num);
```

#### Disctionary Permutation

```cpp
// get dictionary permutations
string s = "123";
do {
    // print the original one, then keep moving to next permutations
    cout << s << endl;
} while (next_permutation(s.begin(), s.end()));
```

- NOTE: if you want to print all permutations, start with the sorted list

#### Max/Min Element

```cpp
int *maxi = max_element(a, a + 4);  // gives the address
```
