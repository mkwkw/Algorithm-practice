#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<string> cookie;
    int n, heartX, heartY, leftArm, rightArm, waist, waistEndX, leftLeg, rightLeg;
    cin>>n;

    cookie.assign(n, "");

    for(int i=0; i<n; i++){
        cin>>cookie[i];
    }

    //머리 찾기
    bool head = false;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(cookie[i][j]=='*'){
                head = true;
                heartX = i+1;
                heartY = j;
                break;
            }
        }
        if(head){
            break;
        }
    }

    //오른쪽 팔
    rightArm = 0;
    for(int j=heartY+1; j<n; j++){
        if(cookie[heartX][j]=='*'){
            rightArm++;
        }
        else{
            break;
        }
    }

    //왼쪽 팔
    leftArm = 0;
    for(int j=heartY-1; j>=0; j--){
        if(cookie[heartX][j]=='*'){
            leftArm++;
        }
        else{
            break;
        }
    }

    //허리
    waist = 0;
    for(int i=heartX+1; i<n; i++){
        if(cookie[i][heartY]=='*'){
            waist++;
            waistEndX = i;
        }
        else{
            break;
        }
    }

    //오른쪽 다리
    rightLeg = 0;
    for(int i=waistEndX+1; i<n; i++){
        if(cookie[i][heartY+1]=='*'){
            rightLeg++;
        }
        else{
            break;
        }
    }

    //왼쪽 다리
    leftLeg = 0;
    for(int i=waistEndX+1; i<n; i++){
        if(cookie[i][heartY-1]=='*'){
            leftLeg++;
        }
        else{
            break;
        }
    }

    cout<<heartX+1<<' '<<heartY+1<<'\n';
    cout<<leftArm<<' '<<rightArm<<' '<<waist<<' '<<leftLeg<<' '<<rightLeg;
}