#include "vectorint.hpp"

VectorInt::VectorInt(int size) : m_size(size) {
    mp_Data = new int[size];
}

VectorInt::~VectorInt() {
    if(mp_Data != nullptr) {
        delete [] mp_Data;
    }
    mp_Data = nullptr;
}

void VectorInt::push_back(int val) {
    //Vector resize
    m_size = m_size + 1;  

    //temporary Array      
    int *tmp = new int[m_size];
    
    //copy Data in temporary Array 
    int i = 0;
    for (i = 0; i < m_size; i++)
    {
        tmp[i] = mp_Data[i];
    }

    //write transmitted value in temporary array
    tmp[m_size - 1] = val;
    delete[] mp_Data;
    mp_Data = tmp;
}

auto VectorInt::size() -> int {
    return m_size;
}

auto VectorInt::at(int index) -> int{
       return mp_Data[index];
}