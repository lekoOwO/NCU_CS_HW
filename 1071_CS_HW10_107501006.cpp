#include <iostream>
#include <algorithm>
#include <numeric>

using Box = float[3];
const Box box1 = {31, 22.8, 10.3};
const Box box2 = {23, 18, 19};
const Box box3 = {39.5, 27.5, 23};
const Box box4 = {10, 10, 62.5};

int fit(const Box container, const Box object){
    int maxValue = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++){
            int leftIndexs[3] = {0, 1, 2};
            std::remove_if(leftIndexs, leftIndexs + 3, [i](int a) { return a == i; });

            int firstStep[3] = {static_cast<int>(container[0] / object[i]),
                                static_cast<int>(container[1] / object[leftIndexs[j]]),
                                static_cast<int>(container[2] / object[leftIndexs[1-j]])};
            int current = std::accumulate(firstStep, firstStep + 3, 1, [](auto a, auto b) { return a * b; });
            if (!current) continue;

            float left[3] = {container[0] - object[i] * firstStep[0],
                             container[1] - object[leftIndexs[j]] * firstStep[1],
                             container[2] - object[leftIndexs[1-j]] * firstStep[2]};

            for (int k = 0; k < 3; k++){
                if (left[k] >= *std::min_element(object, object + 3)){
                    Box leftbox;
                    std::copy(container, container + 3, leftbox);
                    leftbox[k] = left[k];
                    current += fit(leftbox, object);
                    }
                }
            if (current > maxValue)
                maxValue = current;
        }
    }
    return maxValue;
}

int main(){
    float x, y, z;
    std::string boxType;
    const Box *box;
    std::cout << "Container slides (using cm): ";
    std::cin >> x >> y >> z;
    std::cout << "Box type: ";
    std::cin >> boxType;
    if (boxType == "box1") box = &box1;
    else if (boxType == "box2") box = &box2;
    else if (boxType == "box3") box = &box3;
    else if (boxType == "box4") box = &box4;
    else {
        std::cout << "Error!\n";
        return 0;
    }

    int count = fit(Box{x, y, z}, *box);
    
    std::cout << "The maximum number of " << boxType << ": " << count << std::endl;
    std::cout << "Their occupied volume: " << count * std::accumulate(*box, (*box) + 3, 1, [](auto a, auto b) { return a * b; }) << " cm3\n";
    return 0;
}