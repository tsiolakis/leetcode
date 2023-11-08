class Solution:
    def validMountainArray(self, arr: List[int]) -> bool:
        if len(arr) < 3:
            return False
        peak = -1
        for i in range(1, len(arr)):
            if arr[i] > arr[i-1]:
                continue
            elif arr[i] == arr[i-1]:
                return False
            else:
                peak = i-1
                break
        for i in range(peak+2, len(arr)):
            if arr[i] < arr[i-1]:
                continue
            else:
                return False
        #if peak is still -1 then  no peak was found (e.g. [0,1,2,3,4,5,6]) therefore there is no mountain
        #or if peak is 0 like in array [6,5,4,3,2,1,0] then we also have no mountain
        if peak > 0:
            return True
        return False
