#include <iostream>
#include <vector>

char list_select{};

void show_menu()
{
    std::cout << "P - Print numbers\n";
    std::cout << "A - Add a number\n";
    std::cout << "M - Display mean of the numbers\n";
    std::cout << "S - Display smallest number\n";
    std::cout << "L - Dipslay the largers number\n";
    std::cout << "C - Clear numbers!\n";
    std::cout << "Q - Quit" << std::endl;
    std::cin >> list_select;
}

void wrong_choice()
{
    std::cout << "Please make a correct choice" << std::endl;
}

void list_empty()
{
    std::cout << "[] - the list is empty" << std::endl;
}

void small_big_empty()
{
    std::cout << "Unable to determine the number - list is empty" << std::endl;
}

int main()
{
    std::vector<int> data{};
    show_menu();

    if (list_select == 'P' || list_select == 'p')
    {
        if (data.size() == 0)
            std::cout << "[] - the list is empty";

        else
        {
            std::cout << "[";
            for (auto numbers : data)
                std::cout << numbers << " ";
            std::cout << "]";
        }
    }
    else if (list_select == 'A' || list_select == 'a')
    {
        int data_entry{};
        std::cout << "Enter a number: ";
        std::cin >> data_entry;
        data.push_back(data_entry);
        std::cout << data_entry << "added! " << std::endl;
    }
    else if (list_select == 'M' || list_select == 'm')
    {
        if (data.size() == 0)
            std::cout << "Unable to calculate the mean - no data" << std::endl;
        else
        {
            int total{}, average{};
            for (auto num : data)
                total += num;
            average = total / data.size();
            std::cout << average << std::endl;
        }
    }
    else if (list_select == 'S' || list_select == 's')
    {
        if (data.size() == 0)
            small_big_empty();
        else
        {
            int smallest = data.at(0);
            for (auto num : data)
                if (num < smallest)
                    smallest = num;
            std::cout << "Smallest number is: " << smallest << std::endl;
        }
    }
    else if (list_select == 'L' || list_select == 'l')
    {
        if (data.size() == 0)
            small_big_empty();
        else
        {
            int largest = data.at(0);
            for (auto num : data)
                if (num > largest)
                    largest = num;
            std::cout << "The largest number is: " << largest << std::endl;
        }
    }
    else if (list_select == 'C' || list_select == 'c')
    {
        if (data.size() == 0)
            list_empty();
        else
        {
            data.clear();
            std::cout << "List has been cleared!" << std::endl;
        }
    }
    while (list_select != 'Q' && list_select != 'q')
        ;
    return 0;
}