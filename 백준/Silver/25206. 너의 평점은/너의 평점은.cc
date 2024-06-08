#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string subject, score;
    double sbScore, realScore, sumScore = 0, allScoreSum = 0, avg = 0;

    for (int i = 0; i < 20; i++) {
        cin >> subject >> sbScore >> score;
        realScore = 0.0;

        switch (score[0]) {
            case 'A': realScore = 4.0; break;
            case 'B': realScore = 3.0; break;
            case 'C': realScore = 2.0; break;
            case 'D': realScore = 1.0; break;
            case 'F': realScore = 0.0; break;
            default: break;
        }

        if (score[0] == 'P') {
            continue;
        }

        if (score.length() > 1 && score[1] == '+') {
            realScore += 0.5;
        }

        sumScore += sbScore;
        allScoreSum += realScore * sbScore;
    }

    if (sumScore == 0) {
        cout << fixed << setprecision(6) << 0.000000;
    } else {
        avg = allScoreSum / sumScore;
        cout << fixed << setprecision(6) << avg;
    }

    return 0;
}
