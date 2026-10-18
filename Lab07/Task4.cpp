#include <stdio.h>

int main() {
    int arr[3][3][3];

    printf("Enter elements for the 3x3x3 3D array (27 elements):\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                printf("Element [%d][%d][%d]: ", i, j, k);
                scanf("%d", &arr[i][j][k]);
            }
        }
    }

    int overall_sum = 0;
    int overall_max = arr[0][0][0];
    int overall_min = arr[0][0][0];
    int total_elements = 27;

    for (int i = 0; i < 3; i++) {
        int layer_sum = 0;
        int layer_max = arr[i][0][0];
        int layer_min = arr[i][0][0];

        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                int val = arr[i][j][k];
                layer_sum += val;
                if (val > layer_max) layer_max = val;
                if (val < layer_min) layer_min = val;

                overall_sum += val;
                if (val > overall_max) overall_max = val;
                if (val < overall_min) overall_min = val;
            }
        }

        printf("\n Layer %d Analysis  \n", i + 1);
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                printf("%d ", arr[i][j][k]);
            }
            printf("\n");
        }
        printf("Layer Total = %d\n", layer_sum);
        printf("Layer Average = %d\n", layer_sum / 9.0);
        printf("Layer Maximum = %d\n", layer_max);
        printf("Layer Minimum = %d\n", layer_min);
    }

    printf("\n OVERALL DATA INSIGHTS \n");
    printf("Overall Grand Total = %d\n", overall_sum);
    printf("Overall Grand Average = %d\n", overall_sum / total_elements);
    printf("Overall Maximum Value = %d\n", overall_max);
    printf("Overall Minimum Value = %d\n", overall_min);

    return 0;
}
