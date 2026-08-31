#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <unordered_map>

using namespace std;


class RecentCounter {
public:
    RecentCounter() {
        int counter = 0;
    }

    int ping(int t) {

    }
};


class Solution {

public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        unordered_map <int,int> found;

        for (int i = 0; i < nums.size(); i++) {

            found[nums[i]] = i;

        }

        int l, r;
        for (int i = 0; i < nums.size(); i++) {

            int x = target - nums[i];
            
            if (found.count(x)&& found[x]!=i)
            {
                l = i;
                r = found[x];
               break;
            }
        }

        return { l,r };
    }

    bool isPalindrome(int x) {

        if (x <= 0)
            return false;

        int invX = 0;
        int tempX = x;

        while (tempX != 0) {
            
            invX += tempX % 10;
            invX *= 10;
            tempX /= 10;

        }
        cout << invX;
        return (invX == x);

    }

};
bool isPalindrome(int x) {

    if (x <= 0)
        return false;

    long long  invX = 0;
    long long tempX = x;

    while (tempX != 0) {
        invX *= 10;
        invX += tempX % 10;
     
        tempX /= 10;

    }
   
    return (invX == x);

}

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
    
};


ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

    if (list1 == NULL && list2 == NULL)
        return list1;
    else if (list1 == NULL)
        return list2;
    else if (list2 == NULL)
        return list1;



    int min;

    if (list1->val < list2->val)
    {
        min = list1->val;
        list1 = list1->next;
    }
    else {
        min = list2->val;
        list2 = list2->next;
    }
    
    ListNode* mergedlist = new ListNode(min);
    ListNode* pointer = mergedlist;

    while (list1->next != nullptr && list2->next != nullptr) {

        if (list1->val < list2->val) {
            pointer->next = list1;
            pointer = pointer->next;
            list1 = list1->next;
        }
        else {
            pointer->next = list2;
            pointer = pointer->next;
            list2 = list2->next;
        }

    }

    if (list1 != nullptr) {
        pointer->next = list1;
        pointer = pointer->next;
    }
    else if(list2 != nullptr) {
        pointer->next = list2;
        pointer = pointer->next;
    }



    return mergedlist;

}

int removeDuplicates(vector<int>& nums) {
    if (nums.empty()) {
        return 0;
    }

    // insertIndex tracks where the next unique element should go
    int insertIndex = 1;

    for (int i = 1; i < nums.size(); ++i) {
        //  new unique element
        if (nums[i] != nums[i - 1]) {
            // Put it in the Last next after uniquE position
            nums[insertIndex] = nums[i];

            // Move the insertIndex forward
            insertIndex++;
        }
    }

    return insertIndex;
}

// Same like the prev, two pointers one slow and one fast.
int removeElement(vector<int>& nums, int val) {

  
    int back = 0;

    for (int i = 0; i < nums.size(); i++) {

        if (nums[i] != val) {

            nums[back] = nums[i];

            back++;
        }


    }

    return back;
}




int strStr(string haystack, string needle) {
    /*
 
    bool equal = true;

    for (int i = 0; i < haystack.length(); i++) {

        if (haystack[i] == needle[0]) {
            int iter = i + 1;
            for (int j = 1; j < needle.length(); j++) {

                if (haystack[iter] != needle[j]) {
                    equal = false;
                    break;
                }
                iter++;
            }

            if (equal == true)
                return i; 
            
        }
        equal = true;
    }

    return -1;*/


    // Better answer (LOWER complexity)

    if (needle.length() > haystack.length())
        return -1;

    for (int i = 0; i <= haystack.length() - needle.length(); ++i) {
        if (haystack.substr(i, needle.length()) == needle) {
            return i;
        }
    }
    return -1;

}





int main()
{
  

   cout<< isPalindrome(1234567899);

    return 0;
}