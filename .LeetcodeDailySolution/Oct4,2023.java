import java.util.ArrayList;
import java.util.List;

class MyHashMap {

private static final int SIZE = 1000;
private List<List<int[]>> data;

public MyHashMap() {
    data = new ArrayList<>(SIZE);
    for (int i = 0; i < SIZE; i++) {
        data.add(new ArrayList<>());
    }
}

private int getIndex(int key) {
    return Integer.hashCode(key) % SIZE;
}

public void put(int key, int value) {
    int index = getIndex(key);
    for (int[] entry : data.get(index)) {
        if (entry[0] == key) {
            entry[1] = value;
            return;
        }
    }
    data.get(index).add(new int[]{key, value});
}

public int get(int key) {
    int index = getIndex(key);
    for (int[] entry : data.get(index)) {
        if (entry[0] == key) {
            return entry[1];
        }
    }
    return -1;
}

public void remove(int key) {
    int index = getIndex(key);
    List<int[]> entries = data.get(index);
    for (int i = 0; i < entries.size(); i++) {
        if (entries.get(i)[0] == key) {
            entries.remove(i);
            return;
        }
    }
  }
}

public class Main {
  public static void main(String[] args) {
    MyHashMap myHashMap = new MyHashMap();
    myHashMap.put(1, 1);
    myHashMap.put(2, 2);
    System.out.println(myHashMap.get(1)); 
    System.out.println(myHashMap.get(3)); 
    myHashMap.put(2, 1);
    System.out.println(myHashMap.get(2)); 
    myHashMap.remove(2);
    System.out.println(myHashMap.get(2)); 
  }
}
