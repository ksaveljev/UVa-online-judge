import java.util.Scanner;

class Main {
  public static void main(String[] args) {
    (new UVa10554()).solve();
  }
}

class UVa10554 {
  private final Scanner sc = new Scanner(System.in);
  private String[] input = new String[5];
  private int[] parsed = new int[5];
  private final String delimiter = "-";
  private double totalCalories = 0, fatCalories = 0, currentCalories = 0;
  private int perc = 0;
  private char type;
  private boolean finished = false;

  public void solve() {
    while (sc.hasNext()) {
      input[0] = sc.next();

      if (input[0].equals(delimiter)) {
        if (finished)
          break;
        else
          finished = true;

        System.out.println((int)(fatCalories * 100.0 / totalCalories + 0.5) + "%");

        totalCalories = 0;
        fatCalories = 0;
        currentCalories = 0;
        perc = 0;
        continue;
      }

      finished = false;

      for (int i = 1; i < 5; ++i)
        input[i] = sc.next();

      for (int i = 0; i < 5; ++i) {
        type = input[i].charAt(input[i].length() - 1);
        parsed[i] = Integer.parseInt(input[i].substring(0, input[i].length() - 1));

        switch (type) {
          case 'g':
            switch (i) {
              case 0:
                parsed[i] *= 9;
                break;
              case 1:
              case 2:
              case 3:
                parsed[i] *= 4;
                break;
              case 4:
                parsed[i] *= 7;
                break;
            }
          // no break statement as we have
          // transformed the input from g to C
          case 'C':
            currentCalories += parsed[i];
            if (i == 0)
              fatCalories += parsed[i];
            parsed[i] = -1;
            break;
          case '%':
            perc += parsed[i];
            break;
        }
      }

      if (perc == 0)
        totalCalories += currentCalories;
      else {
        double tmp = currentCalories * 100.0 / (100 - perc);

        if (parsed[0] != -1) 
          fatCalories += parsed[0] * tmp / 100.0;

        totalCalories += tmp;
      }

      currentCalories = 0;
      perc = 0;
    }
  }
}
