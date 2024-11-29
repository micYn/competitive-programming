#include <bits/stdc++.h>
using namespace std;

int main() {
    // Creating a priority queue of integers where the top element is always the smallest element 
    // arguments to be passed are the datatype of elements to be stored in the priority queue, the Data structure to store the elements, and the comparator function which is used to determine the priority of the elements
    priority_queue<int, vector<int>, greater<int>> min_pq;

    // Inserting elements into the priority queue
    min_pq.push(30);
    min_pq.push(10);
    min_pq.push(50);
    min_pq.push(20);

    // Printing the elements of the priority queue
    cout << "Min Priority Queue: ";
    while (!min_pq.empty()) {
        cout << min_pq.top() << " "; // Accessing the top element
        min_pq.pop(); // Removing the top element
    }
    cout << endl;
    
    // Creating a priority queue of integers where the top element is always the largest element 
    priority_queue<int> max_pq;

    // Inserting elements into the priority queue
    max_pq.push(30);
    max_pq.push(10);
    max_pq.push(50);
    max_pq.push(20);

    // Printing the elements of the priority queue
    cout << "Max Priority Queue: ";
    while (!max_pq.empty()) {
        cout << max_pq.top() << " "; // Accessing the top element
        max_pq.pop(); // Removing the top element
    }
    cout << endl;

    return 0;
}