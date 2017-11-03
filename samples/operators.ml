[Operator("==")]
Bool Equals(Int32 x, Int32 y):
    Int1 ret
    ir:
        %1 = load i32, i32* %x
        %2 = load i32, i32* %y
        %3 = icmp eq i32 %1, %2
        store i1 %3, i1* %ret
    return ret

[Operator("<")]
Bool LessThan(Int32 x, Int32 y):
    Int1 ret
    ir:
        %1 = load i32, i32* %x
        %2 = load i32, i32* %y
        %3 = icmp slt i32 %1, %2
        store i1 %3, i1* %ret
    return ret

[Operator(">")]
Bool GreaterThan(Int32 x, Int32 y):
    Int1 ret
    ir:
        %1 = load i32, i32* %x
        %2 = load i32, i32* %y
        %3 = icmp sgt i32 %1, %2
        store i1 %3, i1* %ret
    return ret