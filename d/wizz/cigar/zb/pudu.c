// �նɷ��� by Calvin

#include <ansi.h>
#include <weapon.h>

inherit STAFF;

void create()
{
        set_name( HIY"�ն�"+WHT"����" NOR, ({ "pudu staff", "staff","fazhang","fa zhang" }) );
        set_weight(4000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
                set("long", HIY "����������������֮�նɷ��ȣ��̶���ԣ��������ޱߡ�\n" NOR);
                set("material", "brass");
                set("value", 200000);
                set("no_get", 1);
                set("no_give", 1);
                set("no_put", 1);
                set("no_drop", 1);
                set("no_sell", "���ֺ���������ɲ���������������!\n");
                set("no_give", 1);
                set("wield_msg", HIY "\n$N�ó�һ���նɷ����������У�ɲ�Ǽ�����һƬ���£�����ع���ҲΪ֮�𶯡�\n\n" NOR);
                set("unwield_msg", HIY "\n$N�������е��նɷ��ȣ���Χ���˲Ŵ���һ��������\n\n" NOR);
	}

   init_staff(200);
	setup();
}
