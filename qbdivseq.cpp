#include <iostream>
#include <vector>
using namespace std;
template<class ForwardIt, class T = typename std::iterator_traits<ForwardIt>::value_type,
         class Compare>
ForwardIt lower_bound(ForwardIt first, ForwardIt last, const T& value, Compare comp)
{
    ForwardIt it;
    typename std::iterator_traits<ForwardIt>::difference_type count, step;
    count = std::distance(first, last);
 
    while (count > 0)
    {
        it = first;
        step = count / 2;
        std::advance(it, step);
 
        if (comp(*it, value))
        {
            first = ++it;
            count -= step + 1;
        }
        else
            count = step;
    }
 
    return first;
}


int main() {
    int n;
    cin >> n;
    vector<int> v;

    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        auto p = lower_bound(v.begin(), v.end(), x, greater<int>());
        if (p == v.end())
            v.push_back(x);
        else
            *p = x;
    }

    cout << v.size() << endl;
    return 0;
}
