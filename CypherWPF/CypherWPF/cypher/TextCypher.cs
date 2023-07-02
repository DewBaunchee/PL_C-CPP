using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CypherWPF.cypher
{
    class TextCypher
    {
        public static File buffFile;
        public static FileInfo encrypt(FileInfo file, string key, int method)
        {
            FileStream fstream = new FileStream(file.FullName, FileMode.Open);
            byte[] fileBytes = new byte[fstream.Length];
            byte[] keyArray = keyToByteArray(key);
            fstream.Read(fileBytes, 0, fileBytes.Length);

            return null;
        }

        private static byte[] keyToByteArray(string key)
        {
            throw new NotImplementedException();
        }
    }
}
