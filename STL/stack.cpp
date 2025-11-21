#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> st;

    st.push(10);
    st.push(20);
    st.push(30);

    cout << "Top element: " << st.top() << "\n";

    cout << "Stack elements (popping): ";
    while(!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }

    return 0;
}
