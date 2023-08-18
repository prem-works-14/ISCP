import java.util.*;

class Student {
    Scanner sc = new Scanner(System.in);
    String rno;
    String name;
    double gpa;
    int age;

    void setRno() {
        rno = sc.next();
    }

    void setName() {
        name = sc.next();
    }

    void setGpa() {
        gpa = sc.nextDouble();
    }

    void setAge() {
        age = sc.nextInt();
    }

    String getRno() {
        return rno;
    }

    String getName() {
        return name;
    }

    double getGpa() {
        return gpa;
    }

    int getAge() {
        return age;
    }
}

class SortByGpa implements Comparator<Student> {
    public int compare(Student a, Student b) {
        if (a.getGpa() < b.getGpa()) {
            return 1;
        } else if (a.getGpa() > b.getGpa()) {
            return -1;
        }
        return 0;
    }
}

public class Main {
    public static void main(String args[]) {
        int n;
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter number of Students: ");
        n = sc.nextInt();
        ArrayList<Student> al = new ArrayList<>();
        System.out.println("Enter Student details:");
        for (int i = 0; i < n; i++) {
            Student s = new Student();
            s.setRno();
            s.setName();
            s.setGpa();
            s.setAge();
            al.add(s);
        }
        Collections.sort(al, new SortByGpa());
        for (int i = 0; i < al.size(); i++)
            System.out.println(al.get(i).getName() + " " + al.get(i).getGpa());
    }
}
