#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<pair<long long, long long>> pinary;
    int n;

    cin>>n;

    pinary.assign(91,{0,0}); //{0으로 끝나는 이친수 개수, 1로 끝나는 이친수 개수}

    pinary[1] = {0,1}; //1자리 이친수: 1 -> 1로 끝나는 이친수 1개
    pinary[2] = {1,0}; //2자리 이친수: 10 -> 0으로 끝나는 이친수 1개
    pinary[3] = {1,1}; //3자리 이친수: 100, 101 -> 0으로 끝나는 이친수 1개, 1로 끝나는 이친수 1개
    
    //0으로 끝나면 다음 자리에서 1,0 붙을 수 있음
    //1로 끝나면 다음 자리에서 0만 붙을 수 있음

    for(int i=4; i<=n; i++){
        //i자리 이친수
        pinary[i].first = pinary[i-1].first + pinary[i-1].second; //i-1자리 이친수 개수 (0으로 끝나는 이친수 개수 + 1로 끝나는 이친수 개수) 
        pinary[i].second = pinary[i-1].first; //i-1자리 이친수 중 0으로 끝나는 이친수 개수
    }

    cout<<pinary[n].first+pinary[n].second;
}

//자료형 범위 주의!
//pair<int, int>로 하면 n이 클 때 (ex. n=90) 오버플로우 발생
//int 대신 long long으로 바꿔주어야함.

