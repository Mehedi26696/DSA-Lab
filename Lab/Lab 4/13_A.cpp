
// https://www.hackerrank.com/challenges/30-queues-stacks/problem
#include <iostream>

using namespace std;

class Solution {
    //Write your code here

    public:
    char stack[100], queue[100];
    int top = -1, front = 0, rear = 0;

    void pushCharacter(char ch) {
        stack[++top] = ch;
    }

    void enqueueCharacter(char ch) {
        queue[rear++] = ch;
    }

    char popCharacter() {
        return stack[top--];
    }

    char dequeueCharacter() {
        return queue[front++];
    }

    

};

int main() {
    // read the string s.
    string s;
    getline(cin, s);
    
  	// create the Solution class object p.
    Solution obj;
    
    // push/enqueue all the characters of string s to stack.
    for (int i = 0; i < s.length(); i++) {
        obj.pushCharacter(s[i]);
        obj.enqueueCharacter(s[i]);
    }
    
    bool isPalindrome = true;
    
    // pop the top character from stack.
    // dequeue the first character from queue.
    // compare both the characters.
    for (int i = 0; i < s.length() / 2; i++) {
        if (obj.popCharacter() != obj.dequeueCharacter()) {
            isPalindrome = false;
            
            break;
        }
    }
    
    // finally print whether string s is palindrome or not.
    if (isPalindrome) {
        cout << "The word, " << s << ", is a palindrome.";
    } else {
        cout << "The word, " << s << ", is not a palindrome.";
    }
    
    return 0;
}