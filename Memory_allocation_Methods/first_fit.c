#include <stdio.h>

struct Block {
    int id, size, allc;
} B[10];

struct Process {
    int id, size, Blkno;
} P[10];

void main() {
    int m, n, i, j;
    printf("Enter the number of memory blocks: ");
    scanf("%d", &m);
    for (i = 0; i < m; i++) {
        printf("Enter the id and size of block %d : ", i + 1);
        scanf("%d %d", &B[i].id, &B[i].size);
        B[i].allc = -1;
    }

    printf("Enter the number of processes: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("Enter the id and size of process %d : ", i + 1);
        scanf("%d %d", &P[i].id, &P[i].size);
        P[i].Blkno = -1;
    }

    
    for (i = 0; i < n; i++) { 
        for (j = 0; j < m; j++)
         { 
            if (B[j].allc == -1 && B[j].size >= P[i].size) 
            {
                P[i].Blkno = B[j].id; 
                B[j].allc = P[i].id; 
                break; 
            }
        }
    }

    printf("Process\t BlockNo\n"); 
    for (i = 0; i < n; i++) {
        printf("%d\t %d\n", P[i].id, P[i].Blkno); 
    }
}
