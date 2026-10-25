// Ingestion engine thread coordinator
#include "telemetry/circular_buffer.hpp"
namespace telemetry { class Engine { CircularBuffer<MetricRecord, 1024> ring_; }; }
