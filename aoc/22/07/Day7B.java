import java.util.*;
import java.io.*;

public class Day7B {
    private static Scanner in;
    private static List<Integer> sizes = new ArrayList<>();
    private static int dfs() {
        for (int i = 0; i < 4; i++) in.next();
        int size = 0, n = 0;
        for (String s = in.next(); !s.equals("$"); s = in.next()) {
            if (s.equals("dir")) {
                n++;
            } else {
                size += Integer.parseInt(s);
            }
            in.next();
            if (!in.hasNext()) break;
        }
        while (n --> 0) size += dfs();
        sizes.add(size);
        if (in.hasNext()) for (int i = 0; i < 3; i++) in.next();
        return size;
    }
    public static void main(String[] args) throws FileNotFoundException {
        in = new Scanner(new File("Day7.in"));
        in.next();
        int rootSize = dfs();
        int res = Integer.MAX_VALUE;
        for (int size: sizes) {
            if (rootSize-size <= 40000000) {
                res = Math.min(res, size);
            }
        }
        System.out.println(res);
    }
}