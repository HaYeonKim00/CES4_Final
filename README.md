# CES4_Final Project

## For Arduino File

#### WiFi.scanNetworks()
One main function that is used in WiFiScan.ino file is WiFi.scanNetworks(). This function returns the number of wifi deviced detected in the area in integer. So if there were 25 devices detected, if the code saya ```int n = WiFi.scanNetworks()```, n will equal to 25. 

#### WiFi.RSSI()
This function returns the RSSI of the device. RSSI stands for received signal strength indicator. RSSI ranges between -100 to 0. So bigger the number, stronger the wifi. Negative seventy is generally believed to be the minimum strength that can be useable. So among the Wifi that ESP32 scanned, I selected only the ones that had -70 or bigger RSSI.

## For Web Serial API

#### reading serial port
Code for this part was copied from https://www.marksantolucito.com/COMS3930/spring2022/serialVisual.html but basically read the port using the same baudRate. ```parseInt()``` was used to make sure that the value that was recieved was int type. 

## For HTML file

Main goal of the html page was to show the number big enough that it could be shown from far away. 

## Video
[CES4_Final Project](https://youtu.be/Ef2DD9kiiIM)

## More about this project
[blog post for the project](https://ordinary-tenor-7bd.notion.site/CES_Final-Project_WiFi-Scanner-bae9d72803c542ddbc5b13ac96a209ec)
