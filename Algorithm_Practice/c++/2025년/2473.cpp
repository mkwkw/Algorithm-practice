#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    long long ans1, ans2, ans3;
    long long abs_sum = 6000000000;
    set<long long> ans;
    
    //입력
    cin>>n;

    vector<long long> v(n, 0);
    
    for(int i=0; i<n; i++)
    {
        cin>>v[i];
    }

    //정렬
    sort(v.begin(), v.end());

    //탐색
    for(int i=0; i<n-2; i++)
    {
        int left = i+1;
        int right = n-1;

        while(left<right)
        {
            long long mix = v[i]+v[left]+v[right];

            //합의 절댓값 비교로 abs_sum 갱신
            //합 비교로 left, right 갱신
            
            if(abs(mix)<abs_sum) //합이 0에 가까울경우 abs_sum 갱신
            { 
                ans1 = v[left];
                ans2 = v[right];
                ans3 = v[i];

                abs_sum = abs(mix);
            }

            if(v[i]+v[left]+v[right]>0)
            {
                right--;
            }
            else{
                left++;
            }
        }
    }

    ans.insert(ans1);
    ans.insert(ans2);
    ans.insert(ans3);

    for(long long a : ans)
    {
        cout<<a<<' ';
    }

}