def process_queries():
    import sys
    input_data = sys.stdin.read().split()
    q = int(input_data[0])
    index = 1
    res = []
    mask64 = (1 << 64) - 1  

    for _ in range(q):
        query_type = int(input_data[index])
        index += 1

        if query_type == 1:

            x = int(input_data[index]); y = int(input_data[index+1])
            index += 2
            res.append(str(x & y))
        elif query_type == 2:

            x = int(input_data[index]); y = int(input_data[index+1])
            index += 2
            res.append(str(x | y))
        elif query_type == 3:

            x = int(input_data[index]); y = int(input_data[index+1])
            index += 2
            res.append(str(x ^ y))
        elif query_type == 4:

            x = int(input_data[index]); y = int(input_data[index+1])
            index += 2

            res.append(str((x << y) & mask64))
        elif query_type == 5:

            x = int(input_data[index]); y = int(input_data[index+1])
            index += 2
            res.append(str(x >> y))
        elif query_type == 6:

            x = int(input_data[index]); y = int(input_data[index+1])
            index += 2
            res.append(str((x >> y) & 1))
        elif query_type == 7:

            x = int(input_data[index])
            i = int(input_data[index+1])
            v = int(input_data[index+2])
            index += 3

            if v == 1:
                x |= (1 << (i))
            else:
                x &= ~(1 << (i))
            res.append(str(x))
    sys.stdout.write("\n".join(res))

if __name__ == "__main__":
    process_queries()