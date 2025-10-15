#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int weight;
    int value;
} Item;

int knapsack01(Item items[], int n, int capacity) {
    int i, w;
    int dp[50][50];

    for (i = 0; i <= n; i++) {
        for (w = 0; w <= capacity; w++) {
            if (i == 0 || w == 0) {
                dp[i][w] = 0;
            } 
            else if (items[i - 1].weight <= w) {
                int include = items[i - 1].value + dp[i - 1][w - items[i - 1].weight];
                int exclude = dp[i - 1][w];
                
                dp[i][w] = (include > exclude) ? include : exclude;
            } 
            else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }
    
    return dp[n][capacity];
}

int main() {
    int n, capacity;
    int i;

    printf("Enter number of items: ");
    if (scanf("%d", &n) != 1 || n < 0 || n > 50) {
        printf("Invalid number of items. Exiting.\n");
        return 1;
    }

    Item items[50];
    for (i = 0; i < n; i++) {
        printf("Enter weight and value of item %d: ", i + 1);
        if (scanf("%d %d", &items[i].weight, &items[i].value) != 2) {
            printf("Invalid input for item. Exiting.\n");
            return 1;
        }
    }

    printf("Enter capacity of warehouse: ");
    if (scanf("%d", &capacity) != 1 || capacity < 0 || capacity > 50) {
        printf("Invalid capacity. Exiting.\n");
        return 1;
    }

    int maxValue = knapsack01(items, n, capacity);

    printf("\n--- Warehouse Packing Optimization ---\n");
    printf("Maximum value that can be stored: %d\n", maxValue);
    printf("--------------------------------------\n");

    return 0;
}

