// �նɷ��� by Calvin

#include <ansi.h>
#include <weapon.h>

inherit STAFF;

void create()
{
        set_name( YEL "�նɷ���" NOR, ({ "pudu staff", "staff","fazhang","fa zhang" }) );
        set_weight(4000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
                set("long", HIY "����������������֮�նɷ��ȣ��̶���ԣ��������ޱߡ�\n" NOR);
                set("material", "brass");
             set("value", 15000);
                set("wield_msg", HIY "$N�ó�һ���նɷ����������У�ɲ�Ǽ�����һƬ���£�����ع���ҲΪ֮�𶯡�\n" NOR);
                set("unwield_msg", HIY "$N�������е��նɷ��ȣ���Χ���˲Ŵ���һ��������\n" NOR);
	}

   init_staff(110);
	setup();
}
