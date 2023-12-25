import java.util.*;
import java.io.*;

public class Day5B {
    public static void main(String[] args) throws FileNotFoundException {
        Scanner in = new Scanner(new File("Day5.in"));

        List<String> lines = new ArrayList<>();
        for (String s = in.nextLine(); !s.isEmpty(); s = in.nextLine()) {
            lines.add(s);
        }
        lines.remove(lines.size()-1);

        int n = (lines.get(0).length()+1)/4;
        List<Stack<Character>> arr = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            Stack<Character> s = new Stack<>();
            arr.add(s);
            int c = 1+4*i;
            for (int l = lines.size()-1; l >= 0 && lines.get(l).charAt(c) != ' '; l--) {
                s.push(lines.get(l).charAt(c));
            }
        }

        while (in.hasNextLine()) {
            in.next();
            int k = in.nextInt();
            in.next();
            int f_i = in.nextInt()-1;
            in.next();
            int t_i = in.nextInt()-1;
            Stack<Character> r = new Stack<>();
            while (k --> 0) {
                r.push(arr.get(f_i).pop());
            }
            while (!r.empty()) arr.get(t_i).push(r.pop());
        }

        String res = "";
        for (Stack<Character> s: arr) res += s.pop();
        System.out.println(res);
    }
}