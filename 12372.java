import java.util.Scanner;

class Main {
  public static void main(String[] args) {
    (new UVa12372()).solve();
  }
}

class UVa12372 {
  final private Scanner sc = new Scanner(System.in);
  private int test_cases, h, w, l;

  public void solve() {
    test_cases = sc.nextInt();

    for (int i = 1; i <= test_cases; i++) {
      l = sc.nextInt();
      w = sc.nextInt();
      h = sc.nextInt();

      System.out.print("Case " + i + ": ");

      if (l > 20 || w > 20 || h > 20)
        System.out.println("bad");
      else
        System.out.println("good");
    }
  }
}
