//Cracked by Roath
inherit ITEM;
#include <ansi.h>
void create()
{
        set_name(HIB "������" NOR, ({"lei zhu"}) ); 
 set_weight(200);
        if( clonep() )
  set_default_object(__FILE__);
 else {
  set("unit", "��");
  set("material", "crystal");
set("value",1); 
                set("long","��˵�е����б���֮һ����֮�ɱ��׻������ɷ����׻�
������\nΪ����������֮�");
                set("owner_name","��������");
                set("owner_id","guanyin pusa");
 }
 setup();
}


