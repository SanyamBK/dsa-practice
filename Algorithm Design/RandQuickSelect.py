import random

def choose_pivot(arr):
    return random.choice(arr)

def rand_quick_select(arr, k):
    if len(arr) == 1:
        return arr[0]
    
    pivot = choose_pivot(arr)
    lesser = [x for x in arr if x < pivot]
    greater = [x for x in arr if x > pivot]
    
    if len(lesser) == k - 1:
        return pivot
    elif len(lesser) > k - 1:
        return rand_quick_select(lesser, k)
    else:
        return rand_quick_select(greater, k - len(lesser) - 1)

# Example usage:
my_array = [5, 2, 9, 1, 7, 3]
k_value = 5
result = rand_quick_select(my_array, k_value)
print(f"The {k_value}th smallest element is: {result}")
