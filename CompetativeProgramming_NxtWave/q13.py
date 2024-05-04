# Find the maximum number of meetings possible 
import heapq

def max_meetings(S,F):
    N = len(S)
    meetings = []
    for i in range(N):
        meetings.append([F[i], S[i],i])
    sorted(meetings, key = lambda x : x[0])
    meetings_list = []
    max_meetings = 1
    finish_time = meetings[0][0]
    meetings_list.append(meetings[0][2] + 1)
    for i in range(1, N):
        if finish_time < meetings[i][1]:
            finish_time = meetings[i][0]
            max_meetings+=1
            meetings_list.append(meetings[i][2] + 1)
    return meetings_list, max_meetings



def max_meetings_priority_q(S,F):
    N = len(S)
    meetings = []
    # O(N) time
    # O(N) space
    for i in range(N):
        heapq.heappush(meetings, [F[i], S[i], i])
    # to return the max mettings that can be performed
    final_list = []
    meeting = heapq.heappop(meetings)
    total_final_meetings = 1
    finish_time = meeting[0]
    final_list.append(meeting[2] + 1)
    while meetings:
        meeting = heapq.heappop(meetings)
        if meeting[1] > finish_time:
            finish_time = meeting[0]
            final_list.append(meeting[2] + 1)
            total_final_meetings += 1
    return final_list, total_final_meetings



S = [1,3,0,5,8,5]
F = [2,4,6,7,9,9] 
print(max_meetings_priority_q(S,F))