/**
 * 枚举：找出小于n的范围内有多少勾股数（a、b、c）
 */
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int cnt = 0;
    for (int a = 1; a < n; a++)
    {
        for (int b = a; b < n; b++)
        {
            int c2 = a * a + b * b;
            if (c2 > n*n)
            {
                break;
            }
            else
            {
                int c = sqrt(c2);
                if (c * c == c2 and c >= b)
                {
                    cnt++;
                }
                else
                {
                    continue;
                }
            }
        }
    }
    cout << cnt << endl;
    return 0;
}