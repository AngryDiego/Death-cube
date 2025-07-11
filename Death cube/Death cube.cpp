// зробити класс - кубик смерті 
// правила гри - людина створює собі якусь змінну на число. Передає цю змінну в кубік - тим самим створює обʼєкт.
// кубик кидається - 1д20 - якщо випадає 1 - смерть. Якщо випадає 20 - гарантована перемога. Всі інші значення - віднімаютсья від оригіналу число.


#include <iostream>
#include <ctime>
#define NOLIK NULL


class Cube {
public :
	int reps = 0;
	int& value;

	Cube (int& v) : value(v) {}

	void Game () {
		do {
			reps++;
			
			srand(time(NOLIK));
			int dice = rand()%20 + 1;

			if (dice == 1) {
				std::cout << "You lost" << std::endl;
				return;
			}

			else if (dice == 20) {
				std::cout << "You won" << std::endl;
				return;
			}

			else {
				value -= dice;
			}

			std::cout << "Amout of repetitions : " << reps << std::endl;

		} while (value >= 1);

		std::cout << "You lost";
	}
};


int main () {
	int valeuble;
	std::cout << "Enter number :";
	std::cin >> valeuble;

	Cube cubic (int valeuble);

	cubic.Game();
}