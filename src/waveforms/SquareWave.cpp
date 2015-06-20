#include <iostream>

#include <unistd.h>
#include <time.h>

#include "../timers.h"

#include "SquareWave.h"
SquareWave::SquareWave(unsigned int lowDuration, unsigned int highDuration)
{
    SetDuration(0);
    SetLowDuration(lowDuration);
    SetHighDuration(highDuration);
}

SquareWave::~SquareWave()
{
}

void SquareWave::Generate()
{
    struct timespec start;
    struct timespec now;
    struct timespec durationStart;
    bool activeHigh = false;
    bool doGenerateInfinitely = (_duration == 0);

    clock_gettime(CLOCK_MONOTONIC, &start);
    clock_gettime(CLOCK_MONOTONIC, &durationStart);

    while (true) {
        clock_gettime(CLOCK_MONOTONIC, &now);

        if (!doGenerateInfinitely && (diff_micro(&start, &now) > _duration)) {
            break;
        }

        if ((activeHigh && (diff_micro(&durationStart, &now) > _highDuration)) ||
            (!activeHigh && (diff_micro(&durationStart, &now) > _lowDuration))) {
            activeHigh = !activeHigh;
            clock_gettime(CLOCK_MONOTONIC, &durationStart);
        }

        if (activeHigh) {
            std::cout << "1" << std::endl;
        } else {
            std::cout << "0" << std::endl;
        }


    }
}
