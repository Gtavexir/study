import matplotlib.pyplot as plt

# ====================== 0.2 ======================

greedy_02__100_sec = [ int(line.strip()) for line in open('./greedy_0.2__100.sec', 'r')]
greedy_02__100_recall = [ float(line.strip()) for line in open('./greedy_0.2__100.recall', 'r')]
plt.plot(greedy_02__100_recall, greedy_02__100_sec, marker='x', label= 'g_0.2__100')

greedy_02_ls__100_sec = [ int(line.strip()) for line in open('./greedy_0.2_ls__100.sec', 'r')]
greedy_02_ls__100_recall = [ float(line.strip()) for line in open('./greedy_0.2_ls__100.recall', 'r')]
plt.plot(greedy_02_ls__100_recall, greedy_02_ls__100_sec, marker='x', label= 'g_0.2_ls__100')

# greedy_02_sec = [ int(line.strip()) for line in open('./greedy_0.2_sec', 'r')]
# greedy_02_recall = [ float(line.strip()) for line in open('./greedy_0.2_recall', 'r')]
#
# greedy_ls_02_sec = [ int(line.strip()) for line in open('./greedy_ls_0.2_sec', 'r')]
# greedy_ls_02_recall = [ float(line.strip()) for line in open('./greedy_ls_0.2_recall', 'r')]
#
# greedy_h_02_sec = [ int(line.strip()) for line in open('greedy_h_02.sec', 'r')]
# greedy_h_02_recall = [ float(line.strip()) for line in open('greedy_h_02.recall', 'r')]
#
# greedy_h_oneStep_02_sec = [ int(line.strip()) for line in open('greedy_h_oneStep_02.sec', 'r')]
# greedy_h_oneStep_02_recall = [ float(line.strip()) for line in open('greedy_h_oneStep_02.recall', 'r')]
#
# plt.plot(greedy_02_recall, greedy_02_sec, marker='x', label= 'g_0.2')
#
# plt.plot(greedy_ls_02_recall, greedy_ls_02_sec, marker='x', label= 'g_ls_0.2')
#
# plt.plot(greedy_h_02_recall, greedy_h_02_sec, marker='x', label= 'g_h9_0.2')
#
# plt.plot(greedy_h_oneStep_02_recall, greedy_h_oneStep_02_sec, marker='x', label= 'g_h9_oneStep_0.2')
#
# greedy_h_02_layer3_sec = [ int(line.strip()) for line in open('greedy_h_02_layer3.sec', 'r')]
# greedy_h_02_layer3_recall = [ float(line.strip()) for line in open('greedy_h_02_layer3.recall', 'r')]
#
# greedy_h_oneStep_02_layer3_sec = [ int(line.strip()) for line in open('greedy_h_oneStep_02_layer3.sec', 'r')]
# greedy_h_oneStep_02_layer3_recall = [ float(line.strip()) for line in open('greedy_h_oneStep_02_layer3.recall', 'r')]
#
# plt.plot(greedy_h_02_layer3_recall, greedy_h_02_layer3_sec, marker='x', label= 'g_h3_0.2')
#
# plt.plot(greedy_h_oneStep_02_layer3_recall, greedy_h_oneStep_02_layer3_sec, marker='x', label= 'g_h3_oneStep_0.2')

greedy_del_edge_02_sec = [int(line.strip()) for line in open('./y_long_cut_0.2_v2.sec', 'r')]
greedy_del_edge_02_recall = [float(line.strip()) for line in open('./y_long_cut_0.2_v2.recall', 'r')]

greedy_del_edge_withL_02_sec = [ int(line.strip()) for line in open('./y_long_cut_0.2_v2_withL.sec', 'r')]
greedy_del_edge_withL_02_recall = [ float(line.strip()) for line in open('./y_long_cut_0.2_v2_withL.recall', 'r')]

plt.plot(greedy_del_edge_02_recall, greedy_del_edge_02_sec, marker='x', label='g_del_edge_0.2')

plt.plot(greedy_del_edge_withL_02_recall, greedy_del_edge_withL_02_sec, marker='x', label='g_del_edge_withL_0.2')

# ====================== 0.5 ======================

greedy_05__100_sec = [ int(line.strip()) for line in open('./greedy_0.5__100.sec', 'r')]
greedy_05__100_recall = [ float(line.strip()) for line in open('./greedy_0.5__100.recall', 'r')]
plt.plot(greedy_05__100_recall, greedy_05__100_sec, marker='x', label= 'g_0.5__100')

greedy_05_ls__100_sec = [ int(line.strip()) for line in open('./greedy_0.5_ls__100.sec', 'r')]
greedy_05_ls__100_recall = [ float(line.strip()) for line in open('./greedy_0.5_ls__100.recall', 'r')]
plt.plot(greedy_05_ls__100_recall, greedy_05_ls__100_sec, marker='x', label= 'g_0.5_ls__100')

# greedy_05_sec = [ int(line.strip()) for line in open('./greedy_0.5_sec', 'r')]
# greedy_05_recall = [ float(line.strip()) for line in open('./greedy_0.5_recall', 'r')]
#
# greedy_ls_05_sec = [ int(line.strip()) for line in open('./greedy_ls_0.5_sec', 'r')]
# greedy_ls_05_recall = [ float(line.strip()) for line in open('./greedy_ls_0.5_recall', 'r')]

# greedy_h_05_sec = [ int(line.strip()) for line in open('greedy_h_05.sec', 'r')]
# greedy_h_05_recall = [ float(line.strip()) for line in open('greedy_h_05.recall', 'r')]
#
# greedy_h_oneStep_05_sec = [ int(line.strip()) for line in open('greedy_h_oneStep_05.sec', 'r')]
# greedy_h_oneStep_05_recall = [ float(line.strip()) for line in open('greedy_h_oneStep_05.recall', 'r')]

# plt.plot(greedy_05_recall, greedy_05_sec, marker='x', label='g_0.5')
#
# plt.plot(greedy_ls_05_recall, greedy_ls_05_sec, marker='x', label='g_ls_0.5')

# plt.plot(greedy_h_05_recall, greedy_h_05_sec, marker='x', label= 'g_h9_0.5')
#
# plt.plot(greedy_h_oneStep_05_recall, greedy_h_oneStep_05_sec, marker='x', label= 'g_h9_oneStep_0.5')

# greedy_h3_05_sec = [ int(line.strip()) for line in open('greedy_h3_05.sec', 'r')]
# greedy_h3_05_recall = [ float(line.strip()) for line in open('greedy_h3_05.recall', 'r')]
#
# greedy_h3_oneStep_05_sec = [ int(line.strip()) for line in open('greedy_h3_oneStep_05.sec', 'r')]
# greedy_h3_oneStep_05_recall = [ float(line.strip()) for line in open('greedy_h3_oneStep_05.recall', 'r')]

# plt.plot(greedy_h3_05_recall, greedy_h3_05_sec, marker='x', label= 'g_h3_0.5')
#
# plt.plot(greedy_h3_oneStep_05_recall, greedy_h3_oneStep_05_sec, marker='x', label= 'g_h3_oneStep_0.5')

greedy_del_edge_05_sec = [int(line.strip()) for line in open('./y_long_cut_0.5_v2.sec', 'r')]
greedy_del_edge_05_recall = [float(line.strip()) for line in open('./y_long_cut_0.5_v2.recall', 'r')]

greedy_del_edge_withL_05_sec = [ int(line.strip()) for line in open('./y_long_cut_0.5_v2_withL.sec', 'r')]
greedy_del_edge_withL_05_recall = [ float(line.strip()) for line in open('./y_long_cut_0.5_v2_withL.recall', 'r')]

plt.plot(greedy_del_edge_05_recall, greedy_del_edge_05_sec, marker='x', label='g_del_edge_0.5')

plt.plot(greedy_del_edge_withL_05_recall, greedy_del_edge_withL_05_sec, marker='x', label='g_del_edge_withL_0.5')

# === plot ===

plt.xlabel("recall")
plt.ylabel("query per sec(1/s)")

plt.legend()
plt.title("glove_25d_angular_k10")

plt.savefig("glove_25d_angular_k10.png")
plt.show()
