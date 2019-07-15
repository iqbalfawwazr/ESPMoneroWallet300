#include "mbedtls/aes.h"


int numBytes = 0;
int i = 0;
int j = 0;
char*letters[40] = {"a", "b", "c", "d", "e", "f","g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z", "1", "2", "3", "4", "5", "6", "7", "8", "9", "0"};
String randString = "";
char coba[32];
char *key = coba;
char *plainText = "TA Kel 5 MONERO ";
  
void encrypt(char * plainText, char * key, unsigned char * outputBuffer){

  mbedtls_aes_context aes;

  mbedtls_aes_init( &aes );
  mbedtls_aes_setkey_enc( &aes, (const unsigned char*) key, strlen(key) * 8 );
  mbedtls_aes_crypt_ecb( &aes, MBEDTLS_AES_ENCRYPT, (const unsigned char*)plainText, outputBuffer);
  mbedtls_aes_free( &aes );
}

void decrypt(unsigned char * chipherText, char * key, unsigned char * outputBuffer){

  mbedtls_aes_context aes;

  mbedtls_aes_init( &aes );
  mbedtls_aes_setkey_dec( &aes, (const unsigned char*) key, strlen(key) * 8 );
  mbedtls_aes_crypt_ecb(&aes, MBEDTLS_AES_DECRYPT, (const unsigned char*)chipherText, outputBuffer);
  mbedtls_aes_free( &aes );
}

void setup() {

  Serial.begin(115200); 
}

void loop() {

  
    numBytes = 16;
    for(i = 0; i<numBytes; i++)
    {
     randString = randString+letters[random(0, 15)];
    }
    //randString.toCharArray(coba, 17); 
    String c=Serial.readString();
    c.toCharArray(coba,17);
    Serial.println(c);
 // Serial.println("\nOriginal plain text:");
  //Serial.println(plainText);
  unsigned char cipherTextOutput[16];
  unsigned char decipheredTextOutput[16];

  encrypt(plainText, key, cipherTextOutput);
  decrypt(cipherTextOutput, key, decipheredTextOutput);

  //Serial.println("\nCiphered text:");
  for (int i = 0; i < 16; i++) {

    char str[3];
    sprintf(str, "%02x", (int)cipherTextOutput[i]);
    String kode;
    kode = String (str);
    Serial.print(kode);
    //Serial.print(str);
  }
  Serial.println();
  //Serial.println("\n\nDeciphered text:");
  for (int i = 0; i < 16; i++) {
  //Serial.print((char)decipheredTextOutput[i]);
  }  
   randString = "";
delay(10000);
  }
