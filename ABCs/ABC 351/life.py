scores = [
    ['Alice', 85, 90, 88],
    ['Bob', 78, 82],
    ['Carol', 92, 88, 95, 90],
    ['David', 80, 85, 78],
    ['Eve', 88, 92]
]

def average_scores(scores):
    ans = []
    for i in scores:
        avg = 0
        for q in range(1, len(i)):
            avg += i[q]
        avg /= (len(i) - 1)
        yes = f"{i[0]}: Average score = {avg:.2f}"
        ans.append(yes)
    return ans

average_results = average_scores(scores)
print(average_results[4])