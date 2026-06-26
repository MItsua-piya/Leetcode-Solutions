class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>s;
        for(string ch:tokens){
           if (ch != "+" && ch != "-" && ch != "*" && ch != "/"){
              s.push(stoi(ch));
               
            }
            else{
             
               int op2=s.top();
             s.pop();
                int op1=s.top();
                s.pop();
               
                if (ch == "+") s.push(op1 + op2);
                else if (ch == "-") s.push(op1 - op2);
                else if (ch == "*") s.push(op1 * op2);
                else s.push(op1 / op2);
            }
        }
        int result=s.top();
        return result;
    }
};