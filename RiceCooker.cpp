#include "RiceCooker.h"

RiceCooker::RiceCooker() : Appliance() // Appliance는 default생성자로 생성, machineState는 무동작으로 초기화
{
	machineState = NO_OPERATION;
}
RiceCooker::RiceCooker(string machineName, int powerConsumption) : Appliance(machineName, powerConsumption) 
// Appliance는 Overloaded 생성자로 생성, machineState는 무동작으로 초기화
{
	machineState = NO_OPERATION;
}
													  // getter, setter member function
int RiceCooker::getMachineState() const // machineState 멤버 값 반환 함수
{
	return machineState;
}
void RiceCooker::setMachineState(int machineState) // machineState 멤버 초기화 함수
{
	this->machineState = machineState;
}
										// member function
void RiceCooker::stateView() // 객체의 상태 출력
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
	case 1: cout << "무동작"; break;
	case 2: cout << "보온"; break;
	case 3: cout << "밥짓기"; break;
	case 4: cout << "데우기";
	}
	cout << endl;
}