#include <iostream>
#include <map>
using namespace std;

int main() {
    map<string, int> marks;

    marks["Alice"] = 90;
    marks["Bob"] = 80;
    marks["Charlie"] = 95;

    cout << "Marks list:\n";
    for (auto p : marks) {
        cout << p.first << " = " << p.second << endl;
    }

    return 0;
}
