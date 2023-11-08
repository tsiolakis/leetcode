class Solution:
    def replaceElements(self, arr: List[int]) -> List[int]:
        maximus = [0]*len(arr)
        maximus[-1] = arr[-1]
        for i in range(len(arr)-1, -1, -1):
            maximus[i] = arr[i] if maximus[i+1]<arr[i] else maximus[i+1]
        for i in range(len(arr)-1):
            arr[i] = maximus[i+1]
        arr[-1] = -1
        return arr
