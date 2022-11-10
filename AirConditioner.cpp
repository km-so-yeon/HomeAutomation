#include "AirConditioner.h"

AirConditioner::AirConditioner() : Appliance()
// Appliance는 default 생성자로 생성, machineState는 송풍으로 초기화
{
	machineState = SENDAIR;
	setTemperature = 25;
}
AirConditioner::AirConditioner(string machineName, int powerConsumption) : Appliance(machineName, powerConsumption)
// Appliance는 Overloaded 생성자로 생성, machineState는 송풍으로 초기화
{
	machineState = SENDAIR;
}
														 // getter, setter member function
int AirConditioner::getMachineState() const // machineState 멤버값 반환 함수
{
	return machineState;
}
int AirConditioner::getSetTemperature() const  // setTemperature 멤버값 반환 함수
{
	return setTemperature;
}
void AirConditioner::setMachineState(int machineState) // machineState 멤버 초기화 함수
{
	this->machineState = machineState;
}
void AirConditioner::setSetTemperature(int setTemperature) // setTemperature 멤버 초기화 함수
{
	this->setTemperature = setTemperature;
}
											// member function
AirConditioner & AirConditioner::operator++() // 설정 온도를 1도씩 올린다(prefix increment)
{
	++setTemperature;
	return *this;
}
AirConditioner & AirConditioner::operator--() // 설정 온도를 1도씩 내린다(prefix decrement)
{
	--setTemperature;
	return *this;
}
void AirConditioner::stateView()  // 객체의 상태 출력
{
	cout << "제품명 : " << this->getMachineName();
	if (this->getPowerFlag())
	{
		cout << " (ON) ";
	}
	else
	{
		cout << " (OFF) ";
	}
	cout << "설정상태 : ";
	switch (machineState)
	{
	case 1: cout << "송풍"; break;
	case 2: cout << "냉방"; break;
	case 3: cout << "난방";
	}
	cout << endl;
}