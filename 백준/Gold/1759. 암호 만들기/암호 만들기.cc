#include <bits/stdc++.h>
#define ll long long
#define X first
#define Y second
#define pb push_back
#define pii pair<int, int>
#define mi map<int, int>
#define qi queue<int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define elif else if
#define io ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
using namespace std;
int n, key;
char num[20];
char arr[20];
bool isused[20];

bool checkComp(char t){
    return t == 'a' || t == 'e' || t == 'i' || t == 'o' || t == 'u';
}

void select(int k){
    if(k == key){
        bool flag = false;
        int cnt1 = 0;
        int cnt2 = 0;
        for(int i = 0; i < key; i++){
            if(checkComp(num[i])) cnt1++;
            else cnt2++;
        }
        if(cnt1 >= 1 && cnt2 >= 2) flag = true;

        if(flag){
            for(int i = 0; i < key; i++)
                cout <<  num[i];
            cout << "\n";
        }
    }

    for(int i = 0; i<n; i++){
        if(isused[i] || num[k-1] > arr[i]) continue;
        num[k] = arr[i];
        isused[i] = 1;
        select(k+1);
        isused[i] = 0;
    }
}

int main() {
    io;
    cin >> key >> n;
    for(int i = 0; i<n; i++){
        cin >> arr[i];
    }
    sort(arr, arr+n);

    select(0);
}