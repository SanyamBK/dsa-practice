
void bubble_sort(int *input, int size)
{
    for (int i = 1; i < size; i++) {
        for (int j = 0; j < size - i; j++) {
            if (input[j] > input[j+1]) {
                int temp = input[j];
                input[j] = input[j+1];
                input[j+1] = temp; 
            }
        }
    }
}
