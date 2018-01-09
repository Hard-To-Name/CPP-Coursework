#include<iostream>
using namespace std;

double convert(int knot)
{
    double mpm;
    mpm = knot*6076.0/5280/60;
    return mpm;
}

int main()
{
    int knot;
    cin >> knot;
    cout << convert(knot) << endl;
    return 0;
}
