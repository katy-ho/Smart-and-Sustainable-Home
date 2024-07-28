# Arduino Smart and Sustainable Home

## Description
This project is an Arduino-based home automation system designed to control various aspects of a smart home. It includes functionalities such as door control, doorbell, light automation, and a password-protected sequence activation for added security. The system uses different sensors and actuators to provide a seamless and automated experience for the user.

## Features
1. **Door Control**: Automatically opens and closes the door using a servo motor controlled by a push button.
2. **Doorbell**: Activates a melody when the doorbell button is pressed.
3. **Light Automation**: Controls lights based on ambient light levels using an LDR (Light Dependent Resistor) and manual toggle switch.
4. **Ultrasonic Distance Measurement**: Turns on a room light when an object is detected within a certain distance using an ultrasonic sensor.
5. **Password Sequence Activation**: Implements a three-stage password entry system to activate the servo motor.

## Components
- Arduino Board
- Servo Motor
- Push Buttons
- LDR (Light Dependent Resistor)
- Ultrasonic Sensor
- LED Lights
- Buzzer

## Pin Configuration
- **Servo Motor**: Pin 3
- **Push Button for Door**: Pin 5
- **Doorbell Button**: Pin 2
- **Buzzer**: Pin 8
- **LDR**: Pin A0
- **Balcony Light**: Pin 7
- **Manual Light Control Button**: Pin 4
- **Room Light**: Pin 11
- **Password Entry Button**: Pin 6
- **Password Confirm Button**: Pin 13
- **Ultrasonic Sensor**: Trigger Pin 9, Echo Pin 10

## Usage
1. **Setup**: Connect the components to the Arduino board as per the pin configuration.
2. **Upload Code**: Upload the provided code to the Arduino board using the Arduino IDE.
3. **Operation**:
   - Press the door button to toggle the door's servo motor.
   - Press the doorbell button to hear the melody.
   - The balcony light will turn on automatically when it gets dark.
   - Use the manual toggle switch to control an additional light.
   - The room light will turn on when an object is detected within 10 cm.
   - Use the password buttons to enter a sequence and activate the servo motor if the sequence is correct.

## Code Explanation
- **readUltrasonicDistance**: Function to read distance using the ultrasonic sensor.
- **setup**: Initializes the pins and serial communication.
- **loop**: Main loop that continuously checks the state of buttons and sensors to perform actions.
- **incrementCounter**: Increments the respective stage counter based on the current stage.
- **handleStageTransition**: Handles the transition between different stages of the password entry.
- **checkSequence**: Checks the entered password sequence and activates the servo motor if correct.

## Notes
- Ensure all connections are secure and the components are properly interfaced with the Arduino board.
- Modify the pin configuration in the code if necessary to match your setup.

## Example
Here's an example of how to use the system:
1. Press the door button to open/close the door.
2. Press the doorbell button to hear the melody.
3. Observe the balcony light turning on automatically when it gets dark.
4. Use the manual toggle switch to control another light.
5. Approach the ultrasonic sensor to see the room light turn on.
6. Enter the password sequence using the buttons to activate the servo motor.

