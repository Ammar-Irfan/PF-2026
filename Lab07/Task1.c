#include <stdio.h>

int main() {
    int mat[3][3];
    int trans[3][3];
    int adj[3][3];
    int inv[3][3];
    int cofactors[3][3];
    int det = 0;

    printf("Enter elements of a 3x3 matrix row by row:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &mat[i][j]);
        }
    }

   
    

    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            trans[j][i] = mat[i][j];
        }
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", trans[i][j]);
        }
        printf("\n");
    }

    
    det = 0;
    for (int i = 0; i < 3; i++) {
        det += (mat[0][i] * (mat[1][(i + 1) % 3] * mat[2][(i + 2) % 3] - mat[1][(i + 2) % 3] * mat[2][(i + 1) % 3]));
    }
    printf("Determinant = %d\n", det);

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int r1 = (i + 1) % 3;
            int r2 = (i + 2) % 3;
            int c1 = (j + 1) % 3;
            int c2 = (j + 2) % 3;

            float minor = (mat[r1][c1] * mat[r2][c2]) - (mat[r1][c2] * mat[r2][c1]);

            if ((i + j) % 2 != 0) {
                cofactors[i][j] = -minor;
            } else {
                cofactors[i][j] = minor;
            }
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            adj[i][j] = cofactors[j][i];
        }
    }

    if (det == 0) {
        
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                printf("%d", adj[i][j]);
            }
            printf("\n");
        }
        
        printf("Matrix is singular, inverse does not exist.\n");
    } else {
       
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                printf("%d ", adj[i][j]);
            }
            printf("\n");
        }

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                inv[i][j] = adj[i][j] / det;
            }
        }

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                printf("%d ", inv[i][j]);
            }
            printf("\n");
        }
    }

    return 0;
}