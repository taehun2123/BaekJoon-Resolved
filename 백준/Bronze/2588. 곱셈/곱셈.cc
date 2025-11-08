#include <iostream>
using namespace std;
int a, b;
int main() {
    cin >> a >> b;
    int ans1 = a*(b%10);
    int ans2 = a*((b%100)/10);
    int ans3 = a*(b/100);
    int ans4 = a*b;
    cout << ans1 << "\n" << ans2 << "\n" << ans3 << "\n" << ans4;
    return 0;
}
