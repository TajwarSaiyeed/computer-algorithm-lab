def fact(n):
   if n <= 1:
        print(1)
        return 1
    print(n, end=" ")
    return n * fact(n-1)

def main():
    n = int(input())
    print(fact(n))

if __name__== "__main__":
    main()
