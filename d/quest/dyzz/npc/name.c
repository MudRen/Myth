//namd.c
//Created by kuku@sjsh

mapping color_list = ([
"³à":   "chi",          "ºì":   "hong",
"»Æ":   "huang",        "ÂÌ":   "lu",
"Çà":   "qing",         "À¶":   "lan",
"×Ï":   "zi",           "ÎÚ":   "wu",
"ºÚ":   "hei",          "Òø":   "yin",
"°×":   "bai",          "½ð":   "jin",
"»Ò":   "hui",          "Ä¾":   "mu",
"Ë®":   "shui",         "»ð":   "huo",
"ÍÁ":   "tu",           "Î¸":   "wei",
"¹í":   "gui",          "ÔÂ":   "yue",
"Öì":   "zhu",          "ÈÕ":   "ri",
"¶·":   "dou",          "õþ":   "zui",
"¿ü":   "kui",          "²Î":   "shen"
]);

mapping middle_list =([
"½Å"    :       "jiao",         "Í·"    :       "tou",
"Î²"    :       "wei",          "×ì"    :       "zui",
"¶ú"    :       "er",           "ÑÛ"    :       "yan",
"±Ç"    :       "bi",           "ÑÀ"    :       "ya",
"Éà"    :       "she",          "Éí"    :       "shen",
"×¦"    :       "zhua",
]);

mapping animal_list =([
"ÍÃ":   "tu",           "ºü":   "hu",
"Áú":   "long",         "òÔ":   "jiao",
"»¢":   "hu",           "±ª":   "bao",
"Âí":   "ma",           "Â¹":   "lu",
"Ñò":   "yang",         "Éß":   "she",
"â¯":   "zhang",        "¼¦":   "ji",
"¹·":   "gou",          "ÀÇ":   "lang",
"Ô³":   "yuan",         "ºï":   "hou",
"Êó":   "shu",          "Å£":   "niu",
"Öí":   "zhu",          "òð":   "fu",
"²ò":   "chai",         "Ì¡":   "lai",
"áô":   "fei",          "òþ":   "mang",
"ÐÜ":   "xiong",        "Ïó":   "xiang",
"õõ":   "diao",         "Àê":   "li",
"âµ":   "huan",         "î¼":   "pi",
"Ñà":   "yan",          "ò¾":   "yin",
"ïô":   "zhi",          "áó":   "pao",
"â¥":   "ni",           "éá":   "ao",
"Áç":   "ling",         "÷ä":   "ji",
"ÐÉ":   "xing",         "Ä§":   "mo",
"Ñ»":   "ya",                  
]);

varargs mapping random_name(string type)
{
        mapping name;
        int a,b,c;
        string *surnames, *middle_names, *last_names;
        string temp_name, *temp_id, long;
        
        name=allocate_mapping(2);
        switch(type){  
        	case "yaoguai":           		
                        surnames=keys(color_list);
                        middle_names=keys(middle_list);
                        last_names=keys(animal_list);
                        a=random(sizeof(surnames));
                        b=random(sizeof(middle_names));
                        c=random(sizeof(last_names));
                        name=([
                                "name"  : surnames[a]+
                                          middle_names[b]+
                                          last_names[c],
                                "id"    : ({color_list[surnames[a]]+
                                            middle_list[middle_names[b]]+" "+
                                            animal_list[last_names[c]],
                                            animal_list[last_names[c]]}),
                        ]);
	}
        return name;
}