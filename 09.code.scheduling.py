#> Just grab colorama
from colorama import init
init() # This is for Windows
from colorama import Fore

#> Just some bad codes
p1 = ('p1', 0.0, 8.0, Fore.RED)
p2 = ('p2', 0.4, 4.0, Fore.GREEN)
p3 = ('p3', 1.0, 1.0, Fore.BLUE)
p4 = ('p4', 1.3, 5.0, Fore.WHITE)

proc_list = []

proc_list.append(p1)
proc_list.append(p2)
proc_list.append(p3)
proc_list.append(p4)

slice_time = 1.0
#> End of bad codes

def GanttChart(proc_list):
    # print(' - is equivalent with 0.1 ms')
    for proc in proc_list:
        temp = proc[0] + ' ' * (int(proc[1] * 10)) + '-' * (int(proc[2] * 10))
        print(proc[3]+temp)


# GanttChart(proc_list)

def FCFS(proc_list):
    proc_list.sort(key = lambda x: x[1]) # Make sure it's in order in term of arrival time
    str = ''
    for proc in proc_list:
        str = str + proc[3] + '-' * (int(proc[2] * 10))

    return str

def SJF(proc_list):
    proc_list.sort(key = lambda x: x[2]) # Make sure it's in order in term of burst time
    str = ''
    for proc in proc_list:
        str = str + proc[3] + '-' * (int(proc[2] * 10))

    return str

def RR(proc_list, slice_time):
    proc_list.sort(key = lambda x: x[1]) # Make sure it's in order in term of arrival time
    cur_proc_time = []
    for proc in proc_list:
        cur_proc_time.append(tuple([proc[0], proc[1], 0.0, proc[3]]))

    str = ''
    goon = True
    while goon:
        finish_count = 0
        for cur_proc, proc, i in zip(cur_proc_time, proc_list, range(len(cur_proc_time))):
            if cur_proc[2] == proc[2]:
                finish_count = finish_count + 1
            else:
                temp_cur_proc = list(cur_proc)
                temp_cur_proc[2] = temp_cur_proc[2] + slice_time
                cur_proc_time[i] = tuple(temp_cur_proc)
                str = str + proc[3] + '-' * 10


        if int(finish_count) == int(len(cur_proc_time)):
            goon = False


    return str

# def SRTF(proc_list):
#     total_burst = sum([i[2] for i in proc_list])
#     proc_list.sort(key = lambda x: x[1]) # Make sure it's in order in term of arrival time
#     str = ''
#
#     return str

print(SJF(proc_list))
str = Fore.RED + '-' * 4 + Fore.GREEN + '-' * 6 + Fore.BLUE + '-' * 10 + Fore.GREEN + '-' * 34 + Fore.WHITE + '-' * 50 + Fore.RED + '-' * 76
print(str)
