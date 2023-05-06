#include <iostream>
#include <vector>

using namespace std;

//unionfind�� ã��
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

    //�� ���ð� ����Ǿ��ִٸ� �� ���� ���� ��ȣ�� unionHead�� ����
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(cities[i][j]==1){
                int unionHead = min(cityUnion[i], cityUnion[j]);
                cityUnion[i] = unionHead;
                cityUnion[j] = unionHead; 
            }
        }
    }

    //�޺κп��� union�� �ٲ� �պκп� ������� �ʾ��� ��� ����Ͽ� �� �� �� ����
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
    int nowSet = cityUnion[plan[0]]; //���� ��ȹ �� ù ��° ������ unionHead
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