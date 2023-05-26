#include "pch.h"
#include "IntArray.h"
#include <exception>
#include <iostream>


    // BadRange() - для выхода за пределы массива
    // BadLength() - предоставление неправильной длины массиву

// конструктор для массива заданного размера
IntArray::IntArray(int length) : m_length{ length }
{
    if (length < 0)
    {
        throw BadLength();
    }
        
    try
    {
        if (length >= 0)
           m_data = new int[length] {};
    }
    catch (BadLength& bd) // обработка исключений типа const char*
    {
        std::cout << "Error: " <<bd.what() << std::endl;
    }

}

// деструктор для освобождения динамических данных
IntArray::~IntArray()
{
    delete[] m_data;
}

int IntArray::getM_length() const
{
    return m_length;
}

// Erase() стирает массив и установит длину в 0
void IntArray::Erase()
{
    delete[] m_data;
    m_data = nullptr;
    m_length = 0;
}

// Перегрузка оператора [] для доступа к массиву
int& IntArray::operator[](int index)
{
    if (index < 0 && index > m_length)
    {
        throw BadRange();
    }

    try
    {
        return m_data[index];
    }

    catch (BadRange& br) // обработка исключений типа const char*
    {
        cout << "Error: " << br.what() << endl;
    }
 }

// reallocate уничтожает все элементы массива при изменении его размера
void IntArray::reallocate(int newLength)
{
    Erase();

    if (newLength <= 0)
        return;

    m_data = new int[newLength];
    m_length = newLength;
}

// reallocate или resize

// resize сохранит все элементы в массиве при изменении его размера
void IntArray::resize(int newLength)
{
    if (newLength == m_length)
        return;

    if (newLength <= 0)
    {
        Erase();
        return;
    }

    // выделяем динамическую память под новый массив
    int* data{ new int[newLength] };

    // если длина предыдущего массива больше нуля,
    // копируем элементы в новый массив
    if (m_length > 0)
    {
        
        int elementsToCopy{ (newLength > m_length) ? m_length : newLength };

        for (int index{ 0 }; index < elementsToCopy; ++index)
            data[index] = m_data[index];
    }

    delete[] m_data;

    m_data = data;
    m_length = newLength;
}

// конструктор копирования
IntArray::IntArray(const IntArray& a)
{
    reallocate(a.getM_length());
    for (int index{ 0 }; index < m_length; ++index)
        m_data[index] = a.m_data[index];
}

// оператор присваивания
 IntArray& IntArray::operator=(const IntArray& a)
{
    if (&a == this)
        return *this;

    reallocate(a.getM_length());

    for (int index{ 0 }; index < m_length; ++index)
        m_data[index] = a.m_data[index];

    return *this;
}

// функция вставки
void IntArray::insertBefore(int value, int index)
{
    if (index < 0 || index > m_length)
        throw BadRange();   

    try
    {
    // создадим новый динамический массив, 
    // размером больше на один элемент, чем предыдущий
    int* data{ new int[m_length + 1] };

    // копируем эелменты прошлого массива до необходимого индекса в новый
    for (int before{ 0 }; before < index; ++before)
        data[before] = m_data[before];

    // вставляем элемент
    data[index] = value;

    // копируем оставшиеся элементы массива
    for (int after{ index }; after < m_length; ++after)
        data[after + 1] = m_data[after];

    delete[] m_data;
    m_data = data;
    ++m_length;

    }

    catch (BadRange& br) // обработка исключений типа const char*
    {
        cout << "Error: " << br.what() << endl;
    }
}

// функция удаления
void IntArray::remove(int index)
{
    if (index < 0 || index > m_length)
    {
        throw BadRange();   
    }

    try
    {
    if (m_length == 1)
    {
        Erase();
        return;
    }

    int* data{ new int[m_length - 1] };

    for (int before{ 0 }; before < index; ++before)
        data[before] = m_data[before];

    for (int after{ index + 1 }; after < m_length; ++after)
        data[after - 1] = m_data[after];

    delete[] m_data;
    m_data = data;
    --m_length;
    }
    catch (BadRange& br) // обработка исключений типа const char*
    {
        cout << "Error: " << br.what() << endl;
    }
}

// функция для вставки эллемента в начало массива
void IntArray::insertAtBeggining(int value) 
{ 
    insertBefore(value, 0); 
}

// функция для вставки эллемента в конец массива
void IntArray::insertAtEnd(int value)
{
    insertBefore(value, m_length);
}