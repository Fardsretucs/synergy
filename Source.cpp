#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

class BranchFinances {
public:
	int Room_rent() { //��������� �������� ����� �� �����
		return 50 + ((Profit - 270) * 0.07);
	}

	int All_expenses() { //��������� ��� ������� �� �����
		return Salary + Room_rent() + Auror_Services;
	}

	void print_All_expenses() { //������� �� ����� ��� �������
		cout << "��� �������: " << All_expenses() << endl;
		cout << " -�� �����������: " << Salary << endl;
		cout << " -�������� �����: " << Room_rent() << endl;
		cout << " -������ �����������: " << Auror_Services << endl;
	}

	int Net_Profit() { //��������� ������ �������
		return Profit - All_expenses();
	}

	int get_profit() { //��������� �������
		return Profit;
	}
protected:
	int Profit; //�������
	const int Salary = 35; //�������� �����������
	const int Auror_Services = 15; //������ �����������

	void Profit_Generator() { //���������� ������� �� �����
		srand(time(NULL));
		Profit = rand() % 250 + 250;
	}
};

class NewBranch : public BranchFinances{
public:
	NewBranch() = delete; //������ ����������� �� ���������
	NewBranch(string Name_Branch) { //������ ���� �����������
		this->Name_Branch = Name_Branch;
		Profit_Generator();
	}

	~NewBranch() { //����������
		cout << "���������� �������� ����������!" << endl;
	}
private:
	string Name_Branch; //�������� �����
};

int main() {
	setlocale(LC_ALL, "ru"); //� ���� �������� setlocale, �� ���� ���� ����� �������� �� �������, ��������� ������� ���, ������ ��� ������
	string Name_Brinch;
	string UnderScope(40, '_');

	cout << "������ ����, �������� ����������!" << endl;
	cout << "������� �������� ����� ���������� � ������� �� ������ ������: ";
	cin >> Name_Brinch;
	NewBranch obj(Name_Brinch);
	system("cls");

	cout << "���������� � ����� \"" << Name_Brinch << "\"" << endl; //�������� �����, ������ 54(���������� ������), ������ 59(���������� � ����, ��� � ������������ ��� ������)
	cout << UnderScope << endl;
	obj.print_All_expenses(); //��� �������, ������ 17(�����)
	cout << UnderScope << endl;
	cout << "�������: " << obj.get_profit() << endl; //�������, ������ 32(����������), ������ 28(�����)
	cout << UnderScope << endl;
	cout << "������ �������: " << obj.Net_Profit() << endl; //������ �������, ������ 24
}