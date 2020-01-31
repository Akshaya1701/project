/*
*
* Project Name:   Swich kar Yantra
* Author List:    Akshaya C, Annaprabu R, Amruta R, Kannammai M.
* Filename:     Swich_kar_Yantra.ino
* Functions:    TypeOfToilet(), WaterPump_ON(), Rotate(), WaterPump_OFF(), Detergent_ON(), Detergent_OFF(), clean_brush(), Return_NormalPosition().
* Global Variables: servo_1, servo2, servo3, servo4,  buttonState, buttonPin,angle_1, angle2, angle3, angle4.
*
*/

#include <Servo.h>    //Servo library
 
 Servo servo_1;        //initialize a servo object for the connected servo  
 Servo servo2;        //initialize a servo object for the connected servo 
 Servo servo3;        //initialize a servo object for the connected servo 
 Servo servo4;        //initialize a servo object for the connected servo 
                
int angle_1 = 90;    //assume initial angle as 90 degree for servo motor 1
int angle2 = 90;     //assume initial angle as 90 degree for servo motor 2
int angle3 = 90;    //assume initial angle as 90 degree for servo motor 3
int angle4 = 90;    //assume initial angle as 90 degree for servo motor 4
int buttonState;    //initialize switch 
int buttonPin=0;   //initialize switch value as 0 
/*
*
* Function Name:   setup()
* Input:    switch
* Output:   Assign the pins on arduino for input and output
* Logic:    Sets the pin as input or output
* Example Call:   setup()
*
*/

 
void setup() 
{ 
  servo_1.attach(5);// attach the signal pin of servo to pin 5 of arduino
  servo2.attach(6);// attach the signal pin of servo to pin 6 of arduino
  servo3.attach(9);// attach the signal pin of servo to pin9 of arduino
  servo4.attach(10);// attach the signal pin of servo to pin 10 of arduino  
  pinMode(2,INPUT); //switch
  pinMode(3,OUTPUT);//Water pump
  pinMode(A0,OUTPUT);//detergent pump
  
}


/*
*
* Function Name:   TypeOfToilet()
* Input:    None
* Output:   Controls servo_motor_1
* Logic:    Write high into motor pins to make the motor to rotate in a direction to pull the drone from water.
* Example Call:   TypeOfToilet()
*
*/


void TypeOfToilet()
{ 
    int sensorValue = digitalRead(2);
    buttonState = digitalRead(buttonPin);
    
     if (buttonState == HIGH)//for indian model
    {
        angle2=45;
        servo2.write(angle2); //command to rotate the servo to the specified angle
        delay(1000);//delay for 1 second
    }
    else  if (buttonState == LOW) //for western model
    {
        angle2=75;
        servo2.write(angle2); //command to rotate the servo to the specified angle
        delay(1000);
     
     }  
}

/*
*
* Function Name:   WaterPump_ON()
* Input:    None
* Output:   Controls Watrer pump
* Logic:    Write high into solenoid pins to open the tap.
* Example Call:   WaterPump_ON()
*
*/
void Water_ON()
{

 digitalWrite(3,HIGH);
  
}


/*
*
* Function Name:   WaterPump_OFF()
* Input:    None
* Output:   Controls Watrer pump
* Logic:    Write high into solenoid pins to close the tap.
* Example Call:   WaterPump_OFF()
*
*/

void Water_OFF()
{
  
digitalWrite(3,LOW);
  
}

/*
*
* Function Name:   Detergent_ON()
* Input:    None
* Output:   Controls detergent pump
* Logic:    Write high into  pins to open the tap.
* Example Call:   Detergent_ON()
*
*/

void Detergent_ON()
{  
  
   digitalWrite(A0,HIGH);
   
}

/*
*
* Function Name:   Detergent_ON()
* Input:    None
* Output:   Controls detergent pump
* Logic:    Write high into  pins to open the tap.
* Example Call:   Detergent_ON()
*
*/


void Detergent_OFF()
{
  
  digitalWrite(A0,LOW);
  
}

 /*
*
* Function Name:   Arm_Rotate()
* Input:    None
* Output:   Controls servo motors
* Logic:  change the angle of servo motors to rotate  
* Example Call:   Arm_Rotate()
*
*/

void Arm_Rotate()
{
        angle_1 = 120;                          
        servo_1.write(angle_1); //command to rotate the servo to the specified angle
        delay(3000);
                
        angle3 = 75;
        servo3.write(angle3); //command to rotate the servo to the specified angle
        delay(3000);
              
        angle4 = 90;   
        servo4.write(angle4); //command to rotate the servo to the specified angle
        delay(500);    

        while(angle_1>=60)
        {
          servo_1.write(angle_1); //command to rotate the servo to the specified angle
        delay(3000);
        angle_1=angle_1-10;
        delay(1000);
          
          }


          
}  


/*
*
* Function Name:   Clean_Toilet()
* Input:    None
* Output:   Controls servo motors
* Logic:    change the angle of servo motors to rotate 
* Example Call:   Clean_Toilet()
*
*/

void Clean_Toilet()
{

        angle_1 = 120;                          
        servo_1.write(angle_1); //command to rotate the servo to the specified angle
        delay(3000);
        
        
                
        angle3 = 75;
        servo3.write(angle3); //command to rotate the servo to the specified angle
        delay(3000);
        

        angle4= 90;
        servo4.write(angle4); //command to rotate the servo to the specified angle
        delay(3000);



         while(angle_1>=60)
        {
          servo_1.write(angle_1); //command to rotate the servo to the specified angle
        delay(3000);
        angle_1=angle_1-10;
        delay(1000);
          
          }
                          
 }




/*
*
* Function Name:   clean_brush()
* Input:    None
* Output:   Controls servo motors
* Logic:    change the angle of servo motors to rotate 
* Example Call:   clean_brush()
*
*/
void clean_brush()
{
  
        servo4.write(angle4); //command to rotate the servo to the specified angle
        delay(3000);
  
  
 }

void brush_up()
{
 angle4 = 180;
 servo4.write(angle4); //command to rotate the servo to the specified angle
 delay(2000);
 }
void brush_down()
{
 angle4 = 0;
 servo4.write(angle4); //command to rotate the servo to the specified angle
 delay(2000);
 
 }

/*
* Function Name:   Return_NormalPosition()
* Input:    None
* Output:   all the servo motors come back rest position
* Logic:    change the angle of servo motors to return initial stage
* Example Call:   Return_NormalPosition()
*
*/


void Return_NormalPosition()
{
        angle_1=90;
        servo_1.write(angle_1); //command to rotate the servo to the specified angle
        delay(1000);

        angle2=90;
        servo2.write(angle2); //command to rotate the servo to the specified angle
        delay(1000);

        angle_1=90;
        servo3.write(angle3); //command to rotate the servo to the specified angle
        delay(1000);

        angle4=90;
        servo4.write(angle4); //command to rotate the servo to the specified angle
        delay(1000);
  
}

/*
* Function Name:   loop()
* Input:    None
* Output:   Continiously runs the program in a loop
* Logic:    Runs program in a loop
* Example Call:   loop()
*
*/

void loop() 
{ 

TypeOfToilet();

brush_up();
Water_ON();
Arm_Rotate();
Water_OFF();

Detergent_ON();
Arm_Rotate();

Detergent_OFF();


clean_brush();

Water_ON();
delay(2000);
Water_OFF();


Clean_Toilet();

clean_brush();
brush_down();
Water_ON();
delay(5000);
Water_OFF();

Return_NormalPosition();

}
