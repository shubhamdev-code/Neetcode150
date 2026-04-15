class Solution {
public:
    int evaluateExpr(const string& op, int num1, int num2) {
        if (op == "+") return num1 + num2;
        if (op == "-") return num1 - num2;
        if (op == "*") return num1 * num2;
        return num1 / num2;  
    }

    int evalRPN(vector<string>& tokens) {
        stack<int> stk;

        for (const string& token : tokens) {
            if (token != "+" && token != "-" && token != "*" && token != "/") {
                stk.push(stoi(token));
            } else {
                int num2 = stk.top(); stk.pop();
                int num1 = stk.top(); stk.pop();
                int result = evaluateExpr(token, num1, num2);
                stk.push(result);
            }
        }

        return stk.top();
    }
};