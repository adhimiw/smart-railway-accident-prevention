# Circuit Diagrams

This directory contains circuit diagrams and wiring information for the Smart Railway Station Accident Prevention System.

## Main Circuit Diagram

### Component Layout

```
                    Arduino UNO
                   ┌─────────────┐
                   │             │
    5V ────────────┤ 5V      D13 ├──── LED (Built-in)
    GND ───────────┤ GND     D12 │
                   │         D11 │
                   │         D10 │
    Servo Signal ──┤ D9       D8 ├──── Buzzer (Optional)
                   │          D7 ├──── Ultrasonic Trig
                   │          D6 ├──── Ultrasonic Echo
                   │          D5 │
                   │          D4 │
                   │          D3 │
                   │          D2 │
                   │         D1  │
                   │         D0  │
                   │             │
                   │         A5  │
                   │         A4  │
                   │         A3  │
                   │         A2  │
                   │         A1  │
                   │         A0  │
                   └─────────────┘
```

### Ultrasonic Sensor (HC-SR04) Connections

```
    HC-SR04                    Arduino UNO
   ┌─────────┐                ┌─────────────┐
   │   VCC   ├────────────────┤ 5V          │
   │   Trig  ├────────────────┤ D7          │
   │   Echo  ├────────────────┤ D6          │
   │   GND   ├────────────────┤ GND         │
   └─────────┘                └─────────────┘
```

### Servo Motor (SG90) Connections

```
    SG90 Servo                 Arduino UNO
   ┌─────────────┐            ┌─────────────┐
   │ Red (VCC)   ├────────────┤ 5V          │
   │ Brown (GND) ├────────────┤ GND         │
   │ Orange (PWM)├────────────┤ D9          │
   └─────────────┘            └─────────────┘
```

### Optional Components

#### Buzzer Connection
```
    Buzzer                     Arduino UNO
   ┌─────────┐                ┌─────────────┐
   │    +    ├────────────────┤ D8          │
   │    -    ├────────────────┤ GND         │
   └─────────┘                └─────────────┘
```

#### External LED (if needed)
```
    LED + Resistor             Arduino UNO
   ┌─────────┐                ┌─────────────┐
   │ Anode   ├──[220Ω]────────┤ D13         │
   │ Cathode ├────────────────┤ GND         │
   └─────────┘                └─────────────┘
```

## Breadboard Layout

### Power Distribution
```
Breadboard Power Rails:
┌─────────────────────────────────────┐
│ + + + + + + + + + + + + + + + + + + + │ ← 5V from Arduino
│                                     │
│ - - - - - - - - - - - - - - - - - - - │ ← GND from Arduino
└─────────────────────────────────────┘
```

### Component Placement
1. **Arduino UNO**: Place beside breadboard
2. **HC-SR04**: Mount on breadboard or separate mount
3. **SG90 Servo**: Mount for barrier mechanism
4. **Jumper Wires**: Use different colors for organization

### Wire Color Coding (Recommended)
- **Red**: 5V/VCC connections
- **Black**: GND connections
- **Yellow**: Digital signal (Trig)
- **Green**: Digital signal (Echo)
- **Orange**: PWM signal (Servo)
- **Blue**: Optional signals (Buzzer, LED)

## Physical Installation

### Sensor Placement
```
Railway Platform Layout:

    ┌─────────────────────────────────┐
    │          Platform               │
    │                                 │
    │  [HC-SR04]              [Servo] │ ← Sensors positioned
    │     ↓                      ↓    │   at platform edge
    │ ═══════════════════════════════ │
    │           Track                 │
    └─────────────────────────────────┘
```

### Mounting Considerations
1. **Ultrasonic Sensor**: 
   - Mount 1-2 meters above platform
   - Angle slightly downward
   - Protect from weather

2. **Servo Motor**:
   - Secure mounting for barrier
   - Easy access for maintenance
   - Weather protection

3. **Arduino Enclosure**:
   - Weatherproof housing
   - Ventilation for heat dissipation
   - Easy access to USB port

## Power Supply Options

### Option 1: USB Power (Development)
```
Computer/Power Bank → USB Cable → Arduino UNO
```

### Option 2: External Power Supply
```
12V DC Adapter → Arduino Power Jack
               ↓
            Arduino 5V → Components
```

### Option 3: Battery Power (Portable)
```
9V Battery → Arduino Power Jack
           ↓
        Arduino 5V → Components
```

## Safety Considerations

### Electrical Safety
- Use appropriate wire gauge
- Secure all connections
- Avoid short circuits
- Use fuses for high-current applications

### Mechanical Safety
- Secure mounting of all components
- Smooth barrier operation
- Emergency stop capability
- Regular maintenance access

### Environmental Protection
- IP54 rated enclosures minimum
- Corrosion-resistant materials
- Temperature compensation
- Vibration dampening

## Troubleshooting Guide

### No Power
- Check USB connection
- Verify power supply voltage
- Test continuity of power wires

### Sensor Not Working
- Check 5V and GND connections
- Verify Trig and Echo pin connections
- Test sensor with multimeter

### Servo Not Moving
- Check PWM signal connection
- Verify power supply capacity
- Test servo with simple code

### Intermittent Operation
- Check for loose connections
- Verify adequate power supply
- Look for electromagnetic interference

## Expansion Possibilities

### Additional Sensors
- Multiple ultrasonic sensors
- PIR motion detectors
- Camera modules
- Environmental sensors

### Communication Modules
- WiFi (ESP8266/ESP32)
- Bluetooth (HC-05)
- LoRa modules
- GSM modules

### Enhanced Outputs
- Multiple servo motors
- Relay modules for high-power devices
- Display modules
- Siren/strobe lights

## Files in This Directory

- `main_circuit.png` - Complete circuit diagram
- `breadboard_layout.png` - Breadboard wiring layout
- `component_pinout.png` - Individual component pinouts
- `installation_guide.pdf` - Physical installation guide
- `pcb_design/` - PCB design files (future enhancement)

*Note: Actual image files should be added to this directory*
