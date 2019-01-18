//namd.c
//created by kuku@sjsh

#include <ansi.h>

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
"��":   "kui",          "��":   "shen",
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
"��":   "xing",
]);

mapping animal_names = ([ 
"����":"huli",          "����":"heixiong",
"����":"gouxiong",      "����":"baixiong",
"Ы��":"xiezi",         "���":"chanchu",
"���":"wugong",        "����":"tubie",
"�ɻ�":"feihuang",      "�ȳ�":"huangchong",
"�����":"daqingchong", "����":"chouchong",
"����":"tiaozao",       "ʭ��":"shizi",
"�ϻ�":"laohu",         "ʨ��":"shizi",
"��ʨ":"huangshi",      "��ʨ":"heishi",
"��ʨ":"baishi",        "Ұ��":"yetu",
"����":"huabao",        "ɽ��":"shanbao",
"�ݱ�":"caobao",        "ɽ��":"shanyang",
"���":"mahou",         "⨺�":"mihou",
"Գ��":"yuanhou",       "����":"huilang",
"Ұ��":"yezhu",         "֩��":"zhizhu",
"��¹":"malu",          "��¹":"bailu",
"��¹":"huilu",         "��¹":"heilu",
"ɽ��":"shanji",        "Ұ��":"yeji",
"����":"zhiji",         "���":"ciwei",
"������":"huahuli",     "�׺���":"baihuli",
"�Һ���":"huihuli",     "����":"xingxing",
"����":"feifei",        "����":"baima",
"����":"hongma",        "����":"heima",
"��è":"baimao",        "��è":"huamao",
"��è":"heimao",        "Ұè":"yemao",
"Ұ��":"yema",          "Ұ¿":"yelu",
"����":"baitu",         "����":"huitu",
"ˮţ":"shuiniu",       "��ţ":"maoniu",
"Ұţ":"yeniu",         "����":"baishu",
"����":"huishu",        "������":"heimayi",
"����":"mayi",          "����":"baiyi",
"ɽ����":"shanlaoshu",  "����":"huashe",
"����":"qingshe",       "����":"baishe",
"�Ұ���":"huibanshe",   "����":"jumang",
"ˮ��":"shuishe",       "����":"haili",
"����":"heli",
]);

mapping middle_list =([ 
"��"    :       "jiao",         "ͷ"    :       "tou",
"β"    :       "wei",          "��"    :       "zui",
"��"    :       "er",           "��"    :       "yan",
"��"    :       "bi",           "��"    :       "ya",
"��"    :       "she",          "��"    :       "shen",
"צ"    :       "zhua",
]);
string *title_list = ({ 
        "�¹���ͽ",     "�������ѽ�", 
        "��ѩɽ����",   "�޵׶�����",
        "����ɽ��ͽ",   "��ׯ����ͽ", 
        "�ظ�ԩ��",     "������ͽ",
        "�칬�ѽ�",     "��������",
        "�޵׶�С��",   "��ׯ�۶�ͽ",
        "���Ӷ�ɮ",
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
                                temp_name+=c?"��":"��";
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
                                temp_name+=b?"��":"��";
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
