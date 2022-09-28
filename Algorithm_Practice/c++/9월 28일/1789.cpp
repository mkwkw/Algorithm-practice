#include <iostream>

using namespace std;

//1부터 하나씩 더해나가기 - S를 초과한 수-1
int main(){
    
    long long s;
    cin>>s;

    long long ssum=0; //중간 합
    long long num=1; //더해지는 수
    int cnt = 0; //num의 개수

    while(true){
        ssum += num;
        cnt++;

        if(ssum>s){
            break;
        }
        num++;
    }

    cnt--;
    cout<<cnt;

}