from typing import List


class Solution:
    def numUniqueEmails(self, emails: List[str]) -> int:
        uniqueEmails = set()
        for email in emails:
            uniqueEmails.add(self.parseLocalName(email) + self.parseDomainName(email))
        
        return len(uniqueEmails)

    
    def parseDomainName(self, email: str) -> str:
        return email.split('@')[1]

    
    def parseLocalName(self, email: str) -> str:
        email = email.split('@')[0]
        email = email.split('+')[0]
        email = email.replace('.','')

        return email


if __name__ == "__main__":
    #input =  ["test.email+alex@leetcode.com","test.e.mail+bob.cathy@leetcode.com","testemail+david@lee.tcode.com"]
    input = ["test.email+alex@leetcode.com", "test.email@leetcode.com"]
    print(Solution().numUniqueEmails(input))