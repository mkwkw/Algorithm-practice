import java.util.*;
import java.io.*;

//인덱스 i 기준 왼쪽에서의 최솟값, 오른쪽에서의 최솟값 저장하는 배열 각각 생성
class Solution {
    
    public int solution(int[] a) {
        int answer = 0;
        int[] leftMin = new int[a.length]; //인덱스 i 기준 왼쪽에서의 최솟값
        int[] rightMin = new int[a.length]; //인덱스 i 기준 오른쪽에서의 최솟값
        
        //a의 길이가 1이나 2일 때
        if(a.length==1 || a.length==2){
            return a.length;
        }
        
        //a의 길이가 3이상일 때
        answer = 2; //맨 처음과 맨 끝은 항상 가능
        leftMin[1] = a[0];
        rightMin[a.length-2] = a[a.length-1];
        
        //인덱스 i 왼쪽에서의 최솟값 저장하기
        for(int i=1; i<a.length-1; i++){
            leftMin[i+1] = Math.min(leftMin[i], a[i]);
        }
        
        //인덱스 i 오른쪽에서의 최솟값 저장하기
        for(int i=a.length-2; i>=1; i--){
            rightMin[i-1] = Math.min(rightMin[i], a[i]);
        }
        
        for(int i=1; i<a.length-1; i++){
            //System.out.println(leftMin[i]+" "+a[i]+" "+rightMin[i]);
            if(leftMin[i]<a[i] && rightMin[i]<a[i]){
                continue;
            }
            answer++;
        }
        
        return answer;
    }
}