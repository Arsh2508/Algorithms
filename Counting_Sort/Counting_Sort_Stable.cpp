#include <iostream>
#include <vector>

int Max(std::vector<int>& arr) {
    int max = arr[0];
    for(size_t i = 1; i < arr.size(); ++i) {
        if(arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

int Min(std::vector<int>& arr) {
    int min = arr[0];
    for(size_t i = 1; i < arr.size(); ++i) {
        if(arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

void counting_sort(std::vector<int>& arr) {
    int min = Min(arr);
    int max = Max(arr);

    std::vector<int> freq(max - min + 1);

    for(auto i : arr) {
        ++freq[i - min];
    }

    for(int i = 1; i < freq.size(); ++i) {
        freq[i] += freq[i - 1];
    }

    std::vector<int> res(arr.size());

    for(int i = arr.size() - 1; i >= 0; --i) {
        int j = arr[i] - min;
        --freq[j];
        res[freq[j]] = arr[i];
    }
    arr = std::move(res);

}


int main()
{
    std::vector<int> array = {5, 2, 4, 1, 3, 9, 6, 7};
    counting_sort(array);   

    for(int i : array) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}
