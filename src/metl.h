// metl.h -- Execution time measuring library.

#if defined(NDEBUG) || defined(METLDEBUG)
#ifndef _METL_H_
#define _METL_H_

#include <string>

namespace metl { // Implementation.
    class METL {
    public:
        METL(std::string clock_name);
        ~METL(); // Stops the clock if clock hasn't stopped.
        
        METL& start();  // Starts the clock.
        void stop();    // Manually stop the clock (recommended).
    }
}

#endif /* _METL_H_ */
#endif /* defined(NDEBUG) || defined(METLDEBUG) */