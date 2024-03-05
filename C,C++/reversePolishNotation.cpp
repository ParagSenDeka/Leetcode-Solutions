#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int eval(vector<string> a) {
    stack<int> st;

    for (int i = 0; i < a.size(); i++) {
        if (a[i] != "+" && a[i] != "-" && a[i] != "*" && a[i] != "/") {
            st.push(stoi(a[i]));
        } else {
            int operand_b = st.top();
            st.pop();
            int operand_a = st.top();
            st.pop();

            char op = a[i][0];  // Convert the string to a character
    
            switch (op) {
                case '+':
                    st.push(operand_a + operand_b);
                    break;
                case '-':
                    st.push(operand_a - operand_b);
                    break;
                case '*':
                    st.push(operand_a * operand_b);
                    break;
                case '/':
                    st.push(operand_a / operand_b);
                    break;
                default:
                    break;
            }
        }
    }

    return st.top();
}

int main() {
    vector<string> expression = {"2", "3", "+", "5", "*"};
    cout << "Result: " << eval(expression) << endl;
    return 0;
}
