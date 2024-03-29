#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
} pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
bool find_loop(int winner, int loser);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);

        printf("\n");
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    // TODO
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(candidates[i], name) == 0)
        {
            // if repeated, return false
            for (int j = 0; j < rank; j++)
            {
                if (ranks[j] == i)
                {
                    return false;
                }
            }
            // record and return true
            ranks[rank] = i;
            return true;
        }
    }
    // if no name matched, return false
    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    // TODO
    for (int i = 0; i < candidate_count - 1; i++) // the last one don't need to record
    {
        for (int j = i + 1; j < candidate_count; j++)
        {
            preferences[ranks[i]][ranks[j]]++;
        }
    }
    /*//////////////////////////
    //debug
    printf("update preferences matrix to:\n");
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            printf("%i ", preferences[i][j]);
        }
        printf("\n");
    }
    //////////////////////////*/
    return;
}

///////// preference matrix is correct

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    // TODO
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = i + 1; j < candidate_count; j++)
        {
            int diff = preferences[i][j] - preferences[j][i];
            if (diff > 0)
            {
                pairs[pair_count].winner = i;
                pairs[pair_count].loser = j;
                pair_count++;
            }
            if (diff < 0)
            {
                pairs[pair_count].winner = j;
                pairs[pair_count].loser = i;
                pair_count++;
            }
        }
    }
    /*//////////////////////////
    //debug
    printf("%i pairs (not sorted):\n", pair_count);
    for (int k = 0; k < pair_count; k++)
    {
        printf("%i -> %i (votes: %i)\n", pairs[k].winner, pairs[k].loser, pairs[k].margin);
    }
    //////////////////////////*/
    return;
}

// add pairs correctly

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    // TODO
    // Linear sort (decreasing)
    /*
    for (int i = 0; i < pair_count; i++)
    {
        int max = i;
        for (int j = i + 1; j < pair_count; j++)
        {
            if (preferences[pairs[j].winner][pairs[j].loser] > preferences[pairs[max].winner][pairs[max].loser])
            {
                max = j;
            }
        }

        pair tmp = pairs[i];
        pairs[i] = pairs[max];
        pairs[max] = tmp;
    }
    */

    // Bubble sort (decreasing)
    for (int i = pair_count - 1; i > 0; i--) // [biggest] to [1]
    {
        bool swapped = false;
        for (int j = i; j > 0; j--) // [i] to [1]
        {
            pair temp;
            if (preferences[pairs[j].winner][pairs[j].loser] > preferences[pairs[j - 1].winner][pairs[j - 1].loser])
            {
                temp = pairs[j];
                pairs[j] = pairs[j - 1];
                pairs[j - 1] = temp;
                swapped = true;
            }
        }
        if (!swapped)
        {
            break;
        }
    }

    /*//////////////////////////
    //debug
    printf("%i pairs (sorted):\n", pair_count);
    for (int k = 0; k < pair_count; k++)
    {
        printf("%i -> %i (votes: %i)\n", pairs[k].winner, pairs[k].loser, pairs[k].margin);
    }
    //////////////////////////*/
    return;
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    // TODO
    for (int i = 0; i < pair_count; i++)
    {
        if (!find_loop(pairs[i].winner, pairs[i].loser))
        {
            locked[pairs[i].winner][pairs[i].loser] = true;
        }
    }
    return;
}

// Check whether the new line will generate a loop
bool find_loop(int winner, int loser)
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (locked[loser][i] == true)
        {
            if (i == winner || find_loop(winner, i))
            {
                return true;
            }
        }
    }
    return false;
}

// Print the winner of the election
void print_winner(void)
{
    /*//////////////////////////
    //debug
    printf("lock matrix:\n");
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            printf("%i ", (int) locked[i][j]);
        }
        printf("\n");
    }
    //////////////////////////*/
    // TODO
    int break_flag;
    for (int j = 0; j < candidate_count; j++)
    {
        break_flag = 0;
        for (int i = 0; i < candidate_count; i++)
        {
            if (locked[i][j] == true)
            {
                break_flag = 1;
                break;
            }
        }
        if (break_flag == 1)
        {
            continue;
        }
        printf("%s\n", candidates[j]);
    }
    return;
}
