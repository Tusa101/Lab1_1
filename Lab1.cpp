#include <iostream>
#include <climits>
#include <stdexcept>
#include <Windows.h>
#include <ctype.h>
#include <iomanip>
#include <string>
#include <cstdlib>
using namespace std;

/**
 * Лабораторная работа №1. Основы синтаксиса С/С++
 *
 * Работа представляет собой исходный текст с пропущенными элементами.
 * В тексте работы сформулированы задания в виде  \TODO-комментариев.
 * Объявления функций должны быть скорректированы с учётом описаний в комментариях
  */

  /* TODO №1. Объявление функции "belongsToInterval".
   * Функция проверяет, принадлежит ли значение заданному интервалу.
   *
   * @param x значение, которое следует проверить на принадлежность заданному
   * интервалу
   * @param bottom нижняя граница интервала
   * @param top верхняя граница интервала
   * @return true, если x принадлежит заданному интервалу. В обратному случае - false.
   */
bool belongsToInterval(int x, int bottom, int top);

/* TODO №2. Объявление функции "min".
 * Возвращает меньшее из двух вещественных значений.
 *
 * @param a первое значение
 * @param b второе значение
 * @return Меньшее из переданных значений.
 */
float Min(float a, float b);

/* TODO №3. Объявление функции "min".
 * Возвращает меньшее из двух целочисленных значений.
 *
 * @param a первое значение
 * @param b второе значение
 * @return Меньшее из переданных значений.
 */
int Min(int a, int b);

/* TODO №4. Объявление функции "order".
 * Возвращает порядок (количество знаков) переданного значения.
 *
 * @param x значение, порядок которого следует определить (любое целочисленное значение)
 * @return Количество знаков переданного значения.
 */
short order(int x);

/* TODO №5. Объявление функции "typeInfo"
	Выводит информацию о типах (размер в байтах, максимальное значение, минимальное значение)
	Типы: char, int, short, long, long long
	Размер переменной в байтах - функция/оператор sizeof
	Константы максимальных и минимальных значений определены в файле <climits> (<limits.h>)
*/
void typeInfo();

bool str_is_number(string s);


/* TODO №6. Объявление функции "showLetterCode"
*   Внутри функции считываем символ с консоли (cin >> c)
*   Выводим пользователю сам символ и его числовое представление
*
*/
void showLetterCode();

/**
 * Точка входа в программу.
 *
 * @return Результат, с которым программа завершила выполнение:
 *					0, если программа завершилась успешно.
 *		      не ноль, если возникла ошибка, возвращаемое значение представляет собой код ошибки.
 */
int main() {
	/* TODO №11 Реализовать консольное меню для проверки работы каждой функции.
	* В реализации использовать цикл (для "бесконечного" ожидания ввода)
	* Для ветвления в коде использовать switch
	* Пример меню:
	*       Нажмите клавишу для проверки функции:
	*           t - Информация по примитивным типам
	*           b - Принадлежность интервалу [bottom;top]
	*			m - Минимальное значение из двух аргументов
	*			o - Количество разрядов в числе
	*           с - Кодировка символа
	*           e - Выход из программы
	*
	*/
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout.width(20);
	cout << setw(40) << right << "Лабораторная работа №1.\n";
	cout << setw(48) << right << "Программа <<5 ЗАМЕЧАТЕЛЬНЫХ ФУНКЦИЙ>>\n\n";

	while (true)
	{
		char key;

		cout << "\nНажмите клавишу для проверки функции:\n";
		cout << "\tt - Информация по примитивным типам\n\tb - Принадлежность интервалу[bottom; top]\n\tm - Минимальное значение из двух аргументов\n\to - Количество разрядов(цифр) в числе\n\tс - Кодировка символа\n\te - Выход из программы\n\n\n >>>";
		cin >> key;
		cout << "\n";
		switch (key)
		{
		case 't':
			typeInfo();
			break;
		case'b':
		{
			int bottom;
			int top;
			int x;

			cout << "Введите значения границ интервала и число для проверки принадлежности.\n";

			cout << "bottom = ";
			cin >> bottom;
			if (cin.fail())
			{
				cerr << "Error! Type:" << typeid(invalid_argument).name() << endl;
				return -1;
			}


			cout << "top = ";
			cin >> top;
			if (cin.fail())
			{
				cerr << "Error! Type:" << typeid(invalid_argument).name() << endl;
				return -1;
			}

			cout << "x = ";
			cin >> x;
			if (cin.fail())
			{
				cerr << "Error! Type:" << typeid(invalid_argument).name() << endl;
				return -1;
			}
			if (bottom > top)
			{
				cerr << "Верхняя граница меньше нижней!!!" << endl;
				return -1;
			}

			if (belongsToInterval(x, bottom, top))
			{
				printf("Число %d принадлежит интервалу [%d,%d]\n", x, bottom, top);
			}
			else
			{
				printf("Число %d не принадлежит интервалу [%d,%d]\n", x, bottom, top);
			}
		}
		break;

		case 'm':
		{
			string a;
			string b;

			cout << "Введите значения чисел для нахождения наименьшего\n";
			cout << "a = ";
			cin >> a;
			cout << "\n";
			cout << "b = ";
			cin >> b;
			cout << "\n";

			if (str_is_number(a) && str_is_number(b))
			{
				if (a.find('.') == -1 && b.find('.') == -1)
				{
					int a_int = stoi(a);
					int b_int = stoi(b);
					cout << "Наименьшее из чисел " << a << " и " << b << ": " << Min(a_int, b_int) << "\n";
				}
				else
				{
					float a_flt = stof(a);
					float b_flt = stof(b);
					cout << "Наименьшее из чисел " << a << " и " << b << ": " << Min(a_flt, b_flt) << "\n";

				}
			}
			else
			{
				cerr << "Error! Type:" << typeid(invalid_argument).name() << endl;
				return -1;
			}

		}
		break;
		case 'o':
		{
			int x;
			cout << "Введите значение числа для нахождения количества разрядов в нем.\n";
			cout << "x = ";
			cin >> x;
			if (cin.fail())
			{
				cerr << "Error! Type:" << typeid(invalid_argument).name() << endl;
				return -1;
			}

			cout << "\n";
			cout << "Количество разрядов в веденном числе: " << order(x) << "\n";
		}
		break;
		case 'c':
		{
			showLetterCode();
		}
		break;
		default:
			cout << "Опции на такую кнопку не назначено. Повторите попытку.\n";
			break;
		}
		if (key == 'e')
		{
			system("cls");
			cout << "Завершение работы.\n";
			break;
		}

	}
	return 0;


}

bool str_is_number(string s)
{
	int i = 0;

	while (i < s.length())
	{
		if (!isdigit(s[i]) && s[i] != '.')
		{
			return false;
		}
		i++;
	}
	return true;
}

/* TODO №7 Реализация функции "belongsToInterval" (определение).
 */
bool belongsToInterval(int x, int bottom, int top)
{
	if (bottom <= top && x >= bottom && x <= top)
	{
		return true;
	}
	return false;
	
}


/* TODO №8 Реализация функции "min" для целочисленных аргументов.
 */
int Min(int a, int b)
{
	if (a >= b)
	{
		return b;
	}
	else
	return a;
}
/* TODO №9 Реализация функции "min" для вещественных аргументов.
 */
float Min(float a, float b)
{
	if (a >= b)
	{
		return b;
	}
	return a;
}
/* TODO №10 Реализация функции "order"

*/
short order(int x)
{
	short order = 0;
	do
	{
		x /= 10;
		order++;
	} while (x > 0);
	return order;
}

/* TODO №11 Реализация функции "typeInfo".
 */
void typeInfo()
{
	cout << "Информация о типах данных: \n";

	cout << "\nchar size = " << sizeof(char) << " bytes, min = " << CHAR_MIN << ", max = " << CHAR_MAX << "\n";
	cout << "short size = " << sizeof(short) << " bytes, min =" << SHRT_MIN << ", max = " << SHRT_MAX << "\n";
	cout << "int size = " << sizeof(int) << " bytes, min =" << INT_MIN << ", max = " << INT_MAX << "\n";
	cout << "long size = " << sizeof(long) << " bytes, min =" << LONG_MIN << ", max = " << LONG_MAX << "\n";
	cout << "long long size = " << sizeof(long long) << " bytes, min =" << LLONG_MIN << ", max = " << LLONG_MAX << "\n";
}
/* TODO №12 Реализация функции "showLetterCode".
 */
void showLetterCode()
{
	char c;
	cout << "Введите символ,чтобы узнать его значение в числовом формате:\n";
	cout << "Symbol = ";
	cin >> c;
	int c_int = static_cast<int>(c);
	cout << "Числом, которым закодирован символ [" << c << "] является [" << c_int << "]\n";
}