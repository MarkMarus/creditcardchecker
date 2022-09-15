#include <iostream>
#include <array>
#include <cmath>

using namespace std;
// here we declare the variables;
long long creditcard = 0; // enter credit card info here
int type;
int valid = 0;
array <int, 19> cardbits{};
int digits;
int length = log10(creditcard) + 1;
int sum;
int sum1;

// if credit card is valid console returns valid message if not it returns invalid message
void validate(){
    if (valid == 1)
    {
        cout << "Card is valid!" << endl;
    }
    if (valid == 0){
        cout << "Card is invalid!" << endl;
    }
    return;
}

//

void cardbreakup(){
    if (length<13){
        valid=0;
        cout << "Card number is too short!" << endl; // if card number digits amount is less then 13 returns error message
    }
    cout << "card number: " << creditcard << endl;
    for (int i = 0; i < length; i++){
        digits = creditcard % 10;
        creditcard /= 10;
        cardbits[i] = digits;
    }
}
// checking card
void cardcheck(){
    for (int j = 1; j < length; j += 2)
    {
        cardbits[j] *= 2;
        if (cardbits[j] > 9)
        {
            int c = cardbits[j] % 10;
            int d = cardbits[j] /= 10;
            cardbits[j] = c + d;
        }
        sum += cardbits[j];
    }
    for (int k = 0; k < length; k += 2)
    {
        sum1 += cardbits[k];
    }
    sum += sum1;
    sum %= 10;
    if (sum == 0)
    {
        valid = 1;
    }
}
void cardtype()
{
    // could maybe do switch case here instead but I don't want to in this scenario
    if (cardbits[length - 1] == 4)
    {
        cout << "type: Visa Card" << endl;
        cardcheck();
    }
    if ((cardbits[length - 1] == 3) && (cardbits[length - 2] == 7))
    {
        cout << "type: American Express" << endl;
        cardcheck();
    }
    if (cardbits[length - 1] == 5)
    {
        cout << "type: Master Card" << endl;
        cardcheck();
    }
    if (cardbits[length - 1] == 6)
    {
        cout << "type: Discover Card" << endl;
        cardcheck();
    }
}


// here we are declaring card number

// and finally running all the functions
int main() {
    cardbreakup();
    cardtype();
    validate();
    }
// i tried adding input for credit card but it kept working uncorrectly =((
