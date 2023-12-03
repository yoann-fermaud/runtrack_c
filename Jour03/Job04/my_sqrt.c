int my_sqrt(int nbr) {
    int result = 0;

    while (result * result < nbr) {
        result++;
    }
    if (result * result != nbr) {
        return 0;
    }

    return result;
}
