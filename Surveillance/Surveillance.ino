#define Heart A0
#define LED 13
int A=0,trigger=1;int sum_even,sum_odd=0;
int count1=0,count2=0;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(Heart,INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
if (analogRead(Heart)>0)
{
    A=analogRead(Heart);
    //Serial.println(A);
    if (A>500){
      count1++;
      count2=0;
    }
    else{
      count2++;
      count1=0;
      }
      
    if(count1>=6){
      count1=0;
      count2=0;
      //Serial.println("HIGH Person_1");
      Serial.println("HIGH");
      delay(100);
    }
    if(count2>=6){
      count2=0;
      //Serial.println("LOW Person_1");
      Serial.println("LOW");
      delay(100);
    }
 }

delay(50);
}
