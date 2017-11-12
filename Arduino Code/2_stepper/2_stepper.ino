//Default baud speed for communication

#include <Stepper.h>

#define BAUD 9600
//led 

#define on
int steps;
String temp;
const int stepsPerRevolution = 200;

bool left = false;
bool right = false;
bool stop1 = false;
bool neutral = false;
   
Stepper myStepper(stepsPerRevolution, 2, 3);

void setup(){
      Serial.begin(BAUD);
}

void loop(){
  
      String input; 
      int Distance = 0;
      

      myStepper.setSpeed(500);
      Serial.setTimeout(5);
      
      //If any input is detected in arduino
      if(Serial.available() > 0){
            //read the whole string until '\n' delimiter is read
        
            input = Serial.readStringUntil('\n');
            //Serial.println(input);
      }
            if (input.equals("2")){
                right = true;
                left = false;
                stop1 = false;
                neutral = false;
            }

            if (input.equals("1")){
                right = false;
                left = true;
                stop1 = false;
                neutral = false;
            }

            if (input.equals("0")){
                right = false;
                left = false;
                stop1 = true;
                neutral = false;
            }

             if (input.equals("3")){
                right = false;
                left = false;
                stop1 = false;
                neutral = true;
            }
            //Serial.println(right);
            //Serial.println(left);
            //Serial.println(stop1);
            if (right == true){
                  if(temp.equals("left"))
                      steps = 0;
                  //Serial.println("clockwise");
                  temp = "right";
                  myStepper.step(1);
                  steps++;
                  //delay(500);
            }
        
            if (left == true){
                  if(temp.equals("right"))
                      steps = 0;
                  //Serial.println("counter-clockwise");
                  temp = "left";
                  //Serial.println(temp);
                  myStepper.step(-1);
                  steps++;
                  //Serial.println(steps);
                  //delay(500);
            }
                
            if (stop1 == true){

                  //Serial.println("HELLO: ");
                  //Serial.println(temp);
                  //Serial.println("Stopped");
                  myStepper.step(0);
            }

            if (neutral == true){
              
                  if(temp.equals("left")){
                      //Serial.print("STEPS: ");
                      //Serial.println(steps);
                      if(steps > 0){
                        myStepper.step(1);
                        steps--;
                      }
                  }
                  else if(temp.equals("right")){
                      //Serial.print("STEPS: ");
                      //Serial.println(steps);
                      if(steps > 0){
                        myStepper.step(-1);
                        steps--;
                      }
                  }

                  //steps = 0;
                  //delay(500);
            }
      
}
