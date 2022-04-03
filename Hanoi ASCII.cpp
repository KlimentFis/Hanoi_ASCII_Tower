#include <iostream>
#include <string>
#include <stack>

std::stack <int> tower1;
std::stack <int> tower2;
std::stack <int> tower3;

void move(int i, int k)
{
    int element;

    switch (i)
    {
    case 1:
        element = tower1.top();
        tower1.pop();
        break;
    case 2:
        element = tower2.top();
        tower2.pop();
        break;
    case 3:
        element = tower3.top();
        tower3.pop();
        break;
    }

    switch (k)
    {
    case 1:
        tower1.push(element);
        break;
    case 2:
        tower2.push(element);
        break;
    case 3:
        tower3.push(element);
        break;
    }

}

void print(int char_num, int count)
{
    for (int i = 0; i < count; i++)
        std::cout << char(char_num);
}

void show(int tower_height)
{
    std::stack <int> stack1 = tower1;
    std::stack <int> stack2 = tower2;
    std::stack <int> stack3 = tower3;

    for (int i = tower_height ; i > 0; i--)
    {
        int el1 = 0;
        int el2 = 0;
        int el3 = 0;

        if (stack1.size() == i)
        {
            el1 = stack1.top();
            stack1.pop();
        }
        if (stack2.size() == i)
        {
            el2 = stack2.top();
            stack2.pop();
        }
        if (stack3.size() == i)
        {
            el3 = stack3.top();
            stack3.pop();
        }
        for (int j = 0; j < 2; j++)
        {
            print(32, (tower_height - el1 + 1)*2);
            print(35, el1*2);
            print(124, 1);
            print(35, el1*2);
            print(32, (tower_height - el1 + 1)*2);
            print(32, 1);
            print(32, (tower_height - el2 + 1)*2);
            print(35, el2*2);
            print(124, 1);
            print(35, el2*2);
            print(32, (tower_height - el2 + 1)*2);
            print(32, 1);
            print(32, (tower_height - el3 + 1)*2);
            print(35, el3*2);
            print(124, 1);
            print(35, el3*2);
            print(32, (tower_height - el3 + 1)*2);
            print(32, 1);
            print(10, 1);
        }
    }
    print(35, (tower_height * 4 + 5));
    print(32, 1);
    print(35, (tower_height * 4 + 5));
    print(32, 1);
    print(35, (tower_height * 4 + 5));
    print(10, 1);
}

void hanoi(int n, int i, int k, int disk)
{

    if (n == 1)
    {
        std::cout << "ѕереместите 1 диск с " << i << " на " << k << " башню" << std::endl;
        std::cout << std::endl;
        move(i, k);
        show(disk);
        getchar();
        system("cls");
    }
    else
    {
        int tmp = 6 - i - k;
        hanoi(n - 1, i, tmp, disk);
        std::cout << "ѕереместите 1 диск с " << i << " на " << k << " башню" << std::endl;
        std::cout << std::endl;
        move(i, k);
        show(disk);
        getchar();
        system("cls");
        hanoi(n - 1, tmp, k, disk);
    }
}

int main()
{
    setlocale(LC_ALL, "Rus");
   
    std::cout << "¬ведите количество дисков в ’анойской башне: " << std::endl;int disk;std::cin >> disk;    
    std::cout << "¬ведите стартовую позицию ’анойской башни: " << std::endl;int start; std::cin >> start;
    switch (start)
    {
    case 1:
        for (int i = disk; i > 0; i--)
            tower1.push(i);
        break;
    case 2:
        for (int i = disk; i > 0; i--)
            tower2.push(i);
        break;
    case 3:
        for (int i = disk; i > 0; i--)
            tower3.push(i);
        break;
    }
    
    std::cout << "¬ведите конечную позицию ’анойской башни: " << std::endl;int end; std::cin >> end;
    system("cls");
    std::cout << std::endl; std::cout << std::endl;
    show(disk);
    getchar();
    getchar();
    system("cls");
    hanoi(disk, start, end, disk);
    return 0;
}
