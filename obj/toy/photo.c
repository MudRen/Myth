// ash.c

inherit ITEM;

void create()
{
        set_name("�ҽ�", ({ "huijin", "ash" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
				set("unit", "��");
				set("value",0);
		set("long", "һ���޷����ϵĽ��ڵĻҽ�������һ���ƽٺ����µĲ��ࡣ\n");
		}
        setup();
}

void init()
{
}

