#pragma once

#include <cstdint>
#include <string_view>
#include <chrono>

namespace telemetry {

enum class MetricType : uint8_t {
    COUNTER = 0,
    GAUGE = 1,
    HISTOGRAM = 2
};

struct alignas(32) MetricRecord {
    uint64_t timestamp_ns{0};
    uint32_t metric_id{0};
    MetricType type{MetricType::COUNTER};
    double value{0.0};
    char name[64]{0};
    char tags[128]{0};
};

} // namespace telemetry
