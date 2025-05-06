#define PinPreL1 A5
#define PinPreL2 A4
#define PinPreR1 A3
#define PinPreR2 A2
#define PinML 10
#define PinMR 9

//薄膜压力传感器参数
#define PressureValve 600//启动电机的阈值

void setup(){
  Serial.begin(9600);
  //管脚模式
  pinMode(PinPreL1, INPUT);
  pinMode(PinPreL2, INPUT);
  pinMode(PinPreR1, INPUT);
  pinMode(PinPreR2, INPUT);
  pinMode(PinML, OUTPUT);
  pinMode(PinMR, OUTPUT);
}

void loop(){
  int val = 0;
    int val1 = 0;
    int val2 = 0;
    //左侧
    val1 = analogRead(PinPreL1);
    val2 = analogRead(PinPreL2);
    val = ((val1 > val2)?val1:val2);
    Serial.print("L=");
    Serial.println(val);
    if (val >= PressureValve) {
      analogWrite(PinML, (map(val, PressureValve, 1023, 0, 255)));

    } else {
      digitalWrite(PinML, 0);

    }
    //右侧
    val1 = analogRead(PinPreR1);
    val2 = analogRead(PinPreR2);
    val = ((val1 > val2)?val1:val2);
    Serial.print("R=");
    Serial.println(val);
    if (val >= PressureValve) {
      analogWrite(PinMR, (map(val, PressureValve, 1023, 0, 255)));

    } else {
      digitalWrite(PinMR, 0);

    }

}