using System;
using System.IO;
using System.Runtime.Serialization.Formatters.Binary;
using ClassLibrary;

namespace DataFileInput
{
	class Program
	{
		static void Main(string[] args)
		{
			try
			{
				#region 삭제함
				//bool check;
				//int count;
				//string[] name = new string[8];
				//string[] path = new string[8];
				//using (BinaryReader br = new BinaryReader(File.OpenRead(@"C:\Users\ko997\Desktop\VPN\data.bin")))
				//{
				//	check = br.ReadBoolean();
				//	count = br.ReadInt32();
				//	if(count > 2)
				//	{
				//		for (int i = 2; i < count; i++)
				//		{
				//			name[i] = br.ReadString();
				//			path[i] = br.ReadString();
				//		}
				//	}
				//}
				//Console.WriteLine(check);
				//Console.WriteLine(count);
				//if(count == 2)
				//{
				//	Console.WriteLine("추가된 ovpn 파일이 없습니다.");
				//}
				//else
				//{
				//	for(int i = 2; i < count; i++)
				//	{
				//		Console.Write(name[i] + " ");
				//		Console.WriteLine(path[i]);
				//	}
				//}
				#endregion
				BinaryFormatter bf = new BinaryFormatter();
				OpenVpn ovpn = (OpenVpn)bf.Deserialize(File.OpenRead(@"C:\Users\전성우\Desktop\data.bin"));

				Console.WriteLine("Input");
				Console.WriteLine(ovpn.ToString());
			}
			catch (Exception e)
			{
				Console.WriteLine(e.Message);
				Console.WriteLine(e.StackTrace);
			}
		}
	}
}
