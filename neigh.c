#include <stdio.h>
#include <stdlib.h>

// Structure representing a point in the grid
struct Point {
    int x, y;
    struct Point* up;
    struct Point* right;
    struct Point* down;
    struct Point* left;
};

// Function to create a new point
struct Point* createPoint(int x, int y) {
    struct Point* newPoint = (struct Point*)malloc(sizeof(struct Point));
    newPoint->x = x;
    newPoint->y = y;
    newPoint->up = NULL;
    newPoint->right = NULL;
    newPoint->down = NULL;
    newPoint->left = NULL;
    return newPoint;
}

// Function to link neighboring points
void linkNeighbors(struct Point* current, struct Point* right, struct Point* down) {
    current->right = right;
    current->down = down;
    if (right != NULL) {
        right->left = current;
    }
    if (down != NULL) {
        down->up = current;
    }
}

// Function to perform some operation on a point and its neighbors
void performOperation(struct Point* point) {
    // Your operation code here
    printf("Performing operation on point (%d, %d) and its neighbors.\n", point->x, point->y);
}

int main() {
    // Create a 3x3 grid
    struct Point* p00 = createPoint(0, 0);
    struct Point* p01 = createPoint(1, 0);
    struct Point* p02 = createPoint(2, 0);
    struct Point* p10 = createPoint(0, 1);
    struct Point* p11 = createPoint(1, 1);
    struct Point* p12 = createPoint(2, 1);
    struct Point* p20 = createPoint(0, 2);
    struct Point* p21 = createPoint(1, 2);
    struct Point* p22 = createPoint(2, 2);

    // Link neighbors
    linkNeighbors(p00, p01, p10);
    linkNeighbors(p01, p02, p11);
    linkNeighbors(p02, NULL, p12);
    linkNeighbors(p10, p11, p20);
    linkNeighbors(p11, p12, p21);
    linkNeighbors(p12, NULL, p22);
    linkNeighbors(p20, p21, NULL);
    linkNeighbors(p21, p22, NULL);
    linkNeighbors(p22, NULL, NULL);

    // Perform operation on a point and its neighbors
    performOperation(p11);

    // Clean up memory (free allocated memory)
    free(p00); free(p01); free(p02);
    free(p10); free(p11); free(p12);
    free(p20); free(p21); free(p22);

    return 0;
}