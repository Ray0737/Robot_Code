char Input_data; //ตัวแปรสำหรับเก็บค่าที่คอมพิวเตอร์ส่งมา

void setup()
{
  Serial.begin(115200);
  Serial.println("Input data form your keyboard.");
}
void loop()
{
  if (Serial.available() > 0) { //ถ้าคอมพิวเตอร์ส่งข้อมูลมาให้จะทำเงื่อนไขภายใน if นี้
    Input_data = Serial.read(); //นำค่าที่คอมพิวเตอร์ส่งมาเก็บในตัวแปร Input_data
    if (Input_data == 'A') { //ถ้าตัวแปร key เท่ากับ 1 ให้ทำในปีกกานี้
      Serial.println("get data = A-ant");
    }
  }
}
