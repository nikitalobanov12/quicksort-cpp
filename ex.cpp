// g++ -pedantic -Wall -Wextra -std=c++17 ex.cpp
#include <iostream>
#include <cmath>
#include <vector>

// quicksort with a pivot in the middle position
int quicksortMiddle(std::vector<int> &v, int left, int right)
{
    int i = left, j = right;
    int tmp;
    int pivot = v[(left + right) / 2];
    int comparisons = 0;

    /* partition */
    while (i <= j)
    {
        while (v[i] < pivot)
        {
            i++;
            comparisons++;
        }
        while (v[j] > pivot)
        {
            j--;
            comparisons++;
        }
        if (i <= j)
        {
            tmp = v[i];
            v[i] = v[j];
            v[j] = tmp;
            i++;
            j--;
        }
    };

    /* recursion */
    if (left < j)
        quicksortMiddle(v, left, j);
    if (i < right)
    {
        quicksortMiddle(v, i, right);
    }
    return comparisons;
}

// quicksort with a pivot in the first position
int quicksortFirst(std::vector<int> &v, int left, int right)
{
    int i = left, j = right;
    int tmp;
    int pivot = v[left];
    int comparisons = 0;

    /* partition */
    while (i <= j)
    {
        while (v[i] < pivot)
        {
            i++;
            comparisons++;
        }
        while (v[j] > pivot)
        {
            j--;
            comparisons++;
        }
        if (i <= j)
        {
            tmp = v[i];
            v[i] = v[j];
            v[j] = tmp;
            i++;
            j--;
        }
    };

    /* recursion */
    if (left < j)
        comparisons += quicksortFirst(v, left, j);
    if (i < right)
        comparisons += quicksortFirst(v, i, right);
    return comparisons;
}

// function that makes 2 random vectors and sorts them with each method 1000 times and prints the average number of comparisons
void test(int n)
{
    int comparisonsMiddle = 0;
    int comparisonsFirst = 0;
    // does the process 1000 times
    for (int i = 0; i < 1000; i++)
    {
        std::vector<int> v2(n);
        std::vector<int> v3(n);
        // creates the random vectors
        for (int i = 0; i < n; i++)
        {
            v2[i] = rand() % n;
            v3[i] = v2[i];
        }
        // sorts the vectors
        comparisonsMiddle += quicksortMiddle(v2, 0, n - 1);
        comparisonsFirst += quicksortFirst(v3, 0, n - 1);
    }
    std::cout << "average comparisons for the beggining-partition version: " << comparisonsFirst / 1000 << std::endl;
    std::cout << "average comparisons for the middle-partition version: " << comparisonsMiddle / 1000 << std::endl;
}

int main()
{
    // step 2. ask the user for the size of the vector
    int n;
    std::cout << "Enter a size: ";
    std::cin >> n;

    // test 1: create a vector with size n in ascending order
    std::vector<int> v1(n);
    for (int i = 0; i < n; i++)
    {
        v1[i] = i;
    }
    // uncomment to print the vector and make sure that the function above is working
    //  for(int i = 0; i < n; i++){
    //      std::cout << v1[i] << " ";
    //  }
    //  sort the vector with both versions of the quicksort
    int comparisonsMiddle = quicksortMiddle(v1, 0, n - 1);
    int comparisonsFirst = quicksortFirst(v1, 0, n - 1);
    std::cout << "test 1: ascending order vector" << std::endl;
    std::cout << "Comparisons for the beggining-partition version: " << comparisonsFirst << std::endl;
    std::cout << "Comparisons for the middle-partition version: " << comparisonsMiddle << std::endl;
    std::cout << std::endl;

    std::cout << "test 2: random vector" << std::endl;
    test(n);
    return 0;
}

/* TEST RESULTS

Enter a size: 3
test 1: ascending order vector
Comparisons for the beggining-partition version: 3
Comparisons for the middle-partition version: 2

test 2: random vector
average comparisons for the beggining-partition version: 1
average comparisons for the middle-partition version: 0


Enter a size: 30
test 1: ascending order vector
Comparisons for the beggining-partition version: 435
Comparisons for the middle-partition version: 29

test 2: random vector
average comparisons for the beggining-partition version: 89
average comparisons for the middle-partition version: 18

Enter a size: 1000
test 1: ascending order vector
Comparisons for the beggining-partition version: 499500
Comparisons for the middle-partition version: 999

test 2: random vector
average comparisons for the beggining-partition version: 8428
average comparisons for the middle-partition version: 671


*/