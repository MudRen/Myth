// statud.c
// by mudring

#include <ansi.h>

inherit F_SKILL;

private mapping families = ([ //
//  family              id         master      place         weapon
    "蜀山剑派"     : ({ "shushan", "蜀山剑圣", "/d/shushan", "sword", }),
    "轩辕古墓"     : ({ "gumu", "女娲娘娘", "/d/gumu", "sword", }),
    "月宫"         : ({ "moon", "西王母", "/d/moon", "sword", }),
    "五庄观"       : ({ "zhenyuan", "镇元大仙", "/d/qujing/wuzhuang", "sword", }),
    "大雪山"       : ({ "xueshan", "大鹏明王", "/d/xueshan", "blade", }),
    "三界山"       : ({ "sanjie", "纯阳天师", "/d/sanjie", "blade", }),
    "陷空山无底洞" : ({ "wudidong", "玉鼠精", "/d/qujing/wudidong", "blade", }),
    "火云洞"       : ({ "kusong", "黄飞虎", "/d/qujing/kusong", "spear", }),
    "将军府"       : ({ "jjf", "白法老人", "/d/jjf", "spear", }),
    "阎罗地府"     : ({ "death", "地藏王菩萨", "/d/death", "whip", }),
    "盘丝洞"       : ({ "pansi", "紫霞仙子", "/d/pansi", "whip", }),
    "东海龙宫"     : ({ "dragon", "东海龙王", "/d/sea", "fork", }),
    "南海普陀山"   : ({ "bonze", "观音菩萨", "/d/nanhai", "staff", }),
    "方寸山三星洞" : ({ "puti", "菩提祖师", "/d/lingtai", "stick", }),
]);

private mapping performs = ([ //
//  family              perform 1..n
    "蜀山剑派"     : ({ "wanjian", "fumo", "duanshui", }),
    "轩辕古墓"     : ({ "sword21", }),
    "月宫"         : ({ "tian", }),
    "五庄观"       : ({ "jianzhang",  }),
    "大雪山"       : ({ "duandao", "bing", "yaowu",  }),
    "三界山"       : ({ "tulong", }),
    "陷空山无底洞" : ({ "diyu", }),
    "火云洞"       : ({ "buhui", }),
    "将军府"       : ({ "meihua", "jinghun",  }),
    "阎罗地府"     : ({ "three", "ldlh", "lunhui",  }),
    "盘丝洞"       : ({ "wyly", "tian", }),
    "东海龙宫"     : ({ "bibo", }),
    "南海普陀山"   : ({ "pudu",  }),
    "方寸山三星洞" : ({ "baifo", "qiankun", }),
]);

private string *npc_skill_set(object me)
{
    string family;

    if (!objectp(me))
        return 0;

    family = me->query("family/family_name");
    switch (family)
    {
        case "轩辕古墓":
            return ({
                "spells",   "youming-spells",
                "force",    "jiuyin-force",
                "sword",    "shengling-sword", "qinghu-jian",
                "blade",    "zizhi-blade", "mohuang-blade",
                "mace",     "yinlei-mace",
                "unarmed",  "jiuyin-zhua",
                "dodge",    "kongming-steps",
                "parry",
            });
        case "月宫":
            return ({
                "spells",   "moonshentong",
                "force",    "moonforce",
                "sword",    "snowsword",
                "whip",     "jueqingbian",
                "blade",    "xuanhu-blade",
                "unarmed",  "baihua-zhang",
                "dodge",    "moondance",
                "parry",
            });
        case "方寸山三星洞":
            return ({
                "spells",   "dao",
                "force",    "wuxiangforce",
                "sword",    "liangyi-sword",
                "stick",    "qianjun-bang",
                "unarmed",  "puti-zhi",
                "dodge",    "jindouyun",
                "parry",
            });
        case "五庄观":
            return ({
                "spells",   "taiyi",
                "force",    "zhenyuan-force",
                "sword",    "sanqing-jian", "xiaofeng-sword",
                "blade",    "yange-blade",
                "staff",    "fumo-zhang",
                "hammer",   "kaishan-chui",
                "unarmed",  "wuxing-quan",
                "dodge",    "baguazhen",
                "parry",
            });
        case "陷空山无底洞":
            return ({
                "spells",   "yaofa",
                "force",    "huntian-qigong",
                "sword",    "qixiu-jian",
                "blade",    "kugu-blade",
                "unarmed",  "yinfeng-zhua",
                "dodge",    "lingfu-steps",
                "parry",
            });
        case "盘丝洞":
            return ({
                "spells",   "pansi-dafa",
                "force",    "jiuyin-xinjing",
                "sword",    "chixin-jian", "qingxia-jian",
                "whip",     "yinsuo-jinling",
                "unarmed",  "lanhua-shou",
                "dodge",    "yueying-wubu",
                "parry",
            });
        case "大雪山":
            return ({
                "spells",   "dengxian-dafa",
                "force",    "ningxie-force",
                "sword",    "bainiao-jian",
                "blade",    "bingpo-blade",
                "unarmed",  "cuixin-zhang", "yingzhaogong",
                "dodge",    "xiaoyaoyou",
                "parry",
            });
        case "南海普陀山":
            return ({
                "spells",   "buddhism",
                "force",    "lotusforce",
                "staff",    "lunhui-zhang",
                "stick",    "buddha-stick",
                "spear",    "huoyun-qiang",
                "unarmed",  "jienan-zhi",
                "dodge",    "lotusmove",
                "parry",
            });
        case "蜀山剑派":
            return ({
                "spells",   "taoism",
                "force",    "zixia-shengong",
                "sword",    "shushan-jianfa", "mindsword", "yujianshu", "canxin-jian",
                "whip",     "yirubian",
                "unarmed",  "hunyuan-zhang",
                "dodge",    "sevensteps",
                "parry",
            });
        case "东海龙宫":
            return ({
                "spells",   "seashentong",
                "force",    "dragonforce",
                "fork",     "fengbo-cha",
                "hammer",   "huntian-hammer",
                "unarmed",  "dragonfight",
                "dodge",    "dragonstep",
                "parry",
            });
        case "阎罗地府":
            return ({
                "spells",   "gouhunshu",
                "force",    "tonsillit",
                "sword",    "zhuihun-sword",
                "stick",    "kusang-bang",
                "whip",     "hellfire-whip",
                "unarmed",  "jinghun-zhang",
                "dodge",    "ghost-steps",
                "parry",
            });
        case "三界山":
            return ({
                "spells",   "tianmogong",
                "force",    "huntianforce",
                "sword",    "huxiaojian",
                "stick",    "tianyaofa",
                "blade",    "zileidao",
                "unarmed",  "liushenjue",
                "dodge",    "zhaoyangbu",
                "parry",
            });
        case "火云洞":
            return ({
                "spells",   "pingtian-dafa",
                "force",    "huomoforce",
                "spear",    "huoyun-qiang", "wuyue-spear",
                "stick",    "dali-bang",
                "unarmed",  "moyun-shou",
                "dodge",    "moshenbu",
                "parry",
            });
        case "将军府":
            return ({
                "spells",   "baguazhou",
                "force",    "lengquan-force",
                "spear",    "bawang-qiang",
                "mace",     "jinglei-mace", "wusi-mace",
                "axe",      "sanban-axe",
                "unarmed",  "changquan",
                "dodge",    "yanxing-steps",
                "parry",
            });
        default:
            return ({
                "spells",   "taoism",
                "force",    "zixia-shengong",
                "sword",    "daya-jian",
                "unarmed",  "hunyuan-zhang",
                "dodge",    "sevensteps",
                "parry",
            });
    }
}

private mapping npc_skill_map(object me)
{
    string family;

    if (!objectp(me)) return 0;

    family = me->query("family/family_name");

    switch (family)
    {
        case "轩辕古墓":
            return ([ // sword
                "spells":       "youming-spells",
                "force" :       "jiuyin-force",
                "sword" :       "shengling-sword",
                "blade" :       "mohuang-blade",
                "mace"  :       "yinlei-mace",
                "unarmed":      "jiuyin-zhua",
                "dodge" :       "kongming-steps",
                "parry" :       "shengling-sword",
            ]);
        case "月宫":
            return ([ // sword
                "spells":       "moonshentong",
                "force" :       "moonforce",
                "sword" :       "snowsword",
                "blade" :       "xuanhu-blade",
                "whip"  :       "jueqingbian",
                "unarmed":      "baihua-zhang",
                "dodge" :       "moondance",
                "parry" :       "snowsword",
            ]);
        case "方寸山三星洞":
            return ([ // stick
                "spells":       "dao",
                "force" :       "wuxiangforce",
                "stick" :       "qianjun-bang",
                "sword" :       "liangyi-sword",
                "unarmed":      "puti-zhi",
                "dodge" :       "jindouyun",
                "parry" :       "qianjun-bang",
            ]);
        case "五庄观":
            return ([ // sword
                "spells":       "taiyi",
                "force" :       "zhenyuan-force",
                "sword" :       "sanqing-jian",
                "blade" :       "yange-blade",
                "staff" :       "fumo-zhang",
                "hammer":       "kaishan-chui",
                "unarmed":      "wuxing-quan",
                "dodge" :       "baguazhen",
                "parry" :       "sanqing-jian",
            ]);
        case "陷空山无底洞":
            return ([ // blade
                "spells":       "yaofa",
                "force" :       "huntian-qigong",
                "blade" :       "kugu-blade",
                "sword" :       "qixiu-jian",
                "unarmed":      "yinfeng-zhua",
                "dodge" :       "lingfu-steps",
                "parry" :       "kugu-blade",
            ]);
        case "盘丝洞":
            return ([ // whip
                "spells":       "pansi-dafa",
                "force" :       "jiuyin-xinjing",
                "whip"  :       "yinsuo-jinling",
                "sword" :       "chixin-jian",
                "unarmed":      "lanhua-shou",
                "dodge" :       "yueying-wubu",
                "parry" :       "yinsuo-jinling",
            ]);
        case "大雪山":
            return ([ // sword
                "spells":       "dengxian-dafa",
                "force" :       "ningxie-force",
                "sword" :       "bainiao-jian",
                "blade" :       "bingpo-blade",
                "unarmed":      "cuixin-zhang",
                "dodge" :       "xiaoyaoyou",
                "parry" :       "bingpo-blade",
            ]);
        case "南海普陀山":
            return ([ // staff
                "spells":       "buddhism",
                "force" :       "lotusforce",
                "staff" :       "lunhui-zhang",
                "stick" :       "buddha-stick",
                "spear" :       "huoyun-qiang",
                "unarmed":      "jienan-zhi",
                "dodge" :       "lotusmove",
                "parry" :       "lunhui-zhang",
            ]);
        case "蜀山剑派":
            return ([ // sword
                "spells":       "seashentong",
                "force" :       "zixia-shengong",
                "sword" :       "yujianshu",
                "whip"  :       "yirubian",
                "unarmed":      "hunyuan-zhang",
                "dodge" :       "sevensteps",
                "parry" :       "yujianshu",
            ]);
        case "东海龙宫":
            return ([ // fork
                "spells":       "seashentong",
                "force" :       "dragonforce",
                "fork"  :       "fengbo-cha",
                "hammer":       "huntian-hammer",
                "unarmed":      "dragonfight",
                "dodge" :       "dragonstep",
                "parry" :       "fengbo-cha",
            ]);
        case "阎罗地府":
            return ([ // whip
                "spells":       "gouhunshu",
                "force" :       "tonsillit",
                "whip"  :       "hellfire-whip",
                "stick":        "kusang-bang",
                "sword":        "zhuihun-sword",
                "unarmed":      "jinghun-zhang",
                "dodge" :       "ghost-steps",
                "parry" :       "hellfire-whip",
            ]);
        case "三界山":
            return ([ // sword
                "spells":       "tianmogong",
                "force" :       "huntianforce",
                "sword" :       "huxiaojian",
                "stick":        "tianyaofa",
                "blade":        "zileidao",
                "unarmed":      "liushenjue",
                "dodge" :       "zhaoyangbu",
                "parry" :       "zileidao",
            ]);
        case "火云洞":
            return ([ // spear
                "spells":       "pingtian-dafa",
                "force" :       "huomoforce",
                "spear" :       "wuyue-spear",
                "stick":        "dali-bang",
                "unarmed":      "moyun-shou",
                "dodge" :       "moshenbu",
                "parry" :       "wuyue-spear",
            ]);
        case "将军府":
            return ([ // mace
                "spells":       "baguazhou",
                "force" :       "lengquan-force",
                "mace"  :       "jinglei-mace",
                "axe"   :       "sanban-axe",
                "spear":        "bawang-qiang",
                "unarmed":      "changquan",
                "dodge" :       "yanxing-steps",
                "parry" :       "bawang-qiang",
            ]);
        default:
            return ([ // sword
                "spells":       "taoism",
                "force" :       "zixia-shengong",
                "sword" :       "daya-jian",
                "unarmed":      "hunyuan-zhang",
                "dodge" :       "sevensteps",
                "parry" :       "daya-jian",
            ]);
    }
}

string random_family()
{
    string *familys = keys(families);
    return familys[random(sizeof(familys))];
}

int valid_family(string family)
{
    if (family && !undefinedp(families[family])) 
        return 1;
    return 0;
}

varargs void set_npc_skill(object me, int lvl, string family)
{
    int i, temp;
    string skill, val_map, *sname;
    mapping skill_status;

    if (!objectp(me))
        return;

    if (userp(me) && !is_root(previous_object()))
        return;

    if (!valid_family(family))
    {
        family = me->query("family/family_name");
    }

    if (!valid_family(family))
    {
        family = random_family();
    }
    me->set("family/family_name", family);

    if (mapp(skill_status = me->query_skills()))
    {
        skill_status = me->query_skills();
        sname = keys(skill_status);

        temp = sizeof(skill_status);
        for (i = 0; i < temp; i++)
            me->delete_skill(sname[i]);
    }

    i = sizeof(npc_skill_set(me));
    while (i--)
    {
        skill = npc_skill_set(me)[i];
        me->set_skill(skill, lvl);
    }

    i = sizeof(npc_skill_set(me));
    while (i--)
    {
        skill = npc_skill_set(me)[i];
        if (val_map = npc_skill_map(me)[skill])
            me->map_skill(skill, val_map);
    }
}

// get a family id
string family_id(string family)
{
    if (!valid_family(family))
        return 0;

    return families[family][0];
}

// get a family master name
string family_master(string family)
{
    if (!valid_family(family))
        return 0;

    return families[family][1];
}

// get a family place
object family_place(string family)
{
    string dir;

    if (!valid_family(family))
        return 0;

    dir = families[family][2];
    return NPC_D->task_place(dir);
}

// get the weapon
object family_weapon(string family)
{
    string type;
    object weapon;
    
    if (!valid_family(family))
        return 0;

    type = families[family][3];
    weapon = new(BINGQI_D("job/") + type);
    weapon->set("type", type);
    return weapon;
}

string family_action(string family)
{
    string action;

    if (family && !undefinedp(performs[family]))
    action = performs[family][random(sizeof(performs[family]))];
MONITOR_D->report_debug_object_msg(this_object(), action);
    return action;
}

