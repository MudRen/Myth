// 接引殿.
// 此文件用来调整系统中武学道行过高.
// 严禁随意修改此文件.
// rewritten by mudring Dec/01/2002

#include <room.h>
#include <ansi.h>
inherit ROOM;

void init();
void close_gate();
int do_knock(string);
int valid_leave();
string look_gate();

int do_shen();

void create ()
{
    set ("short", "接引殿");
    set ("long", @LONG

进了南天门，已经可以看到一座座天宫放着七彩霞光，忽隐忽现
于云遮雾绕之中。里壁厢有几根大柱，柱上缠绕着金鳞耀日赤须
龙；一座白玉桥弯弯曲曲地向北延伸，东西两边各有一座大殿，
也不知是干什么用的，你可以隐约听到东边殿中有喧哗之声，似
乎人不少。

LONG);

    set("exits", ([ //
        "south" : __DIR__"nantian",
        "north" : __DIR__"caihongqiao",
        "west" : __DIR__"caifengdian",
        "east" : __DIR__"jinlongdian",
    ]));

    create_door("south", "南天门", "north", DOOR_CLOSED);

    set("no_clean_up", 0);

    setup();
}

void init()
{
    add_action("do_drop", "drop");
    add_action("do_shen", "shen");
}

int do_shen()
{
    object me;
    string s;
    int my_exp, my_level, temp, price, price2, afford;

    me = this_player();
    my_exp = me->query("combat_exp");
    my_level = me->query("level");
    temp = get_level(my_exp);
    // 最高级别200.
    if (temp > 200) temp = 200;

    if (my_level < temp)
    {
        // 下面的计算太夸张了吧.
        if (my_level < 100)  price = 10000 * (my_level + 1);
        if (my_level >= 100) price = 50000 * (my_level + 2);

        price2 = price / 12;
        // 等级在120以后降低gold耗费.
        // 考虑是否增加武学道行消耗.
        if (my_level > 120)
        {
            price = 12000000;

            if (my_level > 120 && !metep(me))
            {
                price = 12000000 + my_level * 100000;
            }
        }

        if (me->query("daoxing") - 500000 < price/4 ||
            me->query("combat_exp") - 500000 < price/4)
        {
            tell_object(me,"你的武学或者道行修为不够，暂时不能升级！\n");
            return 1;
        }

        if (me->query("balance") >= price )
        {
            me->add("balance", -price);
            me->add("daoxing", -price2);
            me->add("combat_exp", -price2);
            temp = me->query("scorepoint") + (my_level / 10 + 100) * 100;
            me->add("level", 1);
            me->set("scorepoint", temp);
            NPC_D->full_hp_status(me);
            message_vision(HIY"$N闭目静静的想着什么，突然人显得神采奕奕起来！\n"NOR, me);
            tell_object(me, HIW "你的级别得到了提升.\n" NOR);
        }
        else
        {
            tell_object(me, sprintf(HIW"你没有足够的金钱为三界捐助福利，升到" HIY "%d"
                        HIW "级的捐助费用为%s！\n "NOR,
                        my_level + 1, MONEY_D->price_str(price)));
        }
    }
    else
    {
        if (my_level >= 200)
            tell_object(me, HIY"恭喜恭喜！你已经达到三界之颠了！\n"NOR);
        else
            tell_object(me, sprintf(HIW "你的武学修为只能够升到" HIY "%d" HIW "级，"
                        "还是多去修行积福吧！\n" NOR, temp));
    }
    return 1;
}


int do_drop()
{
    tell_object(this_player(),"鬼鬼祟祟的想干什么！\n");
    return 1;
}


