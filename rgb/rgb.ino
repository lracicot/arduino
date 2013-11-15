/*
Adafruit Arduino - Lesson 3. RGB LED
*/
int redPin = 11;
int greenPin = 10;
int bluePin = 9;

int colorControl = 0;
int red = 0;
int green;
int blue = 0;

void setup()
{
    pinMode(redPin, OUTPUT);
    pinMode(greenPin, OUTPUT);
    pinMode(bluePin, OUTPUT);
    
    Serial.begin(9600);
}

void loop()
{
    // send data only when you receive data:
    if (Serial.available() > 0) {
      
        // read the incoming byte:
        int incomingByte = Serial.read();
        
        if (incomingByte == 114) {
           colorControl = 1;
           Serial.println("Red control"); 
        }
        else if (incomingByte == 103) {
           colorControl = 2;
           Serial.println("Green control"); 
        }
        else if (incomingByte == 98) {
           colorControl = 3;
           Serial.println("Blue control"); 
        }
          
        else if (colorControl > 0 && incomingByte == 43) {
          
            switch(colorControl)
            {
                case 1:
                    red++;
                    break;
                case 2:
                    green++;
                    break;
                case 3:
                    blue++;
                    break;
                default:
                    break;
            }
        }
          
        else if (colorControl > 0 && incomingByte == 45) {
          
            switch(colorControl)
            {
                case 1:
                    red--;
                    break;
                case 2:
                    green--;
                    break;
                case 3:
                    blue--;
                    break;
                default:
                    break;
            }
        }
        
        else {
             colorControl = 0;
        }
        
        setColor(red, green, blue);
    }
}

void setColor(int red, int green, int blue)
{
    analogWrite(redPin, red);
    analogWrite(greenPin, green);
    analogWrite(bluePin, blue);
}


