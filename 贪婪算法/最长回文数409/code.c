int longestPalindrome(char * s){
    int odd_index = 0;
    int hashmap[52] = {0};
    int res = 0;
    while(*s != '\0')
    {
        if(*s >= 'a' && *s <= 'z')
        {
            hashmap[*s - 'a']++;
        }
        else
        {
            hashmap[*s - 'A' + 26]++;
        }
        s++;
    }
    for(int i = 0; i < 52; i++)
    {
        res += hashmap[i];
        if(hashmap[i] % 2)
        {
            res--;
            odd_index = 1;
        }
    }
    if(odd_index == 1)
        res++;
    return res;
}