#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

vector<int> arr;

void choice(int arr[], int length);
int fibonachi1(int arr[], int length);
int fibonachi2(int arr[], int length);
int fibonachi3(int arr[], int length);


void statMassiv(){
    int length = 10;
    int arr[10] = {};
    int vopr;
    cout << "Введите как вы хотите заполнить массив(1-вручную, 2-случайно): ";
    cin >> vopr;
    if (vopr == 1) {
        for(int i = 0; i < 10; i++)
          {
            cin >> arr[i]; // Вводим с клавиатуры значение ячейки массива
          }
    }
    else if(vopr == 2){
        srand(time(0));
        for(int i = 0; i < 10; i++){
            arr[i] = rand();
            cout << arr[i] << " ";
        }
    }     choice(arr, length);
}

void dinMassiv(){
    int length;
    cout << "введите длину динамического массива:";
    cin >> length;
    int *arr = new int[length];
    int vopr;
    cout << "Введите как вы хотите заполнить массив(1-вручную, 2-случайно): ";
    cin >> vopr;
    if (vopr == 1) {
        for(int i = 0; i < length; i++)
          {
            cin >> arr[i]; // Вводим с клавиатуры значение ячейки массива
          }
    }
    else if(vopr == 2){
        if (length > 0 ) {
                srand(time(0));
                for (int i = 0; i < length; i++) {
                    arr[i] = 100 + rand() % 900; // получаем для заполнения элеметы 100<n<1000
                }
        }
    }
    choice(arr, length);
}

void vectorMassiv(vector<int>& arr){
    int length;
    cout << "введите длину векторного массива:";
    cin >> length;
    arr.resize(length);
    int vopr;
    cout << "Введите как вы хотите заполнить массив(1-вручную, 2-случайно): ";
    cin >> vopr;
    if (vopr == 1) {
        for(int i = 0; i < length; i++)
          {
            cin >> arr[i]; // Вводим с клавиатуры значение ячейки массива
          }
    }
    else if(vopr == 2){
        int tmp = 0;
        srand(time(0));
        for (int i = 0; i < length; i++) {
            tmp = 100 + rand() % 900; // получаем для заполнения элеметы 100<n<1000
            arr.push_back(tmp);
            tmp = 0;
            }
        }
    }

void choice(int arr[], int length){
    int func;
    cout<< "Введите название фибоначи которое вам нужен(1-fibonachi1, 2-fibonachi2, 3-fibonachi3): ";
    cin >> func;
    if(func == 1){
        fibonachi1(arr, length);
    }
    else if(func == 2){
        fibonachi2(arr, length);
    }
    else if(func == 3){
        fibonachi3(arr, length);
    }
}

void logicfibonachi(int arr[], int length){
    for(int i = 0; i < length; i++){
        int element = arr[i], m = 0;
        while (element)
        {
            m = m*10+element%10;
            element /= 10;
        }
        int result = 0;
        while (m!=0 and result !=1)
            {
                int one = 0, two = 0, sum = 0, sumOneTwo;
                one = m%10;
                m /= 10;
                two = m%10;
                m /= 10;
                sumOneTwo = one + two;
                sum += m%10;
                if(sum == sumOneTwo){
                    cout << i << endl;
                    result +=1;
                }
                else if(sumOneTwo >= 10){
                    sum = sum*10 + m%10;
                    if(sum == sumOneTwo){
                        cout << i << endl;
                        result +=1;
                    }
                }
                m = m*10 + two;
            }
        }
    }

int fibonachi1(int arr[], int length){
    logicfibonachi(arr, length);
    return 0;
}

int fibonachi2(int arr[], int length){
    logicfibonachi(arr, length);
    int k = 0, numb = 0;
    cout << "Введите число k " <<endl;
    cin >> k;
    cout << "Введите № элемента массива после которого нужно вставить число k " <<endl;
    cin >> numb;
    for ( int i = length; i -1 > numb; i-- )   // сдвинули элементы вправо и освободили n- е место
           arr[i] = arr[i-1];
        arr[numb]=k; // вставили
        for ( int i = 0; i < length; i++ )
            cout << arr[i] << " ";;
    return 0;
}

int fibonachi3(int arr[], int length){
    logicfibonachi(arr, length);
    int k = 0, numb = 0;
    cout << "Введите № элемента массива после которого нужно вставить число k " <<endl;
    cin >> numb;
    for (long i = numb; i < length; ++i)
    {
      arr[i] = arr[i + 1];
    }
    --length;
    for ( int i = 0; i < length; i++ )
        cout << arr[i] << " ";;
    return 0;
}

int main() {
    vector<int> mas_vector;
    int mas = 0;
    cout<< "Введите цифру массива которое вам нужен(1-statMassiv, 2-dinMassiv, 3-vectorMassiv):";
    cin >> mas;
    switch (mas) {
        case 1:
            statMassiv();
            break;
        case 2:
            dinMassiv();
            break;
        case 3:
            vectorMassiv(mas_vector);
            break;
            
        default:
            break;
    }
}
