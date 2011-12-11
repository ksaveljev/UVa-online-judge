import java.util.Scanner;
import java.util.ArrayList;
import java.util.Arrays;

class Main {
  public static void main(String[] args) {
    (new UVa300()).solve();
  }
}

class Haab {
  private int day_num, year;
  private String month;
  final public static ArrayList<String> haab_months = new ArrayList<String>(Arrays.asList("pop", "no", "zip", "zotz", "tzec", "xul", "yoxkin", "mol", "chen", "yax", "zac", "ceh", "mac", "kankin", "muan", "pax", "koyab", "cumhu", "uayet"));

  Haab (int day_num, String month, int year) {
    this.day_num = day_num;
    this.month = month;
    this.year = year;
  }

  public Tzolkin toTzolkin() {
    int month = haab_months.indexOf(this.month) + 1;
    int days = this.year * 365 + (month-1) * 20 + day_num + 1;

    return new Tzolkin(days);
  }
}

class Tzolkin {
  private int day_num, year;
  private String day_name;
  final public static ArrayList<String> tzolkin_months = new ArrayList<String>(Arrays.asList("imix", "ik", "akbal", "kan", "chicchan", "cimi", "manik", "lamat", "muluk", "ok", "chuen", "eb", "ben", "ix", "mem", "cib", "caban", "eznab", "canac", "ahau"));

  Tzolkin (int days) {
    int tmp;

    tmp = days - (days / 13) * 13;
    this.day_num = (tmp == 0 ? 13 : tmp);

    tmp = days - (days / 20) * 20;
    this.day_name = tzolkin_months.get(tmp == 0 ? 19 : tmp - 1);

    tmp = days % 260;
    this.year = (tmp == 0 ? days / 260 - 1: days / 260);
  }

  @Override
  public String toString() {
    return day_num + " " + day_name + " " + year;
  }
}

class UVa300 {
  private int test_cases_num, day_num, year;
  private String day_name;
  final private Scanner sc = new Scanner(System.in);

  public void solve() {
    test_cases_num = sc.nextInt();

    System.out.println(test_cases_num);

    while (test_cases_num-- > 0) {
      day_num = Integer.parseInt(sc.next().replace('.', ' ').trim());
      day_name = sc.next();
      year = sc.nextInt();

      System.out.println((new Haab(day_num, day_name, year)).toTzolkin());
    }
  }
}
