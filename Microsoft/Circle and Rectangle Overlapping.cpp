// You are given a circle represented as (radius, xCenter, yCenter) and an axis-aligned rectangle represented as (x1, y1, x2, y2), where (x1, y1) are the coordinates of the bottom-left corner, and (x2, y2) are the coordinates of the top-right corner of the rectangle.

// Return true if the circle and rectangle are overlapped otherwise return false. In other words, check if there is any point (xi, yi) that belongs to the circle and the rectangle at the same time.

 

// Example 1:
//         Microsoft/eg.1.1.png

// Input: radius = 1, xCenter = 0, yCenter = 0, x1 = 1, y1 = -1, x2 = 3, y2 = 1
// Output: true
// Explanation: Circle and rectangle share the point (1,0).

// Example 2:

// Input: radius = 1, xCenter = 1, yCenter = 1, x1 = 1, y1 = -3, x2 = 2, y2 = -1
// Output: false

// Example 3:
//         Microsoft/eg.1.3.png

// Input: radius = 1, xCenter = 0, yCenter = 0, x1 = -1, y1 = 0, x2 = 0, y2 = 1
// Output: true
 

// Constraints:

// 1 <= radius <= 2000
// -104 <= xCenter, yCenter <= 104
// -104 <= x1 < x2 <= 104
// -104 <= y1 < y2 <= 104


class Solution {
private:
    // Helper function to calculate the distance between a point (x) and an interval [a1, a2]
    int dist(int a1, int a2, int x) {
        if (x < a1)
            return std::abs(a1 - x);
        if (x > a2)
            return std::abs(x - a2);
        return 0;
    }

public:
    // Function to check if there is an overlap between a circle and a rectangle
    bool checkOverlap(int radius, int x_center, int y_center, int x1, int y1, int x2, int y2) {
        // Calculate the horizontal distance (a) and vertical distance (b) between the circle center and the rectangle
        int a = dist(x1, x2, x_center);
        int b = dist(y1, y2, y_center);

        // Check if the distance squared is less than or equal to the radius squared, indicating an overlap
        // The use of squares avoids the need for square root calculations, improving performance
        return (a * a + b * b) <= (radius * radius);
    }
};