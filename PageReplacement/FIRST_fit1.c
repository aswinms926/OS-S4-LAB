#include <stdio.h>

void main() {
    int n, no, i, j = 0, a[50], frame[50], k, avail = 0, count = 0;

    // Get the number of pages
    printf("Enter the number of pages: ");
    scanf("%d", &n);

    // Get the page numbers
    printf("Enter the page numbers: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    // Get the number of frames
    printf("Enter the number of frames: ");
    scanf("%d", &no);

    // Initialize the frames to -1 to indicate empty
    for (i = 0; i < no; i++) {
        frame[i] = -1;
    }

    // Print header for output
    printf("\nRef_string\t\tFrames\n");

    // Iterate through each page reference
    for (i = 0; i < n; i++) {
        printf("%d\t\t", a[i]);
        avail = 0;

        // Check if the page is already in a frame
        for (k = 0; k < no; k++) {
            if (frame[k] == a[i]) {
                avail = 1;
                break;
            }
        }

        // If the page is not in any frame, replace using FIFO policy
        if (avail == 0) {

            frame[j] = a[i];
            j = (j + 1) % no;
            count++;

            // Print the current state of frames
            for (k = 0; k < no; k++) {
                if (frame[k] != -1) {
                    printf("%d\t", frame[k]);
                } else {
                    printf("-\t");
                }
            }
        }
        else{
            printf("hit\t");
        }
        printf("\n");
    }

    // Print total page faults
    printf("Total page faults: %d\n", count);
}
