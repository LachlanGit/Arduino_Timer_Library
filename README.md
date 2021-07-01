# Arduino Timer Library
Simple timer library for arduino IDE

## Installation
- Click the download code button and select download ZIP
- Extract the contents of the zip file to `C:\Users\<username>\Documents\Arduino\libraries`
- Add `#include <Timers.h>` to the header of your code

## Usage
### Constructor
`Timer timer(startTime, isPaused)`

e.g. `Timer myTimer(5000, true)` will result in a timer set to 5 seconds that is currently paused

### Functions
`void setLength(long timerLength);` Sets the time of a timer object

`void addTime(long addedTime);` Adds time to the timer object (Negative number can be used to subtract time)

`void start();` Starts timer

`void pause();` Pauses timer

`long timeLeft();` Returns time left of a timer in milli seconds

`String string();` Returns time left of a timer in string format

`bool isPaused();` Returns true if timer is paused

### Example
```
#include <Timers.h>

Timer timer(5000, true); //Creates paused timer set to 5000ms 

void setup() {
  Serial.begin(9600);

  timer.start();                  //Starts timer
  delay(2000);                    //Wait 2000ms
  Serial.print(timer.timeLeft()); //Should print ~3000 depending on code execution time
}

void loop() {
}
```
