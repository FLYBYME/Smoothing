#include "smoothing.h"

SMOOTHING::SMOOTHING(int count) {
	numReadings = count;


}

void SMOOTHING::begin() {
	for (int thisReading = 0; thisReading < numReadings; thisReading++) {
		readings[thisReading] = 0;
	}
}

int SMOOTHING::getAverage() {
	return average;
}

int SMOOTHING::getLast() {
	return last;
}

void SMOOTHING::add(int reading) {
	last = reading;
	total = total - readings[readIndex];
	// read from the sensor:
	readings[readIndex] = reading;
	// add the reading to the total:
	total = total + readings[readIndex];
	// advance to the next position in the array:
	readIndex = readIndex + 1;

	// if we're at the end of the array...
	if (readIndex >= numReadings) {
		// ...wrap around to the beginning:
		readIndex = 0;
	}

	// calculate the average:
	average = total / numReadings;

}
