#include <OneWire.h>

#define GPIO_PIN 15

OneWire ds(GPIO_PIN);

void setup(void) {
  Serial.begin(115200);
}

void loop(void) {
  char address[8];
  uint8_t i =0;
  
  if (!ds.search(address)) {
    Serial.println("Nothing to see here! ;)");
    ds.reset_search();
    delay(250);
    return;
  }
  Serial.print(" ROM =");
  for (i = 0; i < 8; i++) {
    Serial.write(' ');
    Serial.print(address[i], HEX);
  }
}
