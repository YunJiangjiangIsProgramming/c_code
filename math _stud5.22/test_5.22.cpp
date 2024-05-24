#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>



// ����ÿ���������Ļ�ʿ����
const int NURSES_PER_SHIFT[6] = { 60, 70, 60, 50, 20, 30 };

// ����������Ҫ�Ļ�ʿ����
int calculateMinimumNurses(const std::vector<int>& shiftTimes) {
    int totalNurses = 0;  // �ܵĻ�ʿ����
    int currentNurses = 0; // ��ǰ���ڹ����Ļ�ʿ����
    int maxNurses = 0;    // ��¼�ﵽ�������ʿ����

    for (int time = 0; time < 24; ++time) {
        // �����ǰʱ�����ϰ�ʱ�䣬���ӻ�ʿ����
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

        // �����ǰʱ�����°�ʱ�䣬���ߴﵽ8Сʱ����ʱ�䣬�������ʿ����
        if ((time == shiftTimes[1] || time == shiftTimes[2] || time == shiftTimes[3] ||
            time == shiftTimes[4] || time == shiftTimes[5] || time == 24) &&
            currentNurses > maxNurses) {
            maxNurses = currentNurses;
            currentNurses = 0;
        }

        // �������ʱ��ﵽ8Сʱ�����û�ʿ����
        if (time % 8 == 0 && time != 0) {
            currentNurses = 0;
        }
    }

    // ������һ�໤ʿ�Ĺ���ʱ��û�дﵽ8Сʱ�����������ܻ�ʿ����
    if (currentNurses > maxNurses) {
        maxNurses = currentNurses;
    }

    return maxNurses;
}

int main() {
    // �����ϰ�ʱ��㣬��������Ǵ�6�㿪ʼ��ÿ�����8Сʱ
    std::vector<int> shiftTimes = { 6, 10, 14, 18, 22, 2 };

    // ���㲢���������Ҫ�Ļ�ʿ����
    int minimumNurses = calculateMinimumNurses(shiftTimes);
    std::cout << "������Ҫ�Ļ�ʿ����: " << minimumNurses << std::endl;

    return 0;
}