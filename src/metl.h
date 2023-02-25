/**
 * @file metl.h
 * @brief Minimalistic Execution Time Library
 */

/**
 * @def metl_start_clock(X)
 * @brief 
 * @param
 */

/**
 * @def metl_stop_clock(X)
 * @brief 
 * @param
 */

/**
 * @def metl_stop_clock()
 * @brief 
 */

#ifndef _METL_H_
#define _METL_H_

#if defined(NDEBUG) || defined(METLDEBUG)

#include <string>
#include <chrono>
#include <list>

/**
 * @namespace metl
 * 
 * METL code available only on non debug environments. It is recommended to use
 * macros instead of this API, but these could also be used provided the proper
 * conditional preprocessing is done to avoid errors during code generation.
 */
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
         * before calling this function.
         */
        void log_terminal();
        
        std::string name;
        bool stopped;
        bool started;
        std::chrono::time_point<std::chrono::high_resolution_clock> start;
        std::chrono::time_point<std::chrono::high_resolution_clock> end;
    }

    class GlobalControl {
    private:
        static std::list<metl::METL> clocks;
    
    public:
        /**
         * Create and save clock with the given name.
         *
         * @param name Clock name.
         */
        static void start_clock(std::string name);

        /**
         * Stop the last clock added or a clock by giving the name of it. Note
         * that giving a name would take longer to stop it. Stop last added
         * clock 
         *
         * @param name Clock name.
         */
        static void stop_clock(std::string name = "");
    }
}

// Macros for using the library classes if in debug mode.

#define metl_start_clock(X) metl::GlobalControl::start_clock(X)
#define metl_stop_clock(X)  metl::GlobalControl::stop_clock(X)
#define metl_stop_clock()   metl::GlobalControl::stop_clock()

#else /* defined(NDEBUG) || defined(METLDEBUG) */

// Macro to replace for no code in no debug environments.
#define metl_start_clock(X)
#define metl_stop_clock(X)
#define metl_stop_clock()

#endif /* defined(NDEBUG) || defined(METLDEBUG) */
#endif /* _METL_H_ */