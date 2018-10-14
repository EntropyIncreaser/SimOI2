{{ self.title() }}

{{ s('问题描述') }}



{{ s('输入格式') }}

{{ self.input_file() }}

第一行一个正整数 $n$，表示账单中的菜品数量。

接下来 $n$ 行，其中第 $i$ 行一个正整数，表示第 $i$ 个菜品的价格。

{{ s('输出格式') }}

{{ self.output_file() }}

输出一行一个正整数，为菜品价格的总和。

{{ s('sample', 1) }}

{{ self.sample_text() }}

{{ s('sample', 2) }}

{{ self.sample_file() }}

该组样例的数据范围同第 3 个测试点。

{{ s('子任务') }}

{{ tbl('data') }}
