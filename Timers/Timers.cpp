#include "Arduino.h"
#include "Timers.h"

Timer::Timer(long timerLength, bool isPaused) {
  _isPaused = isPaused;

  if (_isPaused) {
    _timerLeft = timerLength;
  } else {
    _timerEnd = millis() + timerLength;
  }
}

void Timer::setLength(long timerLength) {
  if (_isPaused) {
    _timerLeft = timerLength;
  } else {
    _timerEnd = millis() + timerLength;
  }
}

void Timer::addTime(long addedTime) {
  if (_isPaused) {
    _timerLeft += addedTime;
  } else {
    _timerEnd += addedTime;
  }
}

void Timer::start() {
  if (_isPaused) {
    _timerEnd = millis() + _timerLeft;
    _isPaused = false;
  }
}

void Timer::pause() {
  if (!_isPaused) {
    _timerLeft = _timerEnd - millis();
    _isPaused = true;
  }
}

long Timer::timeLeft() {
  if (_isPaused) {
    return _timerLeft;
  } else {
    return _timerEnd - millis();
  }
}

String Timer::string() {
  long timeLeft;
  String colon = ":";
  String zero = "0";
  
  if (_isPaused) {
    timeLeft = _timerLeft;
  } else {
    timeLeft = _timerEnd - millis();
  }
  
  byte minutesLeft = floor(timeLeft / 60000);
  byte secondsLeft = (timeLeft % 60000) / 1000;
  
  if (timeLeft < 0) {
    return "0:00";
  } else if (secondsLeft >= 10) {
    return minutesLeft + colon + secondsLeft;
  } else {
    return minutesLeft + colon + zero + secondsLeft;
  }
}

bool Timer::isPaused() {
  return _isPaused;
}