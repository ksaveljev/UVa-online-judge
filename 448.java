import java.util.Scanner;

class Main {
  public static void main(String[] args) {
    (new UVa448()).solve();
  }
}

class Disassembler {
  private int index = 0;
  private String commands;

  public void processCommands(String commands) {
    int sz = commands.length(), opcode, mode, value;
    this.commands = commands;

    while (index < sz) {
      opcode = binToInt(this.commands.substring(index, index + 4));

      index += 4;

      switch (opcode) {
        case 0:
          System.out.println("ADD " + nextOperand() + "," + nextOperand());
          break;
        case 1:
          System.out.println("SUB " + nextOperand() + "," + nextOperand());
          break;
        case 2:
          System.out.println("MUL " + nextOperand() + "," + nextOperand());
          break;
        case 3:
          System.out.println("DIV " + nextOperand() + "," + nextOperand());
          break;
        case 4:
          System.out.println("MOV " + nextOperand() + "," + nextOperand());
          break;
        case 5:
          System.out.println("BREQ " + nextOperand());
          break;
        case 6:
          System.out.println("BRLE " + nextOperand());
          break;
        case 7:
          System.out.println("BRLS " + nextOperand());
          break;
        case 8:
          System.out.println("BRGE " + nextOperand());
          break;
        case 9:
          System.out.println("BRGR " + nextOperand());
          break;
        case 10:
          System.out.println("BRNE " + nextOperand());
          break;
        case 11:
          System.out.println("BR " + nextOperand());
          break;
        case 12:
          System.out.println("AND " + nextOperand() + "," + nextOperand() + "," + nextOperand());
          break;
        case 13:
          System.out.println("OR " + nextOperand() + "," + nextOperand() + "," + nextOperand());
          break;
        case 14:
          System.out.println("XOR " + nextOperand() + "," + nextOperand() + "," + nextOperand());
          break;
        case 15:
          System.out.println("NOT " + nextOperand());
          break;
      }
    }
  }

  private int binToInt(String command) {
    return Integer.parseInt(command, 2);
  }

  private String nextOperand() {
    StringBuilder sb = new StringBuilder();
    int mode = binToInt(commands.substring(index, index + 2));
    index += 2;

    switch (mode) {
      case 0:
        sb.append("R");
        break;
      case 1:
        sb.append("$");
        break;
      case 2:
        sb.append("PC+");
        break;
      case 3:
        break;
    }

    sb.append(binToInt(commands.substring(index, index + 14)));
    index += 14;

    return sb.toString();
  }
}

class UVa448 {
  final private Scanner sc = new Scanner(System.in);
  final private Disassembler dasm = new Disassembler();
  final private String[] hexDigits = {
    "0000", "0001", "0010", "0011",
    "0100", "0101", "0110", "0111",
    "1000", "1001", "1010", "1011",
    "1100", "1101", "1110", "1111",
  };

  public void solve() {
    String input;
    StringBuilder sb = new StringBuilder();

    while (sc.hasNext()) {
      input = sc.next();
      sb.append(input);
    }

    dasm.processCommands(hexToBin(sb.toString()));
  }

  private String hexToBin(String hex) {
    StringBuilder bin = new StringBuilder(hex.length() * 4);

    for (int i = 0, sz = hex.length(); i < sz; i++) {
      int s = Character.digit(hex.charAt(i), 16);
      bin.append(hexDigits[s]);
    }

    return bin.toString();
  }
}
