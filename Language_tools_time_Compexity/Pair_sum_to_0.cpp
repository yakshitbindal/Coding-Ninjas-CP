/*Given a random integer array A of size N. Find and print the pair of elements in the array which sum to 0.
Array A can contain duplicate elements.
While printing a pair, print the smaller element first.
That is, if a valid pair is (6, -6) print "-6 6". There is no constraint that out of 5 pairs which have to be printed in 1st line. You can print pairs in any order, just be careful about the order of elements in a pair.
Input format :
Line 1 : Integer N (Array size)
Line 2 : Array elements (separated by space)
Output format :
Line 1 : Pair 1 elements (separated by space)
Line 2 : Pair 2 elements (separated by space)
Line 3 : and so on
Constraints :
1 <= N <= 10^6
Ai contains all non-zero values
Sample Input:
5
2 1 -2 2 3
Sample Output :
-2 2
-2 2*/

#include<bits/stdc++.h>
using namespace std;
void PairSum(int *input, int n){
/*sort(input, input+n);
    int low = 0; 
    int high = n - 1; 
        while (low < high)  
        { 
            if (input[low] + input[high] == 0) 
            { 
                cout << input[low] << " " << input[high] << endl; 
            } 
            if (input[low] + input[high] > 0) 
            { 
                high--; 
            } 
            else 
            { 
                low++; 
            } 
        } 
}*/
    unordered_map<int, int> m; 
    for (int i = 0; i < n; i++) { 
        int rem = - input[i]; 
        if (m.find(rem) != m.end()){ 
            int count = m[rem]; 
            for (int j = 0; j < count; j++){
                if(rem < input[i])
                    cout << rem << " " << input[i] << endl; 
                else
                    cout << input[i] << " " << rem << endl;
            }
        } 
        m[input[i]]++; 
    } 
} 
