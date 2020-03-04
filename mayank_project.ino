void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);
pinMode(A0, INPUT);
pinMode(D2, INPUT);
}
int ss, gs;
void loop() {
  // put your main code here, to run repeatedly:
ss = digitalRead(D2);
gs = digitalRead(A0);
Serial.println(ss);
Serial.println(gs);
delay(1000);
}
