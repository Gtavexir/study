package lsh;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.StringReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

import org.apache.hadoop.conf.Configuration;
import org.apache.hadoop.conf.Configured;
import org.apache.hadoop.fs.Path;
import org.apache.hadoop.io.IntWritable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Job;
import org.apache.hadoop.mapreduce.Mapper;
import org.apache.hadoop.mapreduce.Reducer;
import org.apache.hadoop.mapreduce.lib.input.FileInputFormat;
import org.apache.hadoop.mapreduce.lib.output.FileOutputFormat;
import org.apache.hadoop.util.Tool;
import org.apache.hadoop.util.ToolRunner;

public class LshCosineMR extends Configured implements Tool{
	public int run(String[] args) throws Exception {
		
		String input = args[0];
        String output = args[1];
		
		Configuration conf = getConf();
		
		int r = conf.getInt("r", 0);
		int d = conf.getInt("d", 0);
		
		// random vector generation and set conf
		ArrayList<ArrayList<Double>> vectors = new ArrayList<ArrayList<Double>>();  
		for(int i = 0; i < r; i++) {
			ArrayList<Double> vector = new ArrayList<Double>();
			for(int j = 0; j < d; j++)
				vector.add(Math.random() * 2 - 1);
			vectors.add(vector);
		}
		String str_vec = "";
		for(int i = 0; i < r; i++) {
			for(int j = 0; j < d; j++)
				str_vec += Double.toString(vectors.get(i).get(j)) + " ";
			str_vec += "\n";
		}
		conf.set("vector", str_vec);
		
		Job job = Job.getInstance(getConf());
		job.setJarByClass(LshCosineMR.class);
		
		job.setMapperClass(Map.class);
        job.setReducerClass(Red.class);
        
        job.setMapOutputKeyClass(Text.class);
        job.setMapOutputValueClass(IntWritable.class);
        
        job.setOutputKeyClass(Text.class);
        job.setOutputValueClass(Text.class);
        
        FileInputFormat.addInputPath(job, new Path(input));
        FileOutputFormat.setOutputPath(job, new Path(output));

        job.waitForCompletion(true);
		
		return 0;
	}
	
	public static class Map extends Mapper<Object, Text, Text, IntWritable> {
		
		Text ok = new Text(); // hashing
		IntWritable ov = new IntWritable(-1); // node idx
		String vector; // random vector
		ArrayList<ArrayList<Double>> vectors = new ArrayList<ArrayList<Double>>();
		int r, d; // vector_len, dimension
		
		@Override
		protected void setup(Context context) throws IOException, InterruptedException {
			Configuration conf = context.getConfiguration();
			
			// get random vector
			vector = conf.get("vector");
			BufferedReader br = new BufferedReader(new StringReader(vector));
			String line;
			while((line = br.readLine()) != null) {
			    ArrayList<Double> tmp = new ArrayList<Double>();
			    StringTokenizer st = new StringTokenizer(line);
			    while(st.hasMoreTokens())
			    	tmp.add(Double.parseDouble(st.nextToken()));
			    vectors.add(tmp);
			}
			
			r = conf.getInt("r", 0);
			d = conf.getInt("d", 0);
		}
		
		@Override
		protected void map(Object key, Text value, Context context) throws IOException, InterruptedException {
			
			StringTokenizer st = new StringTokenizer(value.toString());
			ov.set(Integer.parseInt(st.nextToken())); // set outputkey(node idx)
			String hash = "";
			
			
			ArrayList<Double> target = new ArrayList<Double>();
			while(st.hasMoreTokens())
				target.add(Double.parseDouble(st.nextToken()));
			for(int i = 0; i < r; i++) {
				Double dot = 0.0;
				for(int j = 0; j < d; j++)
					dot += (target.get(j) * vectors.get(i).get(j));
				if(dot < 0)
					hash += "0";
				else
					hash += "1";
			}
			ok.set(hash);
			
			context.write(ok, ov);
		}
	}
	
	public static class Red extends Reducer<Text, IntWritable, Text, Text> {
		
		Text ov = new Text();
		
		@Override
		protected void reduce(Text key, Iterable<IntWritable> value, Context context) throws IOException, InterruptedException {
			String index = "";
			
			for(IntWritable v : value)
				index += (v.toString() + " ");
			
			ov.set(index);
			
			context.write(key, ov);
		}
	}
}
