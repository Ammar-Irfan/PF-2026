#include <stdio.h>

int main() {
    int arr[3][3][3];

    printf("Enter integer elements for the 3x3x3 3D array (27 elements):\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                printf("Element [%d][%d][%d]: ", i, j, k);
                scanf("%d", &arr[i][j][k]);
            }
        }
    }

    printf("\n DISPLAYING ALL LAYERS \n");
    for (int i = 0; i < 3; i++) {
        printf("\nLayer %d:\n", i + 1);
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                printf("%6d ", arr[i][j][k]);
            }
            printf("\n");
        }
    }

    printf("\n LAYER SIMILARITY ANALYSIS \n");
    for (int i = 0; i < 3; i++) {
        for (int l = i + 1; l < 3; l++) {
            int identical = 1;
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    if (arr[i][j][k] != arr[l][j][k]) {
                        identical = 0;
                    }
                }
            }
            printf("Comparison between Layer %d and Layer %d: ", i + 1, l + 1);
            if (identical) {
                printf("Identical\n");
            } else {
                printf("Distinct\n");
            }
        }
    }

    return 0;
}
