import java.util.*;
import java.io.*;

public class Day10A {
    public static void main(String[] args) throws FileNotFoundException {
        Scanner in = new Scanner(new File("Day10.in"));

        int cycle = 1, x = 1, res = 0;
        while (in.hasNext()) {
            cycle++;
            if ((cycle+20)%40 == 0) res += cycle*x; 
            if (in.next().equals("addx")) {
                x += in.nextInt();
                cycle++;
                if ((cycle+20)%40 == 0) res += cycle*x; 
            }
        }
        System.out.println(res);
    }
}