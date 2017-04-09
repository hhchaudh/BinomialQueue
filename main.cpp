#include <iostream>
#include <fstream>
#include "BinomialQueue.h"
#include "Queue.h"

int getChoice();
void menuLoop( BinomialQueue& bQueue );
void insertItem( BinomialQueue& bQueue );
void deletemin( BinomialQueue& bQueue );
void printLevelOrder( BinomialQueue& bQueue );

int main()
{
    int anInteger;
    std::ifstream fileReader( "data.txt" );

    if( fileReader.is_open() )
    {
        BinomialQueue bQueue;

        while( fileReader >> anInteger )
        {
            bQueue.insert( anInteger );
        }

        menuLoop( bQueue );
        fileReader.close();
    }
    else
    {
        std::cout << "Error reading file\n";
    }

    return 0;
}

void menuLoop( BinomialQueue& bQueue )
{
    int choice = 0;

    while( choice != 4 )
    {
        choice = getChoice();

        switch( choice )
        {
        case 1:
            insertItem( bQueue );
            break;
        case 2:
            deletemin( bQueue );
            break;
        case 3:
            printLevelOrder( bQueue );
            break;
        case 4:
        default:
            if( choice != 4 )
            {
                std::cout << "Enter a valid choice (1-4)\n";
            }
            break;
        }
    }
}

int getChoice()
{
    int choice = 0;

    std::cout << "..........................................................\n";
    std::cout << "Please choose one of the folowing commands:\n";
    std::cout << "1 - insert\n"
        << "2 - deletemin\n"
        << "3 - levelorder\n"
        << "4 - exit\n"
        << "\n";

    std::cin >> choice;

    return choice;
}

void insertItem( BinomialQueue& bQueue )
{
    std::cout << "Choose a number to be added to the heap\n";
    int number;
    std::cin >> number;
    bQueue.insert( number );
}

void deletemin( BinomialQueue& bQueue )
{
    bQueue.deleteMin();
}

void printLevelOrder( BinomialQueue& bQueue )
{
    std::cout << "Level Order:\n";
    bQueue.levelOrderDisplay();
    std::cout << std::endl;
}