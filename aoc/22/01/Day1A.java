import java.util.*;
import java.io.*;

public class Day1A {
    public static void main(String args[]) throws FileNotFoundException {
        Scanner in = new Scanner(new File("Day1.in"));

        int res = 0;
        while (in.hasNextLine()) {
            int cnt = 0;
            while (in.hasNextLine()) {
                String s = in.nextLine();
                if (s.isEmpty()) {
                    res = Math.max(res, cnt);
                    break;
                }
                cnt += Integer.parseInt(s);
            }
        }

        System.out.println(res);
    }
}