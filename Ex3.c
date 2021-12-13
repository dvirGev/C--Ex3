#include <stdio.h>
#include <string.h>
#define TXT 1024
#define WORD 30

char word[WORD];
char txt[TXT];
int wordGematria;

void findWord()
{
    char c = 0;
    scanf("%c", &c);
    for (int i = 0; c != ' ' && c != ',' && c != '\t' && c != '\n' && i < WORD; i++)
    {
        word[i] = c;
        scanf("%c", &c);
    }
}
void findTxt()
{
    char c = 0;
    scanf("%c", &c);
    for (int i = 0; c != '~' && i < TXT; i++)
    {
        txt[i] = c;
        scanf("%c", &c);
    }
}
void gematria()
{
    int i = 0;
    while (word[i] != '\0')
    {
        wordGematria += word[i] - 'a' + 1;
        ++i;
    }
}
void gematriaSequences()
{
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
                if(isPrint) {
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
    gematria();
    gematriaSequences();

    return 0;
}
