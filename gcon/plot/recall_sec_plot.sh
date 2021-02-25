#cat ./y_long_cut_0.5_v2 | grep second: | awk '{print $4}' > y_long_cut_0.5_v2.sec
#cat ./y_long_cut_0.5_v2 | grep recall: | awk '{print $2}' > y_long_cut_0.5_v2.recall 

#cat ./y_long_cut_0.5_v2_withL | grep second: | awk '{print $4}' > y_long_cut_0.5_v2_withL.sec
#cat ./y_long_cut_0.5_v2_withL | grep recall: | awk '{print $2}' > y_long_cut_0.5_v2_withL.recall

#cat ./y_long_cut_0.2_v2 | grep second: | awk '{print $4}' > y_long_cut_0.2_v2.sec
#cat ./y_long_cut_0.2_v2 | grep recall: | awk '{print $2}' > y_long_cut_0.2_v2.recall 

#cat ./y_long_cut_0.2_v2_withL | grep second: | awk '{print $4}' > y_long_cut_0.2_v2_withL.sec
#cat ./y_long_cut_0.2_v2_withL | grep recall: | awk '{print $2}' > y_long_cut_0.2_v2_withL.recall

#cat ../search/greedy_0.2_100 | grep second: | awk '{print $4}' > greedy_0.2__100.sec
#cat ../search/greedy_0.2_100 | grep recall: | awk '{print $2}' > greedy_0.2__100.recall

#cat ../search/greedy_0.5_100 | grep second: | awk '{print $4}' > greedy_0.5__100.sec
#cat ../search/greedy_0.5_100 | grep recall: | awk '{print $2}' > greedy_0.5__100.recall

cat ../search/greedy_0.2_ls_100 | grep second: | awk '{print $4}' > greedy_0.2_ls__100.sec
cat ../search/greedy_0.2_ls_100 | grep recall: | awk '{print $2}' > greedy_0.2_ls__100.recall

cat ../search/greedy_0.5_ls_100 | grep second: | awk '{print $4}' > greedy_0.5_ls__100.sec
cat ../search/greedy_0.5_ls_100 | grep recall: | awk '{print $2}' > greedy_0.5_ls__100.recall

python3 recall_sec.py
