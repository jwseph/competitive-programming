import java.util.*;
import java.io.*;

public class Day5B {
    public static void main(String[] args) throws FileNotFoundException {
        Scanner in = new Scanner(new File("Day5.in")).useDelimiter("\\D+");
        
        int grid[][] = new int[1000][1000];
        
        while (in.hasNextInt()) {
            int x1 = in.nextInt();
            int y1 = in.nextInt();
            int x2 = in.nextInt();
            int y2 = in.nextInt();
            int dx = (x1 < x2 ? 1 : x1 > x2 ? -1 : 0);
            int dy = (y1 < y2 ? 1 : y1 > y2 ? -1 : 0);
            for (int x = x1, y = y1; x != x2 || y != y2; ) {
                grid[x][y]++;
                x += dx;
                y += dy;
            }
            grid[x2][y2]++;
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