def add_numbers(num1, num2):
    return num1 + num2

def subtract_numbers(num1, num2):
    return num1 - num2

def multiply_numbers(num1, num2):
    return num1 * num2

def main():
    # 사용자로부터 두 개의 큰 수를 입력받습니다.
    num1 = int(input())
    num2 = int(input())

    # 덧셈
    sum_result = add_numbers(num1, num2)
    print(f"{sum_result}")

    # 뺄셈
    sub_result = subtract_numbers(num1, num2)
    print(f"{sub_result}")

    # 곱셈
    mul_result = multiply_numbers(num1, num2)
    print(f"{mul_result}")

if __name__ == "__main__":
    main()
