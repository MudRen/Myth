//Cracked by Roath
#include <ansi.h>
inherit ITEM;
#include <task.h>
void create()
{
set_name(HIR "������" NOR, ({"huo lingzhu"}) );
 set_weight(200);
        if( clonep() )
  set_default_object(__FILE__);
 else {
  set("unit", "��");
  set("material", "crystal");
  set("value",1);
                set("long","��˵�е����б���֮һ����֮�ɱܻ��գ����ɷ�����ϵ
������\nΪ����������֮�");
                set("owner_id", "guanyin pusa");
  set("owner_name","��������");
 }
 setup();
}


