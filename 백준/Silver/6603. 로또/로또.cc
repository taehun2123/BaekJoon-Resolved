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
int T;
int arr[13];
int num[50];
bool isused[50];
void select(int a){
    if(a==6){
        for(int i = 0 ; i< 6; i++){
            cout << num[i] << " ";
        }
        cout << "\n";
        return;
    }
    for(int i = 0; i<T; i++){
        if(isused[i] || num[a-1] > arr[i]) continue;
        num[a] = arr[i];
        isused[i] = 1;
        select(a+1);
        isused[i] = 0;
    }

}

int main() {
    io;
    while(true){
        cin >> T;
        if(T == 0) return 0;
        for(int i = 0; i<T; i++){
            fill(arr, arr+T, 0);
        }
        for(int i = 0; i<T; i++){
            cin >> arr[i];
        }

        select(0);
        cout << "\n";
    }
}