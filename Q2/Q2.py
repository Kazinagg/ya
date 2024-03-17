def find_palindrome_pairs(words):
    def is_palindrome(check):
        return check == check[::-1]

    words = {word: i for i, word in enumerate(words)}
    valid_pals = []
    for word, k in words.items():
        n = len(word)
        for j in range(n+1):
            pref = word[:j]
            suf = word[j:]
            if is_palindrome(pref):
                back = suf[::-1]
                if back != word and back in words:
                    valid_pals.append((words[back], k))
            if j != n and is_palindrome(suf):
                back = pref[::-1]
                if back != word and back in words:
                    valid_pals.append((k, words[back]))
    return valid_pals



m = []
for i in range(int(input())):
    new_element = input()
    m.append(new_element)

pairs = find_palindrome_pairs(m)

pairs.sort(key=lambda x: (x[0], x[1]))

for pair in pairs:
    print(pair[0] + 1, pair[1] + 1)




# m = []
# m_r = []
# for i in range(int(input())):
#     new_element = input()
#     m.append(new_element)
#     m_r.append(new_element[::-1])

# for i in range(len(m)):
#     for j in range(i+1, len(m)):
#         kank = m[i] + m[j]
#         if kank == kank[::-1]:
#             print(i+1, j+1)
#         kank = m[j] + m[i]
#         if kank == kank[::-1]:
#             print(j+1, i+1)

# import numpy as np
# m = []
# for i in range(int(input())):
#     m.append(input())




# for i in range(len(m)):
#     indexes = [j+1 for j, x in enumerate(m_r) if x == m[i] and i != j]
#     if indexes:
#         print(i+1, indexes[0])



# for i in range(len(m)):
#     for j in range(len(m)):
#         if i != j:
#             m_str = m[i] + m[j]
#             l = len(m_str)
#             if l%2  == 0:
#                 part_1 = m_str[0:l//2]
#                 part_2 = m_str[l//2:]
#                 reversed_part_2 = part_2[::-1]
#                 if part_1 == reversed_part_2:
#                     print (i+1, j+1)
#             else:
#                 l-=1
#                 part_1 = m_str[0:l//2]
#                 part_2 = m_str[(l//2)+1:]
#                 reversed_part_2 = part_2[::-1]
#                 if part_1 == reversed_part_2:
#                     print (i+1, j+1)




# склеить разделить пополам развернуть одну сравнть