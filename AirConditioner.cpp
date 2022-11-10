#include "AirConditioner.h"

AirConditioner::AirConditioner() : Appliance()
// Appliance�� default �����ڷ� ����, machineState�� ��ǳ���� �ʱ�ȭ
{
	machineState = SENDAIR;
	setTemperature = 25;
}
AirConditioner::AirConditioner(string machineName, int powerConsumption) : Appliance(machineName, powerConsumption)
// Appliance�� Overloaded �����ڷ� ����, machineState�� ��ǳ���� �ʱ�ȭ
{
	machineState = SENDAIR;
}
														 // getter, setter member function
int AirConditioner::getMachineState() const // machineState ����� ��ȯ �Լ�
{
	return machineState;
}
int AirConditioner::getSetTemperature() const  // setTemperature ����� ��ȯ �Լ�
{
	return setTemperature;
}
void AirConditioner::setMachineState(int machineState) // machineState ��� �ʱ�ȭ �Լ�
{
	this->machineState = machineState;
}
void AirConditioner::setSetTemperature(int setTemperature) // setTemperature ��� �ʱ�ȭ �Լ�
{
	this->setTemperature = setTemperature;
}
											// member function
AirConditioner & AirConditioner::operator++() // ���� �µ��� 1���� �ø���(prefix increment)
{
	++setTemperature;
	return *this;
}
AirConditioner & AirConditioner::operator--() // ���� �µ��� 1���� ������(prefix decrement)
{
	--setTemperature;
	return *this;
}
void AirConditioner::stateView()  // ��ü�� ���� ���
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
	case 1: cout << "��ǳ"; break;
	case 2: cout << "�ù�"; break;
	case 3: cout << "����";
	}
	cout << endl;
}