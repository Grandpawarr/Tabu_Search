#include "deceptionProblem.h"

#define HistoryListSize 20     // tabu list size
#define NumberOfIteration 1000 // 1000
typedef struct TabuSearch tabu_t;

typedef void (*fptrMove)(tabu_t *);
typedef char *(*fptrAlgo)(char *);
typedef void (*fptrAddHistoryList)(tabu_t *, deception_t *);
typedef int (*fptrDisplay)(tabu_t *);

typedef struct TabuSearch
{
    int listsize;                            /**< Tabu list current length */
    int showsize;                            /**< The value of how large an array needs to be displayed */
    deception_t histoylist[HistoryListSize]; /**< Tabu history */
    deception_t Best;                        /**< The Best solution */
    fptrMove Move;                           /**< TabuSearch Move*/
    fptrAlgo Algo;                           /**< TabuSearch Algorithm*/
    fptrAddHistoryList Addlist;              /**< Add Deception Problem to Tabu history*/
    fptrDisplay Display;                     /**< Display the Tabu history and the best solution */

} tabu_t;

/** Initioal
 * @brief Initioal fisrt problem
 *
 * Initial TabuSearch
 * Generate the first Deception Problem
 *
 * @return tabu_t pointer
 */
tabu_t *T_initial();

/** TabuSearch Move
 * @brief TabuSearch evolution
 *
 * Generate next Deception Problem via preview
 * Add it into Tabu list and calculate the best
 *
 * @param head Target TabuSearch
 * @return Void
 */
void TabuSearch_Move(tabu_t *head);

/** TabuSearch Algorithm
 * @brief Generating next solution
 *
 * The algorithm is to randomly exchange two different positions
 * if two positional charactors are same,regenerate position
 *
 * @param Dstr next Deception problem bit
 * @return Char*
 */
char *TabuSearch_Algo(char *Dstr);

/** Add Tabu history
 * @brief Add the Deception problem to the Tabu history list and
 * judgment Best value
 * @param head Target TabuSearch
 * @param D Added Deception Problem
 * @return Vail
 */
void TabuSearch_AddHistoryList(tabu_t *head, deception_t *D);

/** Display
 * @brief Show history list and best value
 * @param head Target TabuSearch
 * @return Int : If an error occurs,return 1,else 0
 */
int TabuSearch_Display(tabu_t *head);

/** Charactor swap
 * @brief Swap two charactor
 * @param a The charactor1 pointer
 * @param b The charactor1 pointer
 * @return Void
 */
static inline void cSwap(char *a, char *b)
{
    char tmp = *a;
    *a = *b;
    *b = tmp;
}
