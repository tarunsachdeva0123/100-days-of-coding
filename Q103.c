
#include <stdio.h>

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    
    int nums[n];
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }
    
    int totalSum = 0;
    for (int i = 0; i < n; i++) {
        totalSum += nums[i];
    }
    
    int leftSum = 0;
    int pivotIndex = -1;
    
    for (int i = 0; i < n; i++) {
        int rightSum = totalSum - leftSum - nums[i];
        if (leftSum == rightSum) {
            pivotIndex = i;
            break; 
        }
        leftSum += nums[i];
    }
    
    printf("%d\n", pivotIndex);
    
    return 0;
}
