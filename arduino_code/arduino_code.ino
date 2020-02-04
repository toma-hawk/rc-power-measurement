#include <Servo.h>

Servo ESC;                       // create servo object to control the ESC

int potValue;                   // value from the analog pin
int v_read,i_read;
float volt,amps;
void setup()
{
                                // Attach the ESC on pin 9
  ESC.attach(9,1000,2000);      // (pin, min pulse width, max pulse width in microseconds) 
  Serial.begin(9600);
}

void loop()
{
  /* controlling the motor */
  potValue = analogRead(A0);                   // reads the value of the potentiometer (value between 0 and 1023)
//   Serial.println(potValue);
  potValue = map(potValue, 0, 1023, 0, 180);   // scale it to use it with the servo library (value between 0 and 180)
  ESC.write(potValue);                         // Send the signal to the ESC

  /*reading sensor inputs */
  v_read=analogRead(A1);
  i_read=analogRead(A4);
  Serial.println("analog read:");
  Serial.println(v_read);
  Serial.println(i_read);
  /* Calculating the voltage and current measured */
  volt=v_read*((float)5/(1023 * 0.06369));
  amps=i_read*((float)5/(1023 * 0.03660));

  Serial.println(volt);
  Serial.println(amps);
  Serial.println();
  delay(500);
}
