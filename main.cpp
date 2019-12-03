#include <iostream>
#include <fstream>
#include <sstream>
#include <iterator>
#include <vector>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <cstring>

using namespace std;

void removeAll(char * str, char * toRemove);
void replaceWithSpace(char * str)
{
    int strLen = strlen(str);
    for(int i = 0; i < strLen; i++)
    {
        if(str[i] == '<')
        {
            str[i] = ' ';
        }
    }
}



int main() {

    std::ifstream t;
    char str1[10][20];
    int length, i, j = 0, k = 0;
    t.open("element.txt");
    t.seekg(0, std::ios::end);
    length = t.tellg();
    t.seekg(0, std::ios::beg);
    char str[length];
    t.read(str, length);
    t.close();

    char word[] = {R"(<div class="typable mono_standard play_mode" style="opacity: 1; margin-top: 0px; font-family: &quot;Droid Sans Mono&quot;;">)"};
    removeAll(str, word);
    strcpy(word, R"(<div><span class="cursor normal_cursor" style="width: 21px; height: 46px; margin-top: -2px; margin-left: 0px;"></span></div>)");
    removeAll(str, word);
    strcpy(word, "<span class=\"line\">");
    removeAll(str, word);
    strcpy(word, "<span class=\"token _fcs\">");
    removeAll(str, word);
    strcpy(word, "<span class=\"_toknmeta\">");
    removeAll(str, word);
    strcpy(word, "</span><span class=\"token_unit  _clr\">");
    removeAll(str, word);
    strcpy(word, "&nbsp;<i> </i></span></span>");
    removeAll(str, word);
    strcpy(word, "span class=\"token\">");
    removeAll(str, word);
    strcpy(word, "</span>");
    removeAll(str, word);
    strcpy(word, "</div>");
    removeAll(str, word);
    strcpy(word, "@");
    removeAll(str, word);
    strcpy(word, R"( div class="typable mono_standard play_mode" style="opacity: 1; font-family: &quot;Droid Sans Mono&quot;; margin-top: 0px;">)");
    removeAll(str, word);
    strcpy(word, "amp;");
    removeAll(str, word);
    replaceWithSpace(str);

    cout << str;

    ofstream p;
    p.open("element.txt");
    p << str;
    p.close();

    t.open("element.txt");
    t.seekg(0, std::ios::end);
    length = t.tellg();
    t.seekg(0, std::ios::beg);
    t.read(str, length);
    t.close();


    return 0;
}

void removeAll(char * str, char * toRemove)
{
    int i, j, stringLen, toRemoveLen;
    int found;

    stringLen   = strlen(str);      // Length of string
    toRemoveLen = strlen(toRemove); // Length of word to remove


    for(i=0; i <= stringLen - toRemoveLen; i++)
    {
        /* Match word with string */
        found = 1;
        for(j=0; j<toRemoveLen; j++)
        {
            if(str[i + j] != toRemove[j])
            {
                found = 0;
                break;
            }
        }

        /* If it is not a word */

        /*
         * If word is found then shift all characters to left
         * and decrement the string length
         */
        if(found == 1)
        {
            for(j=i; j<=stringLen - toRemoveLen; j++)
            {
                str[j] = str[j + toRemoveLen];
            }

            stringLen = stringLen - toRemoveLen;

            // We will match next occurrence of word from current index.
            i--;
        }
    }
}

