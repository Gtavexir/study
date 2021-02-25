#cat ./test_h3_0.5 | grep second: | awk '{print $4}' > greedy_h3_05.sec
#cat ./test_h3_0.5 | grep recall: | awk '{print $2}' > greedy_h3_05.recall

#cat ./test2_h3_0.5 | grep second: | awk '{print $4}' > greedy_h3_oneStep_05.sec
#cat ./test2_h3_0.5 | grep recall: | awk '{print $2}' > greedy_h3_oneStep_05.recall

#cat ./greedy_0.2__130 | grep second: | awk '{print $4}' > greedy_0.2__130_sec
#cat ./greedy_0.2__130 | grep recall: | awk '{print $2}' > greedy_0.2__130_recall
#
#cat ./greedy_0.2_ls__130 | grep second: | awk '{print $4}' > greedy_0.2_ls__130_sec
#cat ./greedy_0.2_ls__130 | grep recall: | awk '{print $2}' > greedy_0.2_ls__130_recall
#
#cat ./greedy_0.5__200 | grep second: | awk '{print $4}' > greedy_0.5__200_sec
#cat ./greedy_0.5__200 | grep recall: | awk '{print $2}' > greedy_0.5__200_recall
#
#cat ./greedy_0.5_ls__200 | grep second: | awk '{print $4}' > greedy_0.5_ls__200_sec
#cat ./greedy_0.5_ls__200 | grep recall: | awk '{print $2}' > greedy_0.5_ls__200_recall

# ==== h3 ====

cat ../search/h3_0.2_130__1e4_52 | grep second: | awk '{print $4}' > h3_0.2_130__1e4_52_sec
cat ../search/h3_0.2_130__1e4_52 | grep recall: | awk '{print $2}' > h3_0.2_130__1e4_52_recall

cat ../search/h3_0.2_130__1e4_52_oneStep | grep second: | awk '{print $4}' > h3_0.2_130__1e4_52_oneStep_sec
cat ../search/h3_0.2_130__1e4_52_oneStep | grep recall: | awk '{print $2}' > h3_0.2_130__1e4_52_oneStep_recall

cat ../search/h3_0.5_200__1e4_34 | grep second: | awk '{print $4}' > h3_0.5_200__1e4_34_sec
cat ../search/h3_0.5_200__1e4_34 | grep recall: | awk '{print $2}' > h3_0.5_200__1e4_34_recall

cat ../search/h3_0.5_200__1e4_34_oneStep | grep second: | awk '{print $4}' > h3_0.5_200__1e4_34_oneStep_sec
cat ../search/h3_0.5_200__1e4_34_oneStep | grep recall: | awk '{print $2}' > h3_0.5_200__1e4_34_oneStep_recall

# ==== h9 ====

cat ../search/h9_02_130__1e4 | grep second: | awk '{print $4}' > h9_02_130__1e4_sec
cat ../search/h9_02_130__1e4 | grep recall: | awk '{print $2}' > h9_02_130__1e4_recall

cat ../search/h9_02_130__1e4_oneStep | grep second: | awk '{print $4}' > h9_02_130__1e4_oneStep_sec
cat ../search/h9_02_130__1e4_oneStep | grep recall: | awk '{print $2}' > h9_02_130__1e4_oneStep_recall

cat ../search/h9_05_200__1e4 | grep second: | awk '{print $4}' > h9_05_200__1e4_sec
cat ../search/h9_05_200__1e4 | grep recall: | awk '{print $2}' > h9_05_200__1e4_recall

cat ../search/h9_05_200__1e4_oneStep | grep second: | awk '{print $4}' > h9_05_200__1e4_oneStep_sec
cat ../search/h9_05_200__1e4_oneStep | grep recall: | awk '{print $2}' > h9_05_200__1e4_oneStep_recall

# ==== h12 ====

cat ../search/h12_02_130__1e4 | grep second: | awk '{print $4}' > h12_02_130__1e4_sec
cat ../search/h12_02_130__1e4 | grep recall: | awk '{print $2}' > h12_02_130__1e4_recall

cat ../search/h12_02_130__1e4_oneStep | grep second: | awk '{print $4}' > h12_02_130__1e4_oneStep_sec
cat ../search/h12_02_130__1e4_oneStep | grep recall: | awk '{print $2}' > h12_02_130__1e4_oneStep_recall

cat ../search/h12_05_200__1e4 | grep second: | awk '{print $4}' > h12_05_200__1e4_sec
cat ../search/h12_05_200__1e4 | grep recall: | awk '{print $2}' > h12_05_200__1e4_recall

cat ../search/h12_05_200__1e4_oneStep | grep second: | awk '{print $4}' > h12_05_200__1e4_oneStep_sec
cat ../search/h12_05_200__1e4_oneStep | grep recall: | awk '{print $2}' > h12_05_200__1e4_oneStep_recall

# ==== h24 ====

cat ../search/h24_02_130__1e4 | grep second: | awk '{print $4}' > h24_02_130__1e4_sec
cat ../search/h24_02_130__1e4 | grep recall: | awk '{print $2}' > h24_02_130__1e4_recall

cat ../search/h24_02_130__1e4_oneStep | grep second: | awk '{print $4}' > h24_02_130__1e4_oneStep_sec
cat ../search/h24_02_130__1e4_oneStep | grep recall: | awk '{print $2}' > h24_02_130__1e4_oneStep_recall

cat ../search/h24_05_200__1e4 | grep second: | awk '{print $4}' > h24_05_200__1e4_sec
cat ../search/h24_05_200__1e4 | grep recall: | awk '{print $2}' > h24_05_200__1e4_recall

cat ../search/h24_05_200__1e4_oneStep | grep second: | awk '{print $4}' > h24_05_200__1e4_oneStep_sec
cat ../search/h24_05_200__1e4_oneStep | grep recall: | awk '{print $2}' > h24_05_200__1e4_oneStep_recall

# python3 recall_sec.py
