for i in range(0, int(input())):
    s = input()
    cnt = dict()
    chars = sorted(set(s))
    for i in s:
        cnt[i] = 0;
    for i in s:
        cnt[i] += 1
    if len(chars) == 1:
        print(s)
    elif any(cnt[i] == 1 for i in cnt):
        char = ''
        for i in cnt:
            if cnt[i] == 1 and (char > i or char == ''):
                char = i
        print(char + ''.join(cnt[i] * i if i != char else '' for i in chars))
    elif len(chars) == 2:
        c1, d1 = chars[0], chars[1]

        ans = ''
        ans += c1
        cnt[c1] -= 1
        if cnt[c1] + 1 <= cnt[d1] + 2:
            ans += c1;
            cnt[c1] -= 1
            ans += (d1 + c1) * cnt[c1]
            cnt[d1] -= cnt[c1]
            ans += cnt[d1] * d1
        else:
            ans += cnt[chars[1]] * chars[1]
            ans += cnt[chars[0]] * chars[0]
        print(ans)
    elif len(chars) >= 3:
        c1, d1, d2 = chars[0], chars[1], chars[2]
        ans = ''
        if cnt[c1] <= (len(s) - cnt[c1]) + 2:
            ans += c1 + c1
            cnt[c1] -= 2
            for i in chars:
                if i == c1:
                    continue
                while cnt[c1] and cnt[i]:
                    ans += i + c1
                    cnt[c1] -= 1
                    cnt[i] -= 1
            for i in chars:
                ans += i * cnt[i]
                cnt[i] = 0
        else:
            ans += c1
            cnt[c1] -= 1
            ans += d1
            cnt[d1] -= 1
            ans += c1 * cnt[c1]
            cnt[c1] = 0
            ans += d2
            cnt[d2] -= 1
            for i in chars:
                ans += i * cnt[i]
        print(ans)
    elif len(chars) == 1:
        print(s)
    else:
        import sys
        sys.exit(1)