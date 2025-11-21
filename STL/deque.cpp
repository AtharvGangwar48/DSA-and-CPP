#include <iostream>
#include <deque>
using namespace std;

int main() {
    deque<int> dq = {2, 3, 4};

    dq.push_front(1); // add in front
    dq.push_back(5);  // add in back

    dq.pop_front();   // remove from front
    dq.pop_back();    // remove from back

    cout << "Deque elements: ";
    for(int x : dq)
        cout << x << " ";

    return 0;
}
