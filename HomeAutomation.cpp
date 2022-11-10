#include "HomeAutomation.h"
#include <iostream>

HomeAutomation::HomeAutomation()
// appliaceArray의 메모리 영역을 모두 0으로 초기화 하고, applianceCnt를 0으로 초기화
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
HomeAutomation::~HomeAutomation() // applianceArray에 동적 할당된 객체를 모두 해제함
{
	for (int i = 0; i < applianceCnt; i++)
	{
		delete this->applianceArray[i];
	}
}
				   // getter, setter member function
Appliance ** HomeAutomation::getApplianceArray() // applianceArray 멤버 값 반환 함수
{
	return this->applianceArray;
}
int HomeAutomation::getApplianceCnt() const // applianceCnt 멤버 값 반환 함수
{
	return this->applianceCnt;
}
							 // member function
HomeAutomation & HomeAutomation::operator=(const HomeAutomation &r)
// 대입(할당)연산자 오버로딩 함수
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

bool HomeAutomation::addAppliance(Appliance *ap)	// 가전제품을 목록에 추가.  동일한 제품명 추가 불가능. 
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
int HomeAutomation::searchMachine(string machineName) // 가전제품명에 해당하는 가전제품을 찾아서 배열의 index리턴/없을 시 -1 리턴
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
bool HomeAutomation::deleteAppliance(string machineName) // 가전제품명에 해당하는 가전제품을 목록에서 삭제하다
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
void HomeAutomation::listDisplayAppliance() // 등록된 가전제품 전체 목록 및 상태를  확인하다
{
	for (int i = 0; i < applianceCnt; i++)
	{
		cout << "제품명 : " << this->applianceArray[i]->getMachineName();
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
bool HomeAutomation::controlAppliance(string machineName)   // 해당 가전제품을 제어하다
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
				cout << "전원을 끄시겠습니까?(Y/N) : ";
				cin >> yn;
				if (yn == 'Y')
				{
					rp->turnOff();
					return true;
				}
			}
			else
			{
				cout << "전원을 켜시겠습니까?(Y/N) : ";
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
			cout << "1.무동작 / 2.보온 / 3.밥짓기 / 4.데우기 : ";
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
				cout << "전원을 끄시겠습니까?(Y/N) : ";
				cin >> yn;
				if (yn == 'Y')
				{
					wp->turnOff();
					return true;
				}
			}
			else
			{
				cout << "전원을 켜시겠습니까?(Y/N) : ";
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
			cout << "1.무동작 / 2.일반빨래 / 3.삶은빨래 / 4.건조 : ";
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
				cout << "전원을 끄시겠습니까?(Y/N) : ";
				cin >> yn;
				if (yn == 'Y')
				{
					ap->turnOff();
					return true;
				}
			}
			else
			{
				cout << "전원을 켜시겠습니까?(Y/N) : ";
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
			cout << "1.송풍 / 2.냉방 / 3.난방 : ";
			cin >> state;
			ap->setMachineState(state);

			cout << "1.온도 올리기 / 2.온도 내리기 / 3.온도조절 종료 : ";
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

	cout << "** 해당하는 제품이 존재하지 않습니다." << endl;
	return false;
}

void HomeAutomation::setStateAppliance(Appliance * ap) // 켜져있는 가전제품의 상태를 변경하다
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
					cout << "전원을 켜시겠습니까?(Y/N) : ";
					cin >> yn;
					if (yn == 'Y')
					{
						rp->turnOn();
					}
				}
				cout << "1.무동작 / 2.보온 / 3.밥짓기 / 4.데우기 : ";
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
					cout << "전원을 켜시겠습니까?(Y/N) : ";
					cin >> yn;
					if (yn == 'Y')
					{
						wp->turnOn();
					}
				}
				cout << "1.무동작 / 2.일반빨래 / 3.삶은빨래 / 4.건조 : ";
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
					cout << "전원을 켜시겠습니까?(Y/N) : ";
					cin >> yn;
					if (yn == 'Y')
					{
						ap->turnOn();
					}
				}
				cout << "1.송풍 / 2.냉방 / 3.난방 : ";
				cin >> state;
				ap->setMachineState(state);
				cout << "1.온도 올리기 / 2.온도 내리기 / 3.온도조절 종료 : ";
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