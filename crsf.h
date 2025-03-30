#ifndef CRSF_H
#define CRSF_H

#include <Arduino.h>
#define CRFS_ADDRESS 0xC8
#define CRSF_MAX_CHANNELS 16
#define CRSF_PACKET_SIZE 26

#define BAUD_RATE 410000
#define CHANNEL_MASK 0x07FF

extern HardwareSerial* serial_data;
extern uint8_t crfs_buffer[CRSF_PACKET_SIZE];
extern uint16_t channels[CRSF_MAX_CHANNELS];
extern unsigned char crc8tab[256];

void init_crsf(HardwareSerial *serialPort, uint8_t rxPin, uint8_t txPin);
void read_packets(uint8_t debug);

#endif