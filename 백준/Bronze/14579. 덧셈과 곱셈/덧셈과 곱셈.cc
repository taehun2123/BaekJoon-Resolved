#include <bits/stdc++.h>
using namespace std;
int num(int c)
{
    int d = 0;
    int i;
    for (i = 1; i <= c; i++)
    {
        d = d + i;
    }
    return d;
};
int main()
{
    int a, b, i;
    int j=1;

    cin >> a >> b;


    for (i = a; i <= b; i++ )
    {
        j = j * num(i);

        j= j%14579;
    }
    if(a<b&&a>=1&&b<=1000)
        printf("%d\n", j%14579);
}