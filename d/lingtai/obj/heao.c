// pao.c

inherit EQUIP;

void create()
{
        set_name("������", ({"leather coat", "coat"}));
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
		set("long", "һ������֯�͵Ĵ�멡�\n");
                set("value", 500);
		set("no_sell", 1);
                set("armor_type", "cloth");
                set("armor_prop/armor", 10);
                set("armor_prop/spells", 15);
		set("armor_prop/dodge", 5);
             }
}
