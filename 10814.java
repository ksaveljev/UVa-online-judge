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
      in.next();
      BigInteger b = in.nextBigInteger();

      BigInteger div = a.gcd(b);
      a = a.divide(div);
      b = b.divide(div);

      System.out.println(a.toString() + " / " + b.toString());
    }
  }

  public static void main(String args[])
  {
    Main problem = new Main();
    problem.solve();
  }
}
