//Cracked by Roath
inherit ITEM;

void create()
{
        set_name("���С��", ({ "che"}) );
        set_weight(10000000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("long", "һ������ľС����\n");
                set("unit", "��");
        }
}

