[TestClass]
public class CalculatorTests
{
    [TestMethod]
    public void WhenAddIsCalled__ItShouldCallPrint()
    {
        /* Arrange */
        var iPrinterMock = new Mock<IPrinter>();

        // Let's mock the method so when it is called, we handle it
        iPrinterMock.Setup(x => x.Print(It.IsAny<int>()));

        // Create the calculator and pass the mocked printer to it
        var calculator = new Calculator(iPrinterMock.Object);

        /* Act */
        calculator.Add(1, 1);

        /* Assert */
        // Let's make sure that the calculator's Add method called printer.Print. Here we are making sure it is called once but this is optional
        iPrinterMock.Verify(x => x.Print(It.IsAny<int>()), Times.Once);

        // Or we can be more specific and ensure that Print was called with the correct parameter.
        iPrinterMock.Verify(x => x.Print(3), Times.Once);
    }
}
