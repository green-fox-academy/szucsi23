//
// Created by hun46 on 2019. 04. 17..
//

#ifndef PETROL_CAR_H
#define PETROL_CAR_H


class Car {
public:
    Car(int gasAmount = 30, int capacity = 40);

    int getGasAmount() const;
    void setGasAmount(int gasAmount);

    int getCapacity() const;

    bool isFull();
    void fill();

private:
    int gasAmount;
    int capacity;
};

#endif //PETROL_CAR_H
