#include <stdio.h>
#include <string.h>

const char *strfind(const char *needle, const char *hay) {
    size_t needle_len = strlen(needle);
    size_t hay_len = strlen(hay);
    const char *current_location = needle;
    int found = 0;
    while (current_location <= needle + needle_len - hay_len) {
        found = 1;
        for (int i = 0; i<hay_len; i++) {
            if (current_location[i] != hay[i]) {
                found = 0;
                break;
            }
        }
        if (found == 1) {
            return current_location;
        }
        current_location++;
    }
    return NULL;
};


int main()
{
    const char *loc = strfind("hello there", "ell");
    if (loc != NULL) {
        printf("%c%c%c\n", loc[0], loc[1], loc[2]);
    }
    else {
        printf("NULL\n");
    }


    return 0;
}