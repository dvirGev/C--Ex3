#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TXT 1024
#define WORD 30

char word[WORD];
char txt[TXT];

void findWord()
{
    char c = 0;
    scanf("%c", &c);
    int i = 0;
    for (; c != ' ' && c != '\t' && c != '\n' && i < WORD; i++)
    {
        word[i] = c;
        scanf("%c", &c);
    }
    word[i] = '\0';
}
void findTxt()
{
    char c = 0;
    scanf("%c", &c);
    int i = 0;
    for (; c != '~' && i < TXT; i++)
    {
        txt[i] = c;
        scanf("%c", &c);
    }
    txt[i] = '\0';
}
int gematria()
{
    int wordGematria = 0;
    int i = 0;
    while (word[i] != '\0')
    {
        if (word[i] >= 'a' && word[i] <= 'z')
        {
            wordGematria += word[i] - 'a' + 1;
        }
        else if (word[i] >= 'A' && word[i] <= 'Z')
        {
            wordGematria += word[i] - 'A' + 1;
        }
        ++i;
    }
    return wordGematria;
}
char *atbash()
{
    int i = 0;
    char *newWord = malloc(sizeof(char) * WORD);
    while (word[i] != '\0' || i <= WORD)
    {
        if (word[i] >= 'a' && word[i] <= 'm')
        {
            newWord[i] = 'z' - word[i] + 'a';
        }
        else if (word[i] >= 'A' && word[i] <= 'M')
        {
            newWord[i] = 'Z' - word[i] + 'A';
        }
        else if (word[i] >= 'n' && word[i] <= 'z')
        {
            newWord[i] = 'a' - word[i] + 'z';
        }
        else if (word[i] >= 'N' && word[i] <= 'Z')
        {
            newWord[i] = 'A' - word[i] + 'Z';
        }
        else
        {
            newWord[i] = word[i];
        }
        ++i;
    }
    newWord[i] = '\0';
    return newWord;
}
char *revers(char *currWord)
{
    char *newWord = malloc(sizeof(char) * WORD);
    int end = 0;
    while (currWord[end] != '\0')
    {
        ++end;
    }
    for (int i = 0; i < end; i++)
    {
        newWord[i] = currWord[end - i - 1];
    }
    newWord[end] = '\0';
    return newWord;
}
// A
void gematriaSequences()
{
    int wordGematria = gematria();
    printf("Gematria Sequences: ");
    int isPrint = 0;
    int i = 0;
    while (txt[i] != '\0')
    {
        int sum = 0;
        int j = i;
        if ((txt[i] >= 'a' && txt[i] <= 'z') || (txt[i] >= 'A' && txt[i] <= 'Z'))
        {
            while (txt[j] != '\0' && sum < wordGematria)
            {
                if (txt[j] >= 'a' && txt[j] <= 'z')
                {
                    sum += txt[j] - 'a' + 1;
                }
                else if (txt[j] >= 'A' && txt[j] <= 'Z')
                {
                    sum += txt[j] - 'A' + 1;
                }
                ++j;
            }
            --j;
            if (sum == wordGematria)
            {
                if (isPrint)
                {
                    printf("~");
                }
                for (int k = i; k <= j; k++)
                {
                    printf("%c", txt[k]);
                }
                ++isPrint;
            }
        }
        ++i;
    }
}
// B
void atbashSequences()
{
    char *atbashWord = atbash();
    char *reversAtbash = revers(atbashWord);
    printf("Atbash Sequences: ");
    int isPrint = 0;
    int i = 0;
    while (txt[i] != '\0')
    {
        if (txt[i] == atbashWord[0])
        {
            int flag = 0;
            int j = i;
            int k = 0;
            while (txt[j] != '\0' && atbashWord[k] != '\0' && k >= 0)
            {
                if ((txt[j] >= 'a' && txt[j] <= 'z') || (txt[j] >= 'A' && txt[j] <= 'Z'))
                {
                    if (txt[j] == atbashWord[k])
                    {
                        ++k;
                        if (atbashWord[k] == '\0')
                        {
                            flag = 1;
                            k = -1;
                        }
                    }
                    else
                    {
                        k = -1;
                    }
                }
                ++j;
            }
            --j;
            if (flag)
            {
                if (isPrint)
                {
                    printf("~");
                }
                for (int k = i; k <= j; k++)
                {
                    printf("%c", txt[k]);
                }
                ++isPrint;
            }
        }
        else if (txt[i] == reversAtbash[0])
        {
            int flag = 0;
            int j = i;
            int k = 0;
            while (txt[j] != '\0' && reversAtbash[k] != '\0' && k >= 0)
            {
                if ((txt[j] >= 'a' && txt[j] <= 'z') || (txt[j] >= 'A' && txt[j] <= 'Z'))
                {
                    if (txt[j] == reversAtbash[k])
                    {
                        ++k;
                        if (reversAtbash[k] == '\0')
                        {
                            flag = 1;
                            k = -1;
                        }
                    }
                    else
                    {
                        k = -1;
                    }
                }
                ++j;
            }
            --j;
            if (flag)
            {
                if (isPrint)
                {
                    printf("~");
                }
                for (int k = i; k <= j; k++)
                {
                    printf("%c", txt[k]);
                }
                ++isPrint;
            }
        }
        ++i;
    }
    free(atbashWord);
    free(reversAtbash);
}
// C
void anagramSequences()
{
    printf("Anagram Sequences: ");
    int isPrint = 0;
    int i = 0;
    while (txt[i] != '\0')
    {
        if (txt[i] != ' ' && txt[i] != '\t' && txt[i] != '\n')
        {
            char copy[WORD];
            strcpy(copy, word);
            int flag = 0;
            int j = i;
            while (txt[j] != '\0' && flag == 0)
            {
                if (txt[j] != ' ' && txt[j] != '\t' && txt[j] != '\n')
                {
                    flag = -1;
                    for (int k = 0; copy[k] != '\0' && flag <= -1; k++)
                    {
                        if (txt[j] == copy[k])
                        {
                            copy[k] *= -1;
                            flag = 0;
                        }
                    }
                    if (flag == 0)
                    {
                        flag = 1;
                        for (int k = 0; copy[k] != '\0' && flag == 1; k++)
                        {
                            if (copy[k] > 0)
                            {
                                flag = 0;
                            }
                        }
                    }
                }
                ++j;
            }
            --j;
            if (flag == 1)
            {
                if (isPrint)
                {
                    printf("~");
                }
                for (int k = i; k <= j; k++)
                {
                    printf("%c", txt[k]);
                }
                ++isPrint;
            }
        }
        ++i;
    }
}
int main()
{
    findWord();
    findTxt();
    gematriaSequences();
    printf("\n");
    atbashSequences();
    printf("\n");
    anagramSequences();
}
