//백준 11659
//구간 합 구하기4
//누적 합
import java.util.*;
public class p18 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int m = sc.nextInt();
		
		int arr[] = new int [n+1];
		arr[0]=0;
 		for(int i=1; i<=n; i++) {
			arr[i]=sc.nextInt();
		}
 		
 		//누적합
 		int prefixsum[] = new int [n+1];
 		prefixsum[0] = arr[0];
 		for(int i=1; i<=n; i++) {
 			prefixsum[i] = prefixsum[i-1]+arr[i];
 			
 		}
 		
 		int a[] = new int [m];
 		int b[] = new int [m];
 		
 		for(int i=0; i<m; i++) {
 			a[i] = sc.nextInt();
 			b[i] = sc.nextInt();
 		}
 		
 		for(int i=0; i<m; i++) {
 			System.out.println(prefixsum[b[i]]-prefixsum[a[i]-1]);
 		}
 		sc.close();
	}
}
