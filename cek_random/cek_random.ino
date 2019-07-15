
int numBytes = 0;
int i = 0;
int j = 0;
char*letters[40] = {"a", "b", "c", "d", "e", "f","g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z", "1", "2", "3", "4", "5", "6", "7", "8", "9", "0"};
String randString = "";
char coba[32];

void setup() {
  Serial.begin(115200);
  
}

void loop() {
  if(Serial.available()) 
  {
    numBytes = 16;
    for(i = 0; i<numBytes; i++)
    {
     randString = randString+letters[random(0, 15)];
    }
    Serial.println(numBytes);
    randString.toCharArray(coba, 17);
    Serial.println (coba); 
    randString = "";
    delay(1000);
 }
}
