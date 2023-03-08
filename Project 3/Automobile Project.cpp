#include <iostream>
using namespace std;

int histogramGlobalArray[12];

class autoMobile {
    public:
        string modelName;
        int price;
        string ownerName;
        autoMobile* next;

        autoMobile() {
            modelName = "";
            price = 0;
            ownerName = "";
            next = NULL;
        }
        
        autoMobile(int cost, string car, string owner) {
            price = cost;
            modelName = car;
            ownerName = owner;
            next = NULL;
        }
};

void carListPrint(autoMobile* temp){
    while(temp) {
        cout << temp -> modelName << " - " << temp -> price << " - " << temp-> ownerName << endl;
        temp = temp -> next;
    }
        cout << endl;
}

void printHistogramOfData() {
    int max = 20500; 
    for (int m = max; m >= 5500; m-=500) { 
        cout.width(4); 
        cout << right << m << " | "; 
        
        for (int n = 0; n < 12; n++) { 
            if (histogramGlobalArray[n] >= m)
                cout << " * ";
            else {
                cout << "   ";
        }
    }
        cout << endl;
    }
    
    for (int i = 0; i < 12 + 4; i++)
        cout << "----";
  
    cout << "\n";
    cout << "    ";
  
    for (int i = 0; i < 12; i++) {
        cout.width(4);
        cout << right << histogramGlobalArray[i] << " ";
    }
}

int getAveragePrice(autoMobile* temp) {
    int sum = 0;
    while(temp) {
        sum += temp -> price;
        temp = temp -> next;
    }
    
    int averagePrice = sum/12; 
    return averagePrice;
}

void carsMoreExpensiveThanAverage(autoMobile* temp, float averagePrice) {
        while(temp) {
            if(temp -> price > averagePrice)
                cout << temp -> modelName<< " - " << temp -> price << " - " << temp -> ownerName << endl;
            temp = temp -> next;
    }
    
    cout << endl;
}

autoMobile* carsLessExpensive(autoMobile* temp, int averagePrice) {
        int c = (averagePrice*25) / 100;
        cout << "Average price of car (25%): $" << c << endl;
        autoMobile* head = temp;
        autoMobile* prev = temp;
        autoMobile* t = NULL;
        temp = temp -> next;
    
    while(temp) {
        if(temp->price < c) {
            prev -> next = temp -> next;
            t = temp;
            temp = temp -> next;
            delete t;
        }
        
        else {
            prev = temp;
            temp = temp -> next;
        }
    }
    
    return head;
}

int main() {

     string Name;

    autoMobile* head = new autoMobile(5500, "Cadillac", "Aquib");
    histogramGlobalArray[0] = 5500;
    
    autoMobile* car1 = new autoMobile(12500,"BMW","Ahona");
    histogramGlobalArray[1] = 12500;
    head->next = car1;
    
    autoMobile* car2 = new autoMobile(6500, "Toyota", "Sufian");
    histogramGlobalArray[2] = 6500;
    car1->next = car2;
    
    autoMobile* car3 = new autoMobile(13500, "BMW", "Shahid");
    histogramGlobalArray[3] = 13500;
    car2->next = car3;
    
    autoMobile* car4 = new autoMobile(7500, "Cadillac", "Pritom");
    histogramGlobalArray[4] = 7500;
    car3->next = car4;
    
    autoMobile* car5 = new autoMobile(8500, "Toyota", "Shakil");
    histogramGlobalArray[5] = 8500;
    car4->next = car5;
    
    autoMobile* car6 = new autoMobile(8000, "BMW", "Ithmam");
    histogramGlobalArray[6] = 8000;
    car5->next = car6;
    
    autoMobile* car7 = new autoMobile(13000, "Toyota","Fardin");
    histogramGlobalArray[7] = 13000;
    car6->next = car7;
    
    autoMobile* car8 = new autoMobile(20000, "BMW", "Sagrey");
    histogramGlobalArray[8] = 20000;
    car7->next = car8;
    
    autoMobile* car9 = new autoMobile(19500, "Toyota", "Shadman");
    histogramGlobalArray[9] = 19500;
    car8->next = car9;
    
    autoMobile* car10 = new autoMobile(16500, "Cadillac", "Abrar");
    histogramGlobalArray[10] = 16500;
    car9->next = car10;
    
    autoMobile* car11 = new autoMobile(14500, "Cadillac", "Hridoy");
    histogramGlobalArray[11] = 14500;
    car10->next = car11;

    cout << "List of contained cars: \n";
    cout << endl;
    carListPrint(head);
    cout << "Histogram: \n";
    cout << endl;
    printHistogramOfData();
    cout << endl;
    cout << endl;
    cout << endl;
    
    float averagePrice = getAveragePrice(head);
    cout << "Average price of cars: $" << averagePrice << endl;
    cout << endl;
    
    cout << "Cars which are expensive than the average price: \n";
    carsMoreExpensiveThanAverage(head,averagePrice);

    head = carsLessExpensive(head,averagePrice);
    cout << endl;
    
    cout << "Updated list of cars contained: \n";
    cout << endl;
    carListPrint(head);
    return 0;
}