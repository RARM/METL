// metl.h -- Execution time measuring library.

#if defined(NDEBUG) || defined(METLDEBUG)
#ifndef _METL_H_
#define _METL_H_

namespace metl { // Implementation.
    class metl {
        metl() {
            // Code here...
        }
    }
}

#endif /* _METL_H_ */

#else /* defined(NDEBUG) || defined(METLDEBUG) */
#ifndef _METL_H_
#define _METL_H_

// Replace calls to nothing if not in debug mode.
// #define metl::metl()

#endif /* _METL_H_ */
#endif /* defined(NDEBUG) || defined(METLDEBUG) */