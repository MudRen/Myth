// Created by aeddy@2003/05/05

#include <armor.h>

inherit FLOWER;

void create ()
{
	set_name(HIW "�껨" NOR, ({ "rain flower", "rain", "flower" }));
	set_weight(100);
	set("long",WHT"һ�������ڵ��Ͽ��Ļ�����Ө��͸����һ�����ᣬ�����������\n"NOR);
	set("unit", "��");
	set("value", 1);
	set("female_only", 1);
	set("no_break", 1);
	set("armor_type", "flower");
	set("material", "flower");
	set("Fmaterial", "wood");
	set("no_sell", "��ô�������껨��ҲҪ��Ǯ��\n");
	set("no_drop", "�Ե����껨�������Ե���һ�����룬���Ǻú���ϧ���ɡ�\n");
	set("no_give", "�͵����껨������������������������������֮����\n");
	set("no_get", "����Ȼ���껨��ҡ������Ҫ˽��ʹ���ݽߡ�\n");
	set("no_put", "�껨��Ҫ��������������Ҫ˽��ʹ���ݽߡ�\n");
	set("armor_prop/armor", 10);
	set("armor_prop/personality", 10);
	set("unequip_msg","$N����Ө��"+query("name")+"����ط������ġ�����\n");
	set("wear_msg", "$N��һ�侧Ө��"+query("name")+"������ǰ����Ө��͸��ӳ����$P����������Ӱ��\n" );
	setup();
}
