#define LS 2
#define MS 4
#define RS 5
#define LM1 6
#define RM1 7
#define LM2 8
#define RM2 9
#define LME 10
#define RME 11

void setup() 
{
  Serial.begin(9600);
  pinMode(LS,INPUT);
  pinMode(RS,INPUT);
  pinMode(MS,INPUT);
  pinMode(LM1,OUTPUT);
  pinMode(RM1,OUTPUT);
  pinMode(LM2,OUTPUT);
  pinMode(RM2,OUTPUT);
  pinMode(LME,OUTPUT);
  pinMode(RME,OUTPUT);
}

void loop()
{
  int a = digitalRead(LS);
  int b = digitalRead(MS);
  int c = digitalRead(RS);
  Serial.println("LS:");
  Serial.println(a);
  Serial.println("MS:");
  Serial.println(b);
  Serial.println("RS:");
  Serial.println(c);
  if(b==1)
  {
    if(a==0 && c==0)                             //straight
    {
    digitalWrite(LM1,HIGH);
    digitalWrite(LM2,LOW);
    digitalWrite(RM1,HIGH);
    digitalWrite(RM2,LOW);
    analogWrite(LME,110);
    analogWrite(RME,110);
    }
    else if(a==1 && c==0)                              //left<90
    {
    digitalWrite(LM1,LOW);
    digitalWrite(LM2,HIGH);
    digitalWrite(RM1,HIGH);
    digitalWrite(RM2,LOW);
    analogWrite(LME,110);
    analogWrite(RME,110);
    }
    else if(a==0 && c==1)                              //right<90
    {
    digitalWrite(LM1,HIGH);
    digitalWrite(LM2,LOW);
    digitalWrite(RM1,LOW);
    digitalWrite(RM2,HIGH);
    analogWrite(LME,110);
    analogWrite(RME,110);
    }
    else                               //stop
    {
    digitalWrite(LM1,LOW);
    digitalWrite(LM2,LOW);
    digitalWrite(RM1,LOW);
    digitalWrite(RM2,LOW);
    analogWrite(LME,0);
    analogWrite(RME,0);
    }
  }
  else
  {
    if(a==0 && c==0)                                     //backturn
    {
    digitalWrite(LM1,HIGH);
    digitalWrite(LM2,LOW);
    digitalWrite(RM1,LOW);
    digitalWrite(RM2,HIGH);
    analogWrite(LME,110);
    analogWrite(RME,110);
    }
    else if(a==1 && c==0)                                 //left>90
    {
    digitalWrite(LM1,LOW);
    digitalWrite(LM2,LOW);
    digitalWrite(RM1,HIGH);
    digitalWrite(RM2,LOW);
    analogWrite(LME,110);
    analogWrite(RME,110);
    }
    else if(a==0 && c==1)                                 //right>90
    {
    digitalWrite(LM1,HIGH);
    digitalWrite(LM2,LOW);
    digitalWrite(RM1,LOW);
    digitalWrite(RM2,LOW);
    analogWrite(LME,110);
    analogWrite(RME,110);
    }
    else                                  //invalidcase
    {
    digitalWrite(LM1,LOW);
    digitalWrite(LM2,LOW);
    digitalWrite(RM1,LOW);
    digitalWrite(RM2,LOW);
    analogWrite(LME,0);
    analogWrite(RME,0);
    }
  }        
  
}
