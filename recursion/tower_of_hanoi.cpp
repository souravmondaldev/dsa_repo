#include <bits/stdc++.h>
using namespace std;

// f(n, a, b, c) moving n rods from a to c using b
// f(n, from, using, to)
void towerOfHanoi(int n, char from, char usingd, char to)
{
    if (n == 1)
    {
        cout << "Move " << from << " to " << to << endl;
        return;
    }
    towerOfHanoi(n - 1, from, to, usingd);
    cout << "Move " << from << " to " << to << endl;
    towerOfHanoi(n - 1, usingd, from, to);
    // }
}
int main()
{
    int n;
    cin >> n;
    towerOfHanoi(n, 'A', 'B', 'C');
}