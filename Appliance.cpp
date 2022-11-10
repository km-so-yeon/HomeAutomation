#include "Appliance.h"

Appliance::Appliance()  // default constructor (machineName:Null string, powerFlag:false, powerConsumption:0, startHour:0, useHour:0)
{
	machineName = "";
	powerFlag = false;
	powerConsumption = 0;
	startHour = 0;
	useHour = 0;
}
Appliance::Appliance(string machineName, int powerConsumption, bool powerFlag, time_t startHour, time_t useHour)
{
	this->machineName = machineName;
	this->powerConsumption = powerConsumption;
	this->powerFlag = powerFlag;
	this->startHour = startHour;
	this->useHour = useHour;
}
						 // getter, setter member function
string Appliance::getMachineName() const  // machineName ����� ��ȯ �Լ�
{
	return this->machineName;
}
bool Appliance::getPowerFlag() const // powerFlag ��� �� ��ȯ �Լ� 
{
	return this->powerFlag;
}
int Appliance::getPowerConsumption() const // powerConsumtion ��� �� ��ȯ �Լ�
{
	return this->powerConsumption;
}
time_t Appliance::getStartHour() // startHour ��� �� ��ȯ �Լ�
{
	return this->startHour;
}
time_t Appliance::getUseHour() // useHour ��� �� ��ȯ �Լ�
{
	return this->useHour;
}
void Appliance::setMachineName(string machineName)  // machineName ��� �ʱ�ȭ �Լ�
{
	this->machineName = machineName;
}
void Appliance::setPowerFlag(bool powerFlag) // powerFlag ��� �ʱ�ȭ �Լ� 
{
	this->powerFlag = powerFlag;
}
void Appliance::setPowerConsumption(int powerConsumption) // powerConsumtion ��� �ʱ�ȭ �Լ�
{
	this->powerConsumption = powerConsumption;
}
												// member fucntion
bool Appliance::turnOn() // ��ǰ�� �Ѵ�
{
	time_t currentTime;
	time(&currentTime);
	if (powerFlag == false)
	{
		powerFlag = true;
		startHour = currentTime;
		return true;
	}
	return false;
}
bool Appliance::turnOff() // ��ǰ�� ����
{
	time_t currentTime;
	time(&currentTime);
	if (powerFlag == true)
	{
		powerFlag = true;
		useHour = currentTime;
		return true;
	}
	return false;
}