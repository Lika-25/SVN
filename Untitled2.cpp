#include <iostream>
#include <cstring>
using namespace std;//,...


class String {
private:
    char* s; // Рядок, який буде зберігатися в об'єкті
public:
    // Конструктор класу
    String(const char* str="") { // Виділення пам'яті для рядка та копіювання переданого рядка
        s = new char[strlen(str)+1];
        strcpy(s, str);
    }

    // Деструктор класу
    ~String()
	 {// Звільнення пам'яті, яку займає рядок
        delete[] s;
    }

    // Ініціалізація з ASCIZ–рядка
    void init_from_asciz(const char* str) {// Видалення останнього символу - нуль-байту
        int len = strlen(str);
        s = new char[len];
        strncpy(s, str, len-1);
        s[len-1] = '\0';
    }

    // Введення з клавіатури
    void input() {// Запит рядка від користувача
        char buf[65536];
        cout<<"vvedit vash ryadok : "<<endl;
        cin.getline(buf, 65536);
        s = new char[strlen(buf)+1];
        strcpy(s, buf);
    }

    // Виведення на екран
    void output() {// Вивід рядка на екран
        cout <<"Vash ryadok : "<< s << endl;
    }

    // Повернення кількості символів у рядку
    int length() {// Повернення довжини рядка
    	cout<<"Dovgina ryadka : ";
        return strlen(s);
    }

    // Конкатенація рядків
    void concatenate(String other) {// Додавання рядка з іншого об'єкту до поточного рядка
        char* newstr = new char[strlen(s) + strlen(other.s) + 1];
        strcpy(newstr, s);
        strcat(newstr, other.s);
        delete[] s;
        s = newstr;
    }

    // Пошук підрядка
    int find(String substr) {// Пошук першого входження підрядка в рядку
        char* ptr = strstr(s, substr.s);
        if (ptr == nullptr) 
		{
            return -1;
        }
        return ptr - s;
    }

    // Пошук і заміна підрядка
    void replace(String oldsubstr, String newsubstr) { // Заміна всіх входжень підрядка на новий підрядок
        char* ptr = strstr(s, oldsubstr.s);
        while (ptr != nullptr) {
            char* newstr = new char[strlen(s) + strlen(newsubstr.s) - strlen(oldsubstr.s) + 1];
            strncpy(newstr, s, ptr - s);
            newstr[ptr - s] = '\0';
			 strcat(newstr, newsubstr.s);
			 strcat(newstr, ptr + strlen(oldsubstr.s));
            delete[] s;
            s = newstr;
            ptr = strstr(s, oldsubstr.s);
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

    s1.output(); // Виведе "Vash ryadok : Hello, "
    s2.output(); // Виведе "Vash ryadok : world!"
    s3.concatenate(s1); // Додасть до порожнього рядка s3 рядок s1
    s3.concatenate(s2); // Додасть до s3 рядок s2
    cout<<"Pislya konkatenatciyi ";
    s3.output(); // Виведе "Vash ryadok : Hello, world!"

    String s4;
    cout<<"Dlya vuznachennya rozmiry  ";
    s4.input(); // Запит рядка від користувача
    s4.output(); // Виведе введений рядок

    int len = s4.length(); // Збереже довжину введеного рядка у змінну len
    cout << "Dovgina ryadka : " << len << endl;

    String s5;
    cout<<"Dlya vyznachennya pozytsiyi  ";
	s5.input();
	s5.output();
	
	String s6;
	cout<<"Pidryadoc ";
	s6.input();
	s6.output();
	
    int index = s5.find(s6); // Збереже позицію першого входження "brown" у змінну index
    cout << "Pozitsiya pidryadka: " << index << endl;
    
	String s7;
	cout<<"Dlya zminy fragmenty v ryadky ";
	s7.input();
	s7.output();
	
    s5.replace(s6, s7); // Замінить у рядку всі входження "brown" на "red"
    s5.output(); // Виведе "Vash ryadok : quick red fox jumps over the lazy dog"

    return 0;
}
