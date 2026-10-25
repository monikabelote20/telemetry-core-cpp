// Ingestion engine thread coordinator with graceful stop
#include "telemetry/circular_buffer.hpp"
#include <atomic>
namespace telemetry { class Engine { std::atomic<bool> running_{true}; }; }
