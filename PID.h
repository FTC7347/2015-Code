#if defined(PID_H)
#define PID_H

struct PIDController {
	float kP, kI, kD, iAccumulator, setPoint;
	bool cont;
	int lastTime;
	float maxOutput, maxInput, minOutput, minInput;
	float prevError;
}

float PIDUpdate(float input, struct PIDController *ctr) {
	float output = 0;
	float error = ctr->setPoint - input;
	if(ctr->cont) {
		if (fabs(error)>(ctr->maxInput - ctr->minInput)/2) {
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
	result = ctr->kP * error + ctr->kI * ctr->iAccumulator + ctr->kD * (error - ctr->prevError);
	ctr->prevError = error;
	if (result > ctr->maxOutput) result = ctr->maxOutput;
	else if (result < ctr->minOutput) result = ctr->minOutput;

	return result;
}

#endif
