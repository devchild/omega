Int32 ToInt32(Int64 x):
    Int32 ret
    ir:
        %1 = load i64, i64* %x
        %2 = trunc i64 %1 to i32
        store i32 %2, i32* %ret
    return ret

[Operator("+")]
Int32 add(Int32 x, Int32 y):
    Int32 ret
    ir:
        %1 = load i32, i32* %x
        %2 = load i32, i32* %y
        %3 = add i32 %1, %2
        store i32 %3, i32* %ret
    return ret