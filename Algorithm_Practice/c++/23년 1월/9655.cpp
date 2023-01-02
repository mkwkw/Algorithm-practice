#include <iostream>

using namespace std;

int main(){
    int n;
    cin>>n;

    if((n/3+n%3)%2==0){
        cout<<"CY";
    }
    else{
        cout<<"SK";
    }
}

//생각한 방법
//1. n이 0이 될 때까지 계속 반복문 - 가능하긴한데 비효율적일 것 같다.
//2. 3으로 나눈 몫과 나머지 이용 - 규칙 찾기
//2번 사용 - 통과
//검색해보니, n이 짝수인지, 홀수인지만 판별해서 출력해도 된다.