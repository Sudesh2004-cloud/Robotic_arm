#include <Servo.h>

// Declare servo objects for each joint of the robotic arm
Servo base;       // Base rotation
Servo p;          // Shoulder joint
Servo a;          // Elbow joint
Servo q;          // (Optional/Extra) joint - not actively used in this code
Servo end_rot;    // Wrist rotation
Servo close;      // Gripper (open/close)

void setup() {
  // Attach each servo to its corresponding PWM pin
  base.attach(7);
  p.attach(6);
  a.attach(5);
  q.attach(4);
  end_rot.attach(3);
  close.attach(2);

  // Initialize all servos to neutral position (90 degrees)
  base.write(90);
  p.write(90);
  a.write(90);
  q.write(90);
  end_rot.write(90);
  close.write(90);

  delay(3000); // Wait for servos to reach the neutral position
}

void loop() {
  // Start movement sequence

  // Step 1: Rotate base to far left
  base.write(0);
  delay(1000);

  // Step 2: Adjust shoulder and elbow
  p.write(45);    // Shoulder down
  delay(1000);
  a.write(135);   // Elbow up
  delay(1000);

  // Step 3: Rotate wrist and open gripper
  end_rot.write(45);
  delay(1000);
  close.write(90); // Open gripper
  delay(1000);

  // Step 4: Close gripper (simulate pick)
  close.write(180);
  delay(1000);

  // Step 5: Move base back to center
  base.write(90);
  delay(1000);

  // Step 6: Simulate release
  close.write(90);  // Open gripper
  delay(1000);
  close.write(180); // Close gripper again
  delay(1000);

  // Step 7: Reset all positions to neutral
  base.write(90);
  p.write(90);
  a.write(90);
  q.write(90);
  end_rot.write(90);
  close.write(90);
  
  delay(3000); // Wait before repeating the loop
}

