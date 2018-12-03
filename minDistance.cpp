#include <algorithm>
#include <functional>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

const int INFINITY = numeric_limits<int>::max();

int main(void) {
    // init
    int pointCount, lineCount, startPoint, destPoint;
    cin >> pointCount >> lineCount >> startPoint >> destPoint;
    vector<vector<int>> pointDistanceMatrix(pointCount,
                                            vector<int>(pointCount, INFINITY));
    vector<int> minDistanceMatrix(pointCount, INFINITY);
    vector<int> points(pointCount);
    iota(points.begin(), points.end(), 0);
    for (int i = 0; i < lineCount; i++) {
        int tempStartPoint, tempDestPoint, tempDis;
        cin >> tempStartPoint >> tempDestPoint >> tempDis;
        pointDistanceMatrix[tempStartPoint - 1][tempDestPoint - 1] = tempDis;
    }
    minDistanceMatrix[startPoint - 1] = 0;

    auto p = startPoint - 1;
    while (size(points) != 0) {
        for (int i = 0; i < pointCount; i++) {
            if (pointDistanceMatrix[p][i] == INFINITY) {
                continue;
            }
            if (minDistanceMatrix[i] == INFINITY ||
                pointDistanceMatrix[p][i] + minDistanceMatrix[p] <
                    minDistanceMatrix[i]) {
                minDistanceMatrix[i] =
                    pointDistanceMatrix[p][i] + minDistanceMatrix[p];
            }
        }
        points.erase(std::remove(points.begin(), points.end(), p),
                     points.end());

        int temp = INFINITY;
        for (auto e : points) {
            if (minDistanceMatrix[e] < temp) {
                temp = minDistanceMatrix[e];
                p    = e;
            }
        }
    }

    cout << "Distance: " << minDistanceMatrix[destPoint - 1];
    return 0;
}
