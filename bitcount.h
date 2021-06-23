int bitcount(int x){
    int count = 0;
    while(x != 0){
        if(x & 1)
            count++;
        x >>= 1;
    }
    return count;
}