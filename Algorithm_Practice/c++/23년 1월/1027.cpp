#include <iostream>
#include <vector>

using namespace std;

//기울기 크기 비교, 음수/양수인 경우 고려
//다양한 경우 고려
int main(){
    vector<int> building;
    int n, answer = 0;

    cin>>n;

    building.assign(n, 0);
    
    for(int i=0; i<n; i++){
        cin>>building[i];
    }

    if(n==1){
        cout<<"0";
        return 0;
    }

    double rightDegree = (double)(building[0]-building[1])/(-1);
    double leftDegree = (double)(building[n-1]-building[n-2]);

    int tempCnt = 1;
    double degree = 0;
    for(int i=2; i<n; i++){
        degree = (double)(building[0]-building[i])/(-i);
            //cout<<"rightDegree: "<<rightDegree<<" degree: "<<degree<<'\n';
            if(rightDegree<0 && degree<0){
                if(abs(rightDegree)>abs(degree)){
                    tempCnt++;
                    rightDegree = degree;
                    //cout<<"tempCnt: "<<tempCnt<<'\n';
                }
                else{
                    continue;
                }
            }
            else if(rightDegree<0 && degree>=0){
                rightDegree = degree;
                tempCnt++;
                //cout<<"tempCnt: "<<tempCnt<<'\n';
            }
            else if(rightDegree>=0 && degree<0){
                continue;
            }
            else if(rightDegree>=0 && degree>=0){
                if(abs(rightDegree)<abs(degree)){
                    tempCnt++;
                    rightDegree = degree;
                    //cout<<"tempCnt: "<<tempCnt<<'\n';
                }
                else{
                    continue;
                }
            }
        answer = max(tempCnt, answer);
    }
    tempCnt = 1;
    for(int i=n-3; i>=0; i--){
        degree = (double)(building[n-1]-building[i])/(n-1-i);
            //cout<<"leftDegree: "<<leftDegree<<" degree: "<<degree<<'\n';
            if(leftDegree<0 && degree<0){
                if(abs(leftDegree)<abs(degree)){
                    tempCnt++;
                    leftDegree = degree;
                    //cout<<"tempCnt: "<<tempCnt<<'\n';
                }
                else{
                    continue;
                }
            }
            else if(leftDegree<0 && degree>=0){
                leftDegree = degree;
                tempCnt++;
                //cout<<"tempCnt: "<<tempCnt<<'\n';
            }
            else if(leftDegree>=0 && degree<0){
                continue;
            }
            else if(leftDegree>=0 && degree>=0){
                if(abs(leftDegree)>abs(degree)){
                    tempCnt++;
                    leftDegree = degree;
                    //cout<<"tempCnt: "<<tempCnt<<'\n';
                }
                else{
                    continue;
                }
            }
    }

    answer = max(answer, tempCnt);

    for(int i=1; i<n-1; i++){
        int tempCnt = 2;
        double leftDegree = (double)(building[i] - building[i-1]), rightDegree = (double)(building[i+1]-building[i]);
        double degree = 0;
        //왼쪽
        for(int j=i-2; j>=0; j--){
            //cout<<"i: "<<i<<" building[i] "<<building[i]<<" j: "<<j<<" building[j] "<<building[j]<<'\n';
            degree = (double)(building[i]-building[j])/(i-j);
            //cout<<"leftDegree: "<<leftDegree<<" degree: "<<degree<<'\n';
            if(leftDegree<0 && degree<0){
                if(abs(leftDegree)<abs(degree)){
                    tempCnt++;
                    leftDegree = degree;
                    //cout<<"tempCnt: "<<tempCnt<<'\n';
                }
                else{
                    continue;
                }
            }
            else if(leftDegree>=0 && degree<0){
                leftDegree = degree;
                tempCnt++;
                //cout<<"tempCnt: "<<tempCnt<<'\n';
            }
            else if(leftDegree<0 && degree>=0){
                continue;
            }
            else if(leftDegree>=0 && degree>=0){
                if(abs(leftDegree)>abs(degree)){
                    tempCnt++;
                    leftDegree = degree;
                    //cout<<"tempCnt: "<<tempCnt<<'\n';
                }
                else{
                    continue;
                }
            }           
        }
        //오른쪽
        for(int j=i+2; j<n; j++){
            //cout<<"i: "<<i<<" building[i] "<<building[i]<<" j: "<<j<<" building[j] "<<building[j]<<'\n';
            degree = (double)(building[j]-building[i])/(j-i);
            //cout<<"rightDegree: "<<rightDegree<<" degree: "<<degree<<'\n';
            if(rightDegree<0 && degree<0){
                if(abs(rightDegree)>abs(degree)){
                    tempCnt++;
                    rightDegree = degree;
                    //cout<<"tempCnt: "<<tempCnt<<'\n';
                }
                else{
                    continue;
                }
            }
            else if(rightDegree<0 && degree>=0){
                rightDegree = degree;
                tempCnt++;
                //cout<<"tempCnt: "<<tempCnt<<'\n';
            }
            else if(rightDegree>=0 && degree<0){
                continue;
            }
            else if(rightDegree>=0 && degree>=0){
                if(abs(rightDegree)<abs(degree)){
                    tempCnt++;
                    rightDegree = degree;
                    //cout<<"tempCnt: "<<tempCnt<<'\n';
                }
                else{
                    continue;
                }
            }  
        }
        //cout<<"tempCnt: "<<tempCnt<<'\n';
        answer = max(answer, tempCnt);
    }

    cout<<answer;
}