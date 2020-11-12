class Boo
{
    private readonly string _field;

    public Boo()
    {
        _field = GetField();
    }

    private string GetField()
    {
        return "MyFieldInitialization";
    }
}
