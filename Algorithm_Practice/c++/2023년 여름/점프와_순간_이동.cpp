#include <iostream>
#include <vector>
#include <iostream>

using namespace std;

//n이 0이 될 때까지
//n이 짝수일 때는 n/2
//n이 홀수일 때는 n-1, 이 때만 점프 횟수+1
int solution(int n)
{
    int ans = 0;
    
    while(n>0){
        if(n%2!=0){
            ans++;
            n -= 1;
        }
        else{
            n /= 2;
        }
    }

    return ans;
}