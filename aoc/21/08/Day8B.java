import java.util.*;
import java.io.*;

public class Day8B {
    public static final Map<String, Integer> key = new HashMap<String, Integer>();
    static {
        key.put("abcefg", 0);
        key.put("cf", 1);
        key.put("acdeg", 2);
        key.put("acdfg", 3);
        key.put("bcdf", 4);
        key.put("abdfg", 5);
        key.put("abdefg", 6);
        key.put("acf", 7);
        key.put("abcdefg", 8);
        key.put("abcdfg", 9);
    }
    public static void main(String[] args) throws FileNotFoundException {
        Scanner in = new Scanner(new File("Day8.in"));
        
        int res = 0;
        while (in.hasNext()) {
            String _in[] = in.nextLine().split(" \\| ");
            int a[] = new int[7];
            List<Character> _1 = new ArrayList<Character>(), _4 = new ArrayList<Character>();
            for (String s: _in[0].split(" ")) {
                for (char c: s.toCharArray()) a[c-'a']++;
                if (s.length() == 2) for (char c: s.toCharArray()) _1.add(c);
                if (s.length() == 4) for (char c: s.toCharArray()) _4.add(c);
            }
            Map<Character, Character> hash = new HashMap<Character, Character>();
            List<Character> _7 = new ArrayList<Character>(), _8 = new ArrayList<Character>();
            for (int i = 0; i < 7; i++) {
                char c = (char)(i+'a');
                switch (a[i]) {
                    case 6: hash.put('b', c); break;
                    case 4: hash.put('e', c); break;
                    case 9: hash.put('f', c); break;
                    case 7: _7.add(c); break;
                    case 8: _8.add(c); break;
                }
            }
            _1.remove(hash.get('f'));
            hash.put('c', _1.get(0));
            _4.remove(hash.get('b'));
            _4.remove(hash.get('c'));
            _4.remove(hash.get('f'));
            hash.put('d', _4.get(0));
            _7.remove(hash.get('d'));
            hash.put('g', _7.get(0));
            _8.remove(hash.get('c'));
            hash.put('a', _8.get(0));
            Map<Character, Character> decode = new HashMap<Character, Character>();
            for (Map.Entry<Character, Character> entry: hash.entrySet()) {
                decode.put(entry.getValue(), entry.getKey());
            }
            int num = 0;
            for (String s: _in[1].split(" ")) {
                char cs[] = new char[s.length()];
                for (int i = 0; i < s.length(); i++) {
                    cs[i] = decode.get(s.charAt(i));
                }
                Arrays.sort(cs);
                num = num*10+key.get(new String(cs));
            }
            res += num;
        }
        
        System.out.println(res);
    }
}
