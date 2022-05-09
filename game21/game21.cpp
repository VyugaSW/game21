
#include <iostream>
#include <Windows.h>

using namespace std;
// game 21
void main_menu();
void step_game(int cards_first, int cards_next);
int random_issuance_of_cards();
int check_cards();
int player_turn();
int computer_turn();
bool win(int summa_user, int summa_comp);
void cards_show(int card);

int main()
{
	setlocale(LC_ALL, "");
	int first_card = check_cards(), second_card = check_cards();
	main_menu();
	step_game(first_card, second_card);

}

// интерфейс игры. Начало
void main_menu() {
	cout << "Добро пожаловать в игру 21!\n";
	cout << "Хотите начать? (y/n)\n";
	string flag;
	cin >> flag;
}

// Вывод самих карт
void cards_show(int card) {
	string six = "********\n"
				 "* 6    *\n"
				 "*      *\n"
				 "*      *\n"
				 "*      *\n"
				 "*    9 *\n"
				 "********\n";
	string seven = "********\n"
				   "* 7    *\n"
				   "*      *\n"
				   "*      *\n"
				   "*      *\n"
				   "*    7 *\n"
				   "********\n";
	string eight = "********\n"
				   "* 8    *\n"
				   "*      *\n"
				   "*      *\n"
				   "*      *\n"
				   "*    8 *\n"
				   "********\n";
	string nine = "********\n"
				  "* 9    *\n"
				  "*      *\n"
				  "*      *\n"
				  "*      *\n"
				  "*    6 *\n"
				  "********\n";
	string ten = "********\n"
				 "* 10   *\n"
				 "*      *\n"
				 "*      *\n"
				 "*      *\n"
				 "*   10 *\n"
				 "********\n";
	string valet = "********\n"
				   "*  *** *\n"
				   "*   ** *\n"
				   "* **** *\n"
				   "*  *** *\n"
				   "*valet *\n"
				   "********\n";
	string queen = "********\n"
				   "* **** *\n"
				   "*  *** *\n"
				   "* **** *\n"
				   "*  *** *\n"
				   "*queen *\n"
				   "********\n";
	string king =   "********\n"
					"* ** * *\n"
					"*   ** *\n"
					"* **** *\n"
					"*  *** *\n"
					"* king *\n"
					"********\n";
	string tuz = "********\n"
				 "* **** *\n"
				 "*      *\n"
				 "*   *  *\n"
				 "*      *\n"
				 "* **** *\n"
				 "********\n";
	switch (card) {
	case(2):
		cout << valet;
		break;
	case(3):
		cout << queen;
		break;
	case(4):
		cout << king;
		break;
	case(6):
		cout << six;
		break;
	case(7):
		cout << seven;
		break;
	case(8):
		cout << eight;
		break;
	case(9):
		cout << nine;
		break;
	case(10):
		cout << ten;
		break;
	case(11):
		cout << tuz;
		break;
	default:
		break;

	}

}
void step_game(int cards_first, int cards_next) {
	string flag;
	int extra_card;
	bool f = true;
	int summa_user = cards_first + cards_next, summa_comp = 0;
	cout << "Ваши карты: " << cards_first << "," << cards_next << endl;
	cards_show(cards_first);
	cards_show(cards_next);
	cout << "Итоговая сумма: " << cards_first + cards_next << endl;
	while (f) {
		cout << "Хотите взять еще одну карту?(y/n)\n";
		cin >> flag;
		if (flag == "y") {
			extra_card = player_turn();
			summa_user += extra_card;
			cout << "Ваша карта: " << extra_card << endl;
			cards_show(extra_card);
			cout << "Итоговая сумма: " << summa_user << endl;
			if (summa_user >= 21) {
				summa_comp += computer_turn();
				f = win(summa_user, summa_comp);
			}
		}
		else if (flag == "n") {
			summa_comp += computer_turn();
			f = win(summa_user, summa_comp);
		}
		else
		{
			cout << "Неверный ввод, повторите!";
		}
	}
}
// интерфейс игры. Конец

// рандомная выдача карт. Начало
int random_issuance_of_cards() {
	srand(time(NULL));
	int random_card = rand() % 10 + 2;
	while (random_card == 5) random_card = rand() % 10 + 2;
	return random_card;
}
// учет повторяющихся карт
int check_cards() {
	int arrayRepeatCards[12] = { 0,0,0,0,0,0,0,0,0,0,0,0 }; // кол-во повторов
	int random_card = random_issuance_of_cards();
	do {
		if (arrayRepeatCards[random_card] > 4)
			random_card = random_issuance_of_cards();
		else {
			arrayRepeatCards[random_card]++;
			return random_card;
		}
	} while (true);
}
//рандомная выдача карт. Конец

//ход игрока
int player_turn() {
	return check_cards();
}
//ход компьютера
int computer_turn() {
	int summa = 0;
	summa += check_cards();
	summa += check_cards();
	srand(time(NULL));
	int a, b, c;
	a = rand() % 2; // 50%
	b = rand() % 5; // 25%
	c = rand() % 10;// 10%
	while (summa <= 21)
	{
		if (summa < 11) summa += check_cards();
		else if (10 < summa < 14) if (b < 4) summa += check_cards();
		else if (13 < summa < 16) if (a) summa += check_cards();
		else if (15 < summa < 18) if (b) summa += check_cards();
		else if (17 < summa < 20) if (c) summa += check_cards();
	}
	return summa;
}
//условия выйгрыша
bool win(int summa_user, int summa_comp) {
	cout << "Сумма очков компьютера - " << summa_comp << endl;
	cout << "Ваша итоговая сумма - " << summa_user << endl;
	if (summa_user == 21) cout << "Победа игрока\n";
	else if (summa_user > 21) cout << "Победа компьютера\n";
	else if (summa_comp > 21) cout << "Победа игрока\n";
	else if (summa_user == summa_comp) cout << "Ничья\n";
	else if (summa_comp < 21 && summa_user < 21) {
		if (summa_user > summa_comp) cout << "Победа игрока\n";
		else if (summa_user < summa_comp) cout << "Победа компьютера\n";
		else if (summa_user == summa_comp) cout << "Ничья\n";
	}
	return false;
}
