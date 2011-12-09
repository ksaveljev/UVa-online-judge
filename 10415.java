import java.util.Scanner;

class Main {
  public static void main(String[] args) {
    (new UVa10415()).solve();
  }
}

class Saxophone {
  private String notes;
  private int fingers[] = new int[11];

  Saxophone(String notes) {
    this.notes = notes;
  }

  int[] fingersUsed(char note) {
    if (note == 'c') {
      int result[] = {2,3,4,7,8,9,10};
      return result;
    } else if (note == 'd') {
      int result[] = {2,3,4,7,8,9};
      return result;
    } else if (note == 'e') {
      int result[] = {2,3,4,7,8};
      return result;
    } else if (note == 'f') {
      int result[] = {2,3,4,7};
      return result;
    } else if (note == 'g') {
      int result[] = {2,3,4};
      return result;
    } else if (note == 'a') {
      int result[] = {2,3};
      return result;
    } else if (note == 'b') {
      int result[] = {2};
      return result;
    } else if (note == 'C') {
      int result[] = {3};
      return result;
    } else if (note == 'D') {
      int result[] = {1,2,3,4,7,8,9};
      return result;
    } else if (note == 'E') {
      int result[] = {1,2,3,4,7,8};
      return result;
    } else if (note == 'F') {
      int result[] = {1,2,3,4,7};
      return result;
    } else if (note == 'G') {
      int result[] = {1,2,3,4};
      return result;
    } else if (note == 'A') {
      int result[] = {1,2,3};
      return result;
    } else if (note == 'B') {
      int result[] = {1,2};
      return result;
    }

    return null;
  }

  public void print_fingers_usage() {
    int fingersUsedCache[][] = new int[notes.length()][];

    for (int i = 0, sz = notes.length(); i < sz; i++) {
      fingersUsedCache[i] = fingersUsed(notes.charAt(i));
    }

    for (int i = 0, sz = notes.length(); i < sz; i++) {
      if (i == 0) {
        for (int f : fingersUsedCache[i])
          fingers[f]++;
      } else {
        for (int f : fingersUsedCache[i]) {
          boolean ok = true;
          for (int fprevious : fingersUsedCache[i-1]) {
            if (f == fprevious) {
              ok = false;
              break;
            }
          }
          if (ok)
            fingers[f]++;
        }
      }
    }

    for (int i = 1; i < 11; i++) {
      if (i > 1) 
        System.out.print(" ");
      System.out.print(fingers[i]);
    }
    System.out.println();
  }
}

class UVa10415 {
  private int test_cases_num;
  private String notes;
  private Saxophone sax;
  final private Scanner sc = new Scanner(System.in);

  public void solve() {
    test_cases_num = sc.nextInt();
    sc.nextLine();
    
    while (sc.hasNextLine()) {
      notes = sc.nextLine();
      sax = new Saxophone(notes);
      sax.print_fingers_usage();
    }
  }
}
