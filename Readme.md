### **CRSF (Crossfire) Receiver for ELRS - ESP32 Integration**  

This project enables **ELRS (ExpressLRS) receivers** to communicate via **CRSF (Crossfire) protocol**, allowing control of **drones, RC vehicles, and other remote-controlled devices** using an ESP32 microcontroller.  

---


## **Hardware Requirements**  
- **ESP32 board**
- **ELRS receiver** (e.g., Happymodel, BetaFPV, Radiomaster)  
- **RC transmitter** with ELRS support  

---


### Example of **Wiring (ESP32 ↔ ELRS Receiver)**  
| **ESP32** | **ELRS Receiver** |
|-----------|------------------|
| GPIO 16 (TX) | CRSF RX |
| GPIO 17 (RX) | CRSF TX |
| 5V | VCC |
| GND | GND |


### CRSF Protocol Overview
The CRSF protocol is a bi-directional communication protocol used in the RC hobby community, primarily for telemetry and control data transmission. It allows for low-latency communication between the transmitter and receiver, enabling features like telemetry data, RSSI (Received Signal Strength Indicator), and more.

### CRSF Packet Structure

| **Byte Index** | **Field**         | **Description**                                      |
|--------------|-----------------|--------------------------------------------------|
| 0            | **Device Address**  | Identifies the sender |
| 1            | **Packet Length**   | Total length of the packet (excluding address & CRC) |
| 2 - N        | **Payload Data**    | The actual data being transmitted (channels, telemetry, etc.) |
| N+1          | **CRC**             | Error-checking byte (Cyclic Redundancy Check) |

For the flight controller receiver the Device Address is **0xC8**, and the Packet Length is **26 bytes**. The Payload Data contains the channel data, and the CRC is used to verify the integrity of the packet.


### Library overview

The library can read data from **16 channels**, which are typically used for controlling various functions in RC devices. 

## Channel Mapping

| **Channel** | **Usage**                     | **Value Range** |
|------------|--------------------------------|---------------|
| 1          | Roll                            | 170 - 1800    |
| 2          | Pitch                           | 170 - 1800    |
| 3          | Throttle                        | 170 - 1800    |
| 4          | Yaw                             | 170 - 1800    |
| 5          | Arm/Disarm                      | 170 - 1800    |
| 6          | Flight Mode                     | 170 - 1800    |
| 7 - 16     | Other Assignable Channels       | 170 - 1800    |

### How to Read Channel Data

When a CRSF packet is received, the library decodes the channel data, allowing you to access it as follows:

```cpp
Serial.print("Channel 1 (Roll): ");
Serial.println(channels[0]);

Serial.print("Channel 2 (Pitch): ");
Serial.println(channels[1]);

...
```

[More details about CRSF](https://github.com/tbs-fpv/tbs-crsf-spec/blob/main/crsf.md)