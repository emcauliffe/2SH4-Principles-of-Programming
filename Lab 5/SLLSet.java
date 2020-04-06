public class SLLSet {
    private int size;
    private SLLNode head;

    public SLLSet() {
        size = 0;
        head = null;
    }

    public SLLSet(int[] sortedArray) {
        size = sortedArray.length;

        for (int i = getSize()-1; i >= 0; i--) {
            head = new SLLNode(sortedArray[i], head); //iterate backwards through the input array and store each value in the new linked list
        }
    }

    public int getSize() {
        return size;
    }

    public SLLSet copy() {
        SLLSet copyArray = new SLLSet();
        SLLNode index = head;
        for (int i = 0; i < getSize(); ++i) {
            copyArray.add(index.value); //add each value of original linked list to the newly created linked list
            index = index.next;
        }
        return copyArray;
    }

    public boolean isIn(int v) {
        SLLNode index = head;
        while(true) {
            if (index == null || v < index.value) {
                return false;//immediately return false if v is passed or if v is not found by end of list
            } else if (v == index.value) { //immediately return true if value is found
                return true;
            }
            index = index.next;
        }
    }

    public void add(int v) {
        if (!isIn(v)) {
            ++size;
            if (head == null) {
                head = new SLLNode(v, null); //add head if initial set is empty
            } else { //using else statement to reduce computation time 
                SLLNode index = head;
                for(int i = 0; i < getSize(); ++i) {
                    if(index.value > v) {
                        int temp = index.value; //swap values of index.value and v
                        index.value = v;
                        v = temp;
                    }
                    if (index.next == null) {
                        index.next = new SLLNode(v, null); //add an extra node if last element is reached
                    } else {
                        index = index.next;
                    }
                }
            }
        }
    }

    public void remove(int v) {
        if (isIn(v)) {
            --size;
            if (size == 0) {
                head = null; //create empty set if only 1 element was present 
            } else { //using else statement to reduce computation time 
                SLLNode index = head;
                for(int i = 0; i < getSize(); ++i) {
                    if (index.value >= v) {
                        index.value = index.next.value;
                    }
                    if (index.next.next == null) { //drop the last element 
                        index.next = null;
                    } else {
                        index = index.next;
                    }
                }
            }
        }
    }

    public SLLSet union(SLLSet s) { //O(n)

        SLLSet unionSet = new SLLSet();
        unionSet.head = new SLLNode(0, null); //we are still within the class definition so we can still access private instances
        unionSet.size = 0;

        SLLNode unionBeginning = unionSet.head;//keeps track of original head location
        
        SLLNode index1 = head;
        SLLNode index2 = s.head;

        while (true) { //loop exits when end of both SLLs are reached 
            if (index1 == null && index2 == null) {
                break;
            } else if (index1 != null && (index2 == null || index1.value < index2.value)) {
                //condition trips if "this" value is less than "s" value and short-circuit prevents null pointer exceptions
                unionSet.head.next = new SLLNode(index1.value, null); //store the next value of the linked list
                unionSet.size++;//increase the size 

                index1 = index1.next; //move to next node in "this" list 
            } else if (index2 != null && (index1 == null || index1.value > index2.value)){
                unionSet.head.next = new SLLNode(index2.value, null);
                unionSet.size++;

                index2 = index2.next;//move to next node in "s" list
            } else { //if both values are the same
                unionSet.head.next = new SLLNode(index1.value, null);
                unionSet.size++;

                index1 = index1.next;//move to next node in both lists as both have the same value
                index2 = index2.next;
            }
            unionSet.head = unionSet.head.next;//move to next node and keep filling in values 
        }

        unionSet.head = unionBeginning.next; //return to beginning of linked list but drop the extra zero   
        return unionSet;
    }

    public SLLSet intersection(SLLSet s) {
        SLLSet intersectionSet = new SLLSet();
        intersectionSet.head = new SLLNode(0, null); //we are still within the class definition so we can still access private instances
        intersectionSet.size = 0;

        SLLNode intersectionBeginning = intersectionSet.head;//keeps track of original head location
        
        SLLNode index1 = head;
        SLLNode index2 = s.head;

        while (true) {
            if (index1 == null || index2 == null) {
                break; //immediately break if the end of a list is reached
            } else if (index1.value < index2.value) {
                index1 = index1.next; //move to next node in "this" list 
            } else if (index1.value > index2.value){
                index2 = index2.next;//move to next node in "s" list
            } else { //if both values are the same
                intersectionSet.head.next = new SLLNode(index1.value, null); //add value to intersection set
                intersectionSet.size++;

                index1 = index1.next;//move to next node in both lists as both have the same value
                index2 = index2.next;
                intersectionSet.head = intersectionSet.head.next;//move to next node and keep filling in values
            } 
        }
        intersectionSet.head = intersectionBeginning.next; //return to beginning of linked list but drop the extra zero   
        return intersectionSet;
    }

    public SLLSet difference(SLLSet s) {
        SLLSet differenceSet = new SLLSet();
        SLLNode index = head;
        for (int i = 0; i < getSize(); i++) {
            if (! s.isIn(index.value)) { //iterate through "this" and check if value is in "s", if it is not then add it to the new differenceSet 
                differenceSet.add(index.value);
            }
            index = index.next;
        }
        return differenceSet;
    }

    public static SLLSet union(SLLSet[] sArray) {
        SLLSet unionSet = new SLLSet();
        for (int i = 0; i < sArray.length; i++) {
            unionSet = unionSet.union(sArray[i]); //update unionSet to "add" result of the union with each element of sArray
        }
        return unionSet;
    }

    public String toString() {
        String returnString = "";
        SLLNode index = head;

        if (index != null) {
            while (index.next != null) {
                returnString += index.value + ", ";
                index = index.next;
            }
            returnString += index.value;//don't add a comma for the last value
        }

        return returnString;
    }
}

class SLLNode {
    int value;
    SLLNode next;
    public SLLNode (int i, SLLNode n) {
        value = i;
        next = n;
    }
}