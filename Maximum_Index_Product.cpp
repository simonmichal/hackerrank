#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>

class solution
{
    std::vector<int> input;
    std::vector<std::vector<int>::iterator> left;
    std::vector<std::vector<int>::reverse_iterator> right;

    size_t get_left(std::vector<int>::iterator it)
    {
        auto l = left[it - input.begin()];
        return l == input.end() ? 0 : (l - input.begin() + 1);
    }

    size_t get_right(std::vector<int>::reverse_iterator it)
    {
        auto r = right[it - input.rbegin()];
        return r == input.rend() ? 0 : (r.base() - input.begin());
    }

    size_t index_prod(std::vector<int>::reverse_iterator it)
    {
        return get_right(it) * get_left(it.base() - 1);
    }

public:
    void get_input()
    {
        // read in the numbers
        int n = 0;
        std::cin >> n;
        for(int i = 0; i < n; ++i)
        {
            int tmp;
            std::cin >> tmp;
            input.push_back(tmp);
        }
        // set up left
        left.push_back(input.end());
        for (auto it = input.begin() + 1; it != input.end(); ++it)
        {
            auto prev = it - 1;
            while (prev != input.end() && *prev <= *it)
                prev = left[prev - input.begin()];
            left.push_back(prev);
        }
        // set up right
        right.push_back(input.rend());
        for (auto it = input.rbegin() + 1; it != input.rend(); ++it)
        {
            auto prev = it - 1;
            while (prev != input.rend() && *prev <= *it)
                prev = right[prev - input.rbegin()];
            right.push_back(prev);
        }
    }

    size_t solve()
    {
        size_t max = 0;
       for (auto it = input.rbegin() + 1; it != input.rend(); ++it)
       {
           auto tmp = index_prod(it);
           if (tmp > max) max = tmp;
       }

       return max;
    }

};

int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    solution s;
    s.get_input();
    std::cout << s.solve() << std::endl;
    return 0;
}
