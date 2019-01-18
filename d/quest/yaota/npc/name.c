//namd.c
//created by kuku@sjsh

#include <ansi.h>

mapping color_list = ([ 
"³à":   "chi",          "ºì":   "hong",
"»Æ":   "huang",        "ÂÌ":   "lu",
"Çà":   "qing",         "À¶":   "lan",
"×Ï":   "zi",           "ÎÚ":   "wu",
"ºÚ":   "hei",          "Òø":   "yin",
"°×":   "bai",          "½ğ":   "jin",
"»Ò":   "hui",          "Ä¾":   "mu",
"Ë®":   "shui",         "»ğ":   "huo",
"ÍÁ":   "tu",           "Î¸":   "wei",
"¹í":   "gui",          "ÔÂ":   "yue",
"Öì":   "zhu",          "ÈÕ":   "ri",
"¶·":   "dou",          "õş":   "zui",
"¿ü":   "kui",          "²Î":   "shen",
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
"Öí":   "zhu",          "òğ":   "fu",
"²ò":   "chai",         "Ì¡":   "lai",
"áô":   "fei",          "òş":   "mang",
"ĞÜ":   "xiong",        "Ïó":   "xiang",
"õõ":   "diao",         "Àê":   "li",
"âµ":   "huan",         "î¼":   "pi",
"Ñà":   "yan",          "ò¾":   "yin",
"ïô":   "zhi",          "áó":   "pao",
"â¥":   "ni",           "éá":   "ao",
"Áç":   "ling",         "÷ä":   "ji",
"ĞÉ":   "xing",
]);

mapping animal_names = ([ 
"ºüÀê":"huli",          "ºÚĞÜ":"heixiong",
"¹·ĞÜ":"gouxiong",      "°×ĞÜ":"baixiong",
"Ğ«×Ó":"xiezi",         "ó¸òÜ":"chanchu",
"òÚò¼":"wugong",        "ÍÁ±î":"tubie",
"·É»È":"feihuang",      "»È³æ":"huangchong",
"´óÇà³æ":"daqingchong", "³ô³æ":"chouchong",
"ÌøÔé":"tiaozao",       "Ê­×Ó":"shizi",
"ÀÏ»¢":"laohu",         "Ê¨×Ó":"shizi",
"»ÆÊ¨":"huangshi",      "ºÚÊ¨":"heishi",
"°×Ê¨":"baishi",        "Ò°ÍÃ":"yetu",
"»¨±ª":"huabao",        "É½±ª":"shanbao",
"²İ±ª":"caobao",        "É½Ñò":"shanyang",
"Âíºï":"mahou",         "â¨ºï":"mihou",
"Ô³ºï":"yuanhou",       "»ÒÀÇ":"huilang",
"Ò°Öí":"yezhu",         "Ö©Öë":"zhizhu",
"ÂíÂ¹":"malu",          "°×Â¹":"bailu",
"»ÒÂ¹":"huilu",         "ºÚÂ¹":"heilu",
"É½¼¦":"shanji",        "Ò°¼¦":"yeji",
"ïô¼¦":"zhiji",         "´Ìâ¬":"ciwei",
"»¨ºüÀê":"huahuli",     "°×ºüÀê":"baihuli",
"»ÒºüÀê":"huihuli",     "ĞÉĞÉ":"xingxing",
"áôáô":"feifei",        "°×Âí":"baima",
"ºìÂí":"hongma",        "ºÚÂí":"heima",
"°×Ã¨":"baimao",        "»¨Ã¨":"huamao",
"ºÚÃ¨":"heimao",        "Ò°Ã¨":"yemao",
"Ò°Âí":"yema",          "Ò°Â¿":"yelu",
"°×ÍÃ":"baitu",         "»ÒÍÃ":"huitu",
"Ë®Å£":"shuiniu",       "êóÅ£":"maoniu",
"Ò°Å£":"yeniu",         "°×Êó":"baishu",
"»ÒÊó":"huishu",        "ºÚÂìÒÏ":"heimayi",
"ÂìÒÏ":"mayi",          "°×ÒÏ":"baiyi",
"É½ÀÏÊó":"shanlaoshu",  "»¨Éß":"huashe",
"ÇàÉß":"qingshe",       "°×Éß":"baishe",
"»Ò°ßÉß":"huibanshe",   "¾Şòş":"jumang",
"Ë®Éß":"shuishe",       "º£Àê":"haili",
"ºÓÀê":"heli",
]);

mapping middle_list =([ 
"½Å"    :       "jiao",         "Í·"    :       "tou",
"Î²"    :       "wei",          "×ì"    :       "zui",
"¶ú"    :       "er",           "ÑÛ"    :       "yan",
"±Ç"    :       "bi",           "ÑÀ"    :       "ya",
"Éà"    :       "she",          "Éí"    :       "shen",
"×¦"    :       "zhua",
]);
string *title_list = ({ 
        "ÔÂ¹¬ÆúÍ½",     "½«¾ü¸®ÅÑ½«", 
        "´óÑ©É½ÄõÑı",   "ÎŞµ×¶´ÄõÑı",
        "·½´çÉ½ÆúÍ½",   "Îå×¯¹ÛÄõÍ½", 
        "µØ¸®Ô©¹í",     "Áú¹¬ÆúÍ½",
        "Ìì¹¬ÅÑ½«",     "·½´çÑıµÀ",
        "ÎŞµ×¶´Ğ¡Ñı",   "Îå×¯¹Û¶ñÍ½",
        "ÆÕÍÓ¶ñÉ®",
});     

varargs mapping random_name(string type)
{
        mapping name;
        int a,b,c;
        string *surnames, *middle_names, *last_names;
        string temp_name, *temp_id, long;
        
        name=allocate_mapping(3);
        switch(type)
        {  case "yaoguai": 
          if(random(2))
            {
                        surnames=keys(animal_list);
                        middle_names=keys(middle_list);
                        a=random(sizeof(surnames));
                        b=random(sizeof(middle_names));
                        c=random(sizeof(surnames));
                        name=([    
                                "name"  : surnames[a]+
                                          middle_names[b]+
                                          surnames[c],
                                "id"    : ({animal_list[surnames[a]]+
                                            middle_list[middle_names[b]]+" "+
                                            animal_list[surnames[c]],
                                            animal_list[surnames[c]],"moguai"}),
                                "title" :title_list[random(sizeof(title_list))],
                        ]);
                }
        else
                {
                        if(random(2))
                        {
                                surnames=keys(color_list);
                                middle_names=keys(animal_list);
                                a=random(sizeof(surnames));
                                b=random(sizeof(middle_names));
                                c=random(2);
                                temp_name=surnames[a]+
                                          middle_names[b];
                                temp_name+=c?"¾«":"¹Ö";
                                if(c)
                                        temp_id=({color_list[surnames[a]]+
                                                  animal_list[middle_names[b]]+" "+
                                                "jing", "jing","moguai"});
                                else
                                        temp_id=({color_list[surnames[a]]+
                                                  animal_list[middle_names[b]]+" "+
                                                "guai", "guai","moguai"});
                        }
                        else
                        {
                                surnames=keys(animal_names);
                                a=random(sizeof(surnames));
                                b=random(2);
                                temp_name=surnames[a];
                                temp_name+=b?"¾«":"¹Ö";
                                if(b)
                                        temp_id=({animal_names[surnames[a]]+" "+
                                                  "jing", "jing","moguai"});
                                else
                                        temp_id=({animal_names[surnames[a]]+" "+
                                                  "guai", "guai","moguai"});
                        }
                        name=([    
                                "name" : temp_name,
                                "id"   : temp_id,
                                "title": "NONE",
                        ]);
                }
       }
        return name;
}
