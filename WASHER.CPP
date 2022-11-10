#include "Washer.h"

Washer::Washer() : Appliance()
{
	machineState = NO_OPERATION;
}

Washer::Washer(string machineName, int powerConsumption) : Appliance(machineName, powerConsumption) 
// Appliance�� Overloaded �����ڷ� ����, machineState�� ���������� �ʱ�ȭ
{
	machineState = NO_OPERATION;
}
												  // getter, setter member function
int Washer::getMachineState() const // machineState ��� �� ��ȯ �Լ�
{
	return machineState;
}
void Washer::setMachineState(int machineState) // machineState ��� �ʱ�ȭ �Լ�
{
	this->machineState = machineState;
}
										// member function
void Washer::stateView()
{
	cout << "��ǰ�� : " << this->getMachineName();
	if (this->getPowerFlag())
	{
		cout << " (ON) ";
	}
	else
	{
		cout << " (OFF) ";
	}
	cout << "�������� : ";
	switch (machineState)
	{
	case 1: cout << "������"; break;
	case 2: cout << "�Ϲݻ���"; break;
	case 3: cout << "��������"; break;
	case 4: cout << "����";
	}
	cout << endl;
}