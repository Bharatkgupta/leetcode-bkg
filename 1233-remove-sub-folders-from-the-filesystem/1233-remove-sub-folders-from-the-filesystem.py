class Solution:
    def removeSubfolders(self, folder: List[str]) -> List[str]:
        isSubfolder = {};
        for f in folder:
            isSubfolder[f] = False;
        for f in folder:
            folders = f.split("/")
            for i in range(2,len(folders)):
                prefixFolder = "/".join(folders[:i])
                if prefixFolder in isSubfolder:
                    isSubfolder[f] = True
                    break
        ans = []
        for k, v in isSubfolder.items():
            if v == False:
                ans.append(k)
        return ans