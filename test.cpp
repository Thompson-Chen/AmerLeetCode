#include <iostream>
using namespace std;

int main()
{
    int n = 0;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int ans = 0;
    for (auto &num : arr)
    {
        ans ^= num;
    }
    cout << ans << endl;
    return 0;
}

