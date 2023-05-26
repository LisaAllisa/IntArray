#pragma once
#ifndef INTARRAY_H
#define INTARRAY_H
#include <exception>
#include <iostream>

using namespace std;

// ����� ���������� bad_range � ��� ������ �� ������� �������
class BadRange : public exception
{
public:
    virtual const char* what() const noexcept override
    {
        return " Error: out of massive ";
    }
};

// ����� ���������� bad_length � �������������� ������������ 
// ����� �������
class BadLength : public exception
{
public:
    virtual const char* what() const throw() override
    {
        return " Error: what with length of massive? ";
    }
};

// ����� ��������� ������
//IntegerArray � ������, ������� ������ ����� ����� � ��������
// ��������� ����������� ������ �� ����� ���������� ���������
class IntArray: public BadRange, BadLength
{
private:
    int m_length{}; // ������ �������
    int* m_data{};  // ������ �������

public:
    IntArray() = default;  // ����������� ��� ������� �������
    IntArray(int length);  // ����������� ��� ������� ��������� �������
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