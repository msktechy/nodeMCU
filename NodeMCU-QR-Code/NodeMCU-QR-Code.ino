
#include <qrcode.h>
#include <SSD1306.h>

SSD1306  display(0x3c, 12,14);
QRcode qrcode (&display);

void setup() {

    display.init();
    display.clear();
    display.display();

    // Initialize QRcode display using library
    qrcode.init();
    // create qrcode
    qrcode.create("Text_1");
    delay(10000);
        qrcode.create("Text_2");
    
}

void loop() { }
