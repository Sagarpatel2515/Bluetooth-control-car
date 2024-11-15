
/*Simple Bluetooth control car
 * https://srituhobby.com
 */
 
#define IN1 8
#define IN2 9
#define IN3 10
#define IN4 11

void setup() {
  Serial.begin(9600);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
}

void loop() {
  if (Serial.available() > 0) {
    char value = Serial.read();
    Serial.println(value);

    if (value == 'U') {
      Forward();
    } else if (value == 'D') {
      Backward();
    } else if (value == 'S') {
      Stop();
    }else if(value == 'L'){
      Left();
    }else if(value == 'R'){
      Right();
    }
  }
}

void Forward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}
void Backward() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}
void Stop() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}
void Left() {
  digitalWrite(IN1, LOW);   // Motor A - Reverse
  digitalWrite(IN2, HIGH);  // Motor A - Stop
  digitalWrite(IN3, HIGH);  // Motor B - Forward
  digitalWrite(IN4, LOW);   // Motor B - Stop
}

void Right() {
  digitalWrite(IN1, HIGH);  // Motor A - Forward
  digitalWrite(IN2, LOW);   // Motor A - Stop
  digitalWrite(IN3, LOW);   // Motor B - Reverse
  digitalWrite(IN4, HIGH);  // Motor B - Stop
}