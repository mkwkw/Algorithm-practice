#include <iostream>
#include <set>

using namespace std;

int main(){
    int a,b;
    set<int> s;
    cin>>a>>b;

    for(int i=0; i<a+b; i++){
        int num;
        cin>>num;
        if(s.find(num)==s.end()){
            s.insert(num);
        }
        else{
            s.erase(num);
        }
    }

    cout<<s.size();
    
}

//set - find, insert, erase