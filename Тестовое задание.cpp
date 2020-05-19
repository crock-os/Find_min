#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

int Function(vector<int> Mass)
{
    
    //Проверка на пустоту массива
    if (Mass.empty())
    {
        cout << "Array is empty, please, try again" << endl;
        return 0;
    }
    
    int z = 0;
    
    //Отработка масива только с нулями
    for (int i = 0; i < Mass.size(); i++)
    {
        if (Mass[i] == 0) z++;
        if (z == Mass.size())
        {
            cout << "Array has zero only, please, input other array" << endl;
            return z;
        }
    }
    
    int min_1;
    int min_2;
    
    if (Mass[0] <= Mass[1])
    {
        min_1 = Mass[0];
        min_2 = Mass[1];
    }
    else 
    {
        min_2 = Mass[0];
        min_1 = Mass[1];
    }
    
    for (int i = 1; i < Mass.size(); i++)
    {
        if (Mass[i] <= min_2)
            if (Mass[i] < min_1) min_1 = Mass[i];
            else min_2 = Mass[i];
    }
    
    int sum = min_1 + min_2;
   
    cout << "Sum is equal " << sum << endl;
    
    return sum;
}

void TestFunction()
{
    int a;
    
    cout << "Input number of test (1, 2, 3 or 4) or 5 to use all tests: ";
    cin >> a;
    
    vector<int> Mass1(101);
    vector<int> Mass2(20, 1);
    vector<int> Mass3;
    vector<int> Mass4(20, 0);
    
    switch(a)
    {
        //Отработка 1 тестового массива с числами от -50 до 50
        case 1:
            for (int i = 0; i < Mass1.size(); i++)
                Mass1[i] = -50 + i;
            cout << "Test 1:" << endl;
            assert(Function(Mass1) == -99);
        break;
        
        //Отработка 2 тестового массива с единицами
        case 2:
            cout << "Test 2:" << endl;
            assert(Function(Mass2) == 2);
        break;
        
        //Отработка 3 пустого тестового массива
        case 3:
            cout << "Test 3:" << endl;
            assert(Function(Mass3) == 0);
        break;
        
        //Отработка 4 тестового массива с нулями
        case 4:
            cout << "Test 4:" << endl;
            assert(Function(Mass4) == Mass4.size());
        break;
        
        //Отработка всех тестовых массивов
        case 5:
        
            for (int i = 0; i < Mass1.size(); i++)
                Mass1[i] = -50 + i;
            cout << "Test 1:" << endl;
            assert(Function(Mass1) == -99);
            
            for (int i = 0; i < Mass2.size(); i++)
                Mass2[i] = 1;
            cout << "Test 2:" << endl;
            assert(Function(Mass2) == 2);
            
            cout << "Test 3:" << endl;
            assert(Function(Mass3) == 0);
            
            for (int i = 0; i < Mass4.size(); i++)
                Mass4[i] = 0;
            cout << "Test 4:" << endl;
            assert(Function(Mass4) == Mass4.size());
        break;
        
        default:
         cout << "You select incorrect number, please, try again" << endl;
        break;
    }
    
    cout << "Test OK" << endl;
}

int main()
{
  
  TestFunction();
    
}
