// lightarmor.c
inherit EQUIP;

void create()
{
        set_name("�ټ�", ({"teng jia","tengjia","jia","armor"}));
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
	    set("long", "һ������ټס�\n");
                set("value", 5000);
                set("material", "wood");
                set("armor_type", "cloth");
                set("armor_prop/armor", 20);
             }
}
