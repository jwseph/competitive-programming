import java.util.*;
import java.io.*;

public class Day10B {
    public static void main(String[] args) throws FileNotFoundException {
        Scanner in = new Scanner(new File("Day10.in"));

        int cycle = 1, x = 1;
        char[] res = new String(new char[240]).replace('\0', '.').toCharArray();
        res[0] = '#';
        while (in.hasNext()) {
            cycle++;
            if (Math.abs(x-(cycle-1)%40) <= 1) res[cycle-1] = '#';
            if (in.next().equals("addx")) {
                x += in.nextInt();
                cycle++;
                if (Math.abs(x-(cycle-1)%40) <= 1) res[cycle-1] = '#';
            }
        }
        for (int i = 0; i < res.length; i++) {
            System.out.print(res[i]);
            if ((i+1)%40 == 0) System.out.println();
        }
    }
}