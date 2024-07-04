# print 输出
print 默认输出是换行的，如果要实现不换行需要在变量末尾加上 end=""：

```python
#!/usr/bin/python3
 
x="a"
y="b"
# 换行输出
print( x )
print( y )
 
print('---------')
# 不换行输出
print( x, end=" " )
print( y, end=" " )
print()
```

# 多行语句
Python 通常是一行写完一条语句，但如果语句很长，我们可以使用反斜杠 \ 来实现多行语句，例如：
```python
total = item_one + \
        item_two + \
        item_three
```    

# 列表(ArrayList)
创建列表：使用方括号 [] 创建列表。
访问元素：使用索引访问列表中的元素，索引从 0 开始。
修改元素：通过索引可以直接修改列表中的元素。
添加元素：可以使用 append() 方法在列表末尾添加元素，或者使用 insert() 方法在指定位置插入元素。
删除元素：可以使用 remove() 方法删除列表中的特定元素，或者使用 pop() 方法删除指定索引的元素。
列表切片：可以使用切片操作来获取列表的一部分。
列表遍历：可以使用 for 循环遍历列表中的所有元素。


例：

```python
# 创建一个列表
my_list = [1, 2, 3, 'Python', 4.5]

# 访问列表中的元素
print("第一个元素:", my_list[0])

# 修改列表中的元素
my_list[0] = 100
print("修改后的列表:", my_list)

# 在列表末尾添加元素
my_list.append('新增元素')

# 在指定位置插入元素
my_list.insert(1, '插入元素')

# 删除列表中的元素
my_list.remove('Python')  # 删除字符串 'Python'
popped_element = my_list.pop()  # 删除并返回列表的最后一个元素

# 列表切片
sub_list = my_list[1:3]  # 获取索引1到2的元素

# 遍历列表
for item in my_list:
    print(item)

# 获取列表长度
print("列表长度:", len(my_list))

# 清空列表
my_list.clear()

# 检查元素是否存在于列表中
if '新增元素' in my_list:
    print("'新增元素' 在列表中")
```

## 删除列表元素

可以使用 del 语句来删除列表的的元素，如下实例：
```python
(Python 3.0+)
#!/usr/bin/python3
 
list = ['Google', 'Runoob', 1997, 2000]
 
print ("原始列表 : ", list)
del list[2]
print ("删除第三个元素 : ", list)
```
以上实例输出结果：
```python
原始列表 :  ['Google', 'Runoob', 1997, 2000]
删除第三个元素 :  ['Google', 'Runoob', 2000]
```

## 列表拼接
列表还支持拼接操作：
```python
>>> squares = [1, 4, 9, 16, 25]
>>> squares += [36, 49, 64, 81, 100]
>>> squares
[1, 4, 9, 16, 25, 36, 49, 64, 81, 100]
```
# 元组(静态数组)
在 Python 中，==元组（Tuple）是一种不可变的数据结构==，用于存储一系列的元素。元组与列表类似，也是有序的，但一旦创建，元组中的元素就不能被修改，这使得元组在某些情况下比列表更加安全。

元组的概念和作用：
不可变性：元组一旦创建，其内容就不能被更改。这使得元组在多线程环境中更安全，因为它们不需要锁定。
索引：与列表一样，元组中的元素可以通过索引访问，索引从 0 开始。
嵌套：元组可以包含其他元组，形成嵌套结构。
用途：元组常用于保护数据不被更改，以及作为字典的键（因为字典的键必须是不可变类型）。
元组的基本操作：
创建元组：使用圆括号 () 创建元组。如果元组只包含一个元素，需要在元素后面加上逗号 ,，否则 Python 不会将其解释为元组。
访问元素：使用索引访问元组中的元素。
元组方法：虽然元组不可变，但 Python 还是提供了一些方法来操作元组，如 count() 和 index()。
代码示例：
## 创建元组
my_tuple = (1, 2, 3, 4, 5)

## 访问元组中的元素
print("第一个元素:", my_tuple[0])

## 尝试修改元组中的元素（将会失败，因为元组是不可变的）
## my_tuple[0] = 10  # 这将抛出 TypeError

## 元组的索引和切片
print("从索引1开始的切片:", my_tuple[1:4])

## 元组的 count 方法
print("数字2出现的次数:", my_tuple.count(2))

## 元组的 index 方法
print("数字3的索引:", my_tuple.index(3))

## 元组的嵌套
nested_tuple = (1, (2, 3), 4)
print("嵌套元组:", nested_tuple)

## 元组与列表的转换
list_from_tuple = list(my_tuple)
tuple_from_list = tuple([1, 2, 3])

## 使用元组作为字典的键
dict_with_tuple_keys = {(1, 2): 'a pair'}
print("字典的值:", dict_with_tuple_keys[(1, 2)])

在 Python 中，字典（Dictionary）是一种内置的数据结构，用于存储键值对（key-value pairs）。字典是一种非常灵活且功能强大的数据类型，常用于数据存储和检索。


# 字典（就是map）
item/value

字典的概念和作用：
存储键值对：字典以无序的方式存储键值对，其中每个键映射到一个值。
键的唯一性：字典中的键必须是唯一的，不允许重复。
访问速度：字典提供了非常快速的查找速度，即使在包含大量数据的情况下。
灵活性：字典的键可以是任何不可变类型，包括字符串、数字和元组等。
动态性：字典是可变的，可以动态地添加、删除或修改键值对。

字典的基本操作：
创建字典：使用花括号 {} 创建字典，或者使用 dict() 函数。
访问元素：使用键来访问字典中的值，例如 dict[key]。
添加元素：直接通过键来赋值添加新的键值对。
修改元素：通过键来修改对应的值。
删除元素：使用 del 语句或 pop() 方法删除键值对。
遍历字典：可以遍历字典的键、值或键值对。
代码示例：
## 创建一个字典
```python
my_dict = {
    'name': 'Alice',
    'age': 25,
    'is_student': False
}
```
## 访问字典中的元素
print("名字:", my_dict['name'])

## 添加一个新的键值对
my_dict['country'] = 'Wonderland'

## 修改字典中的值
my_dict['age'] = 26

## 删除字典中的键值对
del my_dict['is_student']
## 或者使用 pop 方法
## removed_value = my_dict.pop('country')

## 访问字典的长度（键值对的数量）
print("字典的长度:", len(my_dict))

## 检查键是否存在于字典中
if 'name' in my_dict:
    print("'name' 键存在于字典中")

## 获取字典中的所有键
print("所有键:", my_dict.keys())

## 获取字典中的所有值
print("所有值:", my_dict.values())

## 获取字典中的所有键值对
print("所有键值对:", my_dict.items())

## 遍历字典的键和值
for key, value in my_dict.items():
    print(f"{key}: {value}")

## 使用 get 方法访问字典，如果键不存在可以返回默认值
print("年龄:", my_dict.get('age', '未知'))
print("职业:", my_dict.get('job', '未提供'))

在 Python 中，集合（Set）是一种无序的、不包含重复元素的数据结构。集合基于哈希表实现，因此它提供了高效的成员检查和元素插入操作。

# 集合(无序不重复)
集合的概念和作用：
无序性：集合中的元素没有特定的顺序。
唯一性：集合自动去除重复的元素。
成员检查：集合提供了快速的成员检查，即可以快速判断一个元素是否存在于集合中。
集合操作：支持数学上的集合操作，如并集、交集、差集和对称差集。

集合的基本操作：
创建集合：使用花括号 {} 或 set() 函数创建集合。注意，使用花括号创建时，如果集合中只有一个元素，必须在元素后面加上逗号 ,。
添加元素：使用 add() 方法向集合添加元素。
删除元素：使用 remove() 或 discard() 方法从集合中删除元素。remove() 会在元素存在时删除它并抛出错误，而 discard() 则不会。
集合运算：使用 union(), intersection(), difference(), symmetric_difference() 等方法进行集合运算。
遍历集合：可以使用循环遍历集合中的元素。
代码示例：
## 创建集合
my_set = {1, 2, 3, 4, 5}

## 添加元素
my_set.add(6)

## 尝试添加重复元素
my_set.add(3)  # 集合中不会出现重复的 3

## 删除元素
my_set.remove(4)  # 删除元素 4

## 尝试删除不存在的元素
## my_set.remove(7)  # 这将抛出 KeyError，因为 7 不在集合中
my_set.discard(7)  # 使用 discard 则不会抛出错误

## 集合的长度
print("集合的长度:", len(my_set))

## 成员检查
print("6 是否在集合中:", 6 in my_set)

## 集合运算
set_a = {1, 2, 3}
set_b = {3, 4, 5}

## 并集
print("并集:", set_a.union(set_b))

## 交集
print("交集:", set_a.intersection(set_b))

## 差集
print("差集:", set_a.difference(set_b))

## 对称差集
print("对称差集:", set_a.symmetric_difference(set_b))

## 遍历集合
for element in my_set:
    print(element)

## 将列表转换为集合
list_to_set = set([1, 2, 2, 3, 3])

## 将集合转换为列表
set_to_list = list(my_set)

# 格式化输出
## format() 方法
```python
name = "John"
age = 25

#方式1
greet = "{} is {} years old.".format(name, age)
print(greet)    # Output: John is 25 years old.

#方式2:参数名
greet = "{name} is {age} years old.".format(name="Alice", age=30)
print(greet)    # Output: Alice is 30 years old.

#方式3:数字
pi = 3.14159
print("{:.2f}".format(pi))    # Output: 3.14
```

## f-string
```python
name = "John"
age = 25

#方式1
greet = f"{name} is {age} years old."
print(greet)    # Output: John is 25 years old.

#方式2: 调用函数
def multiply(x, y):
    return x * y
greet = f"x times y is {multiply(3, 4)}"
print(greet)    # Output: 3 times 4 is 12
```

# 文件读写
Python 中的文件操作是编程中常见的任务之一，用于读取和写入文件。以下是一段使用 Python 3 进行文件操作的完整代码示例，以及对每个部分的解释：

```python
#!/usr/bin/python3
from bs4 import BeautifulSoup
import requests
import os

# 设置请求头
headers = {
    "User-Agent":"Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/126.0.0.0 Safari/537.36 Edg/126.0.0.0"
}

try:
    #设置好保存路径和文件名字
    save_path = "D:/python_file/"
    os.makedirs(save_path, exist_ok=True)
    file_name = "豆瓣电影top250.txt"
    save_file = os.path.join(save_path, file_name)


    for num in range(0, 250, 25):
        # 发送请求,content是响应对象
        print("正在获取网页...")
        content = requests.get(f"https://movie.douban.com/top250?start={num}", headers=headers)
        content.raise_for_status()  # 检查响应状态码是否为200，否则抛出异常
        print("网页获取成功！")
        soup = BeautifulSoup(content.text, "html.parser")   #html.parser是解析器,解析content.text,返回soup对象
        all_titles = soup.find_all("span", attrs={"class":"title"})  # 找到所有h3标签
        print(all_titles)

        with open(save_file, "a", encoding="utf-8") as file:
            for title in all_titles:
                if "/" not in title.text:  # 排除非电影标题
                    print(title.string)
                    file.write(title.string + "\n")
        file.close()
        print(f"保存成功！文件路径：{save_file}")


except requests.exceptions.RequestException as e:
    print(f"Error: {e}")
```



这段代码演示了如何在 Python 3 中打开文件、写入文本、关闭文件、再次打开文件以及读取内容。文件操作是 Python 中的基础技能，适用于数据处理、日志记录等多种场景。

## 附录
+ w	打开一个文件只用于写入。如果该文件已存在则打开文件，并**从开头开始编辑**，即原有内容会被删除。如果该文件不存在，创建新文件。
+ r	打开一个文件用于只读。文件指针将会放在文件的开头。
+ a	==追加==。如果该文件已存在，文件指针将会放在文件的结尾。也就是说，新的内容将会被写入到已有内容之后。如果该文件不存在，创建新文件进行写入。
+ 


## 在桌面创建文件
```python
#!/usr/bin/python3
import os

desktop_path = os.path.join(os.path.expanduser("~"), "Desktop")

filename = "example.txt"
file_path = os.path.join(desktop_path, filename)

with open(file_path, "w") as file:
    file.write("Hello, World!")
    file.write("\n")
    file.write("This is an example file.")


print("File created at:", file_path)
```

# 正则表达式
所有转义字符集合：
https://www.runoob.com/regexp/regexp-metachar.html


>\^[a-zA-Z0-9_-]{3,15}$

+ ^ 表示开始
+ [a-zA-Z0-9_-] 表示匹配包含所有小写、所有大写和0-9的数字和连字符-的字符串
+ {3,15} 字符串长度3-15
+ $ 结束符号

## 字符类
[^ABC] 表示匹配除了ABC之外的任意字符
[\s\S] 表示匹配任意字符，包括空格、换行符等
[\s\S] 表示匹配任意字符，包括空格、换行符等
[\d+]  匹配任意一个或多个阿拉伯数字（0 到 9）。等价于 [0-9]
[\w+]     匹配任意一个或多个单词字符（字母、数字、下划线）。等价于 [a-zA-Z0-9_]

## 非字符
\f	匹配一个换页符。
\n	匹配一个换行符。
\r	匹配一个回车符。
\t	匹配一个制表符。

## 限定符号（辅助）

. 表示匹配除换行符以外的任意字符
\* 匹配零次或多次: zo* 匹配 "z" 或 "zooooo..."  
\+ 匹配一次或多次: zo+ 匹配 "zo" 或 "zoo"  
? 匹配零次或一次: do(es)? 匹配 "do" 或 "does"  

{n} 匹配确定次数: o{2} 匹配 "food" 中的 "oo"  
{n,} 至少匹配n次: o{2,} 匹配 "foooood" 中的 "ooo"  
{n,m} 匹配n到m次: o{1,3} 匹配 "fooooood" 中的 "ooo"

### 贪婪匹配/非贪婪匹配
>\<h1>RUNOOB-菜鸟教程</h1>

+ 贪婪
`/<.*>/` 贪婪匹配，匹配所有字符，`<h1>RUNOOB-菜鸟教程</h1>`

+ 非贪婪
`/<.*?>/` 非贪婪匹配，只匹配第一个字符，`<h1>`
OR `/<w+?>/`

## 边界匹配

^ 匹配字符串的开始
$ 匹配字符串的结束
\b 匹配一个单词的边界
\B 匹配非单词边界

### 示例

```python
import re

# 匹配用户名
pattern = r"^[a-zA-Z0-9_-]{3,15}$"
username = "runoob"
if re.match(pattern, username):
    print("用户名合法")
else:
    print("用户名非法") 
# 输出：用户名合法

# 匹配手机号
pattern = r"^1[3-9]\d{9}$"  # 匹配以13、14、15、16、17、18、19开头的手机号,\d表示任意数字
#{9} 是量词，表示前面的元素（\d）必须出现恰好 9 次。也就是，手机号在 1 和 [3-9] 之后还需要有 9 位数字。
phone = "13812345678"
if re.match(pattern, phone):
    print("手机号合法")
else:
    print("手机号非法")

# 匹配邮箱
pattern = r"^\w+@\w+\.[a-z]{2,3}$"
#[a-z]{2,3}：匹配由小写字母组成的2到3个字符的字符串。
email = "runoob@runoob.com"
```

## 选择
正则表达式中的选择（也称为“或”操作）允许你指定一系列可能的字符或模式，匹配输入字符串中的任何一个。这种功能通过圆括号 () 和竖线 | 符号结合使用来实现。下面详细讲解选择的概念、用法，并通过代码举例来说明。

+ 概念
在正则表达式中，选择操作符 | 用于分隔两个或多个可能的匹配项。当正则表达式引擎在输入字符串中查找匹配项时，它会尝试匹配 | 符号左边的模式，如果失败，则尝试匹配右边的模式，依此类推。

+ 用法
基本用法：(表达式1|表达式2|...)
这意味着匹配 表达式1 或 表达式2 或 ... 中的任何一个。

代码举例
```python
import re  
  
# 示例1：匹配单词 "cat" 或 "dog"  
text = "I have a cat and a dog."  
pattern = r'\b(cat|dog)\b'  # \b 表示单词边界  
matches = re.findall(pattern, text)  
print(matches)  # 输出: ['cat', 'dog']  
  
# 示例2：匹配数字 1 或 2 或 3 开头的电话号码  
text = "Contact us at 123-4567 or 234-5678 or 345-6789."  
pattern = r'\b(1|2|3)\d{2}-\d{4}\b'  # \d 表示数字  
matches = re.findall(pattern, text)  
print(matches)  # 输出: ['123-4567', '234-5678', '345-6789']  
  
# 示例3：匹配字符串 "apple" 或 "banana" 的完整单词  
text = "I like apples and bananas."  
pattern_both = r'\b(apples?|bananas?)\b'
matches = re.findall(pattern, text)  
print(matches)  # 输出: ['apples', 'bananas'] 
#这里的 s? 是一个量词，表示 "s" 字符可以出现零次或一次。因此，apples? 可以匹配 "apple" 或 "apples"，同样地，bananas? 可以匹配 "banana" 或 "bananas"。
```

## 辅助找出匹配项
在正则表达式中，?=, ?<=, ?!, ?<! 这四个操作符被称为“前瞻”（lookahead）和“后顾”（lookbehind）断言。它们不消耗（即不移动正则表达式引擎的指针）任何字符，只用于判断某个位置是否符合特定的条件。下面我将详细解释这些概念，并给出代码示例。

### 1. exp1(?=exp2)
这个断言用于查找 exp1 后面紧跟着 exp2 的位置，但只匹配 exp1，不消耗 exp2。


代码举例：

```python
import re  
  
text = "He is a good boy, she is a good girl."  
pattern = r'\bgood(?= girl)\b'  # 查找后面紧跟" girl"的"good"  
matches = re.findall(pattern, text)  
print(matches)  # 输出: ['good']，只匹配了"good girl"中的"good"
```
### 2. (?<=exp2)exp1：
这个断言用于查找 exp2 后面紧跟着 exp1 的位置，但只匹配 exp1，不消耗 exp2。
代码举例（假设使用的环境支持后顾断言）：

```python
import re  
  
text = "He is a good boy, she is a good girl."  
pattern = r'(?<=good )girl'  # 查找前面是"good "的"girl"  
matches = re.findall(pattern, text)  
print(matches)  # 输出: ['girl']，只匹配了"good girl"中的"girl"
```
### 3. exp1(?!exp2)
这个断言用于查找 exp1 后面不是 exp2 的位置，只匹配 exp1。

代码举例：

```python
import re  
  
text = "He is a good boy, she is a bad girl."  
pattern = r'\bgood(?! girl)\b'  # 查找后面不是" girl"的"good"  
matches = re.findall(pattern, text)  
print(matches)  # 输出: ['good']，只匹配了"good boy"中的"good"
```
### 4. (?<!exp2)exp1
这个断言用于查找 exp2 后面不是紧跟着 exp1 的位置，但只匹配 exp1。

代码举例（假设使用的环境支持负向后顾断言）：

```python
import re  
  
text = "He is a good boy, she is a bad girl."  
pattern = r'(?<!bad )girl'  # 查找前面不是"bad "的"girl"  
matches = re.findall(pattern, text)  
print(matches)  # 输出: ['girl']，只匹配了"good girl"中的"girl"
```

## 反向引用
==运用已经找到的字符串再进行筛选子字符串==



想象一下你正在读一本故事书，书中提到了“小明”这个名字很多次。每次提到“小明”时，你都知道是在说同一个人。在正则表达式中，反向引用的作用就像是你记住“小明”这个名字，然后在书的后面部分再次遇到“小明”时，你能认出这是之前提到的那个人。

具体来说，当你在正则表达式中用一个圆括号()包围一部分模式（比如“小明”），正则表达式引擎就会记住这部分匹配到的内容（即“小明”）。然后，你可以在正则表达式的后续部分使用\1（因为这是第一个被圆括号包围的模式，所以编号是1）来引用之前记住的内容。如果后面出现的文本与前面记住的内容相同，那么这部分文本就会被匹配。

1. 查找重复的字符串
```python
复制代码
import re  
  
# 定义待搜索的字符串  
text = "Is is the cost of of gasoline going up up?"  
# 定义正则表达式，查找重复的单词  
pattern = r'\b(\w+)\s+\1\b'  
# 使用re.findall()查找所有匹配的重复单词  
matches = re.findall(pattern, text)  
  
# 输出匹配结果  
print(matches)  # 输出: ['is', 'of', 'up']  
  
# 解释：  
# \b 表示单词边界  
# (\w+) 捕获一个或多个单词字符（字母、数字或下划线），作为第一个子匹配  
# \s+ 匹配一个或多个空白字符  
# \1 引用第一个子匹配，即之前捕获的单词  
# \b 再次确保单词边界
```
+ `\s` 在r'\b(\w+)\s+\1\b'中的作用是保证前面的(w+)获取的是一个独立的单词，通过识别单词后面的空格来实现（就是\s）。
否则，appleapple也会被识别为一个重复的字符串

2. 分解URI

```python

import re  
  
# 定义待分解的URI  
uri = "https://www.runoob.com:80/html/html-tutorial.html"  
# 定义正则表达式，用于分解URI  
pattern = r'(\w+)://([^/:]+)(:\d*)?([^# ]*)'  
# 使用re.match()进行匹配（注意，这里只匹配整个字符串的开始部分，若需全局匹配可用re.findall()或re.finditer()）  
match = re.match(pattern, uri)  
  
if match:  
    # 匹配成功，输出各个分组  
    protocol = match.group(1)  
    domain = match.group(2)  
    port = match.group(3) if match.group(3) else '默认端口'  # 如果端口不存在，则输出默认端口  
    path = match.group(4)  
      
    print(f"协议: {protocol}")  
    print(f"域地址: {domain}")  
    print(f"端口: {port}")  
    print(f"路径: {path}")  
else:  
    print("URI格式不正确")  
  
# 输出结果（假设URI格式正确）：  
# 协议: https  
# 域地址: www.runoob.com  
# 端口: :80  
# 路径: /html/html-tutorial.html  
  
# 解释：  
# (\w+) 捕获协议部分  
# :// 是URI中固定的一部分  
# ([^/:]+) 捕获域地址部分  
# (:\d*)? 捕获端口号部分，整个部分是可选的  
# ([^# ]*) 捕获路径和/或页信息部分
```

1. ([^/:]+) 捕获域地址部分
^ 和 : 在这个上下文中并不直接作用于 [^/:]+，因为它们是作为整个正则表达式的一部分被理解的，而不是这个特定捕获组的直接部分。但我们可以忽略它们在这个捕获组解释中的直接作用，因为它们在这个上下文中主要用于分隔不同的部分。
[^/:]+ 是一个字符类（character class），它匹配一个或多个不是 / 或 : 的字符。
^ 在字符类的开头表示“非”（negation），所以 [^...] 匹配不在方括号内的任何字符。
/: 指定了不想匹配的字符，即 / 和 :。
+ 表示前面的字符类（在这个情况下是“非/:`”的字符）可以出现一次或多次。
因此，([^/:]+) 会匹配从协议部分（如http://）之后开始，直到遇到下一个 / 或 :（通常是端口号前的分隔符，如果端口号存在的话）之前的所有字符。这部分通常对应于域地址（如www.example.com）。
2. (:\d*)? 捕获端口号部分，整个部分是可选的
: 是一个字面量字符，表示它本身。在URI中，端口号（如果有的话）紧跟在域地址后面，由冒号分隔。
\d 匹配任何十进制数字（等同于 [0-9]）。
* 表示前面的字符（在这个情况下是 \d，即数字）可以出现零次或多次。这意味着端口号部分可以是空的（即没有指定端口号），也可以是一个或多个数字。
(:\d*) 是一个捕获组，它匹配一个冒号后跟零个或多个数字。
? 使得整个 (:\d*) 捕获组成为可选的。这意味着URI中可能不包含端口号部分，正则表达式仍然可以匹配。
3. ([^# ]*) 捕获路径和/或页信息部分
[^# ] 是一个字符类，它匹配任何不是 # 或空格的字符。这个选择是为了排除URI中可能出现的片段标识符（以 # 开头）和可能由空格分隔的额外部分（尽管在标准的URI中空格通常会被编码）。
* 表示前面的字符类（在这个情况下是“非#空格”的字符）可以出现零次或多次。这允许匹配空路径（即URI只包含域地址和可能的端口号），或者包含任意字符序列的路径和/或页信息。
([^# ]*) 会匹配从最后一个 /（如果存在的话）之后开始，直到URI末尾或遇到 # 字符之前的所有字符。这部分通常对应于URI的路径和/或页信息（如/path/to/page.html）。
---

# 爬虫
## 豆瓣网站
这里修改响应头是为了伪装，让服务器认为发送请求的是浏览器而不是爬虫程序
```python
#!/usr/bin/python3

import requests
#响应头
headers = {
    "User-Agent":"Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/126.0.0.0 Safari/537.36 Edg/126.0.0.0"
}
#响应体
response = requests.get("https://movie.douban.com/top250",headers = headers)
if response.ok:
    print(response.text)
else:
    print("Error")
```

## python细则
### match&search
re.match 只匹配字符串的开始，如果字符串开始不符合正则表达式，则匹配失败，函数返回 None，
而 re.search 匹配整个字符串，直到找到一个匹配。

```python
#!/usr/bin/python3
 
import re
 
line = "Cats are smarter than dogs"
 
matchObj = re.match( r'dogs', line, re.M|re.I)
if matchObj:
   print ("match --> matchObj.group() : ", matchObj.group())
else:
   print ("No match!!")
 
matchObj = re.search( r'dogs', line, re.M|re.I)
if matchObj:
   print ("search --> matchObj.group() : ", matchObj.group())
else:
   print ("No match!!")
```
结果：
No match!!
search --> matchObj.group() :  dogs

### compile

==编译一个正则表达式，使其可以被多次使用，提高效率==

+ 格式
```python
re.compile(pattern, flags=0)
```
pattern：一个字符串形式的正则表达式。
flags：可选参数，用于控制正则表达式的匹配方式，如是否忽略大小写、是否多行匹配等。常见的标志位有re.IGNORECASE（或re.I，忽略大小写）、re.MULTILINE（或re.M，多行匹配）等。

+ 搭配match和search使用，例如
```python
match = email_pattern.search(text)  
  
# 判断是否找到了匹配项  
if match:  
    # 如果找到了，使用match对象的group方法获取匹配的字符串并打印出来  
    print("Found email:", match.group())  
else:  
    # 如果没有找到匹配项，打印提示信息  
    print("No email found.")  
```
### findall
在字符串中找到正则表达式所匹配的所有子串，并返回一个列表，如果有多个匹配模式，则返回元组列表，如果没有找到匹配的，则返回空列表。

**注意： match 和 search 是匹配一次 findall 匹配所有。**

## 修饰符
re.I	使匹配对大小写不敏感
re.M	多行匹配，影响 ^ 和 $
re.X	忽略空格和注释


## 爬取价格

```python
#!/usr/bin/python3
#!/usr/bin/python3
from bs4 import BeautifulSoup
import requests

# 设置请求头
headers = {
    "User-Agent":"Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/126.0.0.0 Safari/537.36 Edg/126.0.0.0"
}

try:
    # 发送请求,content是响应对象
    content = requests.get("https://books.toscrape.com/", headers=headers)
    content.raise_for_status()  # 检查响应状态码是否为200，否则抛出异常
    soup = BeautifulSoup(content.text, "html.parser")   #html.parser是解析器,解析content.text,返回soup对象
    #此时soup是整个网站的html文本
        # 找到所有价格的<p>标签，这里的第二个是可选参数，表示class属性为"price_color"的标签
    all_prices = soup.find_all("p", class_="price_color")
    for price in all_prices:
        #此时price是每一个价格的标签,例如其中一项：<p class="price_color">Â£57.25</p>
        print(price.string[2:])  # string返回两个<>之间的文本,这里[2:]是去掉前面的Â£符号
except requests.exceptions.RequestException as e:
    print(f"Error: {e}")

```

### 步骤
1. 导入requests和BeautifulSoup库
2. 设置请求头
3. 发送请求，获取响应对象
4. 检查响应状态码是否为200，否则抛出异常
5. 使用BeautifulSoup解析响应内容，得到soup对象
6. 找到所有价格的<p>标签，这里的第二个是可选参数，表示class属性为"price_color"的标签
7. 遍历所有价格标签，打印出价格

## 获取书名
```python
#!/usr/bin/python3
from bs4 import BeautifulSoup
import requests
import os

# 设置请求头
headers = {
    "User-Agent":"Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/126.0.0.0 Safari/537.36 Edg/126.0.0.0"
}

try:
    #设置好保存路径和文件名字
    save_path = "D:/python_file/"
    os.makedirs(save_path, exist_ok=True)
    file_name = "豆瓣电影top250.txt"
    save_file = os.path.join(save_path, file_name)


    for num in range(0, 250, 25):
        # 发送请求,content是响应对象
        print("正在获取网页...")
        content = requests.get(f"https://movie.douban.com/top250?start={num}", headers=headers)
        content.raise_for_status()  # 检查响应状态码是否为200，否则抛出异常
        print("网页获取成功！")
        soup = BeautifulSoup(content.text, "html.parser")   #html.parser是解析器,解析content.text,返回soup对象
        all_titles = soup.find_all("span", attrs={"class":"title"})  # 找到所有h3标签
        print(all_titles)

        with open(save_file, "a", encoding="utf-8") as file:
            for title in all_titles:
                if "/" not in title.text:  # 排除非电影标题
                    print(title.string)
                    file.write(title.string + "\n")
        print(f"保存成功！文件路径：{save_file}")


except requests.exceptions.RequestException as e:
    print(f"Error: {e}")



```

## 保存文件
1. 导入os库
2. 创建保存文件的目录（左斜杠/）
3. 指定保存文件的路径os.makedirs(save_path, exist_ok=True)
4. 指定文件名
5. 拼接文件路径os.path.join(保存路径，文件名字) 
6. 写入文件
  >with open(文件路径，写入模式) as file: 
   file.write("写入内容")

```python
import os

# 指定保存文件的路径
save_path = "/path/to/save"

# 创建保存文件的目录
os.makedirs(save_path, exist_ok=True)

# 文件名
file_name = "example.txt"

# 拼接文件路径
file_path = os.path.join(save_path, file_name)

# 写入文件
with open(file_path, "w") as file:
    file.write("Hello, world!")

print(f"文件保存到：{file_path}")
```

## 爬美女
```python
#1.获取子页面链接
#2.获取图片src链接
#3.下载图片

import requests
from bs4 import BeautifulSoup
import os
import time

headers = {
    "User-Agent":"Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/126.0.0.0 Safari/537.36 Edg/126.0.0.0"
}
try:

    save_path = "D:/python_file/优美爬虫/"  # 设置保存路径
    os.makedirs(save_path, exist_ok=True)  # 创建文件夹
    # file_name = "优美爬虫"   # 设置文件名
    # save_path = os.path.join(save_path, file_name)   # 拼接路径

    for index in (2,72,1):
        #主链接
        resp = requests.get(f"http://www.umeituku.com/bizhitupian/meinvbizhi/{index}.htm", headers=headers)
        resp.raise_for_status()
        print("获取链接成功...")
        resp.encoding = "utf-8"   #设置编码
        #print(resp.text)

        main_page = BeautifulSoup(resp.text, "html.parser")   #解析网页
        print("解析网页成功...")

        #这里的class后面一定要加个_
        alist = main_page.find("div", class_ = "TypeList").find_all("a")   #获取子页面链接列表
        #print(alist)


        for a in alist:
            #子链接
            href = a.get("href")   #获取子页面链接

            resp2 = requests.get(href)
            resp2.raise_for_status()
            print("获取子页面链接成功...")
            resp2.encoding = "utf-8"   #设置编码

            main_page2 = BeautifulSoup(resp2.text, "html.parser")   #解析子页面
            print("解析子页面成功...")

            blist = main_page2.find_all("p", align = "center")   #获取图片src链接列表
            print(blist)

            for img in blist:
                src = img.find("img").get("src")   #获取图片src链接
                print(src)

                #下载图片
                resp3 = requests.get(src)   #获取图片jpg文件
                zijie = resp3.content   #获取图片二进制数据
                #网址后部分为名字
                name = src.split("/")[-1]   #获取图片名字

                save_path = "D:/python_file/优美爬虫/"   # 刷新前半段保存路径
                save_path = os.path.join(save_path, name)  # 拼接路径
                with open(save_path, mode="wb") as f:
                    f.write(zijie)   #写入图片数据
                print("下载图片成功...")
                time.sleep(1)

except requests.exceptions.RequestException as e:
    print("获取链接失败",e)
```
