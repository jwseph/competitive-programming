import java.util.*;
import java.io.*;

public class Day5A {
    public static void main(String[] args) throws FileNotFoundException {
        Scanner in = new Scanner(new File("Day5.in")).useDelimiter("\\D+");
        
        int grid[][] = new int[1000][1000];
        
        while (in.hasNextInt()) {
            int x1 = in.nextInt();
            int y1 = in.nextInt();
            int x2 = in.nextInt();
            int y2 = in.nextInt();
            if (x1 == x2) {
                if (y1 > y2) {
                    int temp = y1;
                    y1 = y2;
                    y2 = temp;
                }
                int x = x1;
                for (int y = y1; y <= y2; y++) {
                    grid[x][y]++;
                }
            } else if (y1 == y2) {
                if (x1 > x2) {
                    int temp = x1;
                    x1 = x2;
                    x2 = temp;
                }
                int y = y1;
                for (int x = x1; x <= x2; x++) {
                    grid[x][y]++;
                }
            }
        }
        
        int res = 0;
        for (int x = 0; x < 1000; x++) {
            for (int y = 0; y < 1000; y++) {
                if (grid[x][y] >= 2) res++;
            }
        }
        System.out.println(res);
    }
}