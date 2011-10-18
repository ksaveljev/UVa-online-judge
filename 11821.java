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
      BigDecimal result = BigDecimal.ZERO;

      while (true)
      {
        BigDecimal tmp = in.nextBigDecimal();
        if (tmp.compareTo(BigDecimal.ZERO) == 0)
          break;
        result = result.add(tmp);
      }

      //System.out.println(result.stripTrailingZeros().toPlainString());
      char output[] = result.toString().toCharArray();
      int len = output.length - 1;

      while (len >= 0 && output[len] == '0') len--; 
      if (len >= 0 && output[len] == '.') len--; 

      for (int i = 0; i <= len; i++) System.out.print(output[i]);
      System.out.println();
    }
  }

  public static void main(String args[])
  {
    Main problem = new Main();
    problem.solve();
  }
}
