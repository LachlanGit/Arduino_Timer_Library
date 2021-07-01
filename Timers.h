#include "Arduino.h"

#ifndef Timers
#define Timers_H

class Timer
{
  public:
    Timer(long timerLength, bool isPaused);
    void setLength(long timerLength);
    void addTime(long addedTime);
    void start();
    void pause();
    long timeLeft();
    String string();
    bool isPaused();

  private:
    long _timerEnd; 
    long _timerLeft;
    bool _isPaused; //true = paused
};

#endif
