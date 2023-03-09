#include <iostream>
#include <vector>

using namespace std;

template <typename T>
vector<T> less_than_10(const vector<T> &vec)
{
    vector<T> nvec;
    for (int i=0; i<vec.size(); i++) {
        if (vec[i] < 10) {
            nvec.push_back(vec[i]);
        }
    }
    return nvec;
}

int main()
{
    int elem_vals[10] = {11, 2, 3, 4, 15, 6, 7, 8, 9, 10};
    vector<int> pell_seq(elem_vals, elem_vals+10);
    vector<int> nvec;

    nvec = less_than_10(pell_seq);

    for (auto i : nvec) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return 0;
}