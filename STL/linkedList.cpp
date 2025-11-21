#include <iostream>
#include <list>
using namespace std;

int main() {
    list<int> li = {10, 20, 30};

    li.push_front(5);   // insert at front
    li.push_back(40);   // insert at back
    li.pop_front();     // remove from front

    cout << "List elements: ";
    for(int x : li)
        cout << x << " ";

    return 0;
}
