#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n, sum=0, cnt=0;
    cin>>n;

    vector<int>goal(n,0);

    for(int i=0; i<n; i++){
        cin>>goal[i];
        sum += goal[i];
        cnt += goal[i]/2; //2의 개수
    }
    //2의 개수와 1의 개수가 같은가

    if(sum%3==0 && cnt>=sum/3){ 
        //가능한 총 합:2+1, 1+2, 0+3, 3+0 이므로 3의 배수이고 
        //2의 개수가 총합을 3으로 나눈 몫보다 크거나 같은 경우 참 
        //2일 수 >= 총 일 수 ->2일을 1일 2개로 나눌 수 있음.
        //참고: https://velog.io/@axiom0510/b19539
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }

    

}