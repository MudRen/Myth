//namd.c
//Created by kuku@sjsh

mapping color_list = ([
"��":   "chi",          "��":   "hong",
"��":   "huang",        "��":   "lu",
"��":   "qing",         "��":   "lan",
"��":   "zi",           "��":   "wu",
"��":   "hei",          "��":   "yin",
"��":   "bai",          "��":   "jin",
"��":   "hui",          "ľ":   "mu",
"ˮ":   "shui",         "��":   "huo",
"��":   "tu",           "θ":   "wei",
"��":   "gui",          "��":   "yue",
"��":   "zhu",          "��":   "ri",
"��":   "dou",          "��":   "zui",
"��":   "kui",          "��":   "shen"
]);

mapping middle_list =([
"��"    :       "jiao",         "ͷ"    :       "tou",
"β"    :       "wei",          "��"    :       "zui",
"��"    :       "er",           "��"    :       "yan",
"��"    :       "bi",           "��"    :       "ya",
"��"    :       "she",          "��"    :       "shen",
"צ"    :       "zhua",
]);

mapping animal_list =([
"��":   "tu",           "��":   "hu",
"��":   "long",         "��":   "jiao",
"��":   "hu",           "��":   "bao",
"��":   "ma",           "¹":   "lu",
"��":   "yang",         "��":   "she",
"�":   "zhang",        "��":   "ji",
"��":   "gou",          "��":   "lang",
"Գ":   "yuan",         "��":   "hou",
"��":   "shu",          "ţ":   "niu",
"��":   "zhu",          "��":   "fu",
"��":   "chai",         "̡":   "lai",
"��":   "fei",          "��":   "mang",
"��":   "xiong",        "��":   "xiang",
"��":   "diao",         "��":   "li",
"�":   "huan",         "�":   "pi",
"��":   "yan",          "�":   "yin",
"��":   "zhi",          "��":   "pao",
"�":   "ni",           "��":   "ao",
"��":   "ling",         "��":   "ji",
"��":   "xing",         "ħ":   "mo",
"ѻ":   "ya",                  
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