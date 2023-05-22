#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <cmath>
#include <stack>
#include <map>
#include <unordered_map>
#include <iterator>
using namespace std;

struct ListNode{
    int val = 0;
    ListNode* next = nullptr;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class myHelp{
public:
    template <typename templateMassive>
    void coutV(templateMassive& nums) {//вывод контейнеров через пробел
        for (auto& a : nums) {
            cout << a << " ";
        }
        cout << endl;
    }

    void coutV(vector<vector<int>>& nums) {//вывод контейнеров через пробел
        for (auto& a : nums) {
            for (int num : a) {
                cout << num << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    void coutV(ListNode* nums) {//вывод ListNode через пробел
        while (nums) {
            cout << nums->val << " ";
            nums = nums->next;
        }
        cout << endl;
    }

    template <typename createListMassive>
    ListNode* createList(createListMassive& nums) {
        if (!nums.size()) {
            cout << "Попытка создать список из пустого контейнера" << endl;
            return nullptr;
        }
        ListNode* ans = new ListNode(nums[0], nullptr);
        if (nums.size() == 1) {
            return ans;
        }
        ListNode* prevAns = new ListNode(0, ans);
        for (size_t i = 1; i < nums.size(); i++) {
            ans = ans->next = new ListNode(nums[i], nullptr);

        }
        ans = prevAns->next;
        delete(prevAns);
        return ans;
    }

private:
}help;

class classSort {
public:
    /*ВСЕ, если элемент больше чем следующий то меняем, и так весь массив N раз*/
    void boubleSotr(vector <int>& nums) {
        for (size_t i = 1; i < nums.size(); i++) {
            for (size_t j = 0; j < nums.size()-1; j++) {
                if (nums[j] > nums[j + 1]) {
                    swap(nums[j], nums[j + 1]);
                }
            }
        }
    }
    /*ВСЕ, проходим массив от i до конца и находим самый минимальный и swap с элементом[i]*/
    void selectionSort(vector<int>& nums){
        for (size_t i = 0; i < nums.size(); i++) {
            size_t k = i;
            for (size_t j = i; j < nums.size(); j++) {//проходим по массиву начиная с i
                if (nums[k] > nums[j]) {//находим самый минимальный элементс от i до конца
                    k = j;//говорим что j указывает на самый минимальный
                }
            }
            swap(nums[i], nums[k]);//меняем местами самый минимальный k и i
        }
    }
    /*ВСЕ, элемент тянем в начало пока он меньше предыдущего и не вышли за границы*/
    void insertionSort(vector<int>& nums){
        for (int i = 1; i < nums.size(); i++) {
            int key = nums[i],j=i;
            while ((--j) >= 0 && nums[j] > key) { 
                swap(nums[j], nums[j + 1]);
            }
        }
    }
    /*ВСЕ, */
    void mergeSort(vector<int>& nums)
    {
        if (nums.size() > 1) {
            int middle = nums.size() / 2;
            int rem = nums.size() - middle;
            vector<int> L(middle);
            vector<int> R(rem);
            for (int i = 0; i < nums.size(); i++) {
                if (i < middle) {
                    L[i] = nums[i];
                }
                else {
                    R[i - middle] = nums[i];
                }
            }
            mergeSort(L);
            mergeSort(R);
            merge(nums, L, middle, R, rem);
        }
    }
    /*Отрицательные нельзя, считает количесвто каждого элемента, сортировка без сравнения*/
    void countingSort(vector <int>& nums) {
        int K = *max_element(nums.begin(), nums.end());//находим максимальный элемент
        vector <int> counts(K + 1);
        for (int &elem : nums) {//подсчитываем количество каждого элемента
            counts[elem]++;
        }

        int startingIndex = 0;//определяем стартовую позицию для каждого
        for (int i = 0; i < K + 1; i++) {
            int count = counts[i];
            counts[i] = startingIndex;
            startingIndex += count;
        }

        vector<int> sortedArray(nums.size());//на основе вектора позиций вставляем элементы в отсортированный вектор
        for (int &elem : nums) {
            sortedArray[counts[elem]] = elem;
            counts[elem] += 1;
        }
        nums = sortedArray;
    }
    /*ВСЕ, */
    void countSortMap(vector<int>& nums) {
        map<int, int> mapInt;
        for (int num : nums) {
            mapInt[num]++;
        }
        int i = 0;
        for (auto& numInMap : mapInt) {
            while (numInMap.second--) {
                nums[i++] = numInMap.first;
            }
        }
    }
    /*ВСЕ, */
    void quickSort(vector<int>& nums) {
        quickSort(nums, nums.size());
    }

    void quickSort(vector<int>& nums,int size)//работает со всем
    {
        int const lenD = size;
        int pivot = 0;
        int ind = lenD / 2;
        int i, j = 0, k = 0;
        if (lenD > 1) {
            vector<int> L(lenD),R(lenD);
            pivot = nums[ind];
            for (i = 0; i < lenD; i++) {
                if (i != ind) {
                    if (nums[i] < pivot) {
                        L[j] = nums[i];
                        j++;
                    }
                    else {
                        R[k] = nums[i];
                        k++;
                    }
                }
            }
            quickSort(L,j);
            quickSort(R,k);
            for (int cnt = 0; cnt < lenD; cnt++) {
                if (cnt < j) {
                    nums[cnt] = L[cnt];;
                }
                else if (cnt == j) {
                    nums[cnt] = pivot;
                }
                else {
                    nums[cnt] = R[cnt - (j + 1)];
                }
            }
        }
    }
    /*Отрицательные нельзя, */
    void radixSort(vector<int> &nums) {
        int maxElem = *max_element(nums.begin(), nums.end());
        int placeVal = 1;
        while (maxElem / placeVal > 0) {
            radixWithCounting(nums, placeVal);
            placeVal *= 10;
        }
    }
    /*ВСЕ, находит минимальный и тянет в начало*/
    void GnomeSort(vector<int>& nums) {
        int i = 1, j = 2;
        while (i < nums.size()){
            if (nums[i - 1] < nums[i]) {
                i = j;
                j++;
            }
            else{
                swap(nums[i], nums[i - 1]);
                i--;
                if (i == 0) {
                    i = j;
                    j++;
                }
            }
        }
    }
    /*ВСЕ, */
    void heapSort(vector<int>& nums) {
        // Mutates elements in lst by utilizing the heap data structure
        for (int i = nums.size() / 2 - 1; i >= 0; i--) {
            maxHeapify(nums, nums.size(), i);
        }

        for (int i = nums.size() - 1; i > 0; i--) {
            swap(nums[i], nums[0]);
            maxHeapify(nums, i, 0);
        }
    }
    /*ВСЕ, */
    void shellSort(vector<int>& nums) {
        // Start with a big gap, then reduce the gap
        for (int gap = nums.size() / 2; gap > 0; gap /= 2) {
            // Do a gapped insertion sort for this gap size.
            // The first gap elements a[0..gap-1] are already in gapped order
            // keep adding one more element until the entire array is
            // gap sorted 
            for (int i = gap; i < nums.size(); i += 1) {
                // add a[i] to the elements that have been gap sorted
                // save a[i] in temp and make a hole at position i
                int temp = nums[i];

                // shift earlier gap-sorted elements up until the correct 
                // location for a[i] is found
                int j = i;
                for (; j >= gap && nums[j - gap] > temp; j -= gap) {
                    nums[j] = nums[j - gap];
                }
                //  put temp (the original a[i]) in its correct location
                nums[j] = temp;
            }
        }
    }

private:
        void merge(vector<int>& nums, vector<int>& L, int lenL, vector<int>& R, int lenR) {
            int i = 0;
            int j = 0;
            while (i < lenL || j < lenR) {
                if ((i < lenL) && (j < lenR)) {
                    if (L[i] <= R[j]) {
                        nums[i + j] = L[i];
                        i++;
                    }
                    else {
                        nums[i + j] = R[j];
                        j++;
                    }
                }
                else if (i < lenL) {
                    nums[i + j] = L[i];
                    i++;
                }
                else if (j < lenR) {
                    nums[i + j] = R[j];
                    j++;
                }
            }
        }

        void radixWithCounting(vector<int>& nums, int placeVal) {
            int numsSize = nums.size();
            vector<int> counts(nums.size());

            for (int elem : nums) {
                counts[(elem / placeVal) % 10]++;
            }

            int startingIndex = 0;
            for (int i = 0; i < numsSize; i++) {
                int count = counts[i];
                counts[i] = startingIndex;
                startingIndex += count;
            }

            vector<int> sortedArray(numsSize);
            for (int elem : nums) {
                int current = elem / placeVal;
                sortedArray[counts[current % 10]] = elem;
                counts[current % 10] += 1;
            }
            nums = sortedArray;
        }

        void maxHeapify(vector<int>& nums, int heapSize, int index) {
            int left = 2 * index + 1;
            int right = 2 * index + 2;
            int largest = index;
            if (left < heapSize && nums[left] > nums[largest]) {
                largest = left;
            }
            if (right < heapSize && nums[right] > nums[largest]) {
                largest = right;
            }
            if (largest != index) {
                swap(nums[index], nums[largest]);
                maxHeapify(nums, heapSize, largest);
            }
        }
}obj1;




int main() {
    setlocale(0, "rus");
    vector <int> nums{ 10,9,11,-12,-33,8,12,13,6,16,-4,-4,3,-3,3,-3,-4,14,5,-1,0,15,4,16,3,17,-2,2,18,1,19,0,20 };
    help.coutV(nums);
    obj1.radixSort(nums);
    help.coutV(nums);

}