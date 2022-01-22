#include <iostream>
#include <vector>

using namespace std;


int coin(vector<int> &v, int k, int idx){
    int cnt=0; //동전 개수
    
    for(int i=idx; i>=0; i--){
        if(k==0){ //break 조건
            break;
        }

        if(v[i]>k){
            continue;
        }

        cnt += k/v[i]; //몫
        k %= v[i]; //나머지
    }
    return cnt;
}

int main(){
    int n, k, answer;
    vector<int> v;

    cin>>n>>k;

    v.assign(n,0);

    for(int i=0; i<n; i++){
        cin>>v[i];
    }

    answer = coin(v, k, n-1);

    cout<<answer;
}

//몫과 나머지 이용