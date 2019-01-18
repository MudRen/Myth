//namd.c
//Created by kuku@sjsh 2003.3

#include <ansi.h>

mapping equip_prefixs = ([    
        "�ƺ�" : "river",          "����" : "windcloud", 
        "�׵�" : "leidian",        "ħ��" : "moyu", 
        "ħ��" : "demoniac",       "ս��" : "battle", 
        "����" : "yaolong",        "����" : "chishe", 
        "����" : "bird",           "����" : "elong", 
        "����" : "imperial",       "����" : "emperor", 
        "���" : "queen",          "����" : "lord", 
        "��ʥ" : "angel",          "����" : "shenwang", 
        "����" : "yaohou",         "ħ��" : "mowang", 
        "����" : "qixing",         "���" : "egui", 
        "����" : "yulong",         "���" : "yufeng", 
        "�ɺ�" : "songhe",         "����" : "longxiang", 
        "����" : "fengwu",         "��Ӱ" : "wuying", 
        "�Ʒ�" : "pofeng",         "����" : "huanglong", 
        "̫Ԩ" : "taiyuan",        "̫��" : "taifeng", 
        "����" : "xuling",         "���" : "qinghong", 
        "�׺�" : "baihong",        "����" : "chain", 
        "����" : "tianlong",       "�ϵ�" : "zidian", 
        "���" : "fenghuang",      "ˮ��" : "shuihuo", 
        "���" : "jinguang",       "����" : "religious", 
        "ҹ��" : "yecha",          "��Ȫ" : "longquan", 
        "�ƺ�" : "pohan",          "�һ�" : "peach", 
        "�޵�" : "invincible",     "����" : "firebolt", 
        "����" : "kylin",          "��˿" : "jinsi", 
        "����" : "yinguang",       "����" : "auspice", 
        "��Ů" : "fairy",          "����" : "huawen", 
        "����" : "anguang",        "����" : "songwen", 
        "��" : "pangang",        "����" : "guiwen", 
        "���" : "qingfeng",       "�⹳" : "wugou", 
        "��ˮ" : "liushui",        "ܽ��" : "furong", 
        "��Ԩ" : "abyssal",        "����" : "liubo", 
        "����" : "ice",            "��ɽ" : "landslip", 
        "����" : "daohai",         "���" : "juchi", 
        "�׺�" : "canghai",        "����" : "tianmen", 
        "����" : "dimen",          "����" : "yanling", 
        "����" : "wanyue",         "��β" : "yanwei", 
        "���" : "shehun",         "���" : "duohun", 
        "����" : "xuanyue",        "���" : "guihao", 
        "����" : "ray",            "����" : "baiyu", 
        "����" : "pool",           "����" : "lanhong", 
        "����" : "yinshe",         "�պ�" : "zhaohai", 
        "����" : "hell",           "��ͷ" : "longtou", 
        "�ͻ�" : "menghu",         "���" : "shuguang", 
        "�÷�" : "huanfeng",       "����" : "wangyue", 
        "����" : "huolong",        "����" : "ganyue", 
        "��ˮ" : "poshui",         "�޹�" : "huiguang", 
        "����" : "mingguang",      "���" : "tianguang", 
        "���" : "shenguang",      "����" : "guiqi", 
        "��Ʒ" : "xianpin",        "��ˮ" : "tianshui", 
        "��ˮ" : "dishui",         "���" : "tianfeng", 
        "�ط�" : "difeng",         "����" : "tianyu", 
        "����" : "shenyu",         "����" : "guiyu", 
        "����" : "diyu",           "����" : "xianyu", 
        "��ˮ" : "shenshui",       "��ˮ" : "xianshui", 
        "ħˮ" : "moshui",         "����" : "dushe", 
        "��Ҷ" : "zhuye",          "��Ҷ" : "liuye", 
        "����" : "tianzhu",        "����" : "dizhu", 
        "����" : "shenzhu",        "ħ��" : "mozhu", 
        "�˺�" : "scaur",          "����" : "feiwu", 
        "��ʨ" : "mengshi",        "Х��" : "xiaotian", 
        "����" : "mingyue",        "����" : "leopard", 
        "����" : "huxiao",         "ʨ��" : "shixiao", 
        "Ұ��" : "yelang",         "����" : "kuanglang", 
        "����" : "kuanglong",      "����" : "shenlang", 
        "��ʨ" : "shenshi",        "��" : "shenhu", 
        "��" : "leopard",        "��ӥ" : "shenying", 
        "����" : "skyfeather",     "����" : "feather", 
        "���" : "tear",           "����" : "langyun", 
        "�ڷ�" : "wufa",           "����" : "chanbin", 
        "����" : "yunji",          "����" : "wuhuan", 
        "��ü" : "emei",           "����" : "qingzhu", 
        "����" : "mingmou",        "����" : "liupan", 
        "�촽" : "zhuchun",        "��" : "haochi", 
        "��ָ" : "yuzhi",          "�ر�" : "subi", 
        "����" : "xiaocui",        "����" : "chunjiang", 
        "ҹ��" : "yeyue",          "��ݺ" : "crow", 
        "����" : "ciyun",          "����" : "fuyun", 
        "����" : "qingyun",        "����" : "zhaoyun", 
        "ҹ��" : "yeyun",          "����" : "feiyun", 
        "����" : "juanyun",        "����" : "baiyun", 
        "����" : "lanyun",         "����" : "ziyun", 
        "����" : "hongyun",        "����" : "chiyun", 
        "����" : "hongmen",        "����" : "jiaolong", 
        "����" : "leiting",        "ʨ��" : "roar", 
        "�Ի�" : "wohu",           "����" : "sheep", 
        "�Ͼ�" : "laojun",         "��ĸ" : "doumu", 
        "����" : "helan",          "����" : "sunmoon", 
        "����" : "yumen",          "��İ" : "qianmo", 
        "�ݺ�" : "zongheng",       "����" : "chengtian", 
        "����" : "forever",        "���" : "yuhuang", 
        "�ɰ�" : "pine",           "����" : "xumi", 
        "���" : "xiugu",          "����" : "qingxiang", 
        "����" : "luoshen",        "��ӥ" : "falcon", 
        "ʥĸ" : "shengmu",        "�Ĳ�" : "literate", 
        "��ʥ" : "knight",         "��ѩ" : "feixue", 
        "Ʈѩ" : "piaoxue",        "��ѩ" : "luoxue", 
        "��ѩ" : "baixue",         "��ѩ" : "mengxue", 
        "ѩ��" : "xuehua",         "����" : "fog", 
        "ϼε" : "xiawei",         "��ϼ" : "chixia", 
        "����" : "xiaoxiang",      "嫺�" : "hanhai", 
        "ĵ��" : "mudan",          "�ٺ�" : "baihe", 
        "�׺�" : "hehua",          "����" : "longju", 
        "����" : "youlan",         "���" : "feicui",         
        "����" : "yunzhu",         "����" : "haitang", 
        "��ҩ" : "shaoyao",        "�ž�" : "dujuan", 
        "õ��" : "meigui",         "�¼�" : "yueji", 
        "Ǿޱ" : "qiangwei",       "����" : "rock", 
        "��ʦ" : "master",         "����" : "changqing", 
        "����" : "fantian",        "��ħ" : "demonbane", 
        "����" : "fengling",       "����" : "fengxin", 
        "����" : "ziyang",         "����" : "danyang", 
        "��ޱ" : "osmund",         "ľ��" : "muxi", 
        "̫��" : "taiyang",        "���Q" : "huohe", 
        "���Q" : "qinghe",         "���Q" : "baihe", 
        "���Q" : "zihe",           "��ޱ" : "baiwei", 
        "��ޱ" : "lanwei",         "��ޱ" : "qingwei", 
        "��ޱ" : "huowei",         "��ޱ" : "bingwei", 
        "����" : "qingyang",       "����" : "baiyang", 
        "����" : "huoyang",        "����" : "bingyang", 
        "�۹�" : "bone",           "����" : "duxin", 
        "����" : "hancui",         "����" : "bat", 
        "����" : "yuexing",        "����" : "heiyun", 
        "����" : "shark",          "��ɽ" : "hanshan", 
        "����" : "duanyu",         "ժ��" : "zhaixing", 
        "̽��" : "tanxing",        "����" : "feixing", 
        "����" : "heimei",         "��Ӱ" : "lvying", 
        "��ħ" : "demoniac",       "����" : "yinling", 
        "����" : "jinling",        "ǧ��" : "qianren", 
        "����" : "jingdian",       "ǧâ" : "qianmang", 
        "����" : "mystic",         "ħ��" : "mofu", 
        "���" : "desert",         "�Ͼ�" : "yijun", 
        "��ҳ" : "chuye",          "����" : "chunyu", 
        "����" : "xiayu",          "����" : "qiuyu", 
        "����" : "dongyu",         "����" : "chunlan", 
        "�ĺ�" : "xiahe",          "���" : "qiuju", 
        "��÷" : "dongmei",        "��Ȫ" : "yuquan", 
        "��Ȫ" : "yuquan",         "��Ȫ" : "fengquan", 
        "��Ȫ" : "huquan",         "ŭ��" : "billowy", 
        "����" : "billowy",        "��ˮ" : "qingshui", 
        "˫��" : "shuangfeng",     "����" : "ruiqi", 
        "��ʤ" : "bisheng",        "�̹�" : "godly", 
        "����" : "swallow",        "����" : "ligui", 
        "��ͷ" : "guitou",         "����" : "guiwang", 
        "ţͷ" : "niutou",         "�л�" : "juhun", 
        "����" : "hunpo",          "����" : "yazi", 
        "���" : "chiwen",         "����" : "pulao", 
        "����" : "haotie",         "����" : "chuxia",
        "��ͼ" : "shutu",          "Ѫն" : "blood",
        "����" : "tianwei",        "����" : "xuanfeng",
        "��â" : "zimang",         "����" : "xiaoyan",
        "����" : "xinglong",       "����" : "yuelong",
        "����" : "juwei",          "Ӱ��" : "shadow",
        "���" : "canxing",        "����" : "liexin",
        "˫��" : "shuangxing",     "��ϼ" : "wangxia",
        "�ۺ�" : "juhe",           "��̳" : "jingtan",
        "�ɷ�" : "feifeng",        "����" : "denglong",
        "��Ȫ" : "juquan",         "��ԯ" : "xuanyuan",
        "��ͨ" : "shentong",       "�޼�" : "wuji",
        "̫��" : "taibai",         "Ǭ��" : "qiankun",
        "̫��" : "taiji",          "���" : "tiandi",
        "����" : "haoqi",          "����" : "lianyu",
        "����" : "kunlun",         "����" : "jingshen",
        "����" : "aoshi",          "��Ѫ" : "shixue",
        "ǬԪ" : "qianyuan",       "����" : "jueshi",
        "����" : "lingqi",         "����" : "lijing",
        "�⻪" : "guanghua",       "����" : "huoyan",
        "����" : "hanbing",        "��ħ" : "yinmo",
        "����" : "songwen",        "��" : "diaohua",
        "����" : "wrapped-hilt",   "����" : "thorny",
        "����" : "yinyang",        "��ӥ" : "jinying", 
        "��ɰ" : "cinnabar",       "����" : "glowing",
        "���" : "yenholdish",     "ͮ��" : "tongyun",
        "����" : "jinxiang",       "����" : "wyvern",
        "̫��" : "taixuan",        "̫��" : "taiqing",
        "̫��" : "taiyi",          "̫��" : "taiyin",
        "����" : "demonbane",      "����" : "chilong",     
        "��а" : "devilbane",      "���" : "nether",
        "��Ѫ" : "chixue",         "��Ѫ" : "bixue",
        "�޳�" : "woochanian",     "����" : "jiaojao",
        "����" : "dawn",           "����" : "shining",
        "����" : "huoyan",         "����" : "freeze",
        "�粨" : "fengbo",         "����" : "zhenlei",
        "�޺�" : "guardian",      
]);

string *armor_prefixs = ({ 
        "", "", "", "����", "����", "����", "����", 
        "����", "����", "����", "�ۼ�", 
}); 

mapping weapon_list_axe =([   
"��"    :       "axe",          "��"    :       "bigaxe",
"�޸�"  :       "hugeaxe",      
]);

mapping weapon_list_blade =([   
"��"    :       "blade",          "�̵�"   :        "duandao",
"�䵶"  :       "wandao",
]);

mapping weapon_list_fork =([   
"��"    :       "fork",          "�Źɲ�"    :     "jiugucha",
]);

mapping weapon_list_hammer =([   
"��"    :       "hammer",         "÷����"    :     "huahammer",
]);

mapping weapon_list_mace =([  
"�"    :       "mace",         "˫���"    :     "doublemace",
]);

mapping weapon_list_spear =([  
"��ǹ"    :       "shortspear",       "ǹ"       :    "spear",
"��ǹ"    :       "longspear",       "���ǹ"    :     "firespear",
]);

mapping weapon_list_staff =([   
"��"    :       "staff",         "����"    :     "chanstaff",
]);

mapping weapon_list_stick =([   
"��"    :     "stick",         "�̹�"    :     "shortstick",
"���"  :     "bigstick", 
]);

mapping weapon_list_sword =([   
"��"    :       "sword",       "����"       :    "longsword",
"�̽�"  :       "shortsword",       "ϸ��"    :     "thinsword",
]);

mapping weapon_list_whip =([  
"��"    :     "whip",         "����"    :     "longwhip",
"�Žڱ�"  :     "ninewhip", 
]);

mapping armor_list_armor =([  
"��"    :       "armor",   "����"    :       "baojia",        
]);

mapping armor_list_boots =([  
"ѥ"    :       "boots",          "��ѥ"   :        "flyshoes",
]);

mapping armor_list_cloth =([   
"��"    :       "cloth",          "����"    :     "xianpao",
]);

mapping armor_list_hands =([  
"����"    :       "hands",         "����"    :     "hushou",
]);

mapping armor_list_head =([   
"��"    :       "head",         "ñ"    :     "hat",
]);

mapping armor_list_neck =([  
"����"    :       "neck",       "��"       :    "necklace",
]);

mapping armor_list_ring =([  
"��ָ"    :       "ring",         "��ָ"    :     "banzhi",
]);

mapping armor_list_shield =([  
"��"    :     "shield",         "����"    :     "dun",
]);

mapping armor_list_surcoat =([  
"����"    :       "surcoat",       "����"       :    "doupeng",
]);

mapping armor_list_waist =([  
"���ľ�"    :     "waist",         "����"    :     "huxiong",
]);

mapping armor_list_wrists =([  
"����"    :     "wrists",         "���"    :     "wandai",
]);

varargs mapping random_name(string type)
{
        mapping name;
        int a,b,c;
        string *surnames, *middle_names, *last_names;
        string temp_name, *temp_id, long;
        
        name=allocate_mapping(2);
        switch(type){  
                case "axe":                     
                        surnames=keys(equip_prefixs);
                        middle_names=keys(weapon_list_axe);
                        a=random(sizeof(surnames));
                        b=random(sizeof(middle_names));
                        name=([     
                                "name"  : surnames[a]+
                                        middle_names[b],
                                "id"    : ({equip_prefixs[surnames[a]]+" "+
                                        weapon_list_axe[middle_names[b]],
                                        "axe"}),
                        ]);    
                        break;
                case "blade":                           
                        surnames=keys(equip_prefixs);
                        middle_names=keys(weapon_list_blade);
                        a=random(sizeof(surnames));
                        b=random(sizeof(middle_names));
                        name=([     
                                "name"  : surnames[a]+
                                        middle_names[b],
                                "id"    : ({equip_prefixs[surnames[a]]+" "+
                                        weapon_list_blade[middle_names[b]],
                                        "blade"}),
                        ]);      
                        break;
                case "fork":                    
                        surnames=keys(equip_prefixs);
                        middle_names=keys(weapon_list_fork);
                        a=random(sizeof(surnames));
                        b=random(sizeof(middle_names));
                        name=([     
                                "name"  : surnames[a]+
                                        middle_names[b],
                                "id"    : ({equip_prefixs[surnames[a]]+" "+
                                        weapon_list_fork[middle_names[b]],
                                        "fork"}),
                        ]);    
                        break;
                case "hammer":                          
                        surnames=keys(equip_prefixs);
                        middle_names=keys(weapon_list_hammer);
                        a=random(sizeof(surnames));
                        b=random(sizeof(middle_names));
                        name=([     
                                "name"  : surnames[a]+
                                        middle_names[b],
                                "id"    : ({equip_prefixs[surnames[a]]+" "+
                                        weapon_list_hammer[middle_names[b]],
                                        "hammer"}),
                        ]); 
                        break;
                case "mace":                    
                        surnames=keys(equip_prefixs);
                        middle_names=keys(weapon_list_mace);
                        a=random(sizeof(surnames));
                        b=random(sizeof(middle_names));
                        name=([     
                                "name"  : surnames[a]+
                                        middle_names[b],
                                "id"    : ({equip_prefixs[surnames[a]]+" "+
                                        weapon_list_mace[middle_names[b]],
                                        "mace"}),
                        ]);      
                        break;       
                case "spear":                           
                        surnames=keys(equip_prefixs);
                        middle_names=keys(weapon_list_spear);
                        a=random(sizeof(surnames));
                        b=random(sizeof(middle_names));
                        name=([     
                                "name"  : surnames[a]+
                                        middle_names[b],
                                "id"    : ({equip_prefixs[surnames[a]]+" "+
                                        weapon_list_spear[middle_names[b]],
                                        "spear"}),                                      
                        ]);     
                        break;
                case "staff":                           
                        surnames=keys(equip_prefixs);
                        middle_names=keys(weapon_list_staff);
                        a=random(sizeof(surnames));
                        b=random(sizeof(middle_names));
                        name=([     
                                "name"  : surnames[a]+
                                        middle_names[b],
                                "id"    : ({equip_prefixs[surnames[a]]+" "+
                                        weapon_list_staff[middle_names[b]],
                                        "staff"}),
                        ]);   
                        break;
                case "stick":                           
                        surnames=keys(equip_prefixs);
                        middle_names=keys(weapon_list_stick);
                        a=random(sizeof(surnames));
                        b=random(sizeof(middle_names));
                        name=([     
                                "name"  : surnames[a]+
                                        middle_names[b],
                                "id"    : ({equip_prefixs[surnames[a]]+" "+
                                        weapon_list_stick[middle_names[b]],
                                        "stick"}),
                        ]);   
                        break;
                case "sword":                           
                        surnames=keys(equip_prefixs);
                        middle_names=keys(weapon_list_sword);
                        a=random(sizeof(surnames));
                        b=random(sizeof(middle_names));
                        name=([     
                                "name"  : surnames[a]+
                                        middle_names[b],
                                "id"    : ({equip_prefixs[surnames[a]]+" "+
                                        weapon_list_sword[middle_names[b]],
                                        "sword"}),
                        ]);       
                        break;
                case "whip":                    
                        surnames=keys(equip_prefixs);
                        middle_names=keys(weapon_list_whip);
                        a=random(sizeof(surnames));
                        b=random(sizeof(middle_names));
                        name=([     
                                "name"  : surnames[a]+
                                        middle_names[b],
                                "id"    : ({equip_prefixs[surnames[a]]+" "+
                                        weapon_list_whip[middle_names[b]],
                                        "whip"}),
                        ]);       
                        break;
                case "armor":                           
                        surnames=keys(equip_prefixs);
                        middle_names=keys(armor_list_armor);
                        a=random(sizeof(surnames));
                        b=random(sizeof(middle_names));
                        c=random(sizeof(armor_prefixs));   
                        name=([     
                                "name"  : surnames[a]+armor_prefixs[c]+
                                        middle_names[b],
                                "id"    : ({equip_prefixs[surnames[a]]+" "+
                                        armor_list_armor[middle_names[b]],
                                        "armor"}),
                        ]);       
                        break;
                case "boots":                           
                        surnames=keys(equip_prefixs);
                        middle_names=keys(armor_list_boots);
                        a=random(sizeof(surnames));
                        b=random(sizeof(middle_names));
                        c=random(sizeof(armor_prefixs));   
                        name=([     
                                "name"  : surnames[a]+armor_prefixs[c]+
                                        middle_names[b],
                                "id"    : ({equip_prefixs[surnames[a]]+" "+
                                        armor_list_boots[middle_names[b]],
                                        "boots"}),
                        ]);       
                        break;
                case "cloth":                           
                        surnames=keys(equip_prefixs);
                        middle_names=keys(armor_list_cloth);
                        a=random(sizeof(surnames));
                        b=random(sizeof(middle_names));
                        c=random(sizeof(armor_prefixs));   
                        name=([     
                                "name"  : surnames[a]+armor_prefixs[c]+
                                        middle_names[b],
                                "id"    : ({equip_prefixs[surnames[a]]+" "+
                                        armor_list_cloth[middle_names[b]],
                                        "cloth"}),
                        ]);       
                        break;
                case "hands":                           
                        surnames=keys(equip_prefixs);
                        middle_names=keys(armor_list_hands);
                        a=random(sizeof(surnames));
                        b=random(sizeof(middle_names));
                        c=random(sizeof(armor_prefixs));   
                        name=([     
                                "name"  : surnames[a]+armor_prefixs[c]+
                                        middle_names[b],
                                "id"    : ({equip_prefixs[surnames[a]]+" "+
                                        armor_list_hands[middle_names[b]],
                                        "hands"}),
                        ]);       
                        break;
                case "head":                    
                        surnames=keys(equip_prefixs);
                        middle_names=keys(armor_list_head);
                        a=random(sizeof(surnames));
                        b=random(sizeof(middle_names));
                        c=random(sizeof(armor_prefixs));   
                        name=([     
                                "name"  : surnames[a]+armor_prefixs[c]+
                                        middle_names[b],
                                "id"    : ({equip_prefixs[surnames[a]]+" "+
                                        armor_list_head[middle_names[b]],
                                        "head"}),
                        ]);       
                        break;
                case "neck":                    
                        surnames=keys(equip_prefixs);
                        middle_names=keys(armor_list_neck);
                        a=random(sizeof(surnames));
                        b=random(sizeof(middle_names));
                        c=random(sizeof(armor_prefixs));   
                        name=([     
                                "name"  : surnames[a]+armor_prefixs[c]+
                                        middle_names[b],
                                "id"    : ({equip_prefixs[surnames[a]]+" "+
                                        armor_list_neck[middle_names[b]],
                                        "neck"}),
                        ]);       
                        break;
                case "shield":                          
                        surnames=keys(equip_prefixs);
                        middle_names=keys(armor_list_shield);
                        a=random(sizeof(surnames));
                        b=random(sizeof(middle_names));
                        c=random(sizeof(armor_prefixs));   
                        name=([     
                                "name"  : surnames[a]+armor_prefixs[c]+
                                        middle_names[b],
                                "id"    : ({equip_prefixs[surnames[a]]+" "+
                                        armor_list_shield[middle_names[b]],
                                        "shield"}),
                        ]);       
                        break;
                case "waist":                           
                        surnames=keys(equip_prefixs);
                        middle_names=keys(armor_list_waist);
                        a=random(sizeof(surnames));
                        b=random(sizeof(middle_names));
                        c=random(sizeof(armor_prefixs));   
                        name=([     
                                "name"  : surnames[a]+armor_prefixs[c]+
                                        middle_names[b],
                                "id"    : ({equip_prefixs[surnames[a]]+" "+
                                        armor_list_waist[middle_names[b]],
                                        "waist"}),
                        ]);       
                        break;
                case "wrists":                          
                        surnames=keys(equip_prefixs);
                        middle_names=keys(armor_list_wrists);
                        a=random(sizeof(surnames));
                        b=random(sizeof(middle_names));
                        c=random(sizeof(armor_prefixs));   
                        name=([     
                                "name"  : surnames[a]+armor_prefixs[c]+
                                        middle_names[b],
                                "id"    : ({equip_prefixs[surnames[a]]+" "+
                                        armor_list_wrists[middle_names[b]],
                                        "wrists"}),
                        ]);       
                        break;
                case "ring":                    
                        surnames=keys(equip_prefixs);
                        middle_names=keys(armor_list_ring);
                        a=random(sizeof(surnames));
                        b=random(sizeof(middle_names));
                        c=random(sizeof(armor_prefixs));   
                        name=([     
                                "name"  : surnames[a]+armor_prefixs[c]+
                                        middle_names[b],
                                "id"    : ({equip_prefixs[surnames[a]]+" "+
                                        armor_list_ring[middle_names[b]],
                                        "ring"}),
                        ]);       
                        break;
                case "surcoat":                         
                        surnames=keys(equip_prefixs);
                        middle_names=keys(armor_list_surcoat);
                        a=random(sizeof(surnames));
                        b=random(sizeof(middle_names));
                        c=random(sizeof(armor_prefixs));   
                        name=([     
                                "name"  : surnames[a]+armor_prefixs[c]+
                                        middle_names[b],
                                "id"    : ({equip_prefixs[surnames[a]]+" "+
                                        armor_list_surcoat[middle_names[b]],
                                        "surcoat"}),
                        ]);       
                default: break;                                                                                                                                                     
        }
        return name;
}
