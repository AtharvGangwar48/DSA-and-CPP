#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    vector<int> arr = {5, 2, 9, 1, 6};

    sort(arr.begin(), arr.end());  // ascending sort

    cout << "Sorted array: ";
    for (int x : arr)
        cout << x << " ";

    return 0;
}
