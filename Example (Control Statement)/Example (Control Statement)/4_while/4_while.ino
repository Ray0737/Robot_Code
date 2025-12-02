int var = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  while (var < 2) {
    // do something repetitive 200 times
    var++;
    Serial.println("go");
  }
}

void loop() {
  // put your main code here, to run repeatedly:
}
