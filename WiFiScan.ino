#include "WiFi.h"
#include "SPI.h"
#include "TFT_eSPI.h"

TFT_eSPI tft = TFT_eSPI();

void setup()
{
    Serial.begin(1000000);

    // Set WiFi to station mode and disconnect from an AP if it was previously connected
    WiFi.mode(WIFI_STA);
    WiFi.disconnect();
    tft.begin();
    tft.setRotation(3);

}

void loop()
{

    int x = 80;
    int y = 40;


    // WiFi.scanNetworks will return the number of networks found
    int n = WiFi.scanNetworks();
    int k = 0;
    if (n == 0) {
        Serial.println("no networks found");
    } else {
        for (int i = 0; i< n; ++i){
          if (WiFi.RSSI(i) < -70){
            ++k;
          }
        }
        tft.fillScreen(TFT_BLACK);
        tft.setCursor(x,y);
        tft.setTextSize(10);
        tft.setTextColor(TFT_WHITE, TFT_BLACK);
        tft.print(k);
        Serial.println(k);
    }
}

    // Wait a bit before scanning again
