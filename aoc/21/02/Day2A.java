import java.util.*;
import java.io.*;

public class Day2A {
    public static void main(String[] args) throws FileNotFoundException {
        Scanner in = new Scanner(new File("Day2.in"));
        
        int x = 0, y = 0;
        while (in.hasNext()) {
            String s = in.next();
            int d = in.nextInt();
            if (s.equals("forward")) x += d;
            else if (s.equals("down")) y += d;
            else if (s.equals("up")) y -= d;
        }
        
        System.out.println(x*y);
    }
}
