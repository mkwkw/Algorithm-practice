#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

//최소 공약수 찾기
//첫 번째 방법
int gcd1(int a, int b){
    //두 수 중 더 작은 수 기준으로 하나씩 감소하며 공약수가 있는지 판단
    for(int i=min(a,b); i>1; i--){
        //공약수 존재하면 바로 리턴
        if(a%i==0&&b%i==0){
            return i;
        }
    }

    return 1; //끝까지 없다면 최대공약수 1
}

//두 번째 방법
int gcd2(int a, int b){
    if(b==0){
        return a;
    }

    //a%b구한 후 b와 자리 바꾸어서 호출
    return gcd2(b, a%b);
}

int main(){
    int a,b;
    cin>>a>>b;

    int gcd = gcd2(max(a,b), min(a,b));
    int lcm = a*b/gcd;

    cout<<gcd<<'\n'<<lcm;
}

//최대 공약수, 최소 공배수 구하기
//a,b의 최대공약수*최소 공배수 = a*b