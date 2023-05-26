#pragma once
#ifndef INTARRAY_H
#define INTARRAY_H
#include <exception>
#include <iostream>

using namespace std;

// класс исключений bad_range — для выхода за пределы массива
class BadRange : public exception
{
public:
    virtual const char* what() const noexcept override
    {
        return " Error: out of massive ";
    }
};

// класс исключений bad_length — предоставление неправильной 
// длины массиву
class BadLength : public exception
{
public:
    virtual const char* what() const throw() override
    {
        return " Error: what with length of massive? ";
    }
};

// класс контейнер данных
//IntegerArray — объект, который хранит целые числа и способен
// вычислить собственный размер во время выполнения программы
class IntArray: public BadRange, BadLength
{
private:
    int m_length{}; // данные массива
    int* m_data{};  // размер массива

public:
    IntArray() = default;  // конструктор для пустого массива
    IntArray(int length);  // конструктор для массива заданного размера
    ~IntArray();

    int getM_length() const;

    void Erase();
    
    int& operator[](int index);

    void reallocate(int newLength);

    void resize(int newLength);

    IntArray(const IntArray& a);

    IntArray& operator=(const IntArray& a);

    void insertBefore(int value, int index);

    void remove(int index);

    void insertAtBeggining(int value);

    void insertAtEnd(int value);
};

#endif