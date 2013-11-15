int incomingByte = 0;	// for incoming serial data

void setup()
{
    pinMode(13, OUTPUT);
    digitalWrite(13, LOW);
    
    Serial.begin(9600);
}

void loop() {
    
    // send data only when you receive data:
    if (Serial.available() > 0) {
      
    // read the incoming byte:
        incomingByte = Serial.read();
        
        switch(incomingByte)// see what was sent to the board
        {
            case 101:
                digitalWrite(13, HIGH);
                break;
            case 100:
                digitalWrite(13, LOW);
                break;
            default:
                break;
        }
    }
}


