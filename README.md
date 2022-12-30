# spdlog-experimentation
This project is for experimenting with the spdlog library (https://github.com/gabime/spdlog).

## Utilization Methods
The spdlog library can be utilized in a few ways:
- header only
- compiled
- packaged

### Package Utilization
1. Install spdlog.
2. Include "spdlog/spdlog.h"
3. Use spdlog.

## Memory Leak Recreation
A goal here is to recreate a memory leak error that appears to be occurring in 0.13.0 when a rotating file sink is used. Once recreated, we will update to a newer version of the library in an attempt to resolve the issue.

## Troubleshooting
### pthread undefined
Use the -pthread flag with gcc.
https://stackoverflow.com/questions/1662909/undefined-reference-to-pthread-create-in-linux