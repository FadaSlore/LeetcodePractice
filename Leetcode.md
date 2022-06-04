# Leetcode


## [51. N-Queens](https://leetcode.com/problems/n-queens/) - [Solution]()
- 給定`n`，輸出以`n*n`為棋盤的皇后棋擺放法
    - 皇后棋擺放法：同一行、列、斜角不能存在兩個皇后棋
- 技巧：
    - 注意到`1 <= n <= 9`：可以使用`int`儲存棋盤擺放狀態
    - 因為按照`row`枚舉，需要儲存的狀態有：`columns`、`diagonals_forward`、`diagonals_backward`
    - 計算對當前狀態的可放位置，等同於對下列兩項取 AND（`&`）：
        - `(1<<n)-1`（即，有`n`個`1`）
        - 上述三個儲存狀態（`columns`、`diagonals_forward`、`diagonals_backward`）沒佔用的位置：取非（`~`）
    - 列舉可以放的位置：
        - `x&(-x)`：獲得`x`的二進制表示中最低位`1`的位置
            - 該位置即為當前`row`中皇后棋要放的`column`值
        - `x&(x-1)`：將`x`二進制表示中最低位`1`變為`0`


## [303. Range Sum Query - Immutable](https://leetcode.com/problems/range-sum-query-immutable/) - [Solution](/Problems/303_Range_Sum_Query_Immutable.cpp)
- 給定一數組`nums`，實現求**區間**和的 function
- 技巧：預先計算好所有前綴和，再根據給的 index 求出對應值

## [304. Range Sum Query 2D - Immutable](/Problems/304_Range_Sum_Query_2D_Immutable.cpp)
- 相關題：[303](#303-range-sum-query---immutable)
- 給定一數組`matrix`，實現求**區域**和的 function
- 技巧：預先計算好**二維**前綴和，再根據給的行列 index 求出對應值
    - 注意更新及回傳的加減（加上沒有的、減去重疊的）— 集合概念

## [450. Delete Node in a BST](/Problems/450_Delete_Node_in_a_BST.cpp)
- 給定一個二元樹根節點`root`與一數`key`，若`key`存在於此二元數內，則刪除並重組二元樹，回傳新的根節點
- 技巧：回溯法，在過程中記錄所尋找的點的**父節點**
    1. 對`key`節點**右**子樹的所有節點尋找最小值節點（最**左**葉節點）
    2. 對`key`節點**左**子樹的所有節點尋找最大值節點（最**右**葉節點）
    - 需注意的是，當`change_parent`（上述之父節點）與`key`節點（`target`）為同一個節點時，轉換的左右子樹會不同

## [829. Consecutive Numbers Sum](/Problems/829_Consecutive_Numbers_Sum.cpp)
- 給定一數`n`，求連續正整數和為`n`的組數
- 技巧：從`x`到`x+k-1`（`k`個數），和為`n`
    - `(2x+k-1)*k=2n` → 對可整除`2n`的`k`，求出是否存在正整數`x`滿足此式

## [867. Transpose Matrix](/Problems/867_Transpose_Matrix.cpp)
- 給定矩陣`matrix`，輸出轉置（transpose）矩陣

## [929. Unique Email Addresses](https://leetcode.com/problems/unique-email-addresses/) - [Solution](/Problems/929_Unique_Email_Addresses.cpp)
- 給定一組郵件地址`emails`，判斷其中有多少個不同的地址
    - 郵件地址分為`local`與`domain`
        - `local`：由英文小寫字母與`.`、`+`組成，遇`.`忽略，遇`+`忽略其後所有字母符號
        - `domain`：由英文小寫字母與`.`組成，組成不同則不同

