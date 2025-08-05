import random

def choose_pivot(arr):
    """
    Chooses a pivot element from the input array.

    Args:
        arr (list): Input array.

    Returns:
        int: Pivot element.
    """
    return random.choice(arr)

# Example usage:
my_array = [5, 2, 9, 1, 7, 3]
pivot_value = choose_pivot(my_array)
print(f"Randomly chosen pivot: {pivot_value}")
