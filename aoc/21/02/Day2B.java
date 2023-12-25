import java.util.*;
import java.io.*;

public class Day2B {
    public static void main(String[] args) throws FileNotFoundException {
        Scanner in = new Scanner(new File("Day2.in"));
        
        int x = 0, y = 0, a = 0;
        while (in.hasNext()) {
            String s = in.next();
            int d = in.nextInt();
            if (s.equals("forward")) y += a*((x += d)-x+d);
            else if (s.equals("down")) a += d;
            else if (s.equals("up")) a -= d;
        }
        
        System.out.println(x*y);
    }
}
