def max_magic_value():
    # Đọc số lượng bảo bối và chỉ số sức mạnh tăng thêm sau mỗi bước đi
    M, X = map(int, input().split())

    # Đọc thông tin về các bảo bối
    items = [list(map(int, input().split())) for _ in range(M)]

    # Khởi tạo chỉ số sức mạnh và tổng giá trị phép thuật
    power = 0
    total_magic_value = 0

    for i in range(M):
        # Nếu Nobita có thể lấy bảo bối này
        if power >= items[i][0]:
            # Cập nhật chỉ số sức mạnh và tổng giá trị phép thuật
            power += X
            total_magic_value += items[i][1]
        else:
            power += X

    print(total_magic_value)
for _ in range(0, int(input())):
    max_magic_value()
