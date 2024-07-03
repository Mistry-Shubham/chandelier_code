int
  count = 0,
  white_state = HIGH,
  yellow_state = LOW,
  purple_state = LOW,
  btn_state = 0,
  last_btn_state = 0;
const int
  WHITE_LED = 8,
  YELLOW_LED = 6,
  PURPLE_LED = 2,
  READ_PIN = A5;

void setup() {
  Serial.begin(115200);
  pinMode(WHITE_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(PURPLE_LED, OUTPUT);
  update_led_output(white_state, yellow_state, purple_state);
}

void loop() {
  btn_state = analogRead(READ_PIN);

  if (btn_state < 880 && last_btn_state > 980) {
    if (count < 3) {
      count++;
    } else {
      count = 0;
    }

     last_btn_state = 0;
  }


  if (count == 0) {
    white_state = HIGH;
    yellow_state = LOW;
    purple_state = LOW;
  } else if (count == 1) {
    white_state = LOW;
    yellow_state = HIGH;
    purple_state = LOW;
  } else if (count == 2) {
    white_state = LOW;
    yellow_state = LOW;
    purple_state = HIGH;
  } else if (count == 3) {
    white_state = HIGH;
    yellow_state = HIGH;
    purple_state = HIGH;
  }

  update_led_output(white_state, yellow_state, purple_state);

if(btn_state >= last_btn_state){
  last_btn_state = btn_state;
}
}

void update_led_output(int w, int y, int p) {
  digitalWrite(WHITE_LED, w);
  digitalWrite(YELLOW_LED, y);
  digitalWrite(PURPLE_LED, p);
  Serial.print("W:");
  Serial.print(w);
  Serial.print(", Y:");
  Serial.print(y);
  Serial.print(", P:");
  Serial.println(p);
}