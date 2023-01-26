
#include <cmath>

namespace FUN {    
    
    /**
     * Complexity O(log(n))
     * sorted: ascend
     */
    int closer_to_zero_sorted(int ints[], int size){
        if(size <= 0 || ints == nullptr) return -1;
        
        {
            // totologie case for fast end
            int a = ints[0];
            if(a == 0) return a; 
            
            int b = ints[size-1];
            if(b == 0) return b;
            
            if(a > 0 && b > 0) return a;
            if(a < 0 && b < 0) return b;
        }
        
        // dichotomous search for border between negatif and positif number 
        
        // we start from the end so that the end result is on the positif side.
        int index = size-1;
        int size_rest = size-1;
        while (size_rest > 1){
            int midle = index - size_rest/2;
            int value = ints[midle];
            
            // fast end
            // In case of multiple zero, remove if you want the first one
            if(value == 0) return midle;
            
            //greater than OR EQUAL for first zero if needed
            if(value >= 0) index = midle;
            
            size_rest = size_rest/2;
        }
        
        // if negatif side is closer to zero
        if(abs(ints[index]) > abs(ints[index-1])) {
            return index-1; // negatif side
        }
        return index; // positif side
    }
    
    /**
     * Complexity : O(n)
     * 
     */
    int closer_to_zero(int ints[], int size) {
        if(size <= 0 || ints == nullptr) return -1;
        
        int index = 0;
        int abs_best_value = abs(ints[index]);
        
        for(int i = 1; i < size; ++i) {
            int abs_value = abs(ints[i]);
            if(abs_value < abs_best_value 
                || ( abs_value == abs_best_value && ints[index] < 0 )) {
                index = i;
                abs_best_value = abs(ints[index]);
                if(abs_best_value == 0) break;
            }
        }
        
        return index;
    }   
}

#include <iostream>
#include <string>

namespace FUN_TEST {
// Example program
    int Test_closer_to_zero()
    {
        int test[] = {10, -8, 7, -2, 3, 2, 3}; 
        int rep = FUN::closer_to_zero(test, 7);
        std::cout << rep << std::endl;
        std::cout << test[rep] << std::endl;
        
        int test2[] = {-10, -5, -5, -4, -4, -1, 0, 0, 7, 11};
        rep = FUN::closer_to_zero_sorted(test2, 10);
        std::cout << rep << std::endl;
        std::cout << test2[rep] << std::endl;
    
    
        return 0;
    }
}

int main()
{
    FUN_TEST::Test_closer_to_zero();
}
