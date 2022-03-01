#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

pair<long long, long long> find_liquid(vector<long long> &v){

    int left = 0;
    int right = v.size()-1;
    int ans_left=left, ans_right=right;
    int diff=2*1e9+1;
    
    while(left<right){
        
        if(v[left]+v[right]==0){
            ans_left=left;
            ans_right=right;
            break;
        }

        if(abs(v[left]+v[right])<diff){
            ans_left = left;
            ans_right = right;
            diff=abs(v[left]+v[right]);
        }
        
        //아래 조건문들은 left와 right를 조작하므로 while문의 맨 마지막에 배치한다.
        if(v[left]+v[right]>0){
            right--;
        }
        else if(v[left]+v[right]<0){
            left++;
        }

    }

    return make_pair(v[ans_left], v[ans_right]);
}

int main(){
    int n;
    vector<long long> v;

    cin>>n;
    
    v.assign(n,0);

    for(int i=0; i<n; i++){
        cin>>v[i];
    }

    sort(v.begin(), v.end());

    auto answer = find_liquid(v);

    cout<<answer.first<<' '<<answer.second;
}

//두 용액의 합이 0에 가까운 것을 찾는 것이므로 투 포인터를 사용하는 것이 좋다.
//종료 조건과 left와 right가 바뀌고 ans_left, ans_right를 정하는 기준을 세운다.