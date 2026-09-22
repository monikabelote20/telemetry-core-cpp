#include "telemetry/circular_buffer.hpp"
#include <cassert>
#include <iostream>

void test_basic_push_pop() {
    telemetry::CircularBuffer<int, 4> buf;
    assert(buf.empty());
    assert(buf.push(100));
    assert(buf.push(200));
    assert(buf.size() == 2);
    
    auto val1 = buf.pop();
    assert(val1.has_value() && val1.value() == 100);
    
    auto val2 = buf.pop();
    assert(val2.has_value() && val2.value() == 200);
    assert(buf.empty());
    std::cout << "[PASS] test_basic_push_pop passed" << std::endl;
}

void test_overflow_protection() {
    telemetry::CircularBuffer<int, 4> buf;
    for (int i = 0; i < 4; ++i) {
        assert(buf.push(i));
    }
    assert(!buf.push(999)); // Buffer full, must reject
    assert(buf.size() == 4);
    std::cout << "[PASS] test_overflow_protection passed" << std::endl;
}

int main() {
    test_basic_push_pop();
    test_overflow_protection();
    return 0;
}
