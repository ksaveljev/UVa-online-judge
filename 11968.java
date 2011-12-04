import java.util.Scanner;
import java.util.Arrays;

class Main {
  public static void main(String[] args) {
    int t, n, m, k, case_num = 0;
    int prices[] = new int[1000];
    long sum;
    Scanner sc = new Scanner(System.in);

    t = sc.nextInt();

    while (t > 0) {
      t--;
      case_num++;
      sum = 0;
      n = sc.nextInt();
      m = sc.nextInt();
      k = sc.nextInt();

      for (int i = 0; i < n; i++) {
        prices[i] = sc.nextInt();
        sum += prices[i];
      }

      Arrays.sort(prices, 0, m);
      Arrays.sort(prices, m, m + k);

      double avg = sum * 1.0 / n;

      System.out.print("Case #" + case_num + ": ");

      int cake = prices[0];
      for (int i = 1; i < m; i++) {
        if (Math.abs(prices[i] - avg) < Math.abs(cake - avg)) {
          cake = prices[i];
        }
      }

      int drink = prices[m];
      for (int i = m + 1; i < m + k; i++) {
        if (Math.abs(prices[i] - avg) < Math.abs(drink - avg)) {
          drink = prices[i];
        }
      }

      System.out.println(cake + " " + drink);
    }
  }
}
