#include "Washer.h"

Washer::Washer() : Appliance()
{
	machineState = NO_OPERATION;
}

Washer::Washer(string machineName, int powerConsumption) : Appliance(machineName, powerConsumption) 
// Appliance는 Overloaded 생성자로 생성, machineState는 무동작으로 초기화
{
	machineState = NO_OPERATION;
}
												  // getter, setter member function
int Washer::getMachineState() const // machineState 멤버 값 반환 함수
{
	return machineState;
}
void Washer::setMachineState(int machineState) // machineState 멤버 초기화 함수
{
	this->machineState = machineState;
}
										// member function
void Washer::stateView()
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
	case 2: cout << "일반빨래"; break;
	case 3: cout << "삶은빨래"; break;
	case 4: cout << "건조";
	}
	cout << endl;
}