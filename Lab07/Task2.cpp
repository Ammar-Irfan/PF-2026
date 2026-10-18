#include <stdio.h>

int main() {
    int rows, cols;
    printf("Enter rows (up to 5): ");
    scanf("%d", &rows);
    printf("Enter columns (up to 5): ");
    scanf("%d", &cols);

    float mat[5][5];
    printf("Enter elements of the matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%f", &mat[i][j]);
        }
    }

    printf("\nMatrix Types Analysis:\n");

    int is_square = (rows == cols);
    int is_rectangular = (rows != cols);
    int is_zero = 1;
    int is_row = (rows == 1);
    int is_col = (cols == 1);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (mat[i][j] != 0) {
                is_zero = 0;
            }
        }
    }

    if (is_square) printf("Square Matrix\n");
    if (is_rectangular) printf("Rectangular Matrix\n");
    if (is_zero) {
        printf("Zero Matrix\n");
        printf("Null Matrix\n");
    }
    if (is_row) printf("Row Matrix\n");
    if (is_col) printf("Column Matrix\n");

    if (is_square) {
        int is_identity = 1;
        int is_diagonal = 1;
        int is_scalar = 1;
        int is_upper = 1;
        int is_lower = 1;
        int is_symmetric = 1;
        int is_skew = 1;

        float first_diag = mat[0][0];
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (i == j) {
                    if (mat[i][j] != 1) is_identity = 0;
                    if (mat[i][j] != first_diag) is_scalar = 0;
                } else {
                    if (mat[i][j] != 0) {
                        is_identity = 0;
                        is_diagonal = 0;
                        is_scalar = 0;
                    }
                }
                if (i > j && mat[i][j] != 0) is_upper = 0;
                if (i < j && mat[i][j] != 0) is_lower = 0;
                if (mat[i][j] != mat[j][i]) is_symmetric = 0;
                if (i == j && mat[i][j] != 0) is_skew = 0;
                if (i != j && mat[i][j] != -mat[j][i]) is_skew = 0;
            }
        }

        if (is_identity) printf("Identity Matrix\n");
        if (is_diagonal) printf("Diagonal Matrix\n");
        if (is_scalar && !is_zero) printf("Scalar Matrix\n");
        if (is_upper) printf("Upper Triangular Matrix\n");
        if (is_lower) printf("Lower Triangular Matrix\n");
        if (is_symmetric) printf("Symmetric Matrix\n");
        if (is_skew) printf(" Skew-Symmetric Matrix\n");

        float temp[5][5];
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                temp[i][j] = mat[i][j];
            }
        }
        float det = 1.0;
        for (int i = 0; i < rows; i++) {
            int pivot = i;
            for (int k = i + 1; k < rows; k++) {
                float val_k = (temp[k][i] < 0 ? -temp[k][i] : temp[k][i]);
                float val_p = (temp[pivot][i] < 0 ? -temp[pivot][i] : temp[pivot][i]);
                if (val_k > val_p) {
                    pivot = k;
                }
            }
            if (pivot != i) {
                for (int j = 0; j < cols; j++) {
                    float t = temp[i][j];
                    temp[i][j] = temp[pivot][j];
                    temp[pivot][j] = t;
                }
                det = -det;
            }
            float diag_val = (temp[i][i] < 0 ? -temp[i][i] : temp[i][i]);
            if (diag_val < 1e-9) {
                det = 0;
                break;
            }
            det *= temp[i][i];
            for (int k = i + 1; k < rows; k++) {
                float factor = temp[k][i] / temp[i][i];
                for (int j = i; j < cols; j++) {
                    temp[k][j] -= factor * temp[i][j];
                }
            }
        }

        float det_abs = (det < 0 ? -det : det);
        if (det_abs < 1e-9) {
            printf("Singular Matrix\n");
        } else {
            printf("Non-Singular Matrix\n");
        }

        float prod[5][5];
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                prod[i][j] = 0;
                for (int k = 0; k < rows; k++) {
                    prod[i][j] += mat[i][k] * mat[k][j];
                }
            }
        }
        int is_idempotent = 1;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                float diff = prod[i][j] - mat[i][j];
                if ((diff < 0 ? -diff : diff) > 1e-5) {
                    is_idempotent = 0;
                }
            }
        }
        if (is_idempotent) printf("Idempotent Matrix\n");

        float current_pow[5][5];
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                current_pow[i][j] = mat[i][j];
            }
        }
        int is_nilpotent = 0;
        for (int p = 1; p <= rows; p++) {
            int all_zero = 1;
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    float cur_val = (current_pow[i][j] < 0 ? -current_pow[i][j] : current_pow[i][j]);
                    if (cur_val > 1e-5) {
                        all_zero = 0;
                    }
                }
            }
            if (all_zero) {
                is_nilpotent = 1;
                break;
            }
            if (p < rows) {
                float next_pow[5][5];
                for (int i = 0; i < rows; i++) {
                    for (int j = 0; j < cols; j++) {
                        next_pow[i][j] = 0;
                        for (int k = 0; k < rows; k++) {
                            next_pow[i][j] += current_pow[i][k] * mat[k][j];
                        }
                    }
                }
                for (int i = 0; i < rows; i++) {
                    for (int j = 0; j < cols; j++) {
                        current_pow[i][j] = next_pow[i][j];
                    }
                }
            }
        }
        if (is_nilpotent) printf("Nilpotent Matrix\n");
    }

    char choice;
    printf("Do you want to compare with a second matrix for Equal Matrix check? (y/n): ");
    scanf(" %c", &choice);
    if (choice == 'y' || choice == 'Y') {
        int r2, c2;
        printf("Enter rows and columns for second matrix: ");
        scanf("%d %d", &r2, &c2);
        float mat2[5][5];
        printf("Enter elements of second matrix:\n");
        for (int i = 0; i < r2; i++) {
            for (int j = 0; j < c2; j++) {
                scanf("%f", &mat2[i][j]);
            }
        }
        int is_equal = (rows == r2 && cols == c2);
        if (is_equal) {
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    float diff = mat[i][j] - mat2[i][j];
                    if ((diff < 0 ? -diff : diff) > 1e-5) {
                        is_equal = 0;
                    }
                }
            }
        }
        if (is_equal) {
            printf("Equal Matrix\n");
        } else {
            printf("Not Equal Matrices\n");
        }
    }

    return 0;
}