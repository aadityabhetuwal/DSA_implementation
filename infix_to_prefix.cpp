#include <iostream>
#include <vector>
#include <stack>
#include <cmath>

#define ll long long
#define ull unsigned long long long

using namespace std;

int priority(char ch){
    if(ch == '^')  
        return 3;
    else if(ch == '/' || ch == '*')
        return 2;
    else if(ch == '+' || ch == '-')
        return 1;
    else
        return 0;
}

bool is_var(char ch){
    return ((ch >= '0' && ch <= '9') || (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'));
}

void reverse_string(string& st){
    int n = st.size();

    for(int i = n - 1; i >= n / 2; i--){

        if(st[i] == '('){
            st[i] = ')';
        }else if(st[i] == ')'){
            st[i] ='(';
        }

        if(st[n - i - 1] == '('){
            st[n - i - 1] = ')';
        }else if(st[n - i - 1] == ')'){
            st[n - i - 1] = '(';
        }

        swap(st[i], st[n - i - 1]);
    }
}

string convertToPostfix(string infix){
    int tmp;
    char ch;

    infix.push_back(')');

    stack<char> st;
    st.push('(');

    string res = "";
    int count = 0;

    for(const auto &i : infix){
        tmp = priority(i);
                
        if(i == '('){
            st.push(i);

        }else if(is_var(i)){
            res.push_back(i);
            res.push_back(' ');

        } else if (i == ')'){

            while(st.top() != '('){
                res.push_back(st.top());
                res.push_back(' ');
                st.pop();
            }
            st.pop();

        }else {
            while(!st.empty() && '(' && tmp <= priority(st.top()) ){
                res.push_back(st.top());
                res.push_back(' ');
                st.pop();
            }
            st.push(i);
        }

    }

    return res;
}

string convertToPrefix(string st){
    reverse_string(st);

    string res = convertToPostfix(st);

    reverse_string(res);
    return res;
}

int main(){

    // vector<string> ve = {"a*b/c+d^e*f+g"};

    vector<string> ve = {"a+b*(c^d-e)^(f+g*h)-i", "a+b*c", "(a+b)*c+(d-a)", "((4+8)(6-5))/((3-2)(2+2))"};

    for(auto i : ve){
        cout << "\nThe infix expression is : " << i << '\n';
        cout << "The postfix expression is : \n" << convertToPrefix(i) << '\n';
    }


    return 0;
}
