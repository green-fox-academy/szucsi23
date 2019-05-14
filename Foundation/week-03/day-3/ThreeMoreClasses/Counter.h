//
// Created by hun46 on 2019. 04. 17..
//

#ifndef THREEMORECLASSES_COUNTER_H
#define THREEMORECLASSES_COUNTER_H


class Counter {
public:
    Counter(int num = 0);

    void add();
    void add(int);

    int get() const;
    void set(int num);
    void reset();


private:
    int num;
    int store;
};


#endif //THREEMORECLASSES_COUNTER_H
