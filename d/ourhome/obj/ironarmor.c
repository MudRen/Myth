// ironarmor.c
inherit EQUIP;

void create()
{
        set_name("����", ({"tie jia","tiejia","jia","armor"}));
        set_weight(50000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
	    set("long", "һ�����������ס�\n");
                set("value", 5000);
                set("material", "iron");
                set("armor_type", "cloth");
                set("armor_prop/armor", 50);
             }
}
