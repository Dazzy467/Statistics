#pragma once
#include <map>
#include <vector>
#include <algorithm>
#include <math.h>

template<typename T>
class cstatistic
{
public:
    cstatistic() : data(nullptr), size(0) {}
    cstatistic(T* _data, size_t _size)
    {
        this->data = new T[_size];
        this->size = _size;
        std::copy(_data,(_data + _size),this->data);
    }

    template<typename PT,size_t N>
    cstatistic(PT(&_data)[N])
    {
        this->data = new T[N];
        this->size = N;
        std::copy(_data,(_data + N),this->data);
    }

    ~cstatistic()
    {
        if (this->data != nullptr)
            delete[] this->data;
        
        this->size = 0;
    }

public: //accessor 
    const T* getData() const {return this->data;}

    std::map<T,int> getFrequencyMap() const {
        std::map<T,int> freqMap;
        for (size_t i = 0; i < this->size; i++)
        {
            if (freqMap.find(this->data[i]) == freqMap.end()) {
                freqMap[this->data[i]] = 1;
            } else {
                freqMap[this->data[i]]++;
            }
        }
        
        
        return freqMap;
    }
    
    float getMean() const 
    {
        float sum = float{};
        for (size_t i = 0; i < this->size; i++)
            sum += this->data[i];

        return (sum/this->size);
    }

    float getMedian() const
    {
        std::vector<T> tempArr(this->size);
        std::copy(this->data,(this->data+this->size),tempArr.begin());
        std::sort(tempArr.begin(),tempArr.end());
        float median;
        if (this->size % 2 == 0)
        {
            int index = this->size/2;
            median = (tempArr[index] + tempArr[index+1]) / 2;
        }
        else{
            int index = (this->size)/2;
            median = tempArr[index];
        }
        return median;
    }

    T getMode() const
    {
        std::map<T,int> freqMap = this->getFrequencyMap();
        auto mKey = std::max_element(freqMap.begin(),freqMap.end(),[&](const auto& a,const auto& b){
            return a.second < b.second;
        });

        return mKey->first;
    }

    float getStdDeviation() const
    {
        float sum,_tsum;
        
        for (size_t i = 0; i < this->size; i++)
            sum += std::pow(this->data[i] - this->getMean(),2);

        _tsum = sum / (this->size - 1);
        return std::sqrt(_tsum);
    }
public: // Outputing
    void printData()
    {
        for (size_t i = 0; i < this->size; i++)
            std::cout << this->data[i] << " ";
        
        std::cout << std::endl;
    }


private:
    T* data;
    size_t size;
};

template<typename T,size_t n>
void printData(T(&arr)[n])
{
    for (size_t i = 0; i < n; i++)
        std::cout << arr[i] << ' ';
    std::cout << std::endl;
}


template<typename T,size_t n>
void printFreq(T(&arr)[n])
{
    std::map<T,int> freqMap;

    for (size_t i = 0; i < n; i++)
        freqMap[arr[i]]++;
    

    for (auto it = freqMap.begin(); it != freqMap.end(); ++it)
        std::cout << it->first << " : " << it->second << std::endl;
}

template<typename T,size_t n>
void printMean(T(&arr)[n])
{
    float sum = float{};
    for (size_t i = 0; i < n; i++)
        sum += arr[i];
    
    std::cout << "Mean: " << (sum/n) << std::endl;
} 

template<typename T,size_t n>
void printMedian(T(&arr)[n])
{
    std::vector<T> tempArr(n);
    std::copy(arr,(arr+n),tempArr.begin());
    std::sort(tempArr.begin(),tempArr.end());
    float median;
    if (n % 2 == 0)
    {
        int index = n/2;
        median = (tempArr[index] + tempArr[index+1]) / 2;
    }
    else{
        int index = (n)/2;
        median = tempArr[index];
    }

    std::cout << "Median: " << median << std::endl;
}