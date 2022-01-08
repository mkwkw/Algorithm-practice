#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//합병정렬 - 진행 단계 표현
vector<int> merge_sort(vector<int> &v, int n, int k){
    vector<int> ans;
    int d = n/k;
    for(int i=0; i<v.size(); i+=d){
        sort(v.begin()+i, v.begin()+i+d); //인덱스 i부터 i+d까지 정렬
    }
    return v;
}


int main(){
    vector<int> v, ans;    
    int n, k;
    
    cin>>n;

    for(int i=0; i<n; i++){
        int num;
        cin>>num;
        v.push_back(num);
    }

    cin>>k;
    ans = merge_sort(v, n, k);

    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<' ';
    }

}

//for문으로 n/k씩 정렬하면 됨.