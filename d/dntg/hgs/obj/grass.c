// grass.c

#include <ansi.h>

inherit ITEM;

int do_make(string);

void create()
{
	set_name("С��", ({ "grass"}) );
	set("long", "һ�������͵�С�ݡ�\n");
	set("unit", "��" );
        set("no_sell",1);
}



void init()
{                                             
	add_action("do_eat", "eat");
}


int do_eat(string arg)
{
        object me = this_player();

        if (!id(arg)) return notify_fail("��Ҫ��ʲô��\n");

        message_vision("$N������ʳ��ҧ�˼�����ݣ�����ֶ����˳�����\n" , me);

        destruct(this_object());

        return 1;

}

