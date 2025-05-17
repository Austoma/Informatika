#include <iostream>
#include <clocale>
using namespace std;

struct Videotape {
    char name[201]; // название
    char director[201]; // режиссёр
    double duration; // продолжительность
    double price; // цена
};
void RemoveVideotape(int index, Videotape arr[], int& size)
{
    --size;
    for (int i = index; i < size; i++)
    {
        arr[i] = arr[i + 1];
    }
}
void AddVideotapeToEnd(const Videotape& videotape, Videotape arr[], int& size)
{
    arr[size] = videotape;
    ++size;
}
void ReadVideotape(Videotape& videotape)
{
    cout << "Enter the movie name: ";
    cin >> videotape.name;
    cout << "Enter the film's director: ";
    cin >> videotape.director;
    cout << "Enter the movie price: ";
    cin >> videotape.price;
    cout << "Enter the duration of the movie: ";
    cin >> videotape.duration;
}
void PrintArray(Videotape* arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << "[ " << arr[i].name << ", " << arr[i].director << ", " << arr[i].price << ", " << arr[i].duration << " ]\n";
    }
}
int main()
{
    setlocale(LC_ALL, "rus");
    int videotapeQuantity;
    Videotape* videotapeArray;
    cout << "Enter the number of movies: ";
    cin >> videotapeQuantity;
    videotapeArray = new Videotape[videotapeQuantity + 3]; // память + 3
    for (int i = 0; i < videotapeQuantity; i++)
    {
        ReadVideotape(videotapeArray[i]);
    }
    long leastPrice;
    cout << "Enter the reference price: ";
    cin >> leastPrice;
    int i = 0;
    while (i < videotapeQuantity)
    {
        if (videotapeArray[i].price > leastPrice)
        {
            RemoveVideotape(i, videotapeArray, videotapeQuantity);
        }
        else {
            ++i;
        }
    }
    cout << "An array of videos with a higher price after deletion " << leastPrice << ":\n";
    PrintArray(videotapeArray, videotapeQuantity);
    cout << "Add 3 new elements to the end of the array.\n";
    for (int j = 0; j < 3; j++)
    {
        Videotape newVideotape;
        cout << "Enter the data for the new item " << j + 1 << ":\n";
        ReadVideotape(newVideotape);
        AddVideotapeToEnd(newVideotape, videotapeArray, videotapeQuantity);
    }
    cout << "The array after adding 3 new elements:\n";
    PrintArray(videotapeArray, videotapeQuantity);
    delete[] videotapeArray;
    return 0;
}
