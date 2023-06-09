#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
} candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
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
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(candidates[i].name, name) == 0)
        {
            candidates[i].votes++;
            return true;
        }
    }
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    int max_votes = 0;
    for (int i = 0, index = 0; i < candidate_count; i++)
    {
        candidate elem1 = candidates[i];
        if (elem1.votes > max_votes)
        {
            // 複数人が最高得点を持っている可能性を踏まえて保持しておく
            max_votes = elem1.votes;
        }
        for (int j = i + 1; j < candidate_count; j++)
        {
            candidate elem2 = candidates[j];
            if (elem1.votes > elem2.votes)
            {
                // 中身を入れ換える
                candidates[i] = elem2;
                candidates[j] = elem1;
                // 最初から比較し直す
                j = i + 1;
            }
        }
    }
    // 出力処理
    for (int i = 0; i < candidate_count; i++)
    {
        candidate elem = candidates[i];
        if (elem.votes == max_votes)
        {
            printf("%s\n", elem.name);
        }
    }
}
