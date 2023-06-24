#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    // // 方法1——在范围给定的情况下，利用数组下标进行标记（通过洛谷用例，平均耗时3.4ms，空间复杂度700KB左右）
    // int n,m;
    // cin>>n>>m;
    // // 每位同学有从0到N-1的唯一编号
    // int number[1000] = {0};
    // for(int i = 0; i<m;i++)
    // {
    //     int temp = 0;
    //     cin>>temp;
    //     number[temp] = 1;
    // }
    // bool is_lose = false;//判断是否有人缺席
    // for(int i = 0; i<n;i++)
    // {
    //     if(number[i]!= 1)
    //     {
    //         cout<< i <<" ";
    //         is_lose = true;
    //     }
    // }
    // // 如果没有人缺席则输出N
    // if(!is_lose)
    // {
    //     cout<<n;
    // }

    // 方法2：先排序，在检索（利用sort）
    int n, m;
    cin >> n >> m;
    int arr[m];
    bool is_lose = false; // 是否有缺漏
    for (int i = 0; i < m; i++)
    {
        cin >> arr[m];
    }
    sort(arr, arr + m);
    for (int i = 1; i < m; i++)
    {
        if(arr[i] == arr[i-1] or arr[i] - arr[i-1] == 1)
        {
            // 两人之间不存在缺漏或某人多报了
        }
        else{
            for(int i = arr[i-1]+1; i<arr[i];i++)
            {
                cout<<i<<" ";
                is_lose = true;
            }
        }
    }
    // 这部分不要漏了
    if(n-1>=arr[m-1])
    {
        for(int i = arr[i-1]+1; i<n;i++)
        {
            cout<<i<<" ";
        }
    }
    else if(!is_lose)
    {
        cout<<n;
    }
    
    return 0;
}