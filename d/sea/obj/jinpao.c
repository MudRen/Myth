// longpao.c
#include <armor.h>
inherit CLOTH;

void create()
{
        set_name("������", ({"jinhua pao","cloth","pao"}));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
            set("long",
"����һ�������ޱȵĽ����ۣ��������Ÿ��ֻ��ݣ�����һ��������\n");
                set("value", 50000);
                set("material", "cloth");
                set("armor_type", "cloth");
                set("armor_prop/armor", 10);
                set("armor_prop/personality", 3);
                set("female_only", 1);
             }
	setup();
}

