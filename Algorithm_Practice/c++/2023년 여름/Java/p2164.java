import java.util.*;
import java.io.*;

//큐 - offer, poll, size, peek
public class p2164{
    
    public static void main(String[] args) throws IOException{

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        
        Queue<Integer> card = new LinkedList<>();
        
        for(int i=1; i<=n; i++){
            card.offer(i);
        }

        if(card.size()==1){
            System.out.print(card.peek());
            return;
        }

        while(card.size()>1){
            card.poll();
            
            if(card.size()==1){
                System.out.print(card.peek());
                return;
            }

            int topCard = card.peek();
            card.poll();
            card.offer(topCard);
        }

    }
}