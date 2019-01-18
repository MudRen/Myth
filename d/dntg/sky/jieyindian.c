// ������.
// ���ļ���������ϵͳ����ѧ���й���.
// �Ͻ������޸Ĵ��ļ�.
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
    set ("short", "������");
    set ("long", @LONG

���������ţ��Ѿ����Կ���һ�����칬�����߲�ϼ�⣬��������
����������֮�С�������м������������ϲ����Ž���ҫ�ճ���
����һ�����������������������죬�������߸���һ����
Ҳ��֪�Ǹ�ʲô�õģ��������Լ�������ߵ���������֮������
���˲��١�

LONG);

    set("exits", ([ //
        "south" : __DIR__"nantian",
        "north" : __DIR__"caihongqiao",
        "west" : __DIR__"caifengdian",
        "east" : __DIR__"jinlongdian",
    ]));

    create_door("south", "������", "north", DOOR_CLOSED);

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
    // ��߼���200.
    if (temp > 200) temp = 200;

    if (my_level < temp)
    {
        // ����ļ���̫�����˰�.
        if (my_level < 100)  price = 10000 * (my_level + 1);
        if (my_level >= 100) price = 50000 * (my_level + 2);

        price2 = price / 12;
        // �ȼ���120�Ժ󽵵�gold�ķ�.
        // �����Ƿ�������ѧ��������.
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
            tell_object(me,"�����ѧ���ߵ�����Ϊ��������ʱ����������\n");
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
            message_vision(HIY"$N��Ŀ����������ʲô��ͻȻ���Ե��������������\n"NOR, me);
            tell_object(me, HIW "��ļ���õ�������.\n" NOR);
        }
        else
        {
            tell_object(me, sprintf(HIW"��û���㹻�Ľ�ǮΪ�����������������" HIY "%d"
                        HIW "���ľ�������Ϊ%s��\n "NOR,
                        my_level + 1, MONEY_D->price_str(price)));
        }
    }
    else
    {
        if (my_level >= 200)
            tell_object(me, HIY"��ϲ��ϲ�����Ѿ��ﵽ����֮���ˣ�\n"NOR);
        else
            tell_object(me, sprintf(HIW "�����ѧ��Ϊֻ�ܹ�����" HIY "%d" HIW "����"
                        "���Ƕ�ȥ���л����ɣ�\n" NOR, temp));
    }
    return 1;
}


int do_drop()
{
    tell_object(this_player(),"�����������ʲô��\n");
    return 1;
}


