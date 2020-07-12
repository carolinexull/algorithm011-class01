学习笔记

递归模板：
def recursion(level, param1, param2,...):
	if level > MAX_LEVEL:
		process_result
		return
		
	process(level, data...)
	
	self.recursion(level+1, p1, ...)

递归的要点：
1）不要人肉递归，直接从函数本身开始；
2）找最近重复子问题；
3）数学归纳法思维