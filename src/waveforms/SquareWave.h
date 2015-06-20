#pragma once

class SquareWave
{
public:
    SquareWave(unsigned int lowDuration = 1000000, unsigned int highDuration = 1000000);
    virtual ~SquareWave();

    void Generate();

    void SetDuration(unsigned int duration) { _duration = duration; }
    unsigned int GetDuration() { return _duration; }
    void SetLowDuration(unsigned int duration) { _lowDuration = duration; }
    unsigned int GetLowDuration() { return _lowDuration; }
    void SetHighDuration(unsigned int duration) { _highDuration = duration; }
    unsigned int GetHighDuration() { return _highDuration; }

private:
    unsigned int _duration; // microseconds
    unsigned int _lowDuration; // microseconds
    unsigned int _highDuration; // microseconds
};
