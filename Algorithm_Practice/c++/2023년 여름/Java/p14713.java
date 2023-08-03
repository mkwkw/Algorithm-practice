import java.util.*;
import java.io.*;

//큐
//c++이었으면 vector<queue<string>> 이런 식으로 했을텐데
//java라서 2차원 ArrayList로 해결
//ArrayList<String>[] parrot = new ArrayList[앵무새 마리 수];
//앵무새 마리 수만큼 new ArrayList<String>(); 할당
//그 다음에 비교
//앵무새의 말은 순서가 지켜져야하므로, 해당 앵무새의 단어 배열의 0번째 인덱스 문자열만 비교
//앵무새가 최대 100마리밖에 안되므로 완전 탐색 가능
//get(0)할 때, isEmpty체크, 문자열 비교할 때, equals로 사용

public class p14713{

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());

        ArrayList<String>[] parrot = new ArrayList[n];
        
        for(int i=0; i<n; i++){
            parrot[i] = new ArrayList<String>();

            String[] words = br.readLine().split(" ");

            for(int j=0; j<words.length; j++){
                parrot[i].add(words[j]);
            }
        }

        String[] totalWords = br.readLine().split(" ");
        for(int i=0; i<totalWords.length; i++){
            boolean flag = false; 

            for(int j=0; j<parrot.length; j++){
                if(!parrot[j].isEmpty() && parrot[j].get(0).equals(totalWords[i])){
                    flag = true;
                    parrot[j].remove(0);
                    break;
                }
            }

            if(!flag){
                System.out.print("Impossible");
                return;
            }
        }

        boolean flag1 = true;
        for(int i=0; i<parrot.length; i++){
            if(parrot[i].size()>0){
                flag1 = false;
                break; 
            }
        }

        if(flag1){
            System.out.print("Possible");
        }
        else{
            System.out.print("Impossible");
        }
    }
}