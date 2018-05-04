

int x=0;      // x axis variable
int inhaleTime;
int pval=1;
int ppval = 1;
boolean inhaling = false;

/**************************************************************************************
  Function     : setup()
  Description  : Use it to initialize variables, pin modes, start using libraries, etc.
                 The setup function will only run once, after each power up or reset of                  the Arduino board.
***************************************************************************************/

void setup()
{ 
  Serial.begin(115200);  // opens serial port, sets data rate to 9600 bps
  delay(1000);
}

/**************************************************************************************
  Function     : loop()
  Description  : Loops consecutively, allowing your program to change and respond.
                 Use it to actively control the Arduino board.
***************************************************************************************/

void loop()
{
//  int l = random(0,14);
//  if(l== 0 || l==1 || l==2 || l == 3 ||l ==4)
//{
//        Serial.print("BPM : ");
//        Serial.println("65");
//}
//else if(l==5 || l==6||l==7)
//{
//  Serial.print("BPM : ");
//        Serial.println("70");
//}
//else if(l==8||l==9)
//{
//   Serial.print("BPM : ");
//        Serial.println("71");
//}
//else if(l== 10 || l==11 || l==12 || l ==13)
//{
//        Serial.print("BPM : ");
//        Serial.println("62");
//}
//  
  ppval = pval;
  pval = x;
  x  = analogRead(A0);  
  //Serial.println(x); 
  
  if(!inhaling && x>1){
    Serial.println("IN");
    inhaling = true;
  }
  if(inhaling && x<1 && pval<2 && ppval<2){
//    delay(100);// 
    Serial.println("OUT");
    inhaling = false;
  }
  delay(300);
}
