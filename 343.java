import java.io.*;
import java.util.*;
import java.math.*;

class Main
{
  void solve()
  {
    Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));

    while (in.hasNext())
    {
      String a = in.next();
      String b = in.next();
      boolean found = false;
      BigInteger biga, bigb;

      for (int i = 2; i <= 36; i++) {
        try {
          biga = new BigInteger(a, i);
        } catch (Exception e) {
          continue;
        }

        for (int j = 2; j <= 36; j++) {
          try {
            bigb = new BigInteger(b, j);
          } catch (Exception e) {
            continue;
          }

          if (biga.compareTo(bigb) == 0) {
            found = true;
            System.out.println(a + " (base " + i + ") = " + b + " (base " + j + ")");
            break;
          }
        }

        if (found)
          break;
      }

      if (!found) {
        System.out.println(a + " is not equal to " + b + " in any base 2..36");
      }
    }
  }

  public static void main(String args[])
  {
    Main problem = new Main();
    problem.solve();
  }
}
