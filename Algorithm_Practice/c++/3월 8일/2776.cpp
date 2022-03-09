#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int find_num(vector<int> &v, int num){
    int left=0;
    int right=v.size()-1;
    int mid;
    int result=0; //있나 없나
    while(left<=right){
        mid = (left + right)/2;

        if(num>v[mid]){
            left = mid+1;
        }
        else if(num<v[mid]){
            right = mid-1;
        }
        else{
            result=1;
            break;
        }
    }

    return result;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t,n,m;

    cin>>t;
    for(int j=0; j<t; j++){
        vector<int> v;
        cin>>n;
        v.assign(n,0);

        for(int i=0; i<n; i++){
            cin>>v[i];
        }

        sort(v.begin(), v.end());

        cin>>m;

        for(int i=0; i<m; i++){
            int num, answer;
            cin>>num;
            answer = find_num(v,num);
            cout<<answer<<'\n';
        }
    }

}

//이분 탐색 이용
//map 이용할 수도 있음. map[num]=1로 저장한 다음에 숫자 찾기