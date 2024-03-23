#include <stdlib.h>

#define MaxBit 50

typedef struct Deception deception_t;
typedef void (*fpterFunction)(deception_t *);
typedef int (*fpterDisplay)(deception_t *);
typedef void (*fptrDelete)(deception_t *);

typedef struct Deception
{
    char *Dbinary;          /**< Deception bit(random configuration) */
    long long *Dvalue;      /**< Deception value */
    fptrDelete Delete;      /**< Destructor */
    fpterFunction Function; /**< Calculation function */
    fpterDisplay Display;   /**< Show input and answer */

} deception_t;

/** Constructor
 * @brief intial Deception Problem variable and function
 * @param str:the bit you want to add in the Deception Problem
 * @return Deception_t pointer
 */
deception_t *D_new(const char *const str);

/** Destructor
 * @param D The target Deception Problem
 * @return Void
 */
void D_delete(deception_t *const D);

/** Function
 * @brief calculation the Deception Problem
 * @param D The target Deception Problem
 * @return Void
 */
void D_function(deception_t *const D);

/** Display
 * @brief show the Deception Problem Dbinary and Dvalue
 * @param D The target Deception Problem
 * @return Int If an error occurs,return 1,else 0
 */
int D_display(deception_t *const D);

/** Covery
 * @brief Convert binary to decimal
 * @param bit The binary string to covert
 * @param length The length of bit
 * @return Long long The decimal value of the binary string
 */
long long D_coveryDinaryToDecimal(const char *const bit, const int *const length);

/** Get Random
 * @brief Randomly generate integer from the minimum value to the maximum value
 * @param min The minimum number
 * @param max The maimum number
 * @return Int The Randomly generate integer
 */
static inline int getRandom(int min, int max)
{
    return (rand() % (max - min + 1) + min);
}