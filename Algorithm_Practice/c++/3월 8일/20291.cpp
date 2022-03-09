#include <iostream>
#include <map>

using namespace std;

int main(){
    map<string, int> m;
    int n;
    cin>>n;

    for(int i=0; i<n; i++){
        string file, extension="";
        int idx;
        cin>>file;
        extension = file.substr(file.find('.')+1); //.이후부터 자르기
        m[extension]++;
    }

    for(auto ext : m){
        cout<<ext.first<<' '<<ext.second<<'\n'; //map 출력 형식
    }
}
