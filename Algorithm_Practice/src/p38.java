//16563
//어려운 소인수분해
//시간초과
import java.io.*;
public class p38 {

	public static void main(String[] args) throws IOException{
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine()); //숫자 개수
		String brr[] = br.readLine().split(" ");
		int num[] = new int [n]; //소인수분해할 숫자 배열
		int m=2; //나눌 숫자
		
		for(int i=0; i<n; i++) {
			num[i] = Integer.parseInt(brr[i]);			
		}
		
		for(int i=0; i<n; i++) {
			int nn = num[i];
			while(true) {
				m=2;
				for(int j=2; j<=nn; j++) {
					if(num[i]%m!=0) {
						++m;
					}
					else {
						num[i]=num[i]/m;
						System.out.print(m+" ");
					}
					
					if(num[i]==m) {
						break;
					}	
				}
				if(num[i]!=1) {
					System.out.println(num[i]);
					
				}
				else if(num[i]==4) {
					//System.out.println("2 2");
					break;
				}
				else {
					System.out.println();
					
				}
				break;
			}
		}
		
	}

}
