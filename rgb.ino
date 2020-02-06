int colourred=2;
int colourgreen=3;
int colourblue=4;
int sensorPin=A0;
int sensorValue=0;
int r=0;
int g=0; 
int b=0;
int delayTime = 200;
int buttonPin=9;
int a=0,b=0,c=0;
int time=3;
int sensorValueR[3];
int sensorValueG[3];
int sensorValueB[3];
int colourvalue[3];
int white[3]={120,120,120};
int black[3]={30,30,30};
int colourvalue2[3];
int sensorValueR2[3];
int sensorValueG2[3];
int sensorValueB2[3];
int a2;
int b2,c2=0;
int sensitivity=50;
void setup(){
  pinMode(colourred, OUTPUT);        
  pinMode(colourgreen, OUTPUT);
  pinMode(colourblue, OUTPUT);
  pinMode(buttonPin, INPUT);
  pinMode(10, OUTPUT);        
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(8,INPUT);
  
  Serial.begin(9600);
}
  
  void loop(){
    
   
 while(a<time){
   
   takereading();
   a++;
   
 }
 while(b<1)
 {
 avarage();
 manipulate();
 check();
 printout();
 digitalWrite(13,HIGH);
 delay(100);
 digitalWrite(13,LOW);
  b++;
  }
  delay(500);

 while(b2<time)
 {
   takereading2();
   b2++;
   
 }
  while(b2<1)
  {
    avarage2();
    manipulate2();
    check2();
    printout2();
    digitalWrite(13,HIGH);
    delay(100);
    digitalWrite(13,LOW);
    b2++;
  }
    while(b3<1)
    {
     compare(); 
     b3++;
    }
 }
void takereading()
{
  digitalWrite(colourred, HIGH);
  Serial.println("------");
  delay(delayTime);
  sensorValueR[a] = map(analogRead(sensorPin),0,1023,0,255);
  digitalWrite(colourred, LOW);  
  delay(delayTime);
  digitalWrite(colourgreen, HIGH);  
  delay(delayTime);  
  sensorValueG[a] = map(analogRead(sensorPin),0,1023,0,255);
  digitalWrite(colourgreen, LOW); 
  delay(delayTime);
  digitalWrite(colourblue, HIGH);
  delay(delayTime);
  sensorValueB[a] = map(analogRead(sensorPin),0,1023,0,255);
  digitalWrite(colourblue, LOW); 
  delay(delayTime);
}
void avarage()
{
    colourvalue[0]=(((sensorValueR[0]+sensorValueR[1]+sensorValueR[2])/3)-30)*2.83;
    colourvalue[1]=(((sensorValueG[0]+sensorValueG[1]+sensorValueG[2])/3)-30)*2.83;
    colourvalue[2]=(((sensorValueB[0]+sensorValueB[1]+sensorValueB[2])/3)-30)*2.83; 
}
void printout()
{
    Serial.print("R = ");
    Serial.println(int(colourvalue[0]));
    Serial.print("G = ");
    Serial.println(int(colourvalue[1]));
    Serial.print("B = ");
    Serial.println(int(colourvalue[2]));
}
  
void manipulate()
{
    colourvalue[0]=colourvalue[0]-50;
    colourvalue[1]=colourvalue[1]-50;
    colourvalue[2]=colourvalue[2]-90;
}
  
 
  void check()
  {
   for(i=0;i<3;i++)
   {
     if(colourvalue[i]>255)
     {
       colourvalue[i]=255;
     }
     if(colourvalue[i]<0)
     {
       colourvalue[i]=0;
     }
   }
  } 
void takereading2()
{
  digitalWrite(colred, HIGH);  
  Serial.println("-----");
  delay(delayTime);
  sensorValueR2[a2] = map(analogRead(sensorPin),0,1023,0,255);
  digitalWrite(colourred, LOW); 
  delay(delayTime);
  digitalWrite(colourgreen, HIGH);   
  delay(delayTime);  
  sensorValueG2[a2] = map(analogRead(sensorPin),0,1023,0,255);
  digitalWrite(colourgreen, LOW);    
  delay(delayTime);
  digitalWrite(colourblue, HIGH); 
  delay(delayTime);
  sensorValueB2[a2] = map(analogRead(sensorPin),0,1023,0,255);
  digitalWrite(colourblue, LOW); 
  delay(delayTime);
}
void avarage2()
{
    colourvalue2[0]=(((sensorValueR2[0]+sensorValueR2[1]+sensorValueR2[2])/3)-30)*2.83;
    colourvalue2[1]=(((sensorValueG2[0]+sensorValueG2[1]+sensorValueG2[2])/3)-30)*2.83;
    colourvalue2[2]=(((sensorValueB2[0]+sensorValueB2[1]+sensorValueB2[2])/3)-30)*2.83; 
}
  void printout2()
  {
    Serial.print("R = ");
    Serial.println(int(colourvalue2[0]));
    Serial.print("G = ");
    Serial.println(int(colourvalue2[1]));
    Serial.print("B = ");
    Serial.println(int(colourvalue2[2]));
  }
  void manipulate2()
  {
    colourvalue2[0]=colourvalue2[0]-50;
    colourvalue2[1]=colourvalue2[1]-50;
    colourvalue2[2]=colourvalue2[2]-90;
    
  }
  void check2()
  { 
   for(i=0;i<3;i++)
   {
     if(colourvalue2[i]>255)
     {
       colourvalue2[i]=255;
     }
     if(colourvalue2[i]<0)
     {
       colourvalue2[i]=0;
     }
   }
  }

 void compare()
 {
   
    for(i=0;i<3;i++) 
    {
      if(colourvalue2[i]<colourvalue[i]+sensitivity&&colourvalue2[i]>colourvalue[i]-sensitivity)
      {
      Serial.print("Match");
      digitalWrite(13,HIGH); 
      Serial.print("Match"); 
      }
      else
      {
        Serial.print(" not Match");
        
      }
 }
 }
