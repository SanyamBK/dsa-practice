def process_subsegments():
    num_elements, max_sum = map(int, input().split())
    elements_array = list(map(int, input().split()))
    
    prefix_sum_array = [0] * (num_elements + 1)
    dynamic_programming_array = [0] * (num_elements + 3)
    
    # Compute prefix sums
    for i in range(num_elements):
        prefix_sum_array[i + 1] = prefix_sum_array[i] + elements_array[i]
    
    total_valid_subsegments = 0
    
    # Process subsegments in reverse order
    for i in range(num_elements - 1, -1, -1):
        target_sum = prefix_sum_array[i + 1] + max_sum
        
        # Use binary search to find the lower bound of the target sum in prefix_sum_array
        left, right = 0, num_elements + 1
        while left < right:
            mid = (left + right) // 2
            if prefix_sum_array[mid] < target_sum:
                left = mid + 1
            else:
                right = mid
        
        lower_bound_index = left
        
        # Calculate the number of valid subsegments
        if lower_bound_index == num_elements + 1:
            dynamic_programming_array[i] += (num_elements - i)
        elif target_sum == prefix_sum_array[lower_bound_index]:
            dynamic_programming_array[i] += (lower_bound_index - i) + dynamic_programming_array[lower_bound_index + 1]
        else:
            dynamic_programming_array[i] += (lower_bound_index - i - 1) + dynamic_programming_array[lower_bound_index]
    
    # Calculate the total number of valid subsegments
    for i in range(num_elements + 3):
        total_valid_subsegments += dynamic_programming_array[i]
    
    print(total_valid_subsegments)

def main():
    test_cases = int(input())
    for _ in range(test_cases):
        process_subsegments()

if __name__ == "__main__":
    main()
