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

>\^[a-zA-Z0-9_-]{3,15}$
+ ^ 表示开始
+ [a-zA-Z0-9_-] 表示匹配包含所有小写、所有大写和0-9的数字和连字符-的字符串
+ {3,15} 字符串长度3-15
+ $ 结束符号

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
    all_titles = soup.find_all("h3")  #找到所有h3标签
    for title in all_titles:
        link = title.find("a")  #找到所有a标签
        print(link.string)  #打印出所有书名,string是两个<>之间的文本
        #或者写成print(link.get("title"))  #打印出所有书名,get("title")是获取title属性的值
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