//Cracked by Roath
#include <ansi.h>
inherit ITEM;
#include <task.h>
void create()
{
set_name(HIG "������" NOR, ({"feng lingzhu"}));
 set_weight(200);
        if( clonep() )
  set_default_object(__FILE__);
 else {
  set("unit", "��");
  set("material", "crystal");
  set("value",1);
                set("long","��˵�е����б���֮һ����֮�ɱܷ紵�����ɷ�����ϵ
������\nΪ����������֮�");
                set("owner_id", "guanyin pusa");
  set("owner_name","��������");
 }
 setup();
}


