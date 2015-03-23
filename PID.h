#if !defined(PID_H)
#define PID_H

typedef struct PIDController {
	float kP, kI, kD, iAccumulator, setPoint, maxOutput,
	maxInput, minOutput, minInput, prevError;
	bool cont;
	int lastTime;
} PIDController;

float PIDUpdate(float input, PIDController *ctr) {
	float result = 0;
	float error = ctr->setPoint - input;
	if(ctr->cont) {
		if (abs(error)>(ctr->maxInput - ctr->minInput)/2) {
			if (error > 0) {
				error = error - ctr->maxInput + ctr->minInput;
			} else {
				error = error + ctr->maxInput - ctr->minInput;
			}
		}
	}
	if (ctr->kI != 0) {
		float potentialIGain = (ctr->iAccumulator + error) * ctr->kI;
		if (potentialIGain < ctr->maxOutput) {
			if (potentialIGain > ctr->minOutput) {
				ctr->iAccumulator += error;
			} else {
				ctr->iAccumulator = ctr->minOutput / ctr->kI;
			}
		} else {
			ctr->iAccumulator = ctr->maxOutput / ctr->kI;
		}
	}
	//nxtDisplayCenteredTextLine(3, "error: %d", error);
	//nxtDisplayCenteredTextLine(4, "P:%d, kP: %d", ctr->kP * error, ctr->kP);
	result = ctr->kP * error + ctr->kI * ctr->iAccumulator + ctr->kD * (error - ctr->prevError);
	ctr->prevError = error;
	if (result > ctr->maxOutput) result = ctr->maxOutput;
	else if (result < ctr->minOutput) result = ctr->minOutput;

	return result;
}

#endif
