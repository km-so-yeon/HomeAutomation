#ifndef __POWER_H__		// #pragma once : ������� �������� Ǯ���� ���� �����ϴ� ��
#define __POWER_H__
#include "Appliance.h"
#include "HomeAutomation.h"

class HomeAutomation;  // ���漱��(foward ����)

class Power
{
public :
	Power() {}
	int calPowerConsumption(HomeAutomation &rHa);  // ���� ��ǰ�� ���� �Ҹ��� ������
};
#endif