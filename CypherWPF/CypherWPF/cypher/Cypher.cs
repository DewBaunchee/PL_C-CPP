using System;
using System.Collections;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CypherWPF.cypher
{
    class Cypher
    {
        static HashSet<string> txtExtensions = new HashSet<string> { "txt", "doc", "docx", "html", "pdf", "rtf" };
        static HashSet<string> imgExtensions = new HashSet<string> { "jpg", "jpeg", "bmp", "png" };
        public static FileInfo executeEncryption(FileInfo file, String key, int method)
        {
            string ext = getExtension(file);
            if (txtExtensions.Contains(ext))
            {
                return TextCypher.encrypt(file, key, method);
            }
            if (imgExtensions.Contains(ext))
            {
                return ImageCypher.encrypt(file, key, method);
            }
            return null;
        }

        public static String getExtension(FileInfo file)
        {
            return file.FullName.Substring(file.FullName.LastIndexOf('.') + 1);
        }
    }
}
