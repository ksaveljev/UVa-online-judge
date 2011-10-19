import java.io.*;
import java.util.*;
import java.math.*;

class Main
{
  void solve()
  {
    Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
    int n = in.nextInt();

    while (n-- > 0)
    {
      BigInteger a = in.nextBigInteger();
      BigInteger p = in.nextBigInteger();

      System.out.println(p.mod(a).toString());
    }
  }

  public static void main(String args[])
  {
    Main problem = new Main();
    problem.solve();
  }
}
