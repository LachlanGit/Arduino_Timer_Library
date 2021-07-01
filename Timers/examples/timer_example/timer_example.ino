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
