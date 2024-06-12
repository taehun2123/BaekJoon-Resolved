#include <bits/stdc++.h>
using namespace std;

int arr[1001][1001];
bool visited[1001];
int N, M, V;

/* DFS */
void DFS(int V) {
    stack<int> st;
    st.push(V);

    while (!st.empty()) {
        int next = st.top();
        st.pop();

        if (!visited[next]) {
            visited[next] = true;
            cout << next << " ";  // 방문한 노드 출력

            for (int i = N; i >= 1; i--) {
                if (arr[next][i] == 1 && !visited[i]) {
                    st.push(i); // 스택에 i
                }
            }
        }
    }
}

/* BFS */
void BFS(int V){
    queue<int> q; //큐 생성
    q.push(V);    //시작노드 큐에 넣음

    while (!q.empty()){
        int next = q.front();
        q.pop();
        if (!visited[next]) {
            visited[next] = true;
            cout << next << " ";  // 방문한 노드 출력

            for (int i = 1; i <= N; i++) {
                if (arr[next][i] == 1 && !visited[i]) {
                    q.push(i); // 스택에 i
                }
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int u, v;
    cin >> N >> M >> V; //N - 정점의 개수, M - 간선의 개수, V - 방문하는 점.

    for (int i = 0; i < M; i++){
        cin >> u >> v;
        arr[u][v] = 1;
        arr[v][u] = 1; //자리바꿔서도 해주는 이유 : 무방향이기 때문
    }                  //입력 즉시 인접행렬에 넣어줌, 다 돌면 인접행렬 완성

    DFS(V); // DFS 수행

    cout << "\n";
    fill(visited, visited + 1001, false); //방문기록 visited 초기화

    BFS(V); // BFS 수행
}