#include <iostream>
#include <cstring> 
using namespace std;

class Car {
private:
    char* model;
    char* country;
    int year;
    double price;

public:
    Car()
    {
        model = new char[50];
        country = new char[50];
        year = 0;
        price = 0.0;
    }

    Car(const char* m, const char* c, int y, double p)
    {
        model = new char[strlen(m) + 1];
        country = new char[strlen(c) + 1];
        year = y;
        price = p;
    }

    ~Car()
    {
        delete[] model;
        delete[] country;
    }

    const char* getModel() const {return model;}
    void setModel(const char* mdl) 
    {
        delete[] model;
        model = new char[strlen(mdl) + 1];
        strcpy(model, mdl);
    }

    const char* getCountry() const { return country; }
    void setCountry(const char* cntry) 
    {
        delete[] country;
        country = new char[strlen(cntry) + 1];
        strcpy(country, cntry);
    }

    int getYear() const {return year;}
    void setYear(int yr) {year = yr;}

    double getPrice() const {return price;}
    void setPrice(double prc) {price = prc;}

    // Метод ввода данных с клавиатуры
    void Input() 
    {
        char tempModel[50];
        char tempCountry[50];

        cout << "Enter the model: ";
        cin >> tempModel;
        setModel(tempModel);

        cout << "Enter the country: ";
        cin >> tempCountry;
        setCountry(tempCountry);

        cout << "Enter the year: ";
        cin >> year;

        cout << "Enter the price: ";
        cin >> price;
    }

    // Метод вывода данных на консоль
    void Print() const 
    {
        cout << "Model: " << model << endl;
        cout << "Country: " << country << endl;
        cout << "Year: " << year << endl;
        cout << "Price: " << price << endl;
    }
};

int main() 
{
    Car car1("Porsche", "Germany", 2024, 86000.0);
    car1.Print();
    Car car2;
    car2.Input();
    car2.Print();
}
