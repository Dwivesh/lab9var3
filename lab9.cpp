#include <iostream>
using namespace std;

template <typename TArr_in, typename TArr_out>
TArr_out* Tchange_Arrtype(const TArr_in InArr[],size_t S){
    TArr_out* OutArr = new TArr_out[S];
    for (size_t i = 0; i < S; i++) {
        OutArr[i] = static_cast<TArr_out>(InArr[i]);
    }
    return OutArr;
}
int main()
{
    size_t intA = 5;
    int *intArr = new int[intA] {1, 0, -1, 357, 5};

    cout << "Array in int:" << endl;
    for (size_t c = 0; c < intA; c++) {
        cout << c << " " << intArr[c] << endl;
    }

    bool* booArr = Tchange_Arrtype<int, bool>(intArr, intA);

    cout << "Array in bool:" << endl;
    for (size_t c = 0; c < intA; c++) {
        cout << c << " " << booArr[c] << endl;
    }

    char* chaArr = Tchange_Arrtype<int, char>(intArr, intA); /*reinterpret_cast<char*> если вдруг поламается
    (преобразовывает один тип указателя в другой без изменения значения самого указателя)*/

    cout << "Array in char:" << endl;
    for (size_t c = 0; c < intA; c++) {
        cout << c << " " << static_cast<int>(chaArr[c]) << endl; //"<<" не выводит аски(?)
    }

    unsigned int* uninArr = Tchange_Arrtype<int, unsigned int>(intArr, intA);

    cout << "Array in Unsigned Int:" << endl;
    for (size_t c = 0; c < intA; c++) {
        cout << c << " " << uninArr[c] << endl;
    }

    delete[] intArr;
    delete[] booArr;
    delete[] chaArr;
    delete[] uninArr;

    return 0;
}


