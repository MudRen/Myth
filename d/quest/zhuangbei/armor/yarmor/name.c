//namd.c
//Created by kuku@sjsh 2003.3

#include <ansi.h>

mapping equip_prefixs = ([    
        "»ÆºÓ" : "river",          "·çÔÆ" : "windcloud", 
        "À×µç" : "leidian",        "Ä§Óê" : "moyu", 
        "Ä§Éñ" : "demoniac",       "Õ½¿ñ" : "battle", 
        "ÑýÁú" : "yaolong",        "³àÉß" : "chishe", 
        "·ÉÄñ" : "bird",           "¶ñÁú" : "elong", 
        "µÛÍõ" : "imperial",       "ÍõÕß" : "emperor", 
        "Ììºó" : "queen",          "°ÔÍõ" : "lord", 
        "ÌìÊ¥" : "angel",          "ÉñÍõ" : "shenwang", 
        "Ñýºó" : "yaohou",         "Ä§Íõ" : "mowang", 
        "ÆßÐÇ" : "qixing",         "¶ñ¹í" : "egui", 
        "ÓñÁú" : "yulong",         "Óñ·ï" : "yufeng", 
        "ËÉº×" : "songhe",         "ÁúÏè" : "longxiang", 
        "·ïÎè" : "fengwu",         "ÎÞÓ°" : "wuying", 
        "ÆÆ·ç" : "pofeng",         "»ÆÁú" : "huanglong", 
        "Ì«Ô¨" : "taiyuan",        "Ì«·ç" : "taifeng", 
        "ÐéÁé" : "xuling",         "Çàºç" : "qinghong", 
        "°×ºç" : "baihong",        "ÇàË÷" : "chain", 
        "ÌìÁú" : "tianlong",       "×Ïµç" : "zidian", 
        "·ï»Ë" : "fenghuang",      "Ë®»ð" : "shuihuo", 
        "½ð¹â" : "jinguang",       "ÐÞÂÞ" : "religious", 
        "Ò¹²æ" : "yecha",          "ÁúÈª" : "longquan", 
        "ÆÆº®" : "pohan",          "ÌÒ»¨" : "peach", 
        "ÎÞµÐ" : "invincible",     "Åùö¨" : "firebolt", 
        "÷è÷ë" : "kylin",          "½ðË¿" : "jinsi", 
        "Òø¹â" : "yinguang",       "¼ªÏé" : "auspice", 
        "ÌìÅ®" : "fairy",          "»¨ÎÆ" : "huawen", 
        "°µ¹â" : "anguang",        "ËÉÎÆ" : "songwen", 
        "ó´¸Ö" : "pangang",        "¹êÎÄ" : "guiwen", 
        "Çà·æ" : "qingfeng",       "Îâ¹³" : "wugou", 
        "Á÷Ë®" : "liushui",        "Ü½ÈØ" : "furong", 
        "ÉîÔ¨" : "abyssal",        "Á÷²¨" : "liubo", 
        "±ùÊÍ" : "ice",            "¿ªÉ½" : "landslip", 
        "µ¹º£" : "daohai",         "¾â³Ý" : "juchi", 
        "²×º£" : "canghai",        "ÌìÃÅ" : "tianmen", 
        "µØÃÅ" : "dimen",          "Ñãôá" : "yanling", 
        "ÍäÔÂ" : "wanyue",         "ÑàÎ²" : "yanwei", 
        "Éå»ê" : "shehun",         "¶á»ê" : "duohun", 
        "ÏÒÔÂ" : "xuanyue",        "¹íºÅ" : "guihao", 
        "º®¹â" : "ray",            "°×Óñ" : "baiyu", 
        "Ñþ³Ø" : "pool",           "À¶ºç" : "lanhong", 
        "ÒõÉß" : "yinshe",         "ÕÕº£" : "zhaohai", 
        "µØÓü" : "hell",           "ÁúÍ·" : "longtou", 
        "ÃÍ»¢" : "menghu",         "Êï¹â" : "shuguang", 
        "»Ã·ç" : "huanfeng",       "ÍûÔÂ" : "wangyue", 
        "»ðÁú" : "huolong",        "¸ÏÔÂ" : "ganyue", 
        "ÆÃË®" : "poshui",         "»Þ¹â" : "huiguang", 
        "Ã÷¹â" : "mingguang",      "Ìì¹â" : "tianguang", 
        "Éñ¹â" : "shenguang",      "¹íÆø" : "guiqi", 
        "ÏÉÆ·" : "xianpin",        "ÌìË®" : "tianshui", 
        "µØË®" : "dishui",         "Ìì·æ" : "tianfeng", 
        "µØ·æ" : "difeng",         "ÌìÓê" : "tianyu", 
        "ÉñÓê" : "shenyu",         "¹íÓê" : "guiyu", 
        "µØÓê" : "diyu",           "ÏÉÓê" : "xianyu", 
        "ÉñË®" : "shenshui",       "ÏÉË®" : "xianshui", 
        "Ä§Ë®" : "moshui",         "¶¾Éß" : "dushe", 
        "ÖñÒ¶" : "zhuye",          "ÁøÒ¶" : "liuye", 
        "ÌìÖñ" : "tianzhu",        "µØÖñ" : "dizhu", 
        "ÉñÖñ" : "shenzhu",        "Ä§Öñ" : "mozhu", 
        "ÉËºÛ" : "scaur",          "·ÉÎä" : "feiwu", 
        "ÃÍÊ¨" : "mengshi",        "Ð¥Ìì" : "xiaotian", 
        "Ã÷ÔÂ" : "mingyue",        "±ªèÉ" : "leopard", 
        "»¢èÉ" : "huxiao",         "Ê¨èÉ" : "shixiao", 
        "Ò°ÀÇ" : "yelang",         "¿ñÀÇ" : "kuanglang", 
        "¿ñÁú" : "kuanglong",      "ÉñÀÇ" : "shenlang", 
        "ÉñÊ¨" : "shenshi",        "Éñ»¢" : "shenhu", 
        "Éñ±ª" : "leopard",        "ÉñÓ¥" : "shenying", 
        "ÌìÓð" : "skyfeather",     "µØÓð" : "feather", 
        "ÀáºÛ" : "tear",           "ÀËÔÆ" : "langyun", 
        "ÎÚ·¢" : "wufa",           "²õ÷Þ" : "chanbin", 
        "ÔÆ÷Ù" : "yunji",          "Îí÷ß" : "wuhuan", 
        "¶ðÃ¼" : "emei",           "ÇàÖñ" : "qingzhu", 
        "Ã÷íø" : "mingmou",        "Á÷ÅÎ" : "liupan", 
        "Öì´½" : "zhuchun",        "ð©³Ý" : "haochi", 
        "ÓñÖ¸" : "yuzhi",          "ËØ±Û" : "subi", 
        "Ïþ´ä" : "xiaocui",        "´º½­" : "chunjiang", 
        "Ò¹ÔÂ" : "yeyue",          "ÌäÝº" : "crow", 
        "´ÈÔÆ" : "ciyun",          "¸¡ÔÆ" : "fuyun", 
        "ÇàÔÆ" : "qingyun",        "³¯ÔÆ" : "zhaoyun", 
        "Ò¹ÔÆ" : "yeyun",          "·ÉÔÆ" : "feiyun", 
        "¾íÔÆ" : "juanyun",        "°×ÔÆ" : "baiyun", 
        "À¶ÔÆ" : "lanyun",         "×ÏÔÆ" : "ziyun", 
        "ºìÔÆ" : "hongyun",        "³àÔÆ" : "chiyun", 
        "ºèÃÅ" : "hongmen",        "òÔÁú" : "jiaolong", 
        "À×öª" : "leiting",        "Ê¨ºð" : "roar", 
        "ÎÔ»¢" : "wohu",           "ÇàÑò" : "sheep", 
        "ÀÏ¾ý" : "laojun",         "¶·Ä¸" : "doumu", 
        "ºØÀ¼" : "helan",          "ÈÕÔÂ" : "sunmoon", 
        "ÓñÃÅ" : "yumen",          "ÚäÄ°" : "qianmo", 
        "×Ýºá" : "zongheng",       "³ÐÌì" : "chengtian", 
        "ÑÓÓÀ" : "forever",        "Óñ»Ê" : "yuhuang", 
        "ËÉ°Ø" : "pine",           "ÐëÃÖ" : "xumi", 
        "Ðã¹Ç" : "xiugu",          "ÇåÏà" : "qingxiang", 
        "ÂåÉñ" : "luoshen",        "ÌìÓ¥" : "falcon", 
        "Ê¥Ä¸" : "shengmu",        "ÎÄ²ý" : "literate", 
        "ÎäÊ¥" : "knight",         "·ÉÑ©" : "feixue", 
        "Æ®Ñ©" : "piaoxue",        "ÂäÑ©" : "luoxue", 
        "°×Ñ©" : "baixue",         "ÃÎÑ©" : "mengxue", 
        "Ñ©»¨" : "xuehua",         "ÑÌÓê" : "fog", 
        "Ï¼Îµ" : "xiawei",         "³àÏ¼" : "chixia", 
        "äìÏæ" : "xiaoxiang",      "å«º£" : "hanhai", 
        "Äµµ¤" : "mudan",          "°ÙºÏ" : "baihe", 
        "°×ºÉ" : "hehua",          "Áú¾Õ" : "longju", 
        "ÓÄÀ¼" : "youlan",         "ôä´ä" : "feicui",         
        "ÔÆÖñ" : "yunzhu",         "º£ÌÄ" : "haitang", 
        "ÉÖÒ©" : "shaoyao",        "¶Å¾é" : "dujuan", 
        "Ãµ¹å" : "meigui",         "ÔÂ¼¾" : "yueji", 
        "Ç¾Þ±" : "qiangwei",       "²ÔÑÒ" : "rock", 
        "ÌìÊ¦" : "master",         "³£Çà" : "changqing", 
        "·­Ìì" : "fantian",        "½µÄ§" : "demonbane", 
        "·çÁå" : "fengling",       "·çÐÅ" : "fengxin", 
        "×ÏÑô" : "ziyang",         "µ¤Ñô" : "danyang", 
        "×ÏÞ±" : "osmund",         "Ä¾éØ" : "muxi", 
        "Ì«Ñô" : "taiyang",        "»ðúQ" : "huohe", 
        "ÇàúQ" : "qinghe",         "°×úQ" : "baihe", 
        "×ÏúQ" : "zihe",           "°×Þ±" : "baiwei", 
        "À¶Þ±" : "lanwei",         "ÇàÞ±" : "qingwei", 
        "»ðÞ±" : "huowei",         "±ùÞ±" : "bingwei", 
        "ÇàÑô" : "qingyang",       "°×Ñô" : "baiyang", 
        "»ðÑô" : "huoyang",        "±ùÑô" : "bingyang", 
        "¿Û¹Ç" : "bone",           "¶ÉÐÄ" : "duxin", 
        "º¬´ä" : "hancui",         "òùòð" : "bat", 
        "ÔÂÐÎ" : "yuexing",        "ºÚÔÆ" : "heiyun", 
        "Ìúöè" : "shark",          "º³É½" : "hanshan", 
        "¶ÏÓñ" : "duanyu",         "ÕªÐÇ" : "zhaixing", 
        "Ì½ÐÇ" : "tanxing",        "·ÉÐÇ" : "feixing", 
        "ºÚ÷È" : "heimei",         "ÂÌÓ°" : "lvying", 
        "ÓñÄ§" : "demoniac",       "ÒøÁå" : "yinling", 
        "½ðÁå" : "jinling",        "Ç§Øð" : "qianren", 
        "¾§µç" : "jingdian",       "Ç§Ã¢" : "qianmang", 
        "Òõö²" : "mystic",         "Ä§¸¤" : "mofu", 
        "¸ê±Ú" : "desert",         "ÒÏ¾þ" : "yijun", 
        "´£Ò³" : "chuye",          "´ºÓê" : "chunyu", 
        "ÏÄÓê" : "xiayu",          "ÇïÓê" : "qiuyu", 
        "¶¬Óê" : "dongyu",         "´ºÀ¼" : "chunlan", 
        "ÏÄºÉ" : "xiahe",          "Çï¾Õ" : "qiuju", 
        "¶¬Ã·" : "dongmei",        "ÓñÈª" : "yuquan", 
        "ÓðÈª" : "yuquan",         "·çÈª" : "fengquan", 
        "»¢Èª" : "huquan",         "Å­ÌÎ" : "billowy", 
        "äöÁ÷" : "billowy",        "ÇåË®" : "qingshui", 
        "Ë«·æ" : "shuangfeng",     "ÈñÆø" : "ruiqi", 
        "±ØÊ¤" : "bisheng",        "ÅÌ¹Å" : "godly", 
        "·ÉÑà" : "swallow",        "À÷¹í" : "ligui", 
        "¹íÍ·" : "guitou",         "¹íÍõ" : "guiwang", 
        "Å£Í·" : "niutou",         "¾Ð»ê" : "juhun", 
        "»êÆÇ" : "hunpo",          "íýíö" : "yazi", 
        "ó¤ÎÇ" : "chiwen",         "ÆÑÀÎ" : "pulao", 
        "÷Ò÷Ñ" : "haotie",         "òÜÏÄ" : "chuxia",
        "½·Í¼" : "shutu",          "ÑªÕ¶" : "blood",
        "ÌìÍþ" : "tianwei",        "Ðý·ç" : "xuanfeng",
        "×ÏÃ¢" : "zimang",         "Ï÷ÑÒ" : "xiaoyan",
        "ÐÇÁú" : "xinglong",       "ÔÂÁú" : "yuelong",
        "¾ÞÍþ" : "juwei",          "Ó°²Ð" : "shadow",
        "è²ÐÇ" : "canxing",        "ÁÑÐÄ" : "liexin",
        "Ë«ÐÇ" : "shuangxing",     "ÍûÏ¼" : "wangxia",
        "¾Ûº×" : "juhe",           "¾»Ì³" : "jingtan",
        "·É·ï" : "feifeng",        "µÇÁú" : "denglong",
        "¾ÛÈª" : "juquan",         "ÐùÔ¯" : "xuanyuan",
        "ÉñÍ¨" : "shentong",       "ÎÞ¼«" : "wuji",
        "Ì«°×" : "taibai",         "Ç¬À¤" : "qiankun",
        "Ì«¼«" : "taiji",          "ÌìµØ" : "tiandi",
        "ºÆÆø" : "haoqi",          "Á¶Óü" : "lianyu",
        "À¥ÂØ" : "kunlun",         "¾ªÉñ" : "jingshen",
        "°ÁÊÀ" : "aoshi",          "ÊÈÑª" : "shixue",
        "Ç¬Ôª" : "qianyuan",       "¾øÊÀ" : "jueshi",
        "ÁéÆø" : "lingqi",         "Àö¾§" : "lijing",
        "¹â»ª" : "guanghua",       "»ðÑæ" : "huoyan",
        "º®±ù" : "hanbing",        "ÒõÄ§" : "yinmo",
        "ËÉÎÆ" : "songwen",        "µñ»¨" : "diaohua",
        "²ø²¼" : "wrapped-hilt",   "Ìú¼¬" : "thorny",
        "ÒõÑô" : "yinyang",        "½ðÓ¥" : "jinying", 
        "ÖìÉ°" : "cinnabar",       "ÈÕÔÂ" : "glowing",
        "Ñá»ð" : "yenholdish",     "Í®ÔÆ" : "tongyun",
        "½ðÏâ" : "jinxiang",       "ÌìÁú" : "wyvern",
        "Ì«Ðþ" : "taixuan",        "Ì«Çå" : "taiqing",
        "Ì«ÒÒ" : "taiyi",          "Ì«Òõ" : "taiyin",
        "±ÙÑý" : "demonbane",      "³àÁú" : "chilong",     
        "±ÙÐ°" : "devilbane",      "Õò¹í" : "nether",
        "³àÑª" : "chixue",         "±ÌÑª" : "bixue",
        "ÎÞ³¦" : "woochanian",     "½¹½Ä" : "jiaojao",
        "×ÏÑô" : "dawn",           "ÇàÑô" : "shining",
        "»ðÑ×" : "huoyan",         "º®±ù" : "freeze",
        "·ç²¨" : "fengbo",         "ÕðÀ×" : "zhenlei",
        "ÂÞºº" : "guardian",      
]);

string *armor_prefixs = ({ 
        "", "", "", "Ëö×Ó", "Á´×Ó", "ÓãÁÛ", "ÁúÁÛ", 
        "òþÎÆ", "ÓãÎÆ", "ÁúÎÆ", "ÁÛ¼×", 
}); 

mapping weapon_list_axe =([   
"¸«"    :       "axe",          "´ó¸«"    :       "bigaxe",
"¾Þ¸«"  :       "hugeaxe",      
]);

mapping weapon_list_blade =([   
"µ¶"    :       "blade",          "¶Ìµ¶"   :        "duandao",
"Íäµ¶"  :       "wandao",
]);

mapping weapon_list_fork =([   
"²æ"    :       "fork",          "¾Å¹É²æ"    :     "jiugucha",
]);

mapping weapon_list_hammer =([   
"´¸"    :       "hammer",         "Ã·»¨´¸"    :     "huahammer",
]);

mapping weapon_list_mace =([  
"ïµ"    :       "mace",         "Ë«ÈÐïµ"    :     "doublemace",
]);

mapping weapon_list_spear =([  
"¶ÌÇ¹"    :       "shortspear",       "Ç¹"       :    "spear",
"³¤Ç¹"    :       "longspear",       "»ð¼âÇ¹"    :     "firespear",
]);

mapping weapon_list_staff =([   
"ÕÈ"    :       "staff",         "ìøÕÈ"    :     "chanstaff",
]);

mapping weapon_list_stick =([   
"¹÷"    :     "stick",         "¶Ì¹÷"    :     "shortstick",
"´ó¹÷"  :     "bigstick", 
]);

mapping weapon_list_sword =([   
"½£"    :       "sword",       "³¤½£"       :    "longsword",
"¶Ì½£"  :       "shortsword",       "Ï¸½£"    :     "thinsword",
]);

mapping weapon_list_whip =([  
"±Þ"    :     "whip",         "³¤±Þ"    :     "longwhip",
"¾Å½Ú±Þ"  :     "ninewhip", 
]);

mapping armor_list_armor =([  
"¼×"    :       "armor",   "±¦¼×"    :       "baojia",        
]);

mapping armor_list_boots =([  
"Ñ¥"    :       "boots",          "·ÉÑ¥"   :        "flyshoes",
]);

mapping armor_list_cloth =([   
"ÅÛ"    :       "cloth",          "ÏÉÅÛ"    :     "xianpao",
]);

mapping armor_list_hands =([  
"»¤ÕÆ"    :       "hands",         "»¤ÊÖ"    :     "hushou",
]);

mapping armor_list_head =([   
"¿ø"    :       "head",         "Ã±"    :     "hat",
]);

mapping armor_list_neck =([  
"ÏîÁ´"    :       "neck",       "Á´"       :    "necklace",
]);

mapping armor_list_ring =([  
"½äÖ¸"    :       "ring",         "°ßÖ¸"    :     "banzhi",
]);

mapping armor_list_shield =([  
"¶Ü"    :     "shield",         "¶ÜÅÆ"    :     "dun",
]);

mapping armor_list_surcoat =([  
"Åû·ç"    :       "surcoat",       "¶·Åñ"       :    "doupeng",
]);

mapping armor_list_waist =([  
"»¤ÐÄ¾µ"    :     "waist",         "»¤ÐØ"    :     "huxiong",
]);

mapping armor_list_wrists =([  
"»¤Íó"    :     "wrists",         "Íó´ø"    :     "wandai",
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
