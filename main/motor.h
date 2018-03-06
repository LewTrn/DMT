#ifndef motor_h
#define motor_h

#define urban		1 // Urban road motor speed mode
#define motorway	2 // Motorway motor speed mode
#define underground	3 // London underground motor speed mode

#define outMin 		25 // Minimum PID output value
#define outMax 		230 // Maximum PID output value

#define outPinA		3 // Arduino motor output pins (must be PWM output)
#define outPinB		0
#define outPinC		0

#define setScaling 	( (0.625*count) - 19 ) // Scale the count mode with encoder speed (linear relationship)

#define MotorPinA	7 // Arduino interrupt input pins (must share the same interrupt vectors)
#define MotorPinB	0
#define MotorPinC 	0

class motorClass {
  private:
    volatile double encoderPos; // Encoder cycle count
    volatile double count; // Running total set cycle count

  public:
    volatile double increment; // Scale of count increment

    char Kp, Ki, Kd; // PID control constants
    double set, in, out; // PID control

    motorClass(double initialSet, double initialPos): set(initialSet), encoderPos(initialPos) {} // Motor class constructor

    void UpdateSet(); // Update PID control input parameters
    void Encoder(); // Increment the encoder count when triggered
    void DebugDisplay(); // Display chosen variable to the serial monitor
};

extern motorClass motorA; // Declaring motor A class
extern motorClass motorB; // Declaring motor B class
extern motorClass motorC; // Declaring motor C class

void motorInitialise(); // Set up motor pins and interrupt functions
void setMode(char mode);

void assignEncoderA(); // Assign the encoder increment function to Motor A when called
void assignEncoderB(); // Assign the encoder increment function to Motor B when called
void assignEncoderC(); // Assign the encoder increment function to Motor C when called

#endif