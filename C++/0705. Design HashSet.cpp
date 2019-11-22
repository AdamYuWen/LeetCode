/* Design a HashSet without using any built-in hash table libraries.
 * To be specific, your design should include these functions:
 * add(value): Insert a value into the HashSet. 
 * contains(value) : Return whether the value exists in the HashSet or not.
 * remove(value): Remove a value in the HashSet. If the value does not exist in the HashSet, do nothing.
 * Example:
 * MyHashSet hashSet = new MyHashSet();
 * hashSet.add(1);         
 * hashSet.add(2);         
 * hashSet.contains(1);    // returns true
 * hashSet.contains(3);    // returns false (not found)
 * hashSet.add(2);          
 * hashSet.contains(2);    // returns true
 * hashSet.remove(2);          
 * hashSet.contains(2);    // returns false (already removed)
 * Note:
 * All values will be in the range of [0, 1000000].
 * The number of operations will be in the range of [1, 10000].
 * Please do not use the built-in HashSet library.
 * https://leetcode.com/problems/design-hashset/description/
 *
 * Author: Adam Yu Wen
 * Date: August 20, 2018
 */

// Method 1:
// It takes 244 ms, which is slow.
class MyHashSet {
public:
    /** Initialize your data structure here. */
    MyHashSet() {
        
    }
    
    void add(int key) {
        int listSize = list.size();
        for (int i = 0; i < listSize; i++) {
            if (list[i] == key) {
                return;
            }
        }
        list.push_back(key);
    }
    
    void remove(int key) {
        int listSize = list.size();
        for (int i = 0; i < listSize; i++) {
            if (list[i] == key) {
                list.erase(list.begin() + i);
            }
        }
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        int listSize = list.size();
        for (int i = 0; i < listSize; i++) {
            if (list[i] == key) {
                return true;
            }
        }
        return false;
    }
    
private:
    vector<int> list;
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet obj = new MyHashSet();
 * obj.add(key);
 * obj.remove(key);
 * bool param_3 = obj.contains(key);
 */


// Method 2:
class MyHashSet {
public:
    /** Initialize your data structure here. */
    MyHashSet() {
        list = vector<int> (1000001, false);
    }
    
    void add(int key) {
        list[key] = true;
    }
    
    void remove(int key) {
        list[key] = false;
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        return list[key];
    }

private:
    vector<int> list;
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet obj = new MyHashSet();
 * obj.add(key);
 * obj.remove(key);
 * bool param_3 = obj.contains(key);
 */
