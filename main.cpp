#include "crsf.h"

/*
*  Example of code how to use the library
*
*/

void read(void *pvParameters) {
    while (1) {
        read_packets(0);
        vTaskDelay(10 / portTICK_PERIOD_MS);
    }
    vTaskDelete(NULL);
}

void setup() {
    Serial.begin(115200);

    // Initialize a Serial port for comunication with receiver
    init_crsf(&Serial1, 16, 17);
   
    // Create a task to read CRSF packets without blocking the main loop
    xTaskCreatePinnedToCore(
        read,
        "read",
        4096,
        NULL,
        1,
        NULL,
        1
    );
}

void loop() {
    // Use the channels array as needed (0-15)
    Serial.print("Channel 0: ");
    Serial.println(channels[0]);

    // Control servo position
    int servo_position = map(channels[0], 170, 1800, 0, 180);
    Serial.print("Servo position: ");
    Serial.println(servo_position);
    delay(100);
}
