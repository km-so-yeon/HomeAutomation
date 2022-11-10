#include "Power.h"

int Power::calPowerConsumption(HomeAutomation &rHa)
{
	time_t time;
	int powerC;
	int totalC = 0;

	for (int i = 0; i < rHa.getApplianceCnt(); i++)
	{
		if (rHa.getApplianceArray()[i]->getPowerFlag() == false)
		{
			time = rHa.getApplianceArray()[i]->getStartHour() - rHa.getApplianceArray()[i]->getUseHour();
			powerC = rHa.getApplianceArray()[i]->getPowerConsumption();
			totalC += (int)time * powerC;
		}
	}
	return totalC;
}