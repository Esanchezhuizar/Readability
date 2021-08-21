#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

long count_letters(string text);
long count_words(string text);
long count_sentences(string text);
long colemanLiau_index(string text);

int main(void)
{
    string text = get_string("Text: ");

    float L = (float) (count_letters(text) / (float) count_words(text) * 100); 
    float S = (float) (count_sentences(text) / (float) count_words(text) * 100); 
    float index = (0.0588 * L) - (0.296 * S) - 15.8;
    int grade = round(index);
    
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
        printf("Grade %i\n", grade);
    }
  
}

long count_letters(string text)
{
    int len = strlen(text);
    int count = 0;
    for (int i = 0; i <= len; i++)
    {
        char c = text[i];
        if (isblank(c))
        {
            count++;
        }
        else if (isdigit(c))
        {
            count++;
        }
        else if (ispunct(c))
        {
            count++;
        }
    }
    long letter = len - count;
    return letter;
}

long count_words(string text)
{
    long words = 0;
    for (int n = 0; n < strlen(text); n++)
    {
        char c2 = text[n];
        if (isspace(c2))
        {
            words++;
        }
    }
    return words + 1;
}

long count_sentences(string text)
{
    long sentences = 0;
    for (int k = 0; k < strlen(text); k++)
    {
        char c3 = text[k];
        if (c3 == 33 || c3 == 46 || c3 == 63) //ASCII
        {
            sentences++;
        }
    }
    return sentences;
}

