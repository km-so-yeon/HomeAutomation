#include "HomeAutomation.h"
#include <iostream>

HomeAutomation::HomeAutomation()
// appliaceArray�� �޸� ������ ��� 0���� �ʱ�ȭ �ϰ�, applianceCnt�� 0���� �ʱ�ȭ
{
	for (int i = 0; i < APPLIANCE_MAX_CNT; i++)
	{
		applianceArray[i] = 0;
	}
	applianceCnt = 0;
}
HomeAutomation::HomeAutomation(const HomeAutomation &r)// deep copy constructor
{
	for (int i = 0; i < r.applianceCnt; i++)
	{
		if (dynamic_cast<RiceCooker *>(r.applianceArray[i]) != 0)
		{
			this->applianceArray[i] = new RiceCooker;
			this->applianceArray[i] = r.applianceArray[i];
		}
		else if (dynamic_cast<Washer *>(r.applianceArray[i]) != 0)
		{
			this->applianceArray[i] = new Washer;
			this->applianceArray[i] = r.applianceArray[i];
		}
		else if (dynamic_cast<AirConditioner *>(r.applianceArray[i]) != 0)
		{
			this->applianceArray[i] = new AirConditioner;
			this->applianceArray[i] = r.applianceArray[i];
		}
	}
	this->applianceCnt++;
}
HomeAutomation::~HomeAutomation() // applianceArray�� ���� �Ҵ�� ��ü�� ��� ������
{
	for (int i = 0; i < applianceCnt; i++)
	{
		delete this->applianceArray[i];
	}
}
				   // getter, setter member function
Appliance ** HomeAutomation::getApplianceArray() // applianceArray ��� �� ��ȯ �Լ�
{
	return this->applianceArray;
}
int HomeAutomation::getApplianceCnt() const // applianceCnt ��� �� ��ȯ �Լ�
{
	return this->applianceCnt;
}
							 // member function
HomeAutomation & HomeAutomation::operator=(const HomeAutomation &r)
// ����(�Ҵ�)������ �����ε� �Լ�
{
	if (this == &r) return *this;
	for (int i = 0; i < this->applianceCnt; i++)
	{
		delete this->applianceArray[i];
	}
	for (int i = 0; i < r.applianceCnt; i++)
	{
		if (dynamic_cast<RiceCooker *>(r.applianceArray[i]) != 0)
		{
			this->applianceArray[i] = new RiceCooker;
			this->applianceArray[i] = r.applianceArray[i];
		}
		else if (dynamic_cast<Washer *>(r.applianceArray[i]) != 0)
		{
			this->applianceArray[i] = new Washer;
			this->applianceArray[i] = r.applianceArray[i];
		}
		else if (dynamic_cast<AirConditioner *>(r.applianceArray[i]) != 0)
		{
			this->applianceArray[i] = new AirConditioner;
			this->applianceArray[i] = r.applianceArray[i];
		}
	}
	this->applianceCnt = r.applianceCnt;
	return *this;
}

bool HomeAutomation::addAppliance(Appliance *ap)	// ������ǰ�� ��Ͽ� �߰�.  ������ ��ǰ�� �߰� �Ұ���. 
{
	if (this->applianceCnt >= APPLIANCE_MAX_CNT) return false;
	else
	{
		if (dynamic_cast<RiceCooker *>(ap) != 0)
		{
			this->applianceArray[this->applianceCnt] = new RiceCooker;
			this->applianceArray[this->applianceCnt] = ap;
		}
		else if (dynamic_cast<Washer *>(ap) != 0)
		{
			this->applianceArray[this->applianceCnt] = new Washer;
			this->applianceArray[this->applianceCnt] = ap;
		}
		else if (dynamic_cast<AirConditioner *>(ap) != 0)
		{
			this->applianceArray[this->applianceCnt] = new AirConditioner;
			this->applianceArray[this->applianceCnt] = ap;
		}
		this->applianceCnt++;
		return true;
	}
}
int HomeAutomation::searchMachine(string machineName) // ������ǰ�� �ش��ϴ� ������ǰ�� ã�Ƽ� �迭�� index����/���� �� -1 ����
{
	for (int i = 0; i < this->applianceCnt; i++)
	{
		if (this->applianceArray[i]->getMachineName()==machineName)
		{
			return i;
		}
	}
	return -1;
}
bool HomeAutomation::deleteAppliance(string machineName) // ������ǰ�� �ش��ϴ� ������ǰ�� ��Ͽ��� �����ϴ�
{
	for (int i = 0; i < this->applianceCnt; i++)
	{
		if (this->applianceArray[i]->getMachineName() == machineName)
		{
			delete this->applianceArray[i];
			for (int j = i; i < this->applianceCnt - 1; j++)
			{
				this->applianceArray[j] = this->applianceArray[j + 1];
			}
			this->applianceCnt--;
			return true;
		}
	}
	return false;
}
void HomeAutomation::listDisplayAppliance() // ��ϵ� ������ǰ ��ü ��� �� ���¸�  Ȯ���ϴ�
{
	for (int i = 0; i < applianceCnt; i++)
	{
		cout << "��ǰ�� : " << this->applianceArray[i]->getMachineName();
		if (this->applianceArray[i]->getPowerFlag())
		{
			cout << "(ON)" << endl;
		}
		else
		{
			cout << "(OFF)" << endl;
		}
	}
}
bool HomeAutomation::controlAppliance(string machineName)   // �ش� ������ǰ�� �����ϴ�
{
	int temp = -1;
	int state;
	char yn;

	for (int i = 0; i < this->applianceCnt; i++)
	{
		if (this->applianceArray[i]->getMachineName() == machineName)
		{
			temp = i;
			break;
		}
	}

	if (temp != -1)
	{
		if (dynamic_cast<RiceCooker *>(this->applianceArray[temp]) != 0)
		{
			RiceCooker *rp = dynamic_cast<RiceCooker *>(this->applianceArray[temp]);
			if (this->applianceArray[temp]->getPowerFlag())
			{
				cout << "������ ���ðڽ��ϱ�?(Y/N) : ";
				cin >> yn;
				if (yn == 'Y')
				{
					rp->turnOff();
					return true;
				}
			}
			else
			{
				cout << "������ �ѽðڽ��ϱ�?(Y/N) : ";
				cin >> yn;
				if (yn == 'Y')
				{
					rp->turnOn();
				}
				else
				{
					return true;
				}
			}
			cout << "1.������ / 2.���� / 3.������ / 4.����� : ";
			cin >> state;
			rp->setMachineState(state);
			rp->stateView();
			return true;
		}

		else if (dynamic_cast<Washer *>(this->applianceArray[temp]) != 0)
		{
			Washer *wp = dynamic_cast<Washer *>(this->applianceArray[temp]);
			if (this->applianceArray[temp]->getPowerFlag())
			{
				cout << "������ ���ðڽ��ϱ�?(Y/N) : ";
				cin >> yn;
				if (yn == 'Y')
				{
					wp->turnOff();
					return true;
				}
			}
			else
			{
				cout << "������ �ѽðڽ��ϱ�?(Y/N) : ";
				cin >> yn;
				if (yn == 'Y')
				{
					wp->turnOn();
				}
				else
				{
					return true;
				}
			}
			cout << "1.������ / 2.�Ϲݻ��� / 3.�������� / 4.���� : ";
			cin >> state;
			wp->setMachineState(state);
			wp->stateView();
			return true;
		}

		else if (dynamic_cast<AirConditioner *>(this->applianceArray[temp]) != 0)
		{
			AirConditioner *ap = dynamic_cast<AirConditioner *>(this->applianceArray[temp]);
			if (this->applianceArray[temp]->getPowerFlag())
			{
				cout << "������ ���ðڽ��ϱ�?(Y/N) : ";
				cin >> yn;
				if (yn == 'Y')
				{
					ap->turnOff();
					return true;
				}
			}
			else
			{
				cout << "������ �ѽðڽ��ϱ�?(Y/N) : ";
				cin >> yn;
				if (yn == 'Y')
				{
					ap->turnOn();
				}
				else
				{
					return true;
				}
			}
			cout << "1.��ǳ / 2.�ù� / 3.���� : ";
			cin >> state;
			ap->setMachineState(state);

			cout << "1.�µ� �ø��� / 2.�µ� ������ / 3.�µ����� ���� : ";
			cin >> state;
			switch (state)
			{
			case 1:	ap++; break;
			case 2: ap--; break;
			case 3: ap->stateView();
			}

			return true;
		}
	}

	cout << "** �ش��ϴ� ��ǰ�� �������� �ʽ��ϴ�." << endl;
	return false;
}

void HomeAutomation::setStateAppliance(Appliance * ap) // �����ִ� ������ǰ�� ���¸� �����ϴ�
{
	char yn;
	int state;

	for (int i = 0; i < this->applianceCnt; i++)
	{
		if (this->applianceArray[i]->getPowerFlag())
		{
			if (dynamic_cast<RiceCooker *>(this->applianceArray[i]) != 0)
			{
				RiceCooker *rp = dynamic_cast<RiceCooker *>(this->applianceArray[i]);
				if (this->applianceArray[i]->getPowerFlag())
				{
					;
				}
				else
				{
					cout << "������ �ѽðڽ��ϱ�?(Y/N) : ";
					cin >> yn;
					if (yn == 'Y')
					{
						rp->turnOn();
					}
				}
				cout << "1.������ / 2.���� / 3.������ / 4.����� : ";
				cin >> state;
				rp->setMachineState(state);
				rp->stateView();
			}

			else if (dynamic_cast<Washer *>(this->applianceArray[i]) != 0)
			{
				Washer *wp = dynamic_cast<Washer *>(this->applianceArray[i]);
				if (this->applianceArray[i]->getPowerFlag())
				{
					;
				}
				else
				{
					cout << "������ �ѽðڽ��ϱ�?(Y/N) : ";
					cin >> yn;
					if (yn == 'Y')
					{
						wp->turnOn();
					}
				}
				cout << "1.������ / 2.�Ϲݻ��� / 3.�������� / 4.���� : ";
				cin >> state;
				wp->setMachineState(state);
				wp->stateView();
			}

			else if (dynamic_cast<AirConditioner *>(this->applianceArray[i]) != 0)
			{
				AirConditioner *ap = dynamic_cast<AirConditioner *>(this->applianceArray[i]);
				if (this->applianceArray[i]->getPowerFlag())
				{
					;
				}
				else
				{
					cout << "������ �ѽðڽ��ϱ�?(Y/N) : ";
					cin >> yn;
					if (yn == 'Y')
					{
						ap->turnOn();
					}
				}
				cout << "1.��ǳ / 2.�ù� / 3.���� : ";
				cin >> state;
				ap->setMachineState(state);
				cout << "1.�µ� �ø��� / 2.�µ� ������ / 3.�µ����� ���� : ";
				cin >> state;
				switch (state)
				{
				case 1:	ap++; break;
				case 2: ap--; break;
				case 3: ap->stateView();
				}
			}
		}
	}
}