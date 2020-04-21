void setup(){
    //start serial connection
    Serial.begin(9600); // Show in serial monitor
    pinMode(2,INPUT_PULLUP); // Control
    pinMode(3,OUTPUT);
    pinMode(4,OUTPUT);
    pinMode(5,OUTPUT);
    pinMode(6,OUTPUT);
    pinMode(7,OUTPUT);
    pinMode(8,OUTPUT);
    pinMode(9,OUTPUT);
    pinMode(10,OUTPUT);
    pinMode(11,OUTPUT);
    pinMode(12,OUTPUT);
    pinMode(13,OUTPUT);


    for(int led = 3 ; led <= 13 ;led++){
        pinMode(led,OUTPUT);
    }
    tone(8,200,500); // เสียงเริ่มโปรแกรม
    delay(250); 
    tone(8,400,100); // กำเนิดเสียงที่สอง
    
}

int light = 3;
int time = 100;
int count = 1;

void loop(){
    for(light = 3 ; light <= 13 ; light++){ //ไฟไล่ขึ้นไป
        if(light == 8){
            digitalWrite(light,0);
            continue;
        }
        digitalWrite(light,1); // LED on
        delay(time);
        digitalWrite(light,0); // LED off

        if ( digitalRead(2) == 0 ){
            
            
            count = count * 2;
            time = time / 2;
            Serial.println("Faster X 2 (Current Speed : X" + String(count) + ")");
            tone(8,400,100);
            
            delay(700);
        }
        else  {
        }

    }
    for(light = 13 ; light >= 3 ; light--) // ไฟไล่ลง
    {
        if(light == 8){
            digitalWrite(light,0); // trun off L8
            continue;
        }
        digitalWrite(light,1); // LED on
        delay(time);
        digitalWrite(light,0); // LED off

        if ( digitalRead(2) == 0 ){
            
            
            
            count = count * 2;
            Serial.println("Faster X 2 (Current Speed : X" + String(count) + ")");
            tone(8,400,100);
            time = time / 2;
            delay(700);
            
            
        }
        else  {
            
        }
    }
}