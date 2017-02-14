import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String str = sc.next();
		boolean c = false;
		String result = "No";
		for (int i = 0; i < str.length(); i++) {
			if (str.charAt(i) == 'C') {
				c = true;
			} else if (str.charAt(i) == 'F' && c) {
				result = "Yes";
				break;
			}
		}
		System.out.println(result);
	}
}