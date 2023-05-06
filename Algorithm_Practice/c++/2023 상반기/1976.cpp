#include <iostream>
#include <vector>

using namespace std;

//unionfind로 찾기
int main(){
    vector<vector<int>> cities;
    vector<int> plan, cityUnion;
    int n, m;
    
    cin>>n>>m;
    
    cities.assign(n, vector<int>(n, 0));
    cityUnion.assign(n, 0);
    plan.assign(m, 0);

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>cities[i][j];
        }
    }

    for(int i=0; i<m; i++){
        int city;
        cin>>city;
        plan[i] = city-1;
    }

    for(int i=0; i<n; i++){
        cityUnion[i]=i;
    }

    //두 도시가 연결되어있다면 더 작은 도시 번호를 unionHead로 설정
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(cities[i][j]==1){
                int unionHead = min(cityUnion[i], cityUnion[j]);
                cityUnion[i] = unionHead;
                cityUnion[j] = unionHead; 
            }
        }
    }

    //뒷부분에서 union이 바뀌어서 앞부분에 적용되지 않았을 경우 고려하여 한 번 더 시행
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(cities[i][j]==1){
                int unionHead = min(cityUnion[i], cityUnion[j]);
                cityUnion[i] = unionHead;
                cityUnion[j] = unionHead; 
            }
        }
    }
/*
    for(int i=0; i<n; i++){
        cout<<cityUnion[i]<<' ';
    }
    cout<<"\n";
*/
    int nowSet = cityUnion[plan[0]]; //여행 계획 중 첫 번째 도시의 unionHead
    bool flag = true;
    for(int i=1; i<m; i++){
        if(nowSet!=cityUnion[plan[i]]){
            flag = false;
            break;
        }
    }

    if(flag){
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }
}