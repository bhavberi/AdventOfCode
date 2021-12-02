import java.io.File;
import java.util.ArrayList;
import java.util.Scanner;

public class Main {

    private static final String filename = "Day_1.txt";

    
    public static void part1 (ArrayList<Integer> data) {
        int count = 0;
        for (int i = 1; i < data.size(); i++) if (data.get(i) > data.get(i -1)) count++;
        System.out.println("The depth increased: " + count + " times.");
    }

    public static void part2 (ArrayList<Integer> data) {
        int count = 0;
        for (int i = 2; i < data.size() - 1; i++) { 
            if (data.get(i + 1) > data.get(i - 2)) count++;
        }
        System.out.println("The 3 count window depth increased: " + count + " times.");
    }

    /**
     * Main execution point for the program.
     *
     * @param args The arguments that would be given to this program through command line.
     */
    public static void main (String[] args) {
        try {
            Scanner s = new Scanner(new File(filename));
            ArrayList<Integer> data = new ArrayList<>();
            while (s.hasNextLine()) data.add(Integer.parseInt(s.nextLine()));
            part1(data);
            part2(data);
        } catch (Exception e) {
            System.out.println(e.getMessage());
            for (StackTraceElement se : e.getStackTrace()) System.out.println(se.toString());
        }
    }
}
