#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n, m, k = 1;
    string str = "1";
    cin >> n >> m;

    while (((k + m - 1) % n) != 1 ) {
        if (((k + m - 1) % n) == 0) {
            k = n;
            str = str + to_string(k);
        }
        else {
            k = (k + m - 1) % n;
            str = str + to_string(k);
        } 
    }

    cout << str;
    return 0;
}