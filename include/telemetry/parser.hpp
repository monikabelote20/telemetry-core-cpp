#pragma once

#include "telemetry/types.hpp"
#include <string_view>
#include <charconv>

namespace telemetry {

class MetricParser {
public:
    static bool parse_line(std::string_view line, MetricRecord& out_record) noexcept {
        if (line.empty()) return false;

        size_t first_space = line.find(' ');
        if (first_space == std::string_view::npos) return false;

        std::string_view name = line.substr(0, first_space);
        if (name.size() >= sizeof(out_record.name)) return false;

        for (size_t i = 0; i < name.size(); ++i) {
            out_record.name[i] = name[i];
        }
        out_record.name[name.size()] = '\0';

        std::string_view val_str = line.substr(first_space + 1);
        double val = 0.0;
        auto res = std::from_chars(val_str.data(), val_str.data() + val_str.size(), val);
        if (res.ec != std::errc()) return false;

        out_record.value = val;
        out_record.type = MetricType::GAUGE;
        return true;
    }
};

} // namespace telemetry
