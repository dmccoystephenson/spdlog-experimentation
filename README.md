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

## Troubleshooting
### Memory Leak (Unsolved)
A goal here was to recreate a memory leak error that appears to be occurring in 0.13.0 when a rotating file sink is used. This was successfully recreated with the debian package for spdlog which was v0.16.3. Troubleshooting is in progress -- updating spdlog to the most recently released version may solve this.

### pthread undefined
Use the -pthread flag with gcc.
https://stackoverflow.com/questions/1662909/undefined-reference-to-pthread-create-in-linux
