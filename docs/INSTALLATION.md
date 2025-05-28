# Installation Guide

## Hardware Setup

### Required Components
- Arduino UNO
- HC-SR04 Ultrasonic Sensor
- SG90 Servo Motor
- Jumper wires
- Breadboard
- USB cable
- 5V Power supply (optional)

### Circuit Connections

#### Ultrasonic Sensor (HC-SR04)
```
HC-SR04    →    Arduino UNO
VCC        →    5V
GND        →    GND
Trig       →    Digital Pin 7
Echo       →    Digital Pin 6
```

#### Servo Motor (SG90)
```
SG90       →    Arduino UNO
Red (VCC)  →    5V
Brown(GND) →    GND
Orange     →    Digital Pin 9
```

#### Optional Components
```
Buzzer     →    Digital Pin 8
LED        →    Digital Pin 13 (built-in)
```

### Assembly Steps

1. **Prepare the Breadboard**
   - Place the Arduino UNO near the breadboard
   - Ensure stable connections

2. **Connect Power Rails**
   - Connect 5V from Arduino to positive rail
   - Connect GND from Arduino to negative rail

3. **Mount Ultrasonic Sensor**
   - Place HC-SR04 on breadboard
   - Connect according to pin diagram above

4. **Mount Servo Motor**
   - Position servo for barrier mechanism
   - Connect wires as specified

5. **Test Connections**
   - Double-check all connections
   - Ensure no short circuits

## Software Setup

### Prerequisites
- Arduino IDE (version 1.8.0 or later)
- USB drivers for Arduino UNO

### Installation Steps

1. **Download Arduino IDE**
   ```
   Visit: https://www.arduino.cc/en/software
   Download and install for your operating system
   ```

2. **Install Required Libraries**
   - Servo library (usually pre-installed)
   - No additional libraries required

3. **Load the Code**
   - Open Arduino IDE
   - File → Open → Select `src/railway_accident_prevention.ino`

4. **Configure Arduino IDE**
   - Tools → Board → Arduino UNO
   - Tools → Port → Select appropriate COM port

5. **Upload Code**
   - Click Upload button (→)
   - Wait for "Done uploading" message

### Verification

1. **Serial Monitor**
   - Open Tools → Serial Monitor
   - Set baud rate to 9600
   - You should see system initialization messages

2. **Test Functionality**
   - Move hand near ultrasonic sensor
   - Observe servo movement and serial output
   - Verify barrier closes when object detected

## Troubleshooting

### Common Issues

**No Serial Output**
- Check USB connection
- Verify correct COM port selected
- Ensure baud rate is 9600

**Servo Not Moving**
- Check power connections
- Verify servo signal wire connection
- Test with simple servo sweep code

**Sensor Not Detecting**
- Check sensor connections
- Verify trigger and echo pins
- Test sensor with simple distance code

**Erratic Behavior**
- Check for loose connections
- Ensure adequate power supply
- Add delays if needed

### Power Considerations

- Arduino UNO can power small servos via 5V pin
- For multiple servos, use external 5V supply
- Ensure common ground between Arduino and external supply

## Safety Notes

- Always disconnect power when making connections
- Double-check polarity for all components
- Use appropriate wire gauge for current requirements
- Test in safe environment before deployment
