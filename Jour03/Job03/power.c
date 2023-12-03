int power(int nb, int power) {
    int result = 1;

    while (power > 0) {
        result = result * nb;
        power--;
    }

    return result;
}
