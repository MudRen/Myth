//Cracked by Roath
inherit ITEM;
#include <ansi.h>
#include <task.h>
void create()
{
        set_name(CYN"ʥ����"NOR, ({"sheng zhu"}) ); 
 set_weight(1000);
        if( clonep() )
  set_default_object(__FILE__);
 else {
  set("unit", "��");
  set("material", "crystal");
set("value",1); 
                set("long","��س���ʱ�����߹����ϣ����߹����£���һ�ְ����
�ǹ����У���Ϊ�˱���\n
������н�Ϊ���ӡ�\n");
                set("owner_name","��������");
                set("owner_id","guanyin pusa");
 }
 setup();
}


