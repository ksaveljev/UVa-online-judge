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
      BigDecimal a = in.nextBigDecimal();
      BigDecimal b = in.nextBigDecimal();

      BigDecimal result = a.add(b);

      if (result.compareTo(BigDecimal.ZERO) == 0) {
        System.out.println("0.0");
        continue;
      }

      char output[] = result.toString().toCharArray();
      int len = output.length - 1; 

      while (len >= 0 && output[len] == '0') len--; 
      if (len >= 0 && output[len] == '.') {
        len++;
        output[len] = '0';
      }

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
