struct Customer:
    Int32 age
    Int32 test

Customer init(Customer self):
    self.age = 2
    self.test = 3
    return self

Int32 main():
    Customer c
    Customer c2 = c.init()
    Int64 f = c2.age + 2.ToInt64()
    write("test\n", 5)

    return 0
