#if defined(PID_H)
#define PID_H

struct PIDController {
	float kP, kI, kD, iAccumulator, setPoint;

}

float PIDUpdate(float input, struct PIDController *ctr) {
	float output = 0;
	output += ctr->kP * (input - ctr->setPoint);
	//output += ctr->kI * ();


}

#endif
