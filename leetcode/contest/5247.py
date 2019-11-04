class Solution:
    def minimumSwap(self, s1: str, s2: str) -> int:
        num_xy, num_yx = 0, 0
        for c1, c2 in zip(s1, s2):
            if c1 == c2: continue

            if c1 == 'x': num_xy += 1
            if c1 == 'y': num_yx += 1
        
        if (num_xy + num_yx) % 2 != 0:
            return -1
        
        ans = 0
        ans += int(num_xy / 2)
        ans += int(num_yx / 2)

        if num_xy % 2 == 1:
            ans += 2
        
        return ans


if __name__ == "__main__":
    s1 = "xxyyxyxyxx"
    s2 = "xyyxyxxxyx"
    print(Solution().minimumSwap(s1, s2))