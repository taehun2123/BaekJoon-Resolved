#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    vector<pair<int, int>> arr(N); //N개 크기만큼 페어 배열을 저장하기 위한 벡터 생성

    for(int i=0; i<N; i++) {
        cin >> arr[i].first; //맨 처음 배열의 데이터 값을 받음
        arr[i].second = i; //index 값을 저장
    }

    sort(arr.begin(), arr.end()); //A.first을 기준으로 정렬

    int MAX = 0;
    for(int i = 0; i< N; i++) {
        if(MAX < arr[i].second - i) //기존 원래의 index - 현재 index = 정렬 전 index - 정렬 후 index
            MAX = arr[i].second - i; //가장 많이 이동한 값을 저장
    }
    cout << MAX + 1;
}