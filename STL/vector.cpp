#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> nums = {10, 20, 30};

    nums.push_back(40); // add element
    nums.pop_back();    // remove last element

    cout << "Vector elements: ";
    for(int x : nums)
        cout << x << " ";

    cout << "\nSize: " << nums.size();
    return 0;
}
