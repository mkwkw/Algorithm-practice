#include <iostream>
#include <map>
#include <string>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    map<string, int> m1;
    map<int, string> m2;
    int n, m;
    cin>>n>>m;

    for(int i=1; i<=n; i++){
        string str;
        cin>>str;
        m1[str]=i;
        m2[i]=str;        
    }

    for(int i=0; i<m; i++){
        string pstr;
        cin>>pstr;

        if(isdigit(pstr[0])){
            cout<<m2[stoi(pstr)]<<'\n';
        }
        else{
            cout<<m1[pstr]<<'\n';
        }
    }
}