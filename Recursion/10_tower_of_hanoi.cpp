// Tower of Hanoi - Classic Recursion Problem
// Use Case: Algorithm teaching, backup rotation strategies

#include <iostream>
using namespace std;

void tower_of_hanoi(int n, char source, char destination, char auxiliary) {
    if (n == 1) {
        cout << "Move disk 1 from " << source << " to " << destination << endl;
        return;
    }
    
    tower_of_hanoi(n - 1, source, auxiliary, destination);
    cout << "Move disk " << n << " from " << source << " to " << destination << endl;
    tower_of_hanoi(n - 1, auxiliary, destination, source);
}

int main() {
    cout << "Tower of Hanoi with 3 disks:" << endl;
    tower_of_hanoi(3, 'A', 'C', 'B');
    return 0;
}
