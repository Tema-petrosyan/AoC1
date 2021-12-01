#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

void task1(const string &path)
{
    fstream stream;
    stream.open(path);

    int temp(0), current(1), count(0);
    while(!stream.eof())
    {
        stream >> current;
        if(temp != 0 && current > temp) count++;
        temp = current;
    }

    stream.close();
    cout << count << '\n';
}

void task2(const string& path)
{
    vector<int> measures;
    fstream stream;

    stream.open(path);

    int count(1);
    measures.resize(count);
    while(count == 1 || !stream.eof()){
        stream >> measures[count - 1];
        count++;
        measures.resize(count);
    }

    int tempTrio(0), currentTrio, trioCount(0);
    for(int i = 0; i < count - 2; i++)
    {
        currentTrio = measures[i] + measures[i + 1] + measures[i + 2];
        if(currentTrio > tempTrio && tempTrio != 0)
            trioCount++;
        tempTrio = currentTrio;
    }

    stream.close();
    cout << trioCount << '\n';
}

int main()
{
    string path;
    fstream fileStream;
    char confirmChar('m');

    do {
        cout << "Type path to input file with puzzles:\n";
        cin >> path;

        fileStream.open(path);
        if(fileStream.is_open())
        {
            fileStream.close();
            cout << "File successfully opened!\n";
            cout << "First task result - ";
            task1(path);

            cout << "Second task result - ";
            task2(path);

            break;
        }
        else
        {
            fileStream.close();
            cout << "Wrong path to file. Not opened. Try again? y/n - ";
            cin >> confirmChar;
            if(confirmChar == 'y' || confirmChar == 'Y') confirmChar = 'm';
        }
    }while(confirmChar == 'm');
}