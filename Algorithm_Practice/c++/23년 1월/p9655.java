import java.io.*;

public class p9655{

    public static void main(String[] args) throws IOException{

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());

        if((n/3+n%3)%2==0){
            System.out.print("CY");
        }
        else{
            System.out.print("SK");
        }
    }
}