//Cracked by Roath
#include <ansi.h>
inherit ITEM;

void create()
{
        set_name("����", ({"dan pan"}));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 5);
                set("no_get",1);
                set("material", "wood");
        }
        setup();
}
void init()
{
        add_action("do_prepare","hold");
}

int do_prepare(string arg)
{
        object ob = this_player();
        if( ! arg || arg != "dan pan" )
                return notify_fail("��Ҫ����ʲô��\n");

        if( ob->query_temp("prepared") )
                return notify_fail("�㲻���Ѿ�׼��������\n");

        message_vision(HIC"ֻ��$N�ѵ����������У����ý��˲ι������ơ�\n"NOR,ob);
        ob->set_temp("prepared",1);
        return 1;
}
