import java.util.*;
import java.io.*;

public class Day3B {
    private static int getDecimal(String s) {
        int n = s.length();  // has to be 12 anyways
        int res = 0;
        for (int c = 0; c < n; c++) if (s.charAt(n-1-c) == '1') {
            res ^= 1<<c;
        }
        return res;
    }
    public static void main(String[] args) throws FileNotFoundException {
        Scanner in = new Scanner(new File("Day3.in"));
        
        final int n = 12;  // binary length
        List<String> arr = new ArrayList<String>();
        while (in.hasNext()) arr.add(in.next());
        
        List<String> a = new ArrayList<String>(arr);
        for (int c = 0; a.size() > 1; c++) {
            List<String> b = new ArrayList<String>();
            for (int i = a.size()-1; i >= 0; i--) {
                String s = a.get(i);
                if (s.charAt(c) == '1') {
                    b.add(s);
                    a.remove(i);
                }
            }
            if (b.size() >= a.size()) a = b;
            if (a.size() == 1) break;
        }
        int o2 = getDecimal(a.get(0));
        
        a = new ArrayList<String>(arr);
        for (int c = 0; a.size() > 1; c++) {
            List<String> b = new ArrayList<String>();
            for (int i = a.size()-1; i >= 0; i--) {
                String s = a.get(i);
                if (s.charAt(c) == '1') {
                    b.add(s);
                    a.remove(i);
                }
            }
            if (b.size() < a.size()) a = b;
        }
        int co2 = getDecimal(a.get(0));
        
        System.out.println(o2*co2);
    }
}
