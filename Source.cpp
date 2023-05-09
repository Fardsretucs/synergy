#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

class BranchFinances {
public:
	int Room_rent() { //Вычисляет арендную плату за месяц
		return 50 + ((Profit - 270) * 0.07);
	}

	int All_expenses() { //Вычисляет все расходы за месяц
		return Salary + Room_rent() + Auror_Services;
	}

	void print_All_expenses() { //Выводит на экран все расходы
		cout << "Все расходы: " << All_expenses() << endl;
		cout << " -ЗП сотрудников: " << Salary << endl;
		cout << " -Арендная плата: " << Room_rent() << endl;
		cout << " -Услуги мракоборцев: " << Auror_Services << endl;
	}

	int Net_Profit() { //Получение чистой прибыли
		return Profit - All_expenses();
	}

	int get_profit() { //Получение выручки
		return Profit;
	}
protected:
	int Profit; //Выручка
	const int Salary = 35; //Зарплата сотрудников
	const int Auror_Services = 15; //Услуги мракоборцев

	void Profit_Generator() { //Генерирует выручку за месяц
		srand(time(NULL));
		Profit = rand() % 250 + 250;
	}
};

class NewBranch : public BranchFinances{
public:
	NewBranch() = delete; //Удаляю конструктор по умолчанию
	NewBranch(string Name_Branch) { //Создаю свой конструктор
		this->Name_Branch = Name_Branch;
		Profit_Generator();
	}

	~NewBranch() { //Деструктор
		cout << "Досвидания господин Олливандер!" << endl;
	}
private:
	string Name_Branch; //Название лавки
};

int main() {
	setlocale(LC_ALL, "ru"); //У меня прописан setlocale, но если дать лавке название на русском, выведится непойми что, почему так незнаю
	string Name_Brinch;
	string UnderScope(40, '_');

	cout << "Добрый день, господин Олливандер!" << endl;
	cout << "Введите название лавки информацию о которой вы хотите узнать: ";
	cin >> Name_Brinch;
	NewBranch obj(Name_Brinch);
	system("cls");

	cout << "Информация о лавке \"" << Name_Brinch << "\"" << endl; //Название лавки, строка 54(переменная класса), строка 59(переменная в маин, она и используется для вывода)
	cout << UnderScope << endl;
	obj.print_All_expenses(); //Все расходы, строка 17(метод)
	cout << UnderScope << endl;
	cout << "Выручка: " << obj.get_profit() << endl; //Выручка, строка 32(переменная), строка 28(метод)
	cout << UnderScope << endl;
	cout << "Чистая прибыль: " << obj.Net_Profit() << endl; //Чистая прибыль, строка 24
}