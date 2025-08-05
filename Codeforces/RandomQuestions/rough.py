lst = [1, 10, 100, 1000, 10000]

s = "EABCADCE"

nums = []

for i in range(len(s)):
    j = ord(s[i]) - ord('A')
    nums.append(lst[j])

rg = [0] * len(nums)
        
for i in range(len(nums)-1):
    if nums[i+1] > nums[i]:
        rg[i+1] = 1 
    else:
        rg[i+1] = -1
        
for i in range(1, len(nums)):
    nums[i] = nums[i] * rg[i]
    
print(nums)
print(rg)
