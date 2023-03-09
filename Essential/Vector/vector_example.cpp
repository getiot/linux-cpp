#include <iostream>
#include <vector>

int main()
{
    const int seq_size = 18;
    std::vector<int> pell_seq(seq_size);

    pell_seq[0] = 1;
    pell_seq[1] = 2;

    for (int i=2; i<pell_seq.size(); i++) {
        pell_seq[i] = pell_seq[i-2] + 2*pell_seq[i-1];
    }

    std::cout << "The first " << seq_size << " elements of the Pell Series:" << std::endl;

    for (int i=0; i<pell_seq.size(); i++) {
        std::cout << pell_seq[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}