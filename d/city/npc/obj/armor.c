// jinjia.c ���
#include <armor.h>

inherit ARMOR;

void create()
{
        set_name("�����Ӽ�", ({"golden armor","jinjia", "jia", "armor"}));
        set_weight(30000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
		set("long", "һ������֯�͵ı��ף�\n");
                set("material", "steel");
                set("value", 10000);
                set("armor_prop/armor", 60);
				set("no_sell",1);
				set("no_drop","ȥ�����Ѷ��ɣ����ӻ���Ⱦ����!\n");
				set("no_give","�ܹܷ���װ�����ɲ���������Ӵ��\n");
				set("no_get","�����ܹ�һҶ֪�﷢��װ�������ΰ�!\n");
				set("armor_prop/dodge", -5);
        }
        setup();
}


