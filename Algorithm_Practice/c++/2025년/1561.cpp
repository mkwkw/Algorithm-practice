#include <iostream>
#include <vector>

using namespace std;

long long calcNum(long long time, vector<long long> &arr, long long m)
{
    long long cnt = m; //0초에 빈 놀이기구 m개에 다 탐.
    
    for(int i=0; i<m; i++)
    {
        cnt += time/arr[i];
    }

    return cnt;
}

long long calcMinTime(long long n, vector<long long> &arr)
{
    long long low = 0;
    long long high = n*30;
    long long cnt = 0;

    while(low<high)
    {
        long long mid = (low+high)/2;
        cnt = calcNum(mid, arr, arr.size());

        if(cnt<n)
        {
            low = mid+1;
        }
        else
        {
            high = mid;
        }
    }

    return high;    
}

int main()
{
    long long n, m, ans;

    cin>>n>>m;

    vector<long long> arr(m, 0);

    for(int i=0; i<m; i++)
    {
        cin>>arr[i];
    }

    long long time = calcMinTime(n, arr);
    long long beforeNum = 0; //time-1분일때 놀이기구 탄 아이들 수
    if(time>0)
    {
        beforeNum = calcNum(time-1, arr, m); 
    }

    for(int i=0; i<m; i++)
    {
        if(time%arr[i]==0) //time일 때 놀이기구가 비는 경우 = 아이가 타는 경우
        {
            beforeNum += 1;
        }

        if(beforeNum == n)
        {
            ans = i+1;
            break;
        }
    }

    cout<<ans;

}