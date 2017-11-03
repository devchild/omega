struct Customer:
    Int32 age
    Int32 test

Customer init(Customer self):
    self.age = 10
    self.test = 3
    return self

Int32 main():
    Customer c
    Customer c2 = c.init()
    Int32 x = 0
    while (x.LessThan(10)):
        write("c, c2 aging both 1 year\n", 24)
        c2.age = c2.age + 1
        c.age = c.age + 1
        x = x + 1

    if (c.age == 10):
        write("c.age = 10\n", 11)
    
    if (c2.age == 10):
        write("c2.age = 10\n", 12)

    if (c.age == 20):
        write("c.age = 20\n", 11)
    
    if (c2.age == 20):
        write("c2.age = 20\n", 12)
    
    write("test\n", 5)
    write("test\n", 5)
    Customer c
    write("test\n", 5)
    Customer c2 = c.init()
    write("test\n", 5)
    Int64 f = c2.age + 2.ToInt64()
    Int32 f2 = c2.age * 2
    Bool f4 = 2.Equals(4)
    Bool f5 = 2 == 4
    write("test\n", 5)
    Bool f8 = 2.LessThan(4)
    Bool f9 = 2.GreaterThan(4)
    return 0