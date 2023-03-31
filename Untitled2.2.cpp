#include <iostream>
#include <cstring>
using namespace std;

class String {
	
		char* s; // Рядок, який буде зберігатися в об'єкті
	public:
		// Конструктор класу
		String(const char* str="") { 
			s = new char[strlen(str)+1];// Виділення пам'яті для рядка та копіювання переданого рядка
			strcpy(s, str);  
		}

		// Деструктор класу
		~String() {
			delete[] s;
		}

		// Ініціалізація з ASCIZ–рядка
		void asciz(const char* str) {// Видалення останнього символу - нуль-байту
			int len = strlen(str);
			s = new char[len];
			strncpy(s, str, len-1); //копіювання 
			s[len-1] = '\0'; //нульбайт на останнє місце в рядку 
		}

		// Введення з клавіатури
		void input() {// Запит рядка від користувача
			char arr[65536];
			cout<<"vvedit vash ryadok : "<<endl;
			cin.getline(arr, 65536);
			s = new char[strlen(arr)+1]; // створ. нової розміром старої + 0 байт
			strcpy(s, arr);  //копіювання одного віньше
		}

		// Виведення на екран
		void output() {// Вивід рядка на екран
			cout <<"Vash ryadok : "<< s << endl;
		}

		// Повернення кількості символів у рядку
		int length() {
			cout<<"Dovgina ryadka : ";
			return strlen(s);   
		}

		// Конкатенація рядків
		void concatenate(String other) {  
			char* newstr = new char[strlen(s) + strlen(other.s) + 1];
			strcpy(newstr, s); //копіюєм 1 в іньше
			strcat(newstr, other.s); // об'єднання
			delete[] s;
			s = newstr; //переприсвоєння
		}

		// Пошук підрядка
		int find(String substr) {// Пошук першого входження підрядка в рядку
			char* ptr = strstr(s, substr.s); // пошук покажчик на 1 входження
			if (ptr == nullptr) {
				return -1;   // якщо немає то повертає -1
			}
			return ptr - s;   // якщо є то повертає різницю покажчиків
		}

		// Пошук і заміна підрядка
		void replace(String oldsub, String newsub) { // Заміна всіх входжень підрядка на новий підрядок
			char* ptr = strstr(s, oldsub.s); //пошук покажчика га 1 входження
			while (ptr != nullptr) {
				char* newstr = new char[strlen(s) + strlen(newsub.s) - strlen(oldsub.s) + 1]; //нова строка довжиною ісходної + довжина нового підрядка і - того який був
				strncpy(newstr, s, ptr - s);   // копіюємо в новий рядок частину вихідного рядка
				newstr[ptr - s] = '\0';			//додаємо нуль символ
				strcat(newstr, newsub.s);	// додаємо в новий рядок новий підрядок
				strcat(newstr, ptr + strlen(oldsub.s)); //додаємо в новий рядок залишок рядка, наступний за знайденим входженням старого підрядка
				delete[] s; //видаляємо стару строку
				s = newstr;  // присвоюємо покажчик на новий рядок s, тому що ми замінюємо старий підрядок на новий
				ptr = strstr(s, oldsub.s); // шукаємо наступне входження старого підрядка в новому рядку
			}
		}
};

int main() {
	String s1;
	cout<<"Ryadok No 1 ";
	s1.input();


	String s2;
	cout<<"Dlya konkatenacii ";
	s2.input();

	String s3;

	s1.output(); // Виведе "Vash ryadok : рядок
	s2.output(); // Виведе "Vash ryadok : рядок
	s3.concatenate(s1); // Додасть до порожнього рядка s3 рядок s1
	s3.concatenate(s2); // Додасть до s3 рядок s2
	cout<<"Pislya konkatenatciyi ";
	s3.output(); // Виведе "Vash ryadok : Hello, world!"

	String s4;
	cout<<"Dlya vuznachennya rozmiry ";
	s4.input(); // Запит рядка від користувача
	s4.output(); // Виведе введений рядок

	int len = s4.length(); // Збереже довжину введеного рядка у змінну len
	cout << "Dovgina ryadka : " << len << endl;

	String s5;
	cout<<"Dlya vyznachennya pozytsiyi ";
	s5.input();
	s5.output();

	String s6;
	cout<<"Pidryadoc ";
	s6.input();
	s6.output();

	int index = s5.find(s6); // Збереже позицію першого входження підрядка у змінну index
	cout << "Pozitsiya pidryadka: " << index << endl;

	String s7;
	cout<<"Dlya zminy fragmenty v ryadky ";
	s7.input();
	s7.output();

	String s8;
	cout<<"Pidryadoc yakyy zminyty ";
	s8.input();
	s8.output();

	String s9;
	cout<<"Pidryadoc na yakyy zaminyty ";
	s9.input();
	s9.output();


	s7.replace(s8, s9); // Замінить у рядку всі входження
	s7.output(); // Виведе "Vash ryadok : і змінений

	return 0;
}
