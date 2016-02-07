Int64 ToInt64(Int32 x):
    Int64 ret
    ir:
        %1 = load i32, i32* %x
        %2 = sext i32 %1 to i64
        store i64 %2, i64* %ret
    return ret

[Operator("+")]
Int64 add(Int64 x, Int64 y):
    Int64 ret
    ir:
        %1 = load i64, i64* %x
        %2 = load i64, i64* %y
        %3 = add i64 %1, %2
        store i64 %3, i64* %ret
    return ret

[Operator("+")]
Int64 add(Int32 x, Int64 y):
    Int64 x_new = x.ToInt64()
    return x_new + y

[Operator("+")]
Int64 add(Int64 x, Int32 y):
    Int64 y_new = y.ToInt64()
    return x + y_new