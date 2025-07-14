class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        HashMap<String, List<String>> mp = new HashMap<>();

        for (String x : strs) {
            String temp = x;
            char[] arr = temp.toCharArray();
            Arrays.sort(arr);
            temp = new String(arr);

            if (!mp.containsKey(temp)) {
                mp.put(temp, new ArrayList<>());
            }
            mp.get(temp).add(x);
        }

        List<List<String>> ans = new ArrayList<>();

        for (Map.Entry<String, List<String>> entry : mp.entrySet()) {
            ans.add(entry.getValue());
        }

        return ans;
    }
}
