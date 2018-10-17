{{ self.title() }}

{{ s('问题描述') }}

定义

$$
f(n, m) = \sum_{i = 0}^m\binom n i
$$

其中

$$
\binom{n}{i} = \frac{n!}{i!(n-i)!}
$$

给定 $l, r, m$，请你对于 $l \le n \le r$，计算出 $f(n, m)$ 的值。

答案对 $P = 10^9 + 7$ 取模。

{{ s('输入格式') }}

{{ self.input_file() }}

一行三个非负整数 $l, r, m$，保证 $m \le l \le r$。

{{ s('输出格式') }}

{{ self.output_file() }}

输出一行 $r - l + 1$ 个整数，第 $i$ 个表示 $f(l + i - 1, m)$ 的值。

{{ s('sample', 1) }}

{{ self.sample_text() }}

{{ s('sample', 2) }}

{{ self.sample_file() }}

该组样例的数据范围同第 3 个测试点。

{{ s('子任务') }}

{{ tbl('data') }}
