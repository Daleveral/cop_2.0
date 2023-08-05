# Cop-2.0
C++ 警察抓小偷 2.0 相较于之前的版本,做了较大的改变,体现在以下方面 :

1.优化了类的结构,删除了一些冗余的片段,如无用的变量或和判断语句.

2.新增功能: 让用户自主选择小偷的数量,增强游戏难度和可玩性. 实现:让game类中的指针enemy*指向main函数 中的小偷数组(传递参数),将判断小偷移动的 flag变量封装到enemy类内,变量 if_exist 判断其是否存在. 将game类中的update函数分为 updateWithInput ,update_bullet 与 update_enemy 默认小偷数量为8个,用户在main函数键入小偷数值时,便激活几个小偷,for循环遍历小偷数组时即 循环8次,每次都检查 if_exist 再执行操作

3.新增功能: 警察类cop中添加了 face 变量,描述其三种状态:　携枪标志为　★　，携镐标志为一个尖锐箭头， （因为游戏 terraria 中铁镐能破壁 ~） , 携盾状态标志为⊙,可以建立新的墙阻止小偷. 三种状态的切换,为键盘输入 f,q,e 其实现代码和 wasd ,ijkl 都置于 updateWithInput 函数中. 新的两种标记添加到枚举的 MAP_POINT 中,方便打印

IDE:  DEV-C++ ( MinGW GCC10.3.0 32-bit Debug )

