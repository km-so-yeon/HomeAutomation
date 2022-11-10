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
string Appliance::getMachineName() const  // machineName 멤버값 반환 함수
{
	return this->machineName;
}
bool Appliance::getPowerFlag() const // powerFlag 멤버 값 반환 함수 
{
	return this->powerFlag;
}
int Appliance::getPowerConsumption() const // powerConsumtion 멤버 값 반환 함수
{
	return this->powerConsumption;
}
time_t Appliance::getStartHour() // startHour 멤버 값 반환 함수
{
	return this->startHour;
}
time_t Appliance::getUseHour() // useHour 멤버 값 반환 함수
{
	return this->useHour;
}
void Appliance::setMachineName(string machineName)  // machineName 멤버 초기화 함수
{
	this->machineName = machineName;
}
void Appliance::setPowerFlag(bool powerFlag) // powerFlag 멤버 초기화 함수 
{
	this->powerFlag = powerFlag;
}
void Appliance::setPowerConsumption(int powerConsumption) // powerConsumtion 멤버 초기화 함수
{
	this->powerConsumption = powerConsumption;
}
												// member fucntion
bool Appliance::turnOn() // 제품을 켜다
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
bool Appliance::turnOff() // 제품을 끄다
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