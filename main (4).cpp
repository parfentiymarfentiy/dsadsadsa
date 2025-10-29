#include <iostream>
using namespace std;

int main() {
    char s[1000];
    char stack[1000];
    int top = -1;
    
    cout << "Enter string: ";
    cin.getline(s, 1000, ';');
    
    for(int i = 0; s[i] != '\0'; i++) {
        char c = s[i];
        
        if(c == '(' || c == '[' || c == '{') {
            top++;
            stack[top] = c;
        }
        else if(c == ')' || c == ']' || c == '}') {
            if(top == -1) {
                cout << "Error at position " << i << endl;
                return 0;
            }
            
            char last = stack[top];
            top--;
            
            if((last == '(' && c != ')') ||
               (last == '[' && c != ']') ||
               (last == '{' && c != '}')) {
                cout << "Error at position " << i << endl;
                return 0;
            }
        }
    }
    
    if(top != -1) {
        cout << "Error: not all brackets closed" << endl;
    } else {
        cout << "String is correct" << endl;
    }
    
    return 0;
}