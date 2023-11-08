class Solution:
    def checkIfExist(self, arr: List[int]) -> bool:
        uniqueOccurences = set()
        for value in arr:
            for uniqueValue in uniqueOccurences:
                if value == uniqueValue*2 or value == uniqueValue/2:
                    return True
            uniqueOccurences.add(value)
        return False
