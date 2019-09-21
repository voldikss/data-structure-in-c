.PHONY: run clean
run: assets/graph.dat assets/topsort.dat assets/shortest_path.dat
	@echo "############# 图的建立及其操作 #############"
	@gcc test_graph.c graph.c -o a.out && ./a.out < ./assets/graph.dat
	@echo "################# 拓扑排序 #################"
	@gcc test_topsort.c graph.c topsort.c queue.c -o a.out && ./a.out < ./assets/topsort.dat
	@echo "################# 最短路径 #################"
	@gcc test_shortest_path.c graph.c shortest_path.c queue.c -o a.out && ./a.out < ./assets/shortest_path.dat
	@echo "################ 最小生成树 ################"
	@gcc test_mst.c graph.c mst.c -o a.out && ./a.out < ./assets/mst.dat
clean:
	rm -f *.o
	rm -f *.out
