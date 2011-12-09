import java.util.Scanner;
import java.util.Vector;

class Main {
  public static void main(String[] args) {
    (new UVa1241()).solve();
  }
}

class Tournament {
  private int competitors_num, matches[];

  Tournament(int competitors_num, Vector<Integer> withdrawn) {
    this.competitors_num = competitors_num;
    matches = new int[(int)Math.pow(2, competitors_num)];
    for (int i = 0, sz = (int)Math.pow(2, competitors_num); i < sz; i++) 
      if (withdrawn.contains(i+1))
        matches[i] = -1;
      else
        matches[i] = i + 1;
  }

  public int countWO() {
    int result = 0;

    while (competitors_num > 0) {
      int competitors_left = (int)Math.pow(2, competitors_num);

      for (int i = 0; i < competitors_left; i+=2) {
        if (matches[i] != -1 && matches[i+1] != -1) {
          matches[i/2] = matches[i];
        } else if (matches[i] == -1 && matches[i+1] != -1) {
          result++;
          matches[i/2] = matches[i+1];
        } else if (matches[i] != -1 && matches[i+1] == -1) {
          result++;
          matches[i/2] = matches[i];
        } else {
          matches[i/2] = -1;
        }
      }

      competitors_num--;
    }

    return result;
  }
}

class UVa1241 {
  private int n, m, test_cases, tmp;
  final private Scanner sc = new Scanner(System.in);

  public void solve() {
    test_cases = sc.nextInt();

    while (test_cases-- > 0) {
      n = sc.nextInt();
      m = sc.nextInt();

      Vector<Integer> withdrawn = new Vector<Integer>();

      while (m-- > 0) {
        tmp = sc.nextInt();
        withdrawn.add(new Integer(tmp));
      }

      Tournament t = new Tournament(n, withdrawn);
      System.out.println(t.countWO());
    }
  }
}
