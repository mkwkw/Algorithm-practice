import java.io.*;

//구현, 브루트포스(m,n이 20이하로 매우 작음)
//자물쇠의 좌상단 기준으로 열쇠의 어느쪽부터 시작할지 경우를 따져야한다.
//열쇠의 우상단, 우하단, 좌상단, 좌하단 4방향 모두 고려해야함.
//이렇게 해서 안되면
//열쇠를 왼쪽으로 90도 회전한다.
class Solution {
    public boolean solution(int[][] key, int[][] lock) {
        boolean answer = true;
        
        //자물쇠의 홈 개수 세기
        int cnt = 0;
        int tempCnt = 0;
        for(int i=0; i<lock.length; i++){
            for(int j=0; j<lock.length; j++){
                if(lock[i][j]==0){
                    cnt++;
                }
            }
        }
        
        //1. 4번 왼쪽 90도 회전 
        for(int i=0; i<4; i++){
            
            //2. 열쇠를 자물쇠에 맞춰보기 - 4가지 경우
            //2-1. 열쇠의 좌상단이 자물쇠의 좌상단에서 시작
            //2-2. 열쇠의 우상단이 자물쇠의 좌상단에서 시작
            //2-3. 열쇠의 우하단이 자물쇠의 좌상단에서 시작
            //2-4. 열쇠의 좌하단이 자물쇠의 좌상단에서 시작
            for(int j=0; j<lock.length; j++){
                for(int k=0; k<lock.length; k++){
                    
                    //2-1.
                    answer = true;
                    tempCnt = 0;
                    
                    for(int a=0; a<key.length; a++){
                        int nextR = j+a;
                        if(nextR>=lock.length || nextR<0){
                            break;
                        }
                        for(int b=0; b<key.length; b++){
                            int nextC = k+b;
                            if(nextC>=lock.length || nextC<0){
                                break;
                            }
                            
                            if(key[a][b]==1 && lock[nextR][nextC]==1 || key[a][b]==0 && lock[nextR][nextC]==0){ //맞물리지 않는 경우
                                answer = false;
                                break;
                            }
                            else if(key[a][b]==1 && lock[nextR][nextC]==0){ //자물쇠의 홈과 키의 돌기가 맞는 경우 세기 - 자물쇠의 홈이 다 채워져야하므로 "돌기가 맞는 경우 == 자물쇠의 홈의 개수"여야함.
                                tempCnt++;
                            }
                        }

                        if(!answer){
                            break;
                        }
                    }
                    
                    if(answer && tempCnt==cnt){
                        //System.out.println("temp cnt "+tempCnt);
                        return true;
                    }
 
                    //2-2.
                    answer = true;
                    tempCnt = 0;
                    
                    for(int a=0; a<key.length; a++){
                        int nextR = j+a;
                        if(nextR>=lock.length || nextR<0){
                            break;
                        }
                        for(int b=key.length-1; b>=0; b--){
                            int nextC = b-(key.length-1-k);
                            
                            if(nextC>=lock.length || nextC<0){
                                break;
                            }
                            
                            if(key[a][b]==1 && lock[nextR][nextC]==1 || key[a][b]==0 && lock[nextR][nextC]==0){
                                answer = false;
                                break;
                            }
                            else if(key[a][b]==1 && lock[nextR][nextC]==0){ //자물쇠의 홈과 키의 돌기가 맞는 경우 세기 - 자물쇠의 홈이 다 채워져야하므로 "돌기가 맞는 경우 == 자물쇠의 홈의 개수"여야함.
                                tempCnt++;
                            }
                        }

                        if(!answer){
                            break;
                        }
                    }
                    
                    if(answer && tempCnt==cnt){
                        return true;
                    }
                    
                    //2-3.
                    answer = true;
                    tempCnt = 0;
                    
                    for(int a=key.length-1; a>=0; a--){
                        int nextR = a-(key.length-1-j);
                        if(nextR>=lock.length || nextR<0){
                            break;
                        }
                        for(int b=key.length-1; b>=0; b--){
                            int nextC = b-(key.length-1-k);
                            
                            if(nextC>=lock.length || nextC<0){
                                break;
                            }
                            
                            if(key[a][b]==1 && lock[nextR][nextC]==1 || key[a][b]==0 && lock[nextR][nextC]==0){
                                
                                answer = false;
                                break;
                            }
                            else if(key[a][b]==1 && lock[nextR][nextC]==0){ //자물쇠의 홈과 키의 돌기가 맞는 경우 세기 - 자물쇠의 홈이 다 채워져야하므로 "돌기가 맞는 경우 == 자물쇠의 홈의 개수"여야함.
                                tempCnt++;
                            }
                        }
                        
                        if(!answer){
                            break;
                        }
                    }
                    
                    if(answer && tempCnt==cnt){
                        return true;
                    }
                    
                    //2-4.
                    answer = true;
                    tempCnt = 0;
                    
                    for(int a=key.length-1; a>=0; a--){
                        int nextR = a-(key.length-1-j);
                        if(nextR>=lock.length || nextR<0){
                            break;
                        }
                        for(int b=0; b<key.length; b++){
                            int nextC = k+b;
                            
                            if(nextC>=lock.length || nextC<0){
                                break;
                            }
                            
                            
                            if(key[a][b]==1 && lock[nextR][nextC]==1 || key[a][b]==0 && lock[nextR][nextC]==0){
                                
                                answer = false;
                                break;
                            }
                            else if(key[a][b]==1 && lock[nextR][nextC]==0){ //자물쇠의 홈과 키의 돌기가 맞는 경우 세기 - 자물쇠의 홈이 다 채워져야하므로 "돌기가 맞는 경우 == 자물쇠의 홈의 개수"여야함.
                                tempCnt++;
                            }
                        }
                        
                        if(!answer){
                            break;
                        }
                    }
                    
                    if(answer && tempCnt==cnt){
                        return true;
                    }
                    else{ //자물쇠 홈이 안맞거나 열쇠와 맞물리는 홈의 개수가 안맞을 때
                        answer = false; //answer을 false로 바꾸어야함.
                    }
                }
                
            }
            
            
            //키 90도 회전
            int[][] key1 = new int[key.length][key.length];
            for(int j=0; j<key.length; j++){
                for(int k=0; k<key.length; k++){
                    key1[k][key.length-1-j] = key[j][k];
                }
            }
            
            key = key1;
        }
        
        return answer;
    }
}