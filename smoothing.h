
#ifndef SMOOTHING_h
#define SMOOTHING_h



class SMOOTHING
{
public:
	SMOOTHING(int count = 10);
	int getAverage();
	int getLast();
	void add(int reading);
	void begin();
private:
	int numReadings = 10;

	int readings[10];      // the readings from the analog input
	int readIndex = 0;              // the index of the current reading
	int total = 0;                  // the running total
	int average = 0;
	int last = 0;
	int perSecond = 0;
};

#endif
