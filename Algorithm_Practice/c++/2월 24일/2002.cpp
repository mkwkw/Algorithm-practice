#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main(){
    map<string, int> m;
    vector<string> v;
    int n, answer=0;
    string str;
    
    cin>>n;

    v.assign(n,"");
    for(int i=0; i<n; i++){
        cin>>str;
        m[str]=i;
    }
    for(int i=0; i<n; i++){
        cin>>str;
        v[i]=str;
    }

    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(m[v[i]]>m[v[j]]){
                answer++;
                break;
            }
        }
    }

    cout<<answer;   
}

//map에 key는 차량번호, value는 들어온 순서로 저장한다.
//어떤 차가 어떤 차를 추월했는지가 중요한 것이 아니라
//몇 대가 추월했는지 아는 것이 중요하므로
/*
for(int i=0; i<n; i++){
    for(int j=i+1; j<n; j++){
        if(m[v[i]]>m[v[j]]){
            answer++;
            break;
        }
    }
}
이렇게 코드를 작성한다.
*/