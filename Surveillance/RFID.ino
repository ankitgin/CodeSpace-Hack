

  #include<SoftwareSerial.h>
SoftwareSerial mySerial(9,10);
int read_count=0,tag_count=0;
int j=0,k=0; // Variabvles to iterate in for loops
char data_temp, RFID_data[12], data_store[10][12];
boolean disp_control;
String phrase;
int green=0;
int red=1;

void setup()
{
mySerial.begin(9600);
Serial.begin(9600);
pinMode(7, OUTPUT);
pinMode(6, OUTPUT);
}

void loop()
{ 
RecieveData();
StoreData();
PrintData();
ChangeLed();
delay(100);
}

void RecieveData()
{
if(mySerial.available()>0)
{
data_temp=mySerial.read();
RFID_data[read_count]=data_temp;
read_count++;

}
}

void StoreData()
{

if(read_count==12)
{
disp_control=true;  

/*for(k=tag_count;k<=tag_count;k++)
{
for(j=0;j<12;j++)
{
data_store[k][j]=RFID_data[j];
}
}*/
read_count=0;
tag_count++;
}
}

void PrintData()
{
if(disp_control==true)
{
  for(k=0;k<=read_count;k++)
{
    for(j=0;j<12;j++)
  
    {
      //Serial.print(RFID_data[j]);
      phrase = String(phrase +RFID_data[j]);

    }
    //with phrase
    if(phrase=="19004CF605A6"){
  Serial.print("Car 1");
  red=0;
  green=1;
  phrase="";
}
else if(phrase=="19004CF76ECC"){
  Serial.print("Car 2");
  red=0;
  green=1;
  phrase="";
}
else{
  Serial.print(phrase);
}
  
Serial.println();  
}



disp_control=false;
}

}

void ChangeLed()
{
  if(green==1){
    digitalWrite(7, HIGH);
    digitalWrite(6, LOW);
    delay(10000);
  }
  else{
    digitalWrite(7, LOW); 
    digitalWrite(6, HIGH);  
  }
  digitalWrite(7, LOW); 
  digitalWrite(6, HIGH);
  green=0;
  red=1; 
  delay(1000);
}


