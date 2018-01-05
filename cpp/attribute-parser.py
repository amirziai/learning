import sys

def attribute_parser(lines):
	n, q = map(int, lines[0].split())
	stack = []
	output = []
	values = {}
	
	for line in lines[1:n+1]:
		if line[1] == '/':
			stack.pop()
		else:
			line_ = line[1:-1]
			tag_name, *attributes = line_.split()
			stack.append(tag_name)

			for i in range(int(len(attributes) / 3)):
				key = '.'.join(stack) + '~' + attributes[i*3]
				values[key] = attributes[i*3 + 2].replace('"', '')

	for query in lines[n+1:]:
		output.append(values.get(query, 'Not Found!'))

	return output

if __name__ == '__main__':
	problem = sys.argv[1]
	f = attribute_parser
	file_base = 'resources/{}-{}'
	file_path_input = file_base.format(problem, 'input')
	file_path_expected = file_base.format(problem, 'output')
	contents = open(file_path_input).read().splitlines()
	output = f(contents)
	expected = open(file_path_expected).read().splitlines()
	assert output == expected, "Wrong"
