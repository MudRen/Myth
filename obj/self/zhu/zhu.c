#include <ansi.h>
#include <armor.h>
inherit NECK;

void create()
{
       set_name(HIR "ҹ����" NOR, ({"ye mingzhu", "zhu"}));
       set_weight(100);
	  if( clonep() )
	    set_default_object(__FILE__);
	  else {
       set("unit", "��");
       set("long", "һ��" HIR "ҹ����" NOR "����ҹ�����ı�����\n");
       set("value", 10000);
       set("no_steal",1);
       set("no_drop", "��˱����������󰡡�\n");
       set("no_give", "����ϡ��֮����ô������������?\n");
       set("no_sell", "��?����ϡ��֮��˭�����!\n");
       set("wear_msg","$N����һ��ҹ���飬��Χ�ľ�ɫ��ʱһ����\n");
       set("unequip_msg", "$N��ҹ����ȡ������������Ҳ����������\n");
       set("armor_prop/armor", 4);
       set("armor_prop/courage", 4);
       }
       setup();
} 


