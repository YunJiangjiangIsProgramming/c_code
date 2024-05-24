#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>



// 定义每个班次所需的护士数量
const int NURSES_PER_SHIFT[6] = { 60, 70, 60, 50, 20, 30 };

// 计算最少需要的护士数量
int calculateMinimumNurses(const std::vector<int>& shiftTimes) {
    int totalNurses = 0;  // 总的护士数量
    int currentNurses = 0; // 当前正在工作的护士数量
    int maxNurses = 0;    // 记录达到过的最大护士数量

    for (int time = 0; time < 24; ++time) {
        // 如果当前时间是上班时间，增加护士数量
        if (time >= shiftTimes[0] && time < shiftTimes[1]) {
            currentNurses += NURSES_PER_SHIFT[0];
        }
        else if (time >= shiftTimes[1] && time < shiftTimes[2]) {
            currentNurses += NURSES_PER_SHIFT[1];
        }
        else if (time >= shiftTimes[2] && time < shiftTimes[3]) {
            currentNurses += NURSES_PER_SHIFT[2];
        }
        else if (time >= shiftTimes[3] && time < shiftTimes[4]) {
            currentNurses += NURSES_PER_SHIFT[3];
        }
        else if (time >= shiftTimes[4] && time < shiftTimes[5]) {
            currentNurses += NURSES_PER_SHIFT[4];
        }
        else if (time >= shiftTimes[5] || time < shiftTimes[0]) {
            currentNurses += NURSES_PER_SHIFT[5];
        }

        // 如果当前时间是下班时间，或者达到8小时工作时间，更新最大护士数量
        if ((time == shiftTimes[1] || time == shiftTimes[2] || time == shiftTimes[3] ||
            time == shiftTimes[4] || time == shiftTimes[5] || time == 24) &&
            currentNurses > maxNurses) {
            maxNurses = currentNurses;
            currentNurses = 0;
        }

        // 如果工作时间达到8小时，重置护士数量
        if (time % 8 == 0 && time != 0) {
            currentNurses = 0;
        }
    }

    // 如果最后一班护士的工作时间没有达到8小时，考虑增加总护士数量
    if (currentNurses > maxNurses) {
        maxNurses = currentNurses;
    }

    return maxNurses;
}

int main() {
    // 定义上班时间点，这里假设是从6点开始，每个班次8小时
    std::vector<int> shiftTimes = { 6, 10, 14, 18, 22, 2 };

    // 计算并输出最少需要的护士数量
    int minimumNurses = calculateMinimumNurses(shiftTimes);
    std::cout << "最少需要的护士数量: " << minimumNurses << std::endl;

    return 0;
}