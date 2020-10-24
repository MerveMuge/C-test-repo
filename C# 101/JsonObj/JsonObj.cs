using System;
using System.Collections.Generic;
using Newtonsoft.Json;

namespace obj
{
    public class JsonObj
    {

        public String dataType
        {
            get;
            set;
        }

        public String value
        {
            get;
            set;
        }

        public string JsonList()
        {

            List<JsonObj> listJSON = new List<JsonObj>();

            JsonObj obj1 = new JsonObj
            {
                dataType = "uint16",
                value = "1234"
            };

            JsonObj obj2 = new JsonObj()
            {
                dataType = "string",
                value = "this is a very nice string.!!!"
            };

            listJSON.Add(obj1);
            listJSON.Add(obj2);
            string json = JsonConvert.SerializeObject(listJSON);

            return json;
        }

    }

}
