public interface IPrinter
{
    void Print(int answer);
}

public class ConsolePrinter : IPrinter
{
    public void Print(int answer)
    {
        Console.WriteLine("The answer is {0}.", answer);
    }
}

public class Calculator
{
    private IPrinter printer;
    public Calculator(IPrinter printer)
    {
        this.printer = printer;
    }

    public void Add(int num1, int num2)
    {
        printer.Print(num1 + num2);
    }
}
