#include <iostream>
#include <iomanip>
using namespace std;
double a, b;
int main() {
    cin >> a >> b;
    double div = a / b;
    cout << fixed << setprecision(9) << div;
    return 0;
}
