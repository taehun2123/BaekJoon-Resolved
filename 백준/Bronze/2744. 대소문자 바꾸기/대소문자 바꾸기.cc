#include <bits/stdc++.h>
using namespace std;
int main()
{
    string input;
    cin >> input;
    for(int i = 0; i<input.size(); i++){
        if(input[i] >= 'A' && input[i] <= 'Z')
            input[i] = tolower(input[i]);
        else
            input[i] = toupper(input[i]);
    }
    cout << input;
}