#include <string>
#include <vector>

using namespace std;

//행렬A, B의 곱셈 
//A[A의 행][A의 열(B의 행)]*B[A의 열(B의 행)][B의 행]
vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer, arr2Rotate;
    
    answer.assign(arr1.size(), vector<int>(arr2[0].size(),0));
    
    for(int i=0; i<arr1.size(); i++){ //A의 행
        for(int j=0; j<arr2[0].size(); j++){ //B의 열
            for(int k=0; k<arr2.size(); k++){ //A의 열(B의 행)
                answer[i][j] += arr1[i][k]*arr2[k][j];
            }  
        }
    }
    
    return answer;
}