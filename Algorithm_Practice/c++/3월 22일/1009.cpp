#include <iostream>
#include <cmath>

using namespace std;

//일의 자리에만 계속 곱하면 되니까 일의 자리만 남기는 함수가 필요
int one(int num){
    while(num>10){
        num %= 10;
    }
    return num;
}

int main(){
    int t, a, b, answer;
    long long num;

    cin>>t;

    while(t--){
        cin>>a>>b;
        num = a;
        if(a>10){
            num = one(num);
        }
        for(int i=1; i<b; i++){
            num *= a;
            if(num>10){
                num = one(num);
            }
        }
        
        answer = num;
        if(answer==0){
            answer = 10;
        }
        //cout<<num<<'\n';
        cout<<answer<<'\n';
    }

}
//일의 자리에 b번 돌면서 a를 곱함. 그냥 pow(a,b)하면 overflow가 발생하므로
//한 번 돌 때마다 일의 자리만 남기는 것이 포인트