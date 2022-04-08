#include <iostream>
#include <math.h>
#include <Windows.h>
#include <conio.h>

using namespace std;

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
COORD position = { 0, 0 };

int arrayX[100];
int arrayY[100];
double arrayZ[100];

int sizeArrays = 0;

int x1, x2, y1_, y2, stepX, stepY;

const int height = 10;
const int weight = 40;

double checkedValue(const int x, const int y);

bool is_number(char number[]);

int char_to_int(char number[]);
int char_to_int(char number);

void resultCalculation(int x1, int x2, int stepX, int y1, int y2, int stepY, int arrayX[], int arrayY[], double arrayZ[], int height, int weight, int &sizeArrays);

void mainScreen(int weight, int height);
void Frame_with_1_string(int weight, int height);
void Frame_with_2_string(int weight, int height);
void answerScreen(int weight, int height, int arrayX[], int arrayY[], double arrayZ[]);
void Frame_answer_screen(int weight, int height);
void endScreen(int weight, int height);
void writeData(int weight, int height, int& x1, int& x2, int& y1, int& y2, int& stepX, int& stepY, COORD position, HANDLE hConsole);

void lifeCycle(int weight, int height, int& x1, int& x2, int& y1, int& y2, int& stepX, int& stepY, int arrayX[], int arrayY[], double arrayZ[], int& sizeArrays, COORD position, HANDLE hConsole);


int main()
{
    setlocale(LC_ALL, "rus");
    
    lifeCycle(weight, height, x1, x2, y1_, y2, stepX, stepY, arrayX, arrayY, arrayZ, sizeArrays, position, hConsole);

    return 0;
}


double checkedValue(const int x, const int y) {
    if (y != 0)
        return ((2 * pow(x, 3) + (cos(y) / sin(y))) / (pow((1 + log10(y)), 1 / 2)));
    else return 0;
}

//Проверка, является ли введенное число типом инт
bool is_number(char number[]) {
    for (int i = 0; i < 100; i++) {
        if ((char)number[i] != -52 && number[i] != '\0') {
            if (!((char)number[i] >= 48 && (char)number[i] <= 57 && number[i]))
                return false;
        }
        else
            return true;
    }
}
//Перевод из чар числа в инт число
int char_to_int(char number[]) {
    int number_of_digits = 0;

    for (int i = 0; number[i] != '\0'; i++) {
        if ((char)number[i] != -52) {
            number_of_digits++;
        }
    }

    if (number_of_digits == 1) {
        return ((char)(number[0] - 48));
    }
    if (number_of_digits == 2) {
        return ((char)(number[0] - 48) * 10 + (char)(number[1] - 48));
    }
    if (number_of_digits == 3) {
        return (((char)(number[0] - 48) * 100) + (((char)(number[1])) - 48) * 10 + (char)(number[2]) - 48);
    }
}
//Перевод цифры из чар в инт
int char_to_int(char number) {
    return ((char)(number - 48));
}
//основная работа программы
void resultCalculation(int x1, int x2, int stepX, int y1, int y2, int stepY, int arrayX[], int arrayY[], double arrayZ[], int height, int weight, int& sizeArrays) {
    system("cls");

    int local_y = y1;

    int index_x = 0;
    int index_y = 0;
    int index_z = 0;

    for (; x1 < x2; x1++){
        
        y1 = local_y;

        for (; y1 < y2; y1++){
            if (x1 % stepX == 0) {
                if (y1 % stepY == 0) {
                    arrayX[index_x] = x1;
                    arrayY[index_y] = y1;
                    arrayZ[index_z] = checkedValue(x1, y1);

                    index_x++;
                    index_y++;
                    index_z++;

                    sizeArrays++;
                }
            }
        }
    }
    
}

//Рамка с 1 строкой снизу
void Frame_with_1_string(int weight, int height) {
    for (int i = 0; i < weight + 1; i++) {
        cout << "-";
    }

    cout << "\n";

    for (int i = 0; i < height - 1; i++) {

        for (int j = 0; j <= weight; j++)
        {
            if (j == 0 || j == weight) cout << "|";
            else cout << " ";
        }
        cout << "\n";
    }
    for (int i = 0; i < weight + 1; i++) {
        cout << "-";
    }

    cout << "\n";

    for (int i = 0; i < 1; i++)
    {
        for (int j = 0; j <= weight; j++) {
            if (j == 0 || j == weight)
                cout << "|";
            else
                cout << " ";
        }
        cout << "\n";
    }
    for (int i = 0; i < weight + 1; i++) {
        cout << "-";
    }

}
//Рамка с 2 строками снизу
void Frame_with_2_string(int weight, int height) {
    for (int i = 0; i < weight + 1; i++) {
        cout << "-";
    }

    cout << "\n";

    for (int i = 0; i < height - 1; i++) {

        bool i_is_not_a_second_third_fourth = (i == 2 || i == 3 || i == 4) ? 0 : 1;

        for (int j = 0; j <= weight; j++)
        {
            if (j == 0 || j == weight) cout << "|";
            else cout << " ";
        }
        cout << "\n";
    }
    for (int i = 0; i < weight + 1; i++) {
        cout << "-";
    }

    cout << "\n";

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j <= weight; j++) {
            if (j == 0 || j == weight)
                cout << "|";
            else
                cout << " ";
        }
        cout << "\n";
    }
    for (int i = 0; i < weight + 1; i++) {
        cout << "-";
    }

}
//Главный экран
void mainScreen(int weight, int height) {

    Frame_with_1_string(weight, height);

    position = { 15, 3 };
    SetConsoleCursorPosition(hConsole, position);
    cout << "Программа";

    position = { 8, 4 };
    SetConsoleCursorPosition(hConsole, position);
    cout << "Циклическое вычисление";

    position = { 7, 5 };
    SetConsoleCursorPosition(hConsole, position);
    cout << "Рыбаков Павел Алексеевич";

    position = { 15, 6 };
    SetConsoleCursorPosition(hConsole, position);
    cout << "Гр. 1092";


    position = { 8 , 11 };
    SetConsoleCursorPosition(hConsole, position);
    cout << "Esc - Выход, Enter - Далее";

    position = { 0, 13 };
    SetConsoleCursorPosition(hConsole, position);
}
//Рамка экрана ответа
void Frame_answer_screen(int weight, int height) {
    for (int i = 0; i < weight + 1; i++) {
        cout << "-";
    }

    cout << "\n";

    

    for (int i = 0; i < height; i++) {

        if (i == 1) {
            for (int i = 0; i < weight + 1; i++) {
                cout << "-";
            }
        }

        for (int j = 0; j <= weight; j++)
        {
            if ((j == 0 || j == 10 || j == 20 || j == weight) && (i != 1)) cout << "|";
            else cout << " ";
        }
        cout << "\n";
    }
    for (int i = 0; i < weight + 1; i++) {
        cout << "-";
    }

    cout << "\n";

    for (int i = 0; i < 1; i++)
    {
        for (int j = 0; j <= weight; j++) {
            if (j == 0 || j == weight)
                cout << "|";
            else
                cout << " ";
        }
        cout << "\n";
    }
    for (int i = 0; i < weight + 1; i++) {
        cout << "-";
    }

}
//Экран ответа
void answerScreen(int weight, int height, int arrayX[], int arrayY[], double arrayZ[]) {
    system("cls");

    int page = 0;
    char choise;
    int string = 3;

    Frame_answer_screen(weight, height);

    position = { 5, 1 };
    SetConsoleCursorPosition(hConsole, position);
    cout << "X";

    position = { 15, 1 };
    SetConsoleCursorPosition(hConsole, position);
    cout << "Y";

    position = { 30, 1 };
    SetConsoleCursorPosition(hConsole, position);
    cout << "Z";

    for (int i = 0; i < sizeArrays; i++){
        if (page == 0) {
            if (string == 11) {
                string = 3;
                system("cls");
                Frame_answer_screen(weight, height);

                position = { 5, 1 };
                SetConsoleCursorPosition(hConsole, position);
                cout << "X";

                position = { 15, 1 };
                SetConsoleCursorPosition(hConsole, position);
                cout << "Y";

                position = { 30, 1 };
                SetConsoleCursorPosition(hConsole, position);
                cout << "Z";
            }
            position = { 5, (short)(string) };
            SetConsoleCursorPosition(hConsole, position);
            cout << arrayX[i];

            position = { 15, (short)(string) };
            SetConsoleCursorPosition(hConsole, position);
            cout << arrayY[i];

            position = { 27, (short)(string) };
            SetConsoleCursorPosition(hConsole, position);
            cout << arrayZ[i];

            if (i == 7){
                do
                {
                    choise = _getch();
                } while ((char)choise != 97 && (char)choise != 100);

                if (choise == 97) {
                    do
                    {
                        position = { 11, 12 };
                        SetConsoleCursorPosition(hConsole, position);
                        cout << "Это первая страница";
                    } while ((choise = _getch()) != 100);

                    page++;
                }
                else if (choise == 100) page++;
            }
            string++;
        }
        else if (page == 1) {
            
            if (string == 11) { 
                system("cls");
                string = 3; 
                Frame_answer_screen(weight, height);

                position = { 5, 1 };
                SetConsoleCursorPosition(hConsole, position);
                cout << "X";

                position = { 15, 1 };
                SetConsoleCursorPosition(hConsole, position);
                cout << "Y";

                position = { 27, 1 };
                SetConsoleCursorPosition(hConsole, position);
                cout << "Z";
            }

            position = { 5, (short)(string) };
            SetConsoleCursorPosition(hConsole, position);
            cout << arrayX[i];

            position = { 15, (short)(string) };
            SetConsoleCursorPosition(hConsole, position);
            cout << arrayY[i];

            position = { 27, (short)(string) };
            SetConsoleCursorPosition(hConsole, position);
            cout << arrayZ[i];

            if (i == 15) {
                do
                {
                    choise = _getch();
                } while ((char)choise != 97 && (char)choise != 100);

                if (choise == 97) {
                    cout << page--;
                    i = -1;
                }
                else if (choise == 100) page++;
            }

            string++;
        }
        else if (page == 2) {
            if (string == 11) {
                system("cls");
                string = 3;
                Frame_answer_screen(weight, height);

                position = { 5, 1 };
                SetConsoleCursorPosition(hConsole, position);
                cout << "X";

                position = { 15, 1 };
                SetConsoleCursorPosition(hConsole, position);
                cout << "Y";

                position = { 27, 1 };
                SetConsoleCursorPosition(hConsole, position);
                cout << "Z";
            }



            position = { 5, (short)(string) };
            SetConsoleCursorPosition(hConsole, position);
            cout << arrayX[i];

            position = { 15, (short)(string) };
            SetConsoleCursorPosition(hConsole, position);
            cout << arrayY[i];

            position = { 27, (short)(string) };
            SetConsoleCursorPosition(hConsole, position);
            cout << arrayZ[i];

            if (i == 23) {
                do
                {
                    choise = _getch();
                } while ((char)choise != 97 && (char)choise != 100);

                if (choise == 97) {
                    i = 7;
                    cout << page--;
                }
                else if (choise == 100) page++;
            }

            string++;
        }
        else if (page == 3) {
            if (string == 11) {
                system("cls");
                string = 3;
                Frame_answer_screen(weight, height);

                position = { 5, 1 };
                SetConsoleCursorPosition(hConsole, position);
                cout << "X";

                position = { 15, 1 };
                SetConsoleCursorPosition(hConsole, position);
                cout << "Y";

                position = { 27, 1 };
                SetConsoleCursorPosition(hConsole, position);
                cout << "Z";
            }

 

            position = { 5, (short)(string) };
            SetConsoleCursorPosition(hConsole, position);
            cout << arrayX[i];

            position = { 15, (short)(string) };
            SetConsoleCursorPosition(hConsole, position);
            cout << arrayY[i];

            position = { 27, (short)(string) };
            SetConsoleCursorPosition(hConsole, position);
            cout << arrayZ[i];

            if (i == 31) {
                do
                {
                    choise = _getch();
                } while ((char)choise != 97 && (char)choise != 100);
               
                if (choise == 97) {
                    i = 15;
                    cout << page--;
                }
                else if (choise == 100) page++;
            }
            string++;
        }
        else if (page == 4) {
            if (string == 11) {
                system("cls");
                string = 3;
                Frame_answer_screen(weight, height);

                position = { 5, 1 };
                SetConsoleCursorPosition(hConsole, position);
                cout << "X";

                position = { 15, 1 };
                SetConsoleCursorPosition(hConsole, position);
                cout << "Y";

                position = { 27, 1 };
                SetConsoleCursorPosition(hConsole, position);
                cout << "Z";
            }

            position = { 5, (short)(string) };
            SetConsoleCursorPosition(hConsole, position);
            cout << arrayX[i];

            position = { 15, (short)(string) };
            SetConsoleCursorPosition(hConsole, position);
            cout << arrayY[i];

            position = { 27, (short)(string) };
            SetConsoleCursorPosition(hConsole, position);
            cout << arrayZ[i];
            if (i == 39) {
                do
                {
                    choise = _getch();
                } while ((char)choise != 97 && (char)choise != 100);

                if (choise == 97) {
                    i = 23;
                    cout << page--;
                }
                else if (choise == 100) page++;
            }
            string++;
        }
        else if (page == 5) {
            if (string == 11) {
                system("cls");
                string = 3;
                Frame_answer_screen(weight, height);

                position = { 5, 1 };
                SetConsoleCursorPosition(hConsole, position);
                cout << "X";

                position = { 15, 1 };
                SetConsoleCursorPosition(hConsole, position);
                cout << "Y";

                position = { 27, 1 };
                SetConsoleCursorPosition(hConsole, position);
                cout << "Z";
            }

            position = { 5, (short)(string) };
            SetConsoleCursorPosition(hConsole, position);
            cout << arrayX[i];

            position = { 15, (short)(string) };
            SetConsoleCursorPosition(hConsole, position);
            cout << arrayY[i];

            position = { 27, (short)(string) };
            SetConsoleCursorPosition(hConsole, position);
            cout << arrayZ[i];

            if (i == 47) {
                do
                {
                    choise = _getch();
                } while ((char)choise != 97 && (char)choise != 100);
               
                if (choise == 97) {
                    i = 31;
                    cout << page--;
                }
                else if (choise == 100) page++;
            }
            string++;
        }
        else if (page == 6) {
            if (string == 11) {
                system("cls");
                string = 3;
                Frame_answer_screen(weight, height);

                position = { 5, 1 };
                SetConsoleCursorPosition(hConsole, position);
                cout << "X";

                position = { 15, 1 };
                SetConsoleCursorPosition(hConsole, position);
                cout << "Y";

                position = { 27, 1 };
                SetConsoleCursorPosition(hConsole, position);
                cout << "Z";
            }


            position = { 5, (short)(string) };
            SetConsoleCursorPosition(hConsole, position);
            cout << arrayX[i];

            position = { 15, (short)(string) };
            SetConsoleCursorPosition(hConsole, position);
            cout << arrayY[i];

            position = { 27, (short)(string) };
            SetConsoleCursorPosition(hConsole, position);
            cout << arrayZ[i];

            if (i == 55) {
                do
                {
                    choise = _getch();
                } while ((char)choise != 97 && (char)choise != 100);
                
                if (choise == 97) {
                    i = 39;
                    cout << page--;
                }
                else if (choise == 100) page++;
            }
            string++;
        }
        else if (page == 7) {
            if (string == 11) {
                system("cls");
                string = 3;
                Frame_answer_screen(weight, height);

                position = { 5, 1 };
                SetConsoleCursorPosition(hConsole, position);
                cout << "X";

                position = { 15, 1 };
                SetConsoleCursorPosition(hConsole, position);
                cout << "Y";

                position = { 27, 1 };
                SetConsoleCursorPosition(hConsole, position);
                cout << "Z";
            }
            position = { 5, (short)(string) };
            SetConsoleCursorPosition(hConsole, position);
            cout << arrayX[i];

            position = { 15, (short)(string) };
            SetConsoleCursorPosition(hConsole, position);
            cout << arrayY[i];

            position = { 27, (short)(string) };
            SetConsoleCursorPosition(hConsole, position);
            cout << arrayZ[i];

            if (i == 63) {
                do
                {
                    choise = _getch();
                } while ((char)choise != 97 && (char)choise != 100);
                if (choise == 97) {
                    i = 47;
                    cout << page--;
                }
                else if (choise == 100) page++;
            }
            string++;
        }
        else if (page == 8) {
            if (string == 11) {
                system("cls");
                string = 3;
                Frame_answer_screen(weight, height);

                position = { 5, 1 };
                SetConsoleCursorPosition(hConsole, position);
                cout << "X";

                position = { 15, 1 };
                SetConsoleCursorPosition(hConsole, position);
                cout << "Y";

                position = { 27, 1 };
                SetConsoleCursorPosition(hConsole, position);
                cout << "Z";
            }

            position = { 5, (short)(string) };
            SetConsoleCursorPosition(hConsole, position);
            cout << arrayX[i];

            position = { 15, (short)(string) };
            SetConsoleCursorPosition(hConsole, position);
            cout << arrayY[i];

            position = { 27, (short)(string) };
            SetConsoleCursorPosition(hConsole, position);
            cout << arrayZ[i];

            if (i == 71) {
                do
                {
                    choise = _getch();
                } while ((char)choise != 97 && (char)choise != 100);

                if (choise == 97) {
                    i = 55;
                    cout << page--;
                }

                else if (choise == 100) page++;
            }
            string++;
        }
        else if (page == 9) {
            if (string == 11) {
                system("cls");
                string = 3;
                Frame_answer_screen(weight, height);

                position = { 5, 1 };
                SetConsoleCursorPosition(hConsole, position);
                cout << "X";

                position = { 15, 1 };
                SetConsoleCursorPosition(hConsole, position);
                cout << "Y";

                position = { 27, 1 };
                SetConsoleCursorPosition(hConsole, position);
                cout << "Z";
            }

            position = { 5, (short)(string) };
            SetConsoleCursorPosition(hConsole, position);
            cout << arrayX[i];

            position = { 15, (short)(string) };
            SetConsoleCursorPosition(hConsole, position);
            cout << arrayY[i];

            position = { 27, (short)(string) };
            SetConsoleCursorPosition(hConsole, position);
            cout << arrayZ[i];

            if (i == 79) {
                do
                {
                    choise = _getch();
                } while ((char)choise != 97 && (char)choise != 100);
                
                if (choise == 97) {
                    i = 63;
                    cout << page--;
                }
                
                else if (choise == 100) page++;
            }
            string++;
        }
        else if (page == 10) {
            if (string == 11) {
                system("cls");
                string = 3;
                Frame_answer_screen(weight, height);

                position = { 5, 1 };
                SetConsoleCursorPosition(hConsole, position);
                cout << "X";

                position = { 15, 1 };
                SetConsoleCursorPosition(hConsole, position);
                cout << "Y";

                position = { 27, 1 };
                SetConsoleCursorPosition(hConsole, position);
                cout << "Z";


                position = { 2, 12 };
                SetConsoleCursorPosition(hConsole, position);
                cout << "Это последняя страница, ENTER - Далее";
            }

            position = { 5, (short)(string) };
            SetConsoleCursorPosition(hConsole, position);
            cout << arrayX[i];

            position = { 15, (short)(string) };
            SetConsoleCursorPosition(hConsole, position);
            cout << arrayY[i];

            position = { 27, (short)(string) };
            SetConsoleCursorPosition(hConsole, position);
            cout << arrayZ[i];

            if (i == 87) {
                do
                {
                    choise = _getch();
                } while ((char)choise != 97 && (char)choise != 100);

                if (choise == 97) {
                    i = 71;
                    cout << page--;
                }
                else if (choise == 100) {
                    break;
                };
            }
            string++;
        }
    }


    position = { 0, 12 };
    SetConsoleCursorPosition(hConsole, position);
}
//Завершающий экран
void endScreen(int weight, int height) {

    Frame_with_1_string(weight, height);

    position = { 16,3 };
    SetConsoleCursorPosition(hConsole, position);
    cout << "Программа";

    position = { 9, 4 };
    SetConsoleCursorPosition(hConsole, position);
    cout << "Циклическое вычисление";

    position = { 10,5 };
    SetConsoleCursorPosition(hConsole, position);
    cout << "Завершила свою работу";

    position = { 13,11 };
    SetConsoleCursorPosition(hConsole, position);
    cout << "До новых встреч";

    position = { 0, 13 };
    SetConsoleCursorPosition(hConsole, position);

}
//Ввод данных
void writeData(int weight, int height, int &x1, int &x2, int &y1, int &y2, int &stepX, int &stepY, COORD position, HANDLE hConsole) {

    Frame_with_1_string(weight, height);

    char number[50];

    //////////////////////////////////////////////////

    position = { 13, 11 };
    SetConsoleCursorPosition(hConsole, position);
    cout << "Введите данные";

    position = { 10, 3 };
    SetConsoleCursorPosition(hConsole, position);
    cout << "Введите X1: ";
    
    cin >> number;
    while (!is_number(number)) {
        system("cls");

        Frame_with_1_string(weight, height);
        
        position = { 5, 11 };
        SetConsoleCursorPosition(hConsole, position);
        cout << "Ошибка, введите данные повторно";
        
        position = { 10, 3 };
        SetConsoleCursorPosition(hConsole, position);
        cout << "Введите X1: ";
        
        cin >> number;
    }
    x1 = char_to_int(number);

    ////////////////////////////////////////////////////

    ////////////////////////////////////////////////////
    position = { 10, 4 };
    SetConsoleCursorPosition(hConsole, position);
    cout << "Введите X2: ";

    cin >> number;
    while (!is_number(number)) {
        system("cls");

        Frame_with_1_string(weight, height);

        position = { 5, 11 };
        SetConsoleCursorPosition(hConsole, position);
        cout << "Ошибка, введите данные повторно";

        position = { 10, 3 };
        SetConsoleCursorPosition(hConsole, position);
        cout << "Введите X1: ";

        position = { 22, 3 };
        SetConsoleCursorPosition(hConsole, position);
        cout << x1;

        position = { 10, 4 };
        SetConsoleCursorPosition(hConsole, position);

        cout << "Введите X2: ";

        cin >> number;
    }
    x2 = char_to_int(number);
    
    ////////////////////////////////////////////////////

    ////////////////////////////////////////////////////

    position = { 10, 5 };
    SetConsoleCursorPosition(hConsole, position);
    cout << "Введите Y1: ";

    cin >> number;

    while (!is_number(number)) {
        system("cls");

        Frame_with_1_string(weight, height);

        position = { 5, 11 };
        SetConsoleCursorPosition(hConsole, position);
        cout << "Ошибка, введите данные повторно";

        position = { 10, 3 };
        SetConsoleCursorPosition(hConsole, position);
        cout << "Введите X1: ";

        position = { 22, 3 };
        SetConsoleCursorPosition(hConsole, position);
        cout << x1;

        position = { 10, 4 };
        SetConsoleCursorPosition(hConsole, position);
        cout << "Введите x2: ";

        position = { 22, 4 };
        SetConsoleCursorPosition(hConsole, position);
        cout << x2;

        position = { 10, 5 };
        SetConsoleCursorPosition(hConsole, position);
        cout << "Введите Y1: ";

        cin >> number;
    }
    y1 = char_to_int(number);
    
    ////////////////////////////////////////////////////

    ////////////////////////////////////////////////////

    position = { 10, 6 };
    SetConsoleCursorPosition(hConsole, position);
    cout << "Введите Y2: ";
    
    cin >> number;

    while (!is_number(number)) {
        system("cls");

        Frame_with_1_string(weight, height);

        position = { 5, 11 };
        SetConsoleCursorPosition(hConsole, position);
        cout << "Ошибка, введите данные повторно";

        position = { 10, 3 };
        SetConsoleCursorPosition(hConsole, position);
        cout << "Введите X1: ";

        position = { 22, 3 };
        SetConsoleCursorPosition(hConsole, position);
        cout << x1;

        position = { 10, 4 };
        SetConsoleCursorPosition(hConsole, position);
        cout << "Введите x2: ";

        position = { 22, 4 };
        SetConsoleCursorPosition(hConsole, position);
        cout << x2;

        position = { 10, 5 };
        SetConsoleCursorPosition(hConsole, position);
        cout << "Введите Y1: ";

        position = { 22, 5 };
        SetConsoleCursorPosition(hConsole, position);
        cout << y1;

        position = { 10, 6 };
        SetConsoleCursorPosition(hConsole, position);
        cout << "Введите Y2: ";

        cin >> number;
    }

    y2 = char_to_int(number);

    ////////////////////////////////////////////////////

    ////////////////////////////////////////////////////

    position = { 10, 7 };
    SetConsoleCursorPosition(hConsole, position);
    cout << "Введите stepX: ";

    cin >> number;

    while (!is_number(number)) {
        system("cls");

        Frame_with_1_string(weight, height);

        position = { 5, 11 };
        SetConsoleCursorPosition(hConsole, position);
        cout << "Ошибка, введите данные повторно";

        position = { 10, 3 };
        SetConsoleCursorPosition(hConsole, position);
        cout << "Введите X1: ";

        position = { 22, 3 };
        SetConsoleCursorPosition(hConsole, position);
        cout << x1;

        position = { 10, 4 };
        SetConsoleCursorPosition(hConsole, position);
        cout << "Введите x2: ";

        position = { 22, 4 };
        SetConsoleCursorPosition(hConsole, position);
        cout << x2;

        position = { 10, 5 };
        SetConsoleCursorPosition(hConsole, position);
        cout << "Введите Y1: ";

        position = { 22, 5 };
        SetConsoleCursorPosition(hConsole, position);
        cout << y1;

        position = { 10, 6 };
        SetConsoleCursorPosition(hConsole, position);
        cout << "Введите Y2: ";

        position = { 22, 6 };
        SetConsoleCursorPosition(hConsole, position);
        cout << y2;

        position = { 10, 7 };
        SetConsoleCursorPosition(hConsole, position);
        cout << "Введите stepX: ";

        cin >> number;
    }

    stepX = char_to_int(number);

    ////////////////////////////////////////////////////

    ////////////////////////////////////////////////////

    position = { 10, 8 };
    SetConsoleCursorPosition(hConsole, position);

    cout << "Введите stepY: ";

    cin >> number;

    while (!is_number(number)) {
        system("cls");

        Frame_with_1_string(weight, height);
        
        position = { 5, 11 };
        SetConsoleCursorPosition(hConsole, position);
        cout << "Ошибка, введите данные повторно";

        position = { 10, 3 };
        SetConsoleCursorPosition(hConsole, position);
        cout << "Введите X1: ";

        position = { 22, 3 };
        SetConsoleCursorPosition(hConsole, position);
        cout << x1;

        position = { 10, 4 };
        SetConsoleCursorPosition(hConsole, position);
        cout << "Введите x2: ";

        position = { 22, 4 };
        SetConsoleCursorPosition(hConsole, position);
        cout << x2;

        position = { 10, 5 };
        SetConsoleCursorPosition(hConsole, position);
        cout << "Введите Y1: ";

        position = { 22, 5 };
        SetConsoleCursorPosition(hConsole, position);
        cout << y1;

        position = { 10, 6 };
        SetConsoleCursorPosition(hConsole, position);
        cout << "Введите Y2: ";

        position = { 22, 6 };
        SetConsoleCursorPosition(hConsole, position);
        cout << y2;

        position = { 10, 7 };
        SetConsoleCursorPosition(hConsole, position);
        cout << "Введите stepX: ";

        position = { 25, 7 };
        SetConsoleCursorPosition(hConsole, position);
        cout << stepX;


        position = { 10, 8 };
        SetConsoleCursorPosition(hConsole, position);
        cout << "Введите stepY: ";

        cin >> number;
    }

    stepY = char_to_int(number);

    ////////////////////////////////////////////////////

}

//Жизненный цикл
void lifeCycle(int weight, int height, int &x1, int &x2, int &y1, int &y2, int &stepX, int &stepY, int arrayX[], int arrayY[], double arrayZ[], int& sizeArrays, COORD position, HANDLE hConsole) {

    bool life_cycle = true;
    char choise;

    mainScreen(weight, height);

    do {
        //ASCII "Esc" = 27, ASCII "Enter" = 13;

        life_cycle = ((choise = _getch()) == 27) ? 0 : 1;

        if (choise == 27) {
            life_cycle = false;
            system("cls");
        }
        else if (choise == 13) {
            system("cls");

            writeData(weight, height, x1, x2, y1, y2, stepX, stepY, position, hConsole);

            resultCalculation(x1, x2, stepX, y1, y2, stepY, arrayX, arrayY, arrayZ, height, weight, sizeArrays);

            answerScreen(weight, height, arrayX, arrayY, arrayZ);

            cout << "\n\n";
        }
        else {
            system("cls");
            mainScreen(weight, height);
        }

    } while (life_cycle);

    endScreen(weight, height);

    cout << "\n\n\n";
}