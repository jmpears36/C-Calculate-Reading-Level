#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{

//Get a body of text to analyze reading level
string text = get_string("Text: ");

//pass variables to these functions to calculate number of letters, words, and sentences
int letters = count_letters(text);
int words = count_words(text);
int sent = count_sentences(text);

//figure out grade level
// per Coleman-Liau index (0.0588 * L (letters per 100 words) - 0.296 * S (sentences per 100 words) - 15.8)

float L = ((letters * 100.00) / words);
float S = ((sent * 100.00) / words);
float grade = 0.0588 * L - 0.296 * S - 15.8;
int finalgrade = round(grade);

if (grade < 1)
{
    printf("Before Grade 1\n");
}
else if (grade > 16)
{
    printf("Grade 16+\n");
}
else
{
    printf("Grade %i\n", finalgrade);
}
}

int count_letters(string text)
{
    int count = 0;
    int len = strlen(text);

    //loop for counting each letter in text
    for (int i = 0; i < len; i++)
    {
        if (isalpha(text[i]))
        {
            count++;
        }
    }
    return count;
}
int count_words(string text)
{
    //count number of words assuming words = spaces + 1, per CS50 problem set parameters
    int count = 0;
    int len = strlen(text);
    for (int i = 0; i <= len; i++)
    {
        if (isspace(text[i]))
        {
            count++;
        }

    }
    // add one to count since spaces will be one less than word count
    count++;
    return count;
}

int count_sentences(string text)
{
    int count = 0;
    int len = strlen(text);

    //count number of sentences assuming each punctuation mark equals one sentence, per CS50 problem set parameters
    for (int i = 0; i < len; i++)
    {
        if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            count++;
        }
    }
    return count;
}
