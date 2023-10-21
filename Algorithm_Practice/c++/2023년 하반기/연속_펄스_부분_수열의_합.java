import java.util.*;
import java.io.*;

//누적합 - 부분 수열의 합 최댓값 구하기 => +. - 가 섞여있으므로 문제 => 최대 누적합 - 최소 누적합
//{1,-1,1,...} 곱한 경우, {-1,1,-1,...} 곱한 경우 2가지 경우의 배열을 미리 만들어놓는다.
//1. 누적합을 구하는데, 최대 누적합과 최소 누적합을 동시에 구한다.
//2. 최대 누적합 - 최소 누적합으로 구한 것이 부분 수열의 합이 최댓값이 되는 경우이다.
//주의! 음수 값이 있으므로 minSum의 초기값을 0으로 한다. 만약 음수 누적합이 없다면, 그냥 [0]부터 시작하는 부분 수열이 되는 것이다.
class Solution {
    public long solution(int[] sequence) {
        long answer = 0;
        
        //{1,-1,1,...} 곱한 경우
        long minSum = 0;
        long maxSum = 0;
        long[] temp1 = new long [sequence.length];
        temp1[0] = (long)sequence[0]*(-1);
        minSum = Math.min(minSum, temp1[0]);
        maxSum = Math.max(maxSum, temp1[0]);
        
        for(int i=1; i<sequence.length; i++){
            if(i%2==0){
                temp1[i] = (long)(sequence[i]*(-1)+temp1[i-1]);
            }
            else{
                temp1[i] = (long)(sequence[i]+temp1[i-1]);
            }
            
            minSum = Math.min(minSum, temp1[i]);
            maxSum = Math.max(maxSum, temp1[i]);
        }
        
        answer = Math.max(answer, maxSum-minSum);
        
        //{-1,1,-1,...} 곱한 경우
        minSum = 0;
        maxSum = 0;
        long[] temp2 = new long [sequence.length];
        temp2[0] = (long) sequence[0];
        minSum = Math.min(minSum, temp2[0]);
        maxSum = Math.max(maxSum, temp2[0]);
       
        
        for(int i=1; i<sequence.length; i++){
            if(i%2==0){
                temp2[i] = (long)(sequence[i]+temp2[i-1]);
            }
            else{
                temp2[i] = (long)(sequence[i]*(-1)+temp2[i-1]);
            }
            
            minSum = Math.min(minSum, temp2[i]);
            maxSum = Math.max(maxSum, temp2[i]);      
        }
        
        
        answer = Math.max(answer, maxSum - minSum);
        
        return answer;
    }
}