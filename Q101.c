#include <stdio.h>

int main() {
    int n, target;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    
    int nums[n];
    printf("Enter %d sorted elements:\n", n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }
    
    printf("Enter target: ");
    scanf("%d", &target);
    
    int first = -1, last = -1;
    
    for(int i = 0; i < n; i++) {
        if(nums[i] == target) {
            first = i;
            break;
        }
    }
    
    for(int i = n - 1; i >= 0; i--) {
        if(nums[i] == target) {
            last = i;
            break;
        }
    }
    
    printf("%d,%d\n", first, last);
    
    return 0;
}