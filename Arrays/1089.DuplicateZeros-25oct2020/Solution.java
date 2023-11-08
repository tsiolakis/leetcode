class Solution {
    public void duplicateZeros(int[] arr) {
        Queue<Integer> q = new LinkedList<>();

        for (int i = 0; i < arr.length; i++)
            if (arr[i] == 0) {q.add(i);}

        if (q.size() == 0) { return;} //q.size() is number of zeroes
        int[] copy = new int[arr.length];
        q.add(arr.length); //adding arr.length to the queue so the loop continues normally till the array is complete
        int cut = q.remove();
        int diff = 0; //everytime a zero is duplicated diff is raised by one

        for (int i = 0;i < arr.length; i++) {
            if (i <= cut) {
                copy[i] = arr[i - diff];
                continue;
            }
            copy[i] = 0;
            diff += 1;
            cut = q.remove() + diff;
        }

        for (int i = 0;i < arr.length; i++) {
            arr[i] = copy[i];
        }
    }
}
