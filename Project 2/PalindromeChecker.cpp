#include <bits/stdc++.h>
using namespace std;

string rev(string S) {
    string P = S;
    reverse(P.begin(), P.end());
    return P;
}

bool isPalindrome(string S) {
    string P = rev(S);
    if (S==P) {
        return 1;
    }
    
    else {
        return 0;
    }
}

int main () {
    string S = "MADAM";
    if(isPalindrome(S))
    cout << "String is palindrome." << endl;
    else
    cout << "String is not palindrome." << endl;
    return 0;
}