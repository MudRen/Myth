// jiasha.c
//

#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
        set_name(HIW"�ٺ�˿��"NOR, ({"baihe siyi", "siyi", "cloth" }) );
        set("long", "һ�������⻬��˿����������ʢ����"HIW"�ٺϻ���\n"NOR);
	set_weight(0);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("material", "cloth");
                set("no_drop",1);
                set("no_give",1);
                set("no_get",1);
                set("no_sell",1);
		set("armor_prop/armor", 40);
		set("armor_prop/dodge", 50);
                set("armor_prop/personality", 10);
                      set("wear_msg","$N�ռ�����ߵ�"HIM"��ϼ"NOR"�������"HIW"����"NOR"��֯��һ�������������ϡ� ӳ�����������������ڣ������滨��¶������\n"); 
                      set("unequip_msg", "$N���ϵ�˿��ͻȻ��������ɢȥ����ʧ����ľ�ͷ�� ֻ����ϼ������������һĨ"MAG"����\n"); 
                set("value", 50000);

	}
	setup();
}

      int query_autoload() { return 1; } 
