// created 4/5/1997 by snowcat
#include <ansi.h>
#include <dbase.h>
#include <armor.h>
inherit F_AUTOLOAD; 

inherit NECK;

void create ()
{
  set_name(HIM "����õ��" NOR, ({ "rose"}));
  set_weight(100);
  set("long",HIW"�����������峿�Ļ�԰�в�ժ��"NOR+query("name")+HIW"�����滹�����ż��ž�Ө��¶�顣 \n" NOR);
  set("unit", "��");
  set("armor_prop/armor", 1);
  set("armor_prop/personality", 2);
  set("unequip_msg",HIW"$N��"+query("name")+HIW"�����ժ����������Զ������������һ�ᣬ������������������ 

          ������ʱ���������ƻ����ɡ��ֳɴ��ݣ��۶���ǰ����
          ������飬���볤���ء��ַɺ���ۺ;ƣ�ռ��˫���䡣

\n" NOR);
  set("wear_msg", HIW"$N����"+query("name")+HIW"�����������Ǹ�ҹҹ���ε����ˣ����Ϸ���һƬ���ơ� 

          ���Զ�����¥�����繳����į��ͩ��Ժ�����
          �����ϣ����ң���������һ����ζ����ͷ��

\n" NOR);
  setup();
}


//
int query_autoload() { return 1; }
