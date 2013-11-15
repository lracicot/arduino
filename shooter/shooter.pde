int incomingByte = 0;	// for incoming serial data

void setup()
{
    pinMode(13, OUTPUT);
    pinMode(12, OUTPUT);
    pinMode(11, OUTPUT);
    pinMode(10, OUTPUT);
    pinMode(9, OUTPUT);
    
    Serial.begin(9600); // opens serial port, sets data rate to 9600 bps
    
    digitalWrite(1, LOW);
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
    digitalWrite(12, LOW);
    digitalWrite(13, LOW);
}

void loop() {

	// send data only when you receive data:
	if (Serial.available() > 0) {
		// read the incoming byte:
		incomingByte = Serial.read();

                switch(incomingByte)// see what was sent to the board
                {
                    case 131:
                        digitalWrite(13,HIGH);
                        break;
                    case 130:
                        digitalWrite(13, LOW);
                        break;
                    case 121:
                        digitalWrite(12, HIGH);
                        break;
                    case 120:
                        digitalWrite(12, LOW);
                        break;
                    case 111:
                        digitalWrite(11, HIGH);
                        break;
                    case 110:
                        digitalWrite(11, LOW);
                        break;
                    case 101:
                        digitalWrite(10, HIGH);
                        break;
                    case 100:
                        digitalWrite(10, LOW);
                        break;
                    case 91:
                        digitalWrite(9, HIGH);
                        break;
                    case 90:
                        digitalWrite(9, LOW);
                        break;
                    default:
                        break;
                    }

	}
}

