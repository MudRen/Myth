inherit ITEM;
#include <task.h>
void create()
{
  set_name("Ѳɽ����", ({ "xunshan yaopai", "yaopai" }));
  set_weight(1000);
  set("long", "����һ����ͷɽС��Ѳɽ�����ơ�\n" );
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "ֻ");
    set("owner_name","����Ź�");
                 set("owner_id","diaozuan guguai");
  }
  setup();
}

