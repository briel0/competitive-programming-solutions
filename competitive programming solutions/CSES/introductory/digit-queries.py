def conta(atual):
    ans = 0
    i = 1
    while i <= atual:
        ans += atual - i + 1
        i *= 10
    return ans
 
def work():
    k = int(input())
    low, high = 0, int(1e18)
    
    while low <= high:
        mid = (low + high) // 2
        if conta(mid) >= k:
            high = mid - 1
        else:
            low = mid + 1
 
    s = str(low)
    s = s[::-1]  # Reverse the string
    print(s[conta(low) - k])
 
def main():
    t = int(input())
    for _ in range(t):
        work()
 
if __name__ == "__main__":
    main()

