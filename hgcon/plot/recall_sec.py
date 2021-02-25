import matplotlib.pyplot as plt

# ====================== 0.2 ======================

greedy_02__130_sec = [ int(line.strip()) for line in open('./greedy_0.2__130_sec', 'r')]
greedy_02__130_recall = [ float(line.strip()) for line in open('./greedy_0.2__130_recall', 'r')]
#plt.plot(greedy_02__130_recall, greedy_02__130_sec, marker='x', label= 'g_0.2__130')

greedy_02_ls__130_sec = [ int(line.strip()) for line in open('./greedy_0.2_ls__130_sec', 'r')]
greedy_02_ls__130_recall = [ float(line.strip()) for line in open('./greedy_0.2_ls__130_recall', 'r')]
#plt.plot(greedy_02_ls__130_recall, greedy_02_ls__130_sec, marker='x', label= 'g_0.2_ls__130')

h3_02_130__1e4_52_sec = [ int(line.strip()) for line in open('./h3_0.2_130__1e4_52_sec', 'r')]
h3_02_130__1e4_52_recall = [ float(line.strip()) for line in open('./h3_0.2_130__1e4_52_recall', 'r')]
plt.plot(h3_02_130__1e4_52_recall, h3_02_130__1e4_52_sec, marker='x', label= 'h3_02_130__1e4_52')

h3_02_130__1e4_52_oneStep_sec = [ int(line.strip()) for line in open('./h3_0.2_130__1e4_52_oneStep_sec', 'r')]
h3_02_130__1e4_52_oneStep_recall = [ float(line.strip()) for line in open('./h3_0.2_130__1e4_52_oneStep_recall', 'r')]
plt.plot(h3_02_130__1e4_52_oneStep_recall, h3_02_130__1e4_52_oneStep_sec, marker='x', label= 'h3_02_130__1e4_52_oneStep')

h9_02_130__1e4_sec = [ int(line.strip()) for line in open('./h9_02_130__1e4_sec', 'r')]
h9_02_130__1e4_recall = [ float(line.strip()) for line in open('./h9_02_130__1e4_recall', 'r')]
plt.plot(h9_02_130__1e4_recall, h9_02_130__1e4_sec, marker='x', label= 'h9_02_130__1e4')

h9_02_130__1e4_oneStep_sec = [ int(line.strip()) for line in open('./h9_02_130__1e4_oneStep_sec', 'r')]
h9_02_130__1e4_oneStep_recall = [ float(line.strip()) for line in open('./h9_02_130__1e4_oneStep_recall', 'r')]
plt.plot(h9_02_130__1e4_oneStep_recall, h9_02_130__1e4_oneStep_sec, marker='x', label= 'h9_02_130__1e4_oneStep')

h12_02_130__1e4_sec = [ int(line.strip()) for line in open('./h12_02_130__1e4_sec', 'r')]
h12_02_130__1e4_recall = [ float(line.strip()) for line in open('./h12_02_130__1e4_recall', 'r')]
plt.plot(h12_02_130__1e4_recall, h12_02_130__1e4_sec, marker='x', label= 'h12_02_130__1e4')

h12_02_130__1e4_oneStep_sec = [ int(line.strip()) for line in open('./h12_02_130__1e4_oneStep_sec', 'r')]
h12_02_130__1e4_oneStep_recall = [ float(line.strip()) for line in open('./h12_02_130__1e4_oneStep_recall', 'r')]
plt.plot(h12_02_130__1e4_oneStep_recall, h12_02_130__1e4_oneStep_sec, marker='x', label= 'h12_02_130__1e4_oneStep')

h24_02_130__1e4_sec = [ int(line.strip()) for line in open('./h24_02_130__1e4_sec', 'r')]
h24_02_130__1e4_recall = [ float(line.strip()) for line in open('./h24_02_130__1e4_recall', 'r')]
#plt.plot(h24_02_130__1e4_recall, h24_02_130__1e4_sec, marker='x', label= 'h24_02_130__1e4')

h24_02_130__1e4_oneStep_sec = [ int(line.strip()) for line in open('./h24_02_130__1e4_oneStep_sec', 'r')]
h24_02_130__1e4_oneStep_recall = [ float(line.strip()) for line in open('./h24_02_130__1e4_oneStep_recall', 'r')]
#plt.plot(h24_02_130__1e4_oneStep_recall, h24_02_130__1e4_oneStep_sec, marker='x', label= 'h24_02_130__1e4_oneStep')

# ====================== 0.5 ======================

greedy_05__200_sec = [ int(line.strip()) for line in open('./greedy_0.5__200_sec', 'r')]
greedy_05__200_recall = [ float(line.strip()) for line in open('./greedy_0.5__200_recall', 'r')]
#plt.plot(greedy_05__200_recall, greedy_05__200_sec, marker='x', label= 'g_0.5__200')

greedy_05_ls__200_sec = [ int(line.strip()) for line in open('./greedy_0.5_ls__200_sec', 'r')]
greedy_05_ls__200_recall = [ float(line.strip()) for line in open('./greedy_0.5_ls__200_recall', 'r')]
#plt.plot(greedy_05_ls__200_recall, greedy_05_ls__200_sec, marker='x', label= 'g_0.5_ls__200')

h3_05_200__1e4_34_sec = [ int(line.strip()) for line in open('./h3_0.5_200__1e4_34_sec', 'r')]
h3_05_200__1e4_34_recall = [ float(line.strip()) for line in open('./h3_0.5_200__1e4_34_recall', 'r')]
plt.plot(h3_05_200__1e4_34_recall, h3_05_200__1e4_34_sec, marker='x', label= 'h3_05_200__1e4_34')

h3_05_200__1e4_34_oneStep_sec = [ int(line.strip()) for line in open('./h3_0.5_200__1e4_34_oneStep_sec', 'r')]
h3_05_200__1e4_34_oneStep_recall = [ float(line.strip()) for line in open('./h3_0.5_200__1e4_34_oneStep_recall', 'r')]
plt.plot(h3_05_200__1e4_34_oneStep_recall, h3_05_200__1e4_34_oneStep_sec, marker='x', label= 'h3_05_200__1e4_34_oneStep')

h9_05_200__1e4_sec = [ int(line.strip()) for line in open('./h9_05_200__1e4_sec', 'r')]
h9_05_200__1e4_recall = [ float(line.strip()) for line in open('./h9_05_200__1e4_recall', 'r')]
plt.plot(h9_05_200__1e4_recall, h9_05_200__1e4_sec, marker='x', label= 'h9_05_200__1e4')

h9_05_200__1e4_oneStep_sec = [ int(line.strip()) for line in open('./h9_05_200__1e4_oneStep_sec', 'r')]
h9_05_200__1e4_oneStep_recall = [ float(line.strip()) for line in open('./h9_05_200__1e4_oneStep_recall', 'r')]
plt.plot(h9_05_200__1e4_oneStep_recall, h9_05_200__1e4_oneStep_sec, marker='x', label= 'h9_05_200__1e4_oneStep')

h12_05_200__1e4_sec = [ int(line.strip()) for line in open('./h12_05_200__1e4_sec', 'r')]
h12_05_200__1e4_recall = [ float(line.strip()) for line in open('./h12_05_200__1e4_recall', 'r')]
plt.plot(h12_05_200__1e4_recall, h12_05_200__1e4_sec, marker='x', label= 'h12_05_200__1e4')

h12_05_200__1e4_oneStep_sec = [ int(line.strip()) for line in open('./h12_05_200__1e4_oneStep_sec', 'r')]
h12_05_200__1e4_oneStep_recall = [ float(line.strip()) for line in open('./h12_05_200__1e4_oneStep_recall', 'r')]
plt.plot(h12_05_200__1e4_oneStep_recall, h12_05_200__1e4_oneStep_sec, marker='x', label= 'h12_05_200__1e4_oneStep')

h24_05_200__1e4_sec = [ int(line.strip()) for line in open('./h24_05_200__1e4_sec', 'r')]
h24_05_200__1e4_recall = [ float(line.strip()) for line in open('./h24_05_200__1e4_recall', 'r')]
#plt.plot(h24_05_200__1e4_recall, h24_05_200__1e4_sec, marker='x', label= 'h24_05_200__1e4')

h24_05_200__1e4_oneStep_sec = [ int(line.strip()) for line in open('./h24_05_200__1e4_oneStep_sec', 'r')]
h24_05_200__1e4_oneStep_recall = [ float(line.strip()) for line in open('./h24_05_200__1e4_oneStep_recall', 'r')]
#plt.plot(h24_05_200__1e4_oneStep_recall, h24_05_200__1e4_oneStep_sec, marker='x', label= 'h24_05_200__1e4_oneStep')

# ========= plot ===========

plt.xlabel("recall")
plt.ylabel("query per sec(1/s)")

plt.legend()
plt.title("glove_25d_angular_k10")

plt.savefig("glove_25d_angular_k10.png")
plt.show()
