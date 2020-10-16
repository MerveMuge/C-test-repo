using System;
using System.IO;
using System.Text;
using System.Net.Sockets;
//using Tcp_Client.Tcp_Client;

namespace Program
{
    public class Program
    {

        public void TcpClient()
        {
            using var client = new TcpClient();

            var hostname = "webcode.me";
            client.Connect(hostname, 80);

            using NetworkStream networkStream = client.GetStream();
            networkStream.ReadTimeout = 2000;

            using var writer = new StreamWriter(networkStream);

            var message = "HEAD / HTTP/1.1\r\nHost: webcode.me\r\nUser-Agent: C# program\r\n"
                + "Connection: close\r\nAccept: text/html\r\n\r\n";

            Console.WriteLine(message);

            using var reader = new StreamReader(networkStream, Encoding.UTF8);

            byte[] bytes = Encoding.UTF8.GetBytes(message);
            networkStream.Write(bytes, 0, bytes.Length);

            Console.WriteLine(reader.ReadToEnd());
        }
        static void Main(string[] args)
        {
            Program program = new Program();
            program.TcpClient();


        }
    }
}
