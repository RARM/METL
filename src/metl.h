// metl.h -- Execution time measuring library.

#if defined(NDEBUG) || defined(METLDEBUG)
#ifndef _METL_H_
#define _METL_H_

#include <string>
#include <chrono>

namespace metl {
    class METL {
    public:
        /**
         * Initializes the basic info for the clock, but it doesn't start it.
         *
         * @param clock_name String used for printing the clock info.
         */
        METL(std::string clock_name);

        /**
         * The destructor just check if the clock was stopped. If it wasn't, it
         * will issue a warning and will call the {@link METL::stop() stop}
         * method.
         *
         * In the special case when the clock wasn't started, it will also issue
         * a warning.
         */
        ~METL();

        /**
         * Starts running the clock.
         *
         * @return A reference to the current object.
         */
        METL& start();

        /**
         * Stops the clock and prints the clock duration in the terminal. If the
         * clock wasn't started, it will issue a warning.
         */
        void stop();

    private:
        /**
         * Internal method to print the results. The clock must be stopped
         * before being called.
         */
        void log_terminal();
        
        std::string name;
        bool stopped;
        bool started;
        std::chrono::time_point<std::chrono::high_resolution_clock> start;
        std::chrono::time_point<std::chrono::high_resolution_clock> end;
    }
}

#endif /* _METL_H_ */
#endif /* defined(NDEBUG) || defined(METLDEBUG) */