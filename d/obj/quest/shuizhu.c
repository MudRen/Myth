//Cracked by Roath
#include <ansi.h>
inherit ITEM;
void create()
{
set_name(HIW "ˮ����" NOR, ({"shui lingzhu"}) );
 set_weight(200);
        if( clonep() )
  set_default_object(__FILE__);
 else {
  set("unit", "��");
  set("material", "crystal");
  set("value",1);
  set("long","��˵�е����б���֮һ����֮�ɱ�ˮ�ͣ����ɷ���ˮϵ������\nΪ����
������֮�");
                set("owner_name","��������");
                set("owner_id","guanyin pusa");
}
 setup();
}


