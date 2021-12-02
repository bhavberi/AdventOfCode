#include <iostream>
#include <string>

using namespace std;

int main()
{
    long long hori = 0;
    long long dep = 0;
    long long aim = 0;
    for (int i = 0; i < 1000;i++) {
        string s;
        cin >> s;
        long long n;
        cin >> n;
        if (s == "forward") {
            hori += n;
            dep += (aim * n);
        }
        else if (s == "down")
            aim += n;
        else if (s == "up")
            aim -= n;
    }
    cout << hori * dep;
}
