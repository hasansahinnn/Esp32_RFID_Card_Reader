#include <SPI.h>
#include <MFRC522.h>  // Kart Okuyucu
MFRC522 rfid(5, 22);
void setup() {
  rfid.PCD_Init();

}
String cardId;
void loop() {
  while(!rfidkart()={
      Serial.print("Cart Id =>");
      Serial.println(cardId);
    }
}

bool rfidkart(){
       SPI.begin();                                //SPI
       rfid.PCD_Init();
       if ( rfid.PICC_IsNewCardPresent())    //Waiting for Card
        {
          Serial.print("1");
          if ( rfid.PICC_ReadCardSerial())      //Card can't Read
            {
               Serial.print("2");
                 //Success
            
               for(int i=0;i<4;i++){
                 cardId+=rfid.uid.uidByte[i];
               }
               rfid.PICC_HaltA();  
              return true;
            }
        }
        return false;
  }
