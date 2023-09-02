% 测试matlab生成dll，并且这里用的文件名跟函数名不一致
function [C,D] = matAdd(A, B)
C = A+B;
D = A-B;
end