import java.util.*;
import java.io.*;

public class Day4B {
    public static void main(String[] args) throws FileNotFoundException {
        Scanner in = new Scanner(new File("Day4.in"));

        int res = 0;
        while (in.hasNext()) {
            String[] cs = in.next().split("-|,");
            int[] arr = new int[cs.length];
            for (int i = 0; i < cs.length; i++) {
                arr[i] = Integer.parseInt(cs[i]);
            }
            if (arr[0] <= arr[2] && arr[2] <= arr[1] || arr[0] <= arr[3] && arr[3] <= arr[1] || arr[2] <= arr[0] && arr[0] <= arr[3] || arr[2] <= arr[1] && arr[1] <= arr[3]) {
                ++res;
            }
        }

        System.out.println(res);
    }
}