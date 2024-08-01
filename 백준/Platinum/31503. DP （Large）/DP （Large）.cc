#include <bits/stdc++.h>

using namespace std;

// LIS를 계산하여 각 원소에서 끝나는 LIS의 길이를 구하는 함수
vector<int> calculateLIS(const vector<int>& nums) {
    int n = nums.size();
    vector<int> lis(n, 1);  // 모든 위치에서 LIS 길이를 저장할 벡터
    vector<int> seq;        // LIS를 유지하는 벡터

    for (int i = 0; i < n; ++i) {
        // seq에서 nums[i]보다 크거나 같은 첫 번째 요소 위치를 찾음
        auto it = lower_bound(seq.begin(), seq.end(), nums[i]);
        int length = distance(seq.begin(), it) + 1; // 현재 요소의 LIS 길이 계산
        lis[i] = length; // LIS 길이를 lis에 저장

        if (it == seq.end()) {
            seq.push_back(nums[i]); // 새로운 LIS 요소 추가
        } else {
            *it = nums[i]; // 기존 위치 갱신
        }
    }

    return lis;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;
    vector<int> arr(N);
    vector<int> queries(Q);

    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }

    for (int i = 0; i < Q; ++i) {
        cin >> queries[i];
    }

    vector<int> incLIS = calculateLIS(arr); // 증가하는 LIS 계산

    // 배열의 모든 요소를 -1로 변환하고 역순으로 정렬
    for (int &x : arr) x = -x;
    reverse(arr.begin(), arr.end());
    vector<int> decLIS = calculateLIS(arr); // 감소하는 LIS 계산

    // decLIS를 원래 순서로 복원
    reverse(decLIS.begin(), decLIS.end());

    vector<int> results(N);
    for (int i = 0; i < N; ++i) {
        results[i] = incLIS[i] + decLIS[i] - 1; // 바이토닉 수열 길이 계산
    }

    // 쿼리 처리 및 결과 출력
    for (int i = 0; i < Q; ++i) {
        int queryIndex = queries[i] - 1; // 1-based index to 0-based index
        cout << results[queryIndex] << "\n"; // 결과 출력
    }

    return 0;
}
