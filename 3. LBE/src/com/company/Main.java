package com.company;

import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuffer sb = new StringBuffer();
        Queue<Integer> queue = new LinkedList<>();
        int t = Integer.parseInt(br.readLine());
        while(t>0) {
            StringTokenizer st = new StringTokenizer(br.readLine(), " ");
            int n = Integer.parseInt(st.nextToken());
            int idx = Integer.parseInt(st.nextToken());
            int cnt = 0;
            st = new StringTokenizer(br.readLine(), " ");
            int[] priority = new int[n];
            for(int i=0;i<n;i++) {
                queue.add(i);
                priority[i] = Integer.parseInt(st.nextToken());
            }
            while(!queue.isEmpty()) {
                if(priority_TF(queue.peek(),priority)) {
                    int poll = queue.poll();
                    priority[poll] = 0;
                    cnt++;
                    if(poll == idx) break;
                }
                else queue.add(queue.poll());
            }
            sb.append(cnt);
            if(t>1) sb.append("\n");
            queue = new LinkedList<>();
            t--;
        }
        System.out.println(sb);
    }
    public static boolean priority_TF(int n,int[] priority) {
        int max = priority[n];
        for(int i= 0;i< priority.length;i++) {
            if(priority[i] > max) return false;
        }
        return true;
    }
}
