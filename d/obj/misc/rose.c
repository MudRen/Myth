
#include <ansi.h>
#include <dbase.h>
#include <armor.h>

inherit NECK;

#include "message.h"

void create ()
{
  set_name(HIR "��ǧ�Űپ�ʮ�Ŷ�õ��" NOR, ({ "flower"}));
  set_weight(100);
  set("long","һ��õ�壬�͸��ҵİ���"+query("name")+"��\n");
  set("unit", "��");
  set("armor_prop/armor", 1);
  set("armor_prop/personality", 2);
  set("unequip_msg","$N��"+query("name")+"�����ժ����������\n");
  set("wear_msg", "$N����"+query("name")+"�����������������˵����ᡣ\n");
  setup();
}


