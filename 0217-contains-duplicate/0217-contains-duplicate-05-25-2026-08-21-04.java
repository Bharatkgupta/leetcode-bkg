class Solution {
    public boolean containsDuplicate(int[] nums) {
        Set<Integer> noDuplicates = Arrays.stream(nums).boxed().collect(Collectors.toSet());

        return nums.length != noDuplicates.size();
    }
}