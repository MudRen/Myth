// dumpling.c

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("����", ({"fan he", "fan"}));
        set_weight(800);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "һ��С�ɵķ��У����Ż������ڵģ�\n");
                set("unit", "��");
                set("food_remaining", 1);
                set("food_supply", 200);
        }
}

int do_eat(string arg)
{

        object me = this_player();
        if (!id(arg))
                return notify_fail("��Ҫ��ʲô��\n");

	message_vision("$N���Ĵ򿪷��а��˼��ڷ������ûҭ����\n", me);
	destruct(this_object());
        return 1;
}


