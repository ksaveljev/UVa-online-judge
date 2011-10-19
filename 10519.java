import java.io.*;
import java.util.*;
import java.math.*;

class Main
{
  void solve()
  {
    Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
    BigInteger two = new BigInteger("2");

    while (in.hasNext())
    {
      BigInteger n = in.nextBigInteger();
      BigInteger r = n.pow(2);

      if (n.compareTo(new BigInteger("0")) == 0) {
        System.out.println("1");
      } else if (n.compareTo(new BigInteger("1")) == 0) {
        System.out.println("2");
      } else {
        System.out.println(r.subtract(n).add(two).toString());
      }
    }
  }

  public static void main(String args[])
  {
    Main problem = new Main();
    problem.solve();
  }
}
