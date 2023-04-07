#include <iostream>

using namespace std;

int main(){
    int h,w,n,m, r, c;
    cin>>h>>w>>n>>m;

    r = (h-1)/(n+1) + 1;
    c = (w-1)/(m+1) + 1;

    cout<<r*c;
}