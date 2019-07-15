#include "mbedtls/aes.h"

int numBytes = 0;
int i = 0;
int j = 0;
char coba[32];
char *key = "TA MONERO";
char *plainText = coba;
String PASS= "9a296029840576f33bce3b1abee169da"; 


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
 
    String c=Serial.readString();
    c.toCharArray(coba,17);
    unsigned char cipherTextOutput[16];
    unsigned char decipheredTextOutput[16];

    encrypt(plainText, key, cipherTextOutput);
    decrypt(cipherTextOutput, key, decipheredTextOutput);

    //Serial.println("\nCiphered text:");
    char str[3]="";
    char result[100] ="";
    for (int i = 0; i < 16; i++) {

    
    sprintf(str, "%02x", (int)cipherTextOutput[i]);
    strcat(result,str);

    }
    //Serial.println(result);
    Serial.println();
    boolean Cek= isPasswordTrue(PASS,result);
    if (Cek)
      {
      Serial.print("state password:");
      Serial.println(PASS);
      Serial.print("input password:");
      Serial.println(result);
      Serial.println(" otentikasi berhasil, hasil sama");
      }
      else
      {
      Serial.print("state password:");
      Serial.println(PASS);
      Serial.print("input password:");
      Serial.println(result);
      Serial.println(" otentikasi gagal, hasil beda");
      }
    c="";
  delay(10000);
  }

 boolean isPasswordTrue (String x, String y)
{
  if (x==y)
  {
    return true;
  }
  else 
    return false;
}
