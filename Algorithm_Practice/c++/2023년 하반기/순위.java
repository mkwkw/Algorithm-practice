import java.util.*;
import java.io.*;

//i번 선수가 k번 선수를 이기고, k번 선수가 j번 선수를 이기면 -> i번 선수는 j번 선수를 이긴다.
//플로이드 와샬과 비슷한 모양 - k가 가장 바깥 for문 변수가 되도록 하기
//행렬로 표현
class Solution {
    
    public int solution(int n, int[][] results) {
        int answer = n;
        
        //행렬 - 0: 무효, 1: 이김, -1: 짐, -2: 승패 결정X
        int[][] result = new int[n][n];
        
        //초기화
        for(int i=0; i<n; i++){
            Arrays.fill(result[i], -2);
            result[i][i] = 0;
        }
        
        //승패 표시
        for(int i=0; i<results.length; i++){
            result[results[i][0]-1][results[i][1]-1] = 1;
            result[results[i][1]-1][results[i][0]-1] = -1;
        }
        
        //중간에 위치하는 k가 가장 바깥쪽 for문 변수가 되도록 하기
        for(int k=0; k<n; k++){
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    if(result[i][k]==1 && result[k][j]==1){
                        result[i][j]=1;
                        result[j][i]=-1;
                    }
                }
            }
        }
        
        //-2가 있는 row는 선수 순위 확정 불가
        for(int i=0; i<n; i++){
            boolean flag = true;
            for(int j=0; j<n; j++){
                if(result[i][j]==-2){
                    flag = false;
                    break;
                }
            }
            if(!flag){
                answer--;
            }
        }
        return answer;
    }
}