import java.util.*;
import java.io.*;

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