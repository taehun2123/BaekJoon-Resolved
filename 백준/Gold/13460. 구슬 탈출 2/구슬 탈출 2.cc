#include<bits/stdc++.h>
using namespace std;

struct step
{
    int Rx, Ry; // 빨간공
    int Bx, By; // 파란공
    int Count;  // 움직인 수
};

char board[11][11];
bool vis[11][11][11][11];
int N, M;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

void move(int& rx, int& ry, int& distance, int& i)
{
    while (board[rx + dx[i]][ry + dy[i]] != '#' && board[rx][ry] != 'O')
    {
        rx += dx[i];   // x 좌표 이동
        ry += dy[i];   // y 좌표 이동
        distance += 1; // 공이 움직인 거리
    }
}

void BFS(int Rx, int Ry, int Bx, int By)
{
    queue<step> q;
    q.push({ Rx,Ry,Bx,By,0 });
    vis[Rx][Ry][Rx][Ry] = true;
    while (!q.empty())
    {
        int rx = q.front().Rx;
        int ry = q.front().Ry;
        int bx = q.front().Bx;
        int by = q.front().By;
        int count = q.front().Count;
        q.pop();

        if (count >= 10) break; //해당 큐의 굴린 횟수가 10을 넘으면 0 출력하도록

        for (int dir = 0; dir < 4; dir++)
        {
            int nrx = rx, nry = ry, nbx = bx, nby = by;
            int rc = 0, bc = 0, ncount = count + 1;

            //둘다 벽에 부딪힐때까지 move
            move(nrx, nry, rc, dir);
            move(nbx, nby, bc, dir);

            if (board[nbx][nby] == 'O') continue; //파란색이 골지점에 도달하면 다른 방향으로 다시
            if (board[nrx][nry] == 'O') // 빨간색이 골지점에 도달하면 1
            {
                cout << ncount;
                return;
            }

            if (nrx == nbx && nry == nby) //만약 두 지점이 겹치면
            {
                if (rc > bc) nrx -= dx[dir], nry -= dy[dir]; //빨간구슬의 움직인 거리가 파란구슬의 거리보다 더 크면 빨간구슬의 좌표를 이전 지점으로 이전
                else nbx -= dx[dir], nby -= dy[dir]; //위와 반대되는 내용
            }

            if (vis[nrx][nry][nbx][nby]) continue; // 이미 방문한 지점이라면 다시.
            vis[nrx][nry][nbx][nby] = true;
            q.push({ nrx,nry,nbx,nby,ncount });
        }
    }
    cout << -1;
}

void Answer()
{
    cin >> N >> M;
    int Rx = 0, Ry = 0, Bx = 0, By = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> board[i][j];
            if (board[i][j] == 'R')
            {
                Rx = i; Ry = j;
            }
            else if (board[i][j] == 'B')
            {
                Bx = i; By = j;
            }
        }
    }
    BFS(Rx, Ry, Bx, By);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    Answer();
    return 0;
}