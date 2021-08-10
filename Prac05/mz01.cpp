template<typename T1>
auto process(const T1 &vec) {
    typename T1::value_type sum{};
    
    int count(0);
    auto it = vec.rbegin();

    for (; it != vec.rend() && count < 5; ++count, ++it) {
        if(count % 2 == 0) {
            sum += *it;
        }
    }
    return sum;
}
