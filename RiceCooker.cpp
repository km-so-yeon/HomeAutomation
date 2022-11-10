#include "RiceCooker.h"

RiceCooker::RiceCooker() : Appliance() // Appliance�� default�����ڷ� ����, machineState�� ���������� �ʱ�ȭ
{
	machineState = NO_OPERATION;
}
RiceCooker::RiceCooker(string machineName, int powerConsumption) : Appliance(machineName, powerConsumption) 
// Appliance�� Overloaded �����ڷ� ����, machineState�� ���������� �ʱ�ȭ
{
	machineState = NO_OPERATION;
}
													  // getter, setter member function
int RiceCooker::getMachineState() const // machineState ��� �� ��ȯ �Լ�
{
	return machineState;
}
void RiceCooker::setMachineState(int machineState) // machineState ��� �ʱ�ȭ �Լ�
{
	this->machineState = machineState;
}
										// member function
void RiceCooker::stateView() // ��ü�� ���� ���
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
	case 2: cout << "����"; break;
	case 3: cout << "������"; break;
	case 4: cout << "�����";
	}
	cout << endl;
}