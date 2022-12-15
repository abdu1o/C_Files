#include <iostream>
using namespace std;

int CountOfWords(const char* path, char begin);

int main()
{
    const char* pathStatist = "C:\\examples.txt";
    const char* pathText = "C:\\examples.txt";

    FILE* statistics;

    char begin;
    cout << "Enter begin symbol: ";
    cin >> begin;

    if (fopen_s(&statistics, pathStatist, "w") != NULL)
    {
        cout << "NOT OPEN";
    }

    else
    {
        fprintf(statistics, "%s", "words: ");
        fprintf(statistics, "%d", CountOfWords(pathText, begin));
    }

}



int CountOfWords(const char* path, char begin)
{
    FILE* TEXT;

    int space;
    int words = 1;
    bool isStart = false;

    if (fopen_s(&TEXT, path, "r") != NULL)
    {
        cout << "Error";
    }

    else
    {
        while (!feof(TEXT))
        {
            space = fgetc(TEXT);

            if (space == begin)
            {
                isStart = true;
            }

            if (isStart && space == ' ')
            {
                words++;
            }
        }
    }

    return words;
}