import java.util.*;
import java.io.*;

public class Day1B {
    public static void main(String args[]) throws FileNotFoundException {
        Scanner in = new Scanner(new File("Day1.in"));

        TreeSet<Integer> top = new TreeSet<>();
        while (in.hasNextLine()) {
            int cnt = 0;
            while (in.hasNextLine()) {
                String s = in.nextLine();
                if (s.isEmpty()) {
                    top.add(cnt);
                    if (top.size() > 3) top.pollFirst();
                    break;
                }
                cnt += Integer.parseInt(s);
            }
        }

        int res = 0;
        for (int cnt: top) res += cnt;
        System.out.println(res);
    }
}