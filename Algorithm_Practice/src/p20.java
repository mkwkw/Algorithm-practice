//���� 2003
//������ ��
//two pointer
import java.io.*;
public class p20 {

	public static void main(String[] args) throws IOException{
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		String brr1[] = br.readLine().split(" ");
		String brr2[] = br.readLine().split(" ");
		
		int n = Integer.parseInt(brr1[0]); //���� ����
		int m = Integer.parseInt(brr1[1]); //��ǥ ��
		
		int arr[] = new int [n];
		
		
		for(int i=0; i<n; i++) {
			arr[i] = Integer.parseInt(brr2[i]);
		}
		
		
		int sum = 0; //��
		int a = 0; //pointer1
		int b = 0; //pointer2
		int count = 0;
		while(true) {
			if(sum >= m) {
				
				sum -= arr[a++];
				
			}
			else {
				sum += arr[b++];
				
			}
			if(b >= n)
				break;
			if(sum == m)
				count++;
			
		}
		
		System.out.println(count);
	}

}
