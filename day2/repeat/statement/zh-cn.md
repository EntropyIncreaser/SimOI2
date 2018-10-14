{{ self.title() }}

{{ s('问题描述') }}

{{ img('theme.jpeg', size = 0.2, align = 'middle', inline = False, env = ['tex', 'md']) }}

你捡到了一台复读机，这台复读机可以向机器人发号施令。机器人将站在一个二叉树的根上，二叉树是无限延伸的。你将复读机录入一串指令，这串指令单个字符可以是：

* `L`：命令机器人向当前节点的左子走
* `R`：命令机器人向当前节点的右子走
* `U`：命令机器人向当前节点的父亲走（若没有，则命令非法。）

录入指令后，复读机将会把你的指令无限复读下去。比如命令为 `LR`，那么机器人会遵从 `LRLRLRLR...` 一直走下去。

这颗二叉树上有一颗子树上每个节点都埋有宝藏，这颗子树也以整颗二叉树的根为根。机器人到达过的地方如果有宝藏，则会将其开采。如果一个地方没有宝藏，机器人也可以到那里去。机器人也可以反复经过一个地方。

告诉你埋有宝藏的子树，现在请你寻找一条尽量短的指令，使得机器人能够挖掘出所有宝藏。

{{ s('输入格式') }}

{{ self.input_file() }}

一行一个字符串，由 `0123` 中的字符组成，是这颗二叉树的前序遍历。

* `0`：表示这是一个没有儿子的节点。
* `1`：表示这是一个只有左子的节点。
* `2`：表示这是一个只有右子的节点。
* `3`：表示这是一个既有左子又有右子的节点。

{{ s('输出格式') }}

{{ self.output_file() }}

输出一行指令，长度不得超过 4000。

{{ s('sample', 1) }}

{{ self.sample_text() }}

{{ s('sample', 2) }}

{{ self.sample_file() }}

该组样例的数据范围同第 3 个测试点。

{{ s('子任务') }}

{{ tbl('data') }}