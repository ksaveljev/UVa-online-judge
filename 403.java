import java.util.Scanner;
import java.util.Arrays;

class Main {
  public static void main(String[] args) {
    (new UVa403()).solve();
  }
}

class Paper {
  final private int height, width;
  final private char[][] paper;

  // 5x6 chars
  final private String[] bigchars = {
    ".***..*...*.*****.*...*.*...*.", // A
    "****..*...*.****..*...*.****..", // B
    ".****.*...*.*.....*......****.", // C
    "****..*...*.*...*.*...*.****..", // D
    "*****.*.....***...*.....*****.", // E
    "*****.*.....***...*.....*.....", // F
    ".****.*.....*..**.*...*..***..", // G
    "*...*.*...*.*****.*...*.*...*.", // H
    "*****...*.....*.....*...*****.", // I
    "..***....*.....*..*..*...**...", // J
    "*...*.*..*..***...*..*..*...*.", // K
    "*.....*.....*.....*.....*****.", // L
    "*...*.**.**.*.*.*.*...*.*...*.", // M
    "*...*.**..*.*.*.*.*..**.*...*.", // N
    ".***..*...*.*...*.*...*..***..", // O
    "****..*...*.****..*.....*.....", // P
    ".***..*...*.*...*.*..**..****.", // Q
    "****..*...*.****..*..*..*...*.", // R
    ".****.*......***......*.****..", // S
    "*****.*.*.*...*.....*....***..", // T
    "*...*.*...*.*...*.*...*..***..", // U
    "*...*.*...*..*.*...*.*....*...", // V
    "*...*.*...*.*.*.*.**.**.*...*.", // W
    "*...*..*.*....*....*.*..*...*.", // X
    "*...*..*.*....*.....*.....*...", // Y
    "*****....*....*....*....*****.", // Z
  };

  Paper() {
    this(60, 60);
  }

  Paper(int height, int width) {
    this.height = height;
    this.width = width;

    this.paper = new char[height][width];

    for (char[] row : this.paper)
      Arrays.fill(row, '.');
  }

  @Override
  public String toString() {
    StringBuilder result = new StringBuilder();

    for (char[] row : this.paper)
      result.append(new String(row) + "\n");

    return result.toString();
  }

  public void placeMsg(String msg, int row, int column, String font) {
    if (font.equals("C1")) {
      if (row >= 0 && row < this.height) {
        for (int i = 0, sz = msg.length(); i < sz; i++) {
          if (column + i >= 0 && column + i < this.width && msg.charAt(i) != ' ')
            this.paper[row][column+i] = msg.charAt(i);
        }
      }
    } else if (font.equals("C5")) {
      for (int i = row; i < row + 5; i++) {
        if (i >= this.height) continue;
        for (int j = 0, sz = msg.length(); j < sz; j++) {
          if (msg.charAt(j) == ' ') continue; 
          for (int k = 0; k < 6; k++) {
            if (bigchars[msg.charAt(j) - 'A'].charAt(6 * (i - row) + k) == '.') continue;
            if (column + 6 * j + k >= this.width || column + 6 * j + k < 0) continue;
            this.paper[i][column + 6 * j + k] = bigchars[msg.charAt(j) - 'A'].charAt(6 * (i - row) + k);
          }
        }
      }
    }
  }

  public void rightJustify(String msg, int row, String font) {
    if (font.equals("C1"))
      placeMsg(msg, row, width - msg.length(), font);
    else if (font.equals("C5"))
      placeMsg(msg, row, width - msg.length() * 6, font);
  }

  public void leftJustify(String msg, int row, String font) { 
    placeMsg(msg, row, 0, font);
  }

  public void center(String msg, int row, String font) {
    if (font.equals("C1")) {
      placeMsg(msg, row, this.width / 2 - msg.length() / 2, font);
    } else if (font.equals("C5")) {
      placeMsg(msg, row, this.width / 2 - msg.length() * 6 / 2, font);
    }
  }
}

class UVa403 {
  private Paper paper = new Paper();
  private int row, column;
  private String command, font, msg;
  final private Scanner sc = new Scanner(System.in);

  public void solve() {
    while (sc.hasNext()) {
      command = sc.next();

      if (command.equals(".P")) {
        font = sc.next();
        row = sc.nextInt();
        column = sc.nextInt();
        msg = sc.nextLine().split("\\|")[1];
        paper.placeMsg(msg, row - 1, column - 1, font);
      } else if (command.equals(".L")) {
        font = sc.next();
        column = sc.nextInt();
        msg = sc.nextLine().split("\\|")[1];
        paper.leftJustify(msg, column - 1, font);
      } else if (command.equals(".R")) {
        font = sc.next();
        column = sc.nextInt();
        msg = sc.nextLine().split("\\|")[1];
        paper.rightJustify(msg, column - 1, font);
      } else if (command.equals(".C")) {
        font = sc.next();
        column = sc.nextInt();
        msg = sc.nextLine().split("\\|")[1];
        paper.center(msg, column - 1, font);
      } else if (command.equals(".EOP")) {
        System.out.println(paper);
        for (int i = 0; i < 60; i++)
          System.out.print("-");
        System.out.println();
        System.out.println();
        paper = new Paper();
      }
    }
  }
}
