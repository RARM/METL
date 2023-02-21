// metl.h -- Execution time measuring library.

#if defined(NDEBUG) || defined(METLDEBUG)
#ifndef _METL_H_
#define _METL_H_

#include <string>
#include <chrono>

namespace metl {
    class METL {
    public:
        METL(std::string clock_name);
        ~METL(); // Stops the clock if clock hasn't stopped.

        METL& start();  // Starts the clock.
        void stop();    // Manually stop the clock (recommended).

        // Stopping the clock makes it print the info into the terminal.

    private:
        std::chrono::time_point<std::chrono::high_resolution_clock> start;
        std::chrono::time_point<std::chrono::high_resolution_clock> end;
    }
}

#endif /* _METL_H_ */
#endif /* defined(NDEBUG) || defined(METLDEBUG) */